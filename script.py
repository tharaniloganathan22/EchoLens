import vosk
import json
import sounddevice as sd
import queue
import requests

# Load Vosk Model (Ensure the model is downloaded)
MODEL_PATH = "vosk_model"
model = vosk.Model(MODEL_PATH)

# ESP32 Server URL (Replace with your ESP32's IP)
ESP32_URL = "http://192.168.1.100/receive"  # Change to your ESP32 IP

# Queue to store audio data
q = queue.Queue()

# Audio processing function
def callback(indata, frames, time, status):
    if status:
        print(status)
    q.put(bytes(indata))

# Speech recognition function
def recognize_speech():
    with sd.RawInputStream(samplerate=16000, blocksize=8000, dtype="int16",
                           channels=1, callback=callback, latency=0.5):
        print("Listening...")
        rec = vosk.KaldiRecognizer(model, 16000)

        while True:
            data = q.get()
            if rec.AcceptWaveform(data):
                result = json.loads(rec.Result())
                text = result["text"]

                # Send to ESP32 if valid text is detected
                if text.strip() and len(text) > 2:
                    print("Recognized:", text)
                    send_to_esp32(text)

# Function to send text to ESP32 via HTTP
def send_to_esp32(text):
    try:
        response = requests.post(ESP32_URL, json={"text": text})
        print("Sent to ESP32:", response.text)
    except Exception as e:
        print("Error sending to ESP32:", str(e))

if __name__ == "__main__":
    recognize_speech()
