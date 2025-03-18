#include <WiFi.h>

const char* ssid = "aadharsh";      // Replace with your Wi-Fi SSID
const char* password = "aadharsh";  // Replace with your Wi-Fi Password

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi Connected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing needed in the loop
}
