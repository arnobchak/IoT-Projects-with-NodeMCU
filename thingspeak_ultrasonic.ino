#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define TRIG_PIN D1
#define ECHO_PIN D2

const char* ssid = "MotorolaArnob";         // Your WiFi SSID
const char* password = "19421942";            // Your WiFi password
unsigned long myChannelNumber = 2731190;      // Replace with your Channel ID
const char* myWriteAPIKey = "24GT3IB7L3G64HW6"; // Replace with your Write API Key

WiFiClient client; // Create a WiFiClient object

void setup() {
  Serial.begin(9600);
  
  // Initialize the sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

 // Connect to WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  ThingSpeak.begin(client);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // Read the echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calculate the distance in cm
  float distance = duration * 0.034 / 2; // Speed of sound is ~34300 cm/s

 // Check for valid distance
  if (distance >= 0) {
    Serial.print("DISTANCE: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Update ThingSpeak
    ThingSpeak.setField(1, distance);
    
    int httpCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if (httpCode == 200) {
      Serial.println("Data sent successfully.");
    } else {
      Serial.println("Error sending data.");
    }
  } else {
    Serial.println("Failed to read from sensor!");
  }

  delay(20000); // Wait 20 seconds before the next update
}