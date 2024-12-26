#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <OakOLED.h> // OLED library

#define DHTPIN D4
#define DHTTYPE DHT11
#define LED_PIN D0
#define AQI_THRESHOLD 101
#define TEMP_RISE_THRESHOLD 5 // Temperature rise in degrees Celsius

const int mq135Pin = A0;
DHT dht(D4, DHTTYPE);
OakOLED oled;

int previousTemp = 0; // Variable to store the previous temperature reading

void setup() {
  Serial.begin(9600);

  // Initialize OLED
  oled.begin();
  oled.clearDisplay();
  oled.setTextSize(2);
  oled.setTextColor(1);
  oled.setCursor(0, 0);

  // Initialize DHT sensor
  dht.begin();

  // Initialize LED pin as output
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int sensorValue = analogRead(mq135Pin);  // Read the air quality sensor value
  int temp = dht.readTemperature();       // Read temperature from DHT sensor
  int hum = dht.readHumidity();           // Read humidity from DHT sensor

  // Display sensor data on Serial Monitor
  Serial.print("MQ-135 Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(hum);

  // Display sensor data on OLED
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.print(temp);
  oled.println(" Temp");
  oled.print(hum);
  oled.println(" Hum");
  oled.print(sensorValue);
  oled.println(" AQI");
  oled.display();

  // Check conditions for LED blinking
  if (sensorValue > AQI_THRESHOLD || (temp - previousTemp) > TEMP_RISE_THRESHOLD) {
    blinkLED();
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off the LED if conditions are not met
  }

  // Update previous temperature
  previousTemp = temp;

  delay(1000);
}

void blinkLED() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
delay(500);
}