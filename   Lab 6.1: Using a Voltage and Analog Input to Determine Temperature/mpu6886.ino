#include <M5Core2.h> // Include the M5Core2 library for display
#include <WiFi.h>    // Include the Wi-Fi library
#include <ThingSpeak.h> // Include the ThingSpeak library
 
#include "secrets.h" // Your Wi-Fi and ThingSpeak credentials
 
char ssid[] = SECRET_SSID;    // Your network SSID (name)
char pass[] = SECRET_PASS;    // Your network password
 
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
 
WiFiClient client;
 
long lastConnectionTime = 0;
const long postingInterval = 60 * 1000; // Post data every 60 seconds (1 minute)
 
int counter = 0; // A simple counter to demonstrate sending a number
 
void setup() {
  M5.begin(); // Initialize the M5Core2
  M5.Lcd.setTextFont(2); // Set text font size
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color to white on black background
  M5.Lcd.println("M5Core2 ThingSpeak Logger");
  M5.Lcd.println("Connecting to WiFi...");
 
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.begin(115200); // Start serial communication for debugging
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    M5.Lcd.print(".");
  }
 
  M5.Lcd.println("\nWiFi connected");
  M5.Lcd.print("IP address: ");
  M5.Lcd.println(WiFi.localIP());
 
  ThingSpeak.begin(client); // Initialize ThingSpeak
}
 
void loop() {
  // Check if it's time to send data to ThingSpeak
  if (millis() - lastConnectionTime > postingInterval) {
    // Increment the counter or read your sensor data here
    counter++;
 
    M5.Lcd.setCursor(0, 80); // Set cursor for updating display
    M5.Lcd.print("Sending value: ");
    M5.Lcd.println(counter);
 
    // Write to ThingSpeak. Set Field 1 (Wifi Strength for example)
    // You can add more fields if your channel has them
    int x = ThingSpeak.writeField(myChannelNumber, 1, counter, myWriteAPIKey);
 
    if (x == 200) {
      Serial.println("Channel update successful.");
      M5.Lcd.println("Update success!");
    }
    else {
      Serial.println("Problem updating channel. HTTP error code " + String(x));
      M5.Lcd.println("Update failed! Code: " + String(x));
    }
 
    lastConnectionTime = millis(); // Update the last connection time
  }
 
  M5.update(); // Important for M5Core2 button presses, etc. (even if not used here, good practice)
  delay(100); // Small delay to prevent busy-waiting
}