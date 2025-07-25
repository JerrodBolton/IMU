#include <M5Core2.h>

// Analog input pin for sensor
const int sensorPin = 35;

// Variables for current readings
float adcValue = 0.0;
float voltage = 0.0;

// Variables to store max recorded values
float maxAdcValue = 0.0;
float maxVoltage = 0.0;

// Thermistor constants for Steinhart-Hart equation
const float R0 = 10000.0; // Known resistor value (10k Ohm)
const float c1 = 2.378405444e-04;
const float c2 = 2.019202697e-07;
const float c3 = 1.019452229e-07;

void setup() {
  M5.begin();                          // Initialize M5Stack Core2
  Serial.begin(9600);                 // Start serial communication
  pinMode(sensorPin, INPUT);         // Set pin for analog input

  M5.Lcd.fillScreen(BLACK);           // Clear the screen
  M5.Lcd.setTextSize(2);              // Set text size
  M5.Lcd.setTextColor(RED);          // Set text color
}

void loop() {
  // Read and convert analog value to voltage
  adcValue = analogRead(sensorPin);
  voltage = (adcValue / 4095.0) * 3.3;

  // Update max values if current ones are greater
  if (adcValue > maxAdcValue) maxAdcValue = adcValue;
  if (voltage > maxVoltage) maxVoltage = voltage;

  // Calculate resistance from voltage
  float resistance = R0 * ((4095.0 / adcValue) - 1.0);

  // Calculate temperature using Steinhart-Hart equation
  float logR = log(resistance);
  float tempKelvin = 1.0 / (c1 + c2 * logR + c3 * pow(logR, 3));
  float tempCelsius = tempKelvin - 273.15;
  float tempFahrenheit = tempCelsius * 1.8 + 32.0;

  // Clear display before printing new values
  M5.Lcd.fillScreen(WHITE);

  // Display ADC and voltage data
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.printf("ADC Value: %.0f", adcValue);

  M5.Lcd.setCursor(0, 30);
  M5.Lcd.printf("Vol: %.2f V", voltage);

  M5.Lcd.setCursor(0, 50);
  M5.Lcd.printf("Max Volt: %.2f V", maxVoltage);

  M5.Lcd.setCursor(0, 70);
  M5.Lcd.printf("MaxADC: %.0f", maxAdcValue);

  // Display temperature
  M5.Lcd.setCursor(0, 90);
  M5.Lcd.printf("Temperature: %.2f C", tempCelsius);

  M5.Lcd.setCursor(0, 110);
  M5.Lcd.printf("Temperature: %.2f F", tempFahrenheit);

  delay(20000);  // Short delay before next update
}