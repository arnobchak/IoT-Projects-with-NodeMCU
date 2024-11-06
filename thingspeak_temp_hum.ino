#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

#define DHTPIN D2     // Pin where the DHT sensor is connected
#define DHTTYPE DHT11 // Change to DHT22 if you're using a DHT22

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

const char* ssid = "MotorolaArnob";        // Your WiFi SSID
const char* password = "19421942"; // Your WiFi Password
unsigned long myChannelNumber = 2730233; // Replace with your Channel ID
const char* myWriteAPIKey = "DHZKTHQNUYXRTY7U"; // Replace with your Write API Key

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  ThingSpeak.begin(client);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

 Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C");
  Serial.print(" Humidity: ");
  Serial.print(h);
  Serial.println(" %");

  // Update ThingSpeak
  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  
  int httpCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (httpCode == 200) {
    Serial.println("Data sent successfully.");
  } else {
    Serial.println("Error sending data.");
  }

  delay(20000); // Wait 20 seconds before the next update
}