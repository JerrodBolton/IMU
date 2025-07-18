#include <ArduinoJson.h>
#include <IOXhop_FirebaseESP32.h>
#include <IOXhop_FirebaseStream.h>
#include <WiFi.h>
#include <M5Core2.h>
#include "secret.h"

String fireStatus = "";

void setup() {
  Serial.begin(9600);
  M5.begin();
  // connect to wifi.
  WiFi.begin(SECRET_SSID, SECRET_PASS);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("LED_STATUS", "OFF");
}
void loop() {
  // 1. Read the database
  String fireStatus = Firebase.getString("LED_STATUS");
  fireStatus.trim();
  fireStatus.toUpperCase();

  // 2. Act on it
  if (fireStatus == "OFF") {
    // This is a  going to print words on the srceen 
    M5.Lcd.fillScreen(WHITE);
  } else if (fireStatus == "ON") {
    // This is a  going to print words on the srceen 
    M5.Lcd.fillScreen(YELLOW);
  } else {
    Serial.print("Unexpected value: ");
    Serial.println(fireStatus);
  }

  // 3. Don’t hammer Firebase
  delay(300);   // 0.3 s pause
}
