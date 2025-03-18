#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WiFi Credentials
const char* ssid = "aadharsh";  
const char* password = "aadharsh";  
const char* serverUrl = "http://192.168.83.101:5000/data";  

// OLED Display Settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    Serial.begin(115200);
    
    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
        Serial.println("SSD1306 allocation failed");
        while (1); // Halt execution
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);  // Shift text to start from the top
    display.print("Connecting to WiFi...");
    display.display();

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi!");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("WiFi Connected!");
    display.display();
    delay(2000);
}

void loop() {
    if (WiFi.status() == WL_CONNECTED) {  // Check WiFi connection
        HTTPClient http;
        http.begin(serverUrl);  // Connect to Flask server
        int httpResponseCode = http.GET();  // Send GET request

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Received: " + response);  // Print received data
            
            // Display response on OLED with an upward shift
            display.clearDisplay();
            display.setTextSize(2);  // Increase text size
            display.setCursor(0, -16);  // 🔹 Shift text 2 lines upwards
            display.println(response);
            display.display();
        } else {
            Serial.println("Error in HTTP request");
            
            // Display error on OLED
            display.clearDisplay();
            display.setTextSize(1);
            display.setCursor(10, 20);
            display.println("HTTP Error");
            display.display();
        }

        http.end();  // Close connection
    } else {
        Serial.println("WiFi not connected!");
        
        // Display WiFi error on OLED
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(10, 20);
        display.println("WiFi Not Connected!");
        display.display();
    }

    delay(1000);  // Fetch data every 1 second
}
