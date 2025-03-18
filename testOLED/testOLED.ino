#include <WiFi.h>

const char* ssid = "aadharsh";
const char* password = "aadharsh";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  int timeout = 20;  // 20 attempts (10 seconds)
  while (WiFi.status() != WL_CONNECTED && timeout > 0) {
    delay(500);
    Serial.print(".");
    timeout--;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFailed to Connect. Restarting...");
    ESP.restart();
  }
}

void loop() {
}
