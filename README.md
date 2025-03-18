# 🔊 EchoLens – AI-Powered Smart Glasses for the Deaf & Hard of Hearing 🕶️🎧  

### 📌 **Description**  
**EchoLens** is an **AI-powered assistive technology** designed to enhance communication for the **deaf and hard-of-hearing community**. It converts **real-time speech into text** using **Vosk ASR** and displays the output on an **OLED screen** via **ESP32**. The device works **offline**, making it an affordable and accessible solution compared to existing assistive technologies.  

---

## 🚀 **Features**  
✅ **Real-Time Speech-to-Text Conversion** – Uses AI-driven speech recognition to transcribe conversations.  
✅ **OLED Display Integration** – Displays transcribed text on smart glasses using ESP32.  
✅ **Offline Processing** – Works without an internet connection, making it practical and cost-effective.  
✅ **Lightweight & Wearable** – Designed to be compact and comfortable for everyday use.  
✅ **Affordable Hardware** – Built using ESP32, OLED display, and MEMS microphone for a low-cost solution.  

---

## 🛠 **Technologies & Tools Used**  
### **🔹 Software Stack**  
- **Python** – For speech recognition and backend processing  
- **Vosk ASR** – Offline speech-to-text conversion  
- **Flask** – Handles communication between ESP32 and speech recognition module  
- **Arduino (ESP32 C++)** – Embedded programming for ESP32 and OLED display  
- **HTTP Requests** – Transfers recognized text to ESP32  

### **🔹 Hardware Components**  
| Component           | Description  |
|---------------------|-------------|
| **ESP32**          | Microcontroller for processing & WiFi communication |
| **0.96" OLED Display** | Displays transcribed text from speech |
| **MEMS Microphone** | Captures real-time audio input |
| **Lithium Rechargeable Battery** | Powers the device wirelessly |
| **Normal Spectacles Frame** | Holds the components for a wearable experience |

---

## 🎯 **Project Architecture**  
1️⃣ **Speech Recognition (Python + Vosk ASR)**  
- Captures real-time speech using a **microphone**.  
- Converts audio to text using **Vosk ASR**.  

2️⃣ **Flask Web Server**  
- Receives transcribed text.  
- Stores and updates the latest recognized sentence.  
- Provides an API endpoint for ESP32 to fetch the latest text.  

3️⃣ **ESP32 & OLED Display**  
- Connects to **Flask server** via WiFi.  
- Fetches the latest text every few seconds.  
- Displays text on the **OLED screen** attached to the smart glasses.  

---

## 📌 **Setup & Installation**
Create a Virtual Environment & Install Dependencies
python -m venv venv
source venv/bin/activate  # (For macOS/Linux)
venv\Scripts\activate     # (For Windows)
pip install -r requirements.txt

Run Flask Server
python flask_server.py

Run Speech-to-Text Script
python speech_to_text.py

Speak into the microphone, and the recognized text will appear on the webpage and OLED display.
5️⃣ Upload ESP32 Code (Using Arduino IDE)
Open Arduino IDE
Install ESP32 Board & Libraries (WiFi.h, HTTPClient.h, Adafruit_GFX.h, Adafruit_SSD1306.h)
Replace WiFi credentials in the code (ssid and password).
Replace Flask server IP in the ESP32 code.
Upload the code to ESP32 and open the Serial Monitor

## 🖼️ Project Demo  
🔹 **Live Speech-to-Text Display**  
🔹 **Web Interface to View Transcription**  
🔹 **Wearable OLED Display Prototype**  

📽️ **Watch the Demo Video:** [Click Here](https://drive.google.com/drive/folders/187UFego2dzNVU2tK7lBGcyynZrYI2Zyi)

## ⚡ Future Enhancements  
🚀 **Multi-Language Support** – Extend support for regional languages like Hindi, Tamil, etc.  
🚀 **Gesture Control** – Implement ASL (American Sign Language) recognition.  
🚀 **Noise Cancellation** – Improve accuracy in noisy environments.  
🚀 **Longer Battery Life** – Optimize power consumption for extended use.  

---

## 🙌 Contributors  
💡 **Team ByteForce**  

- **Tharani**  
- **Rashmi**  
- **Vijeya Vaishika**  

---

## 🏆 Achievements  
🥇 **1st Place Winner – [Melini 2k25]**  
🎉 **Recognized as the best innovative assistive technology solution!**  

