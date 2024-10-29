#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3iyMqOU3q"
#define BLYNK_TEMPLATE_NAME "Temperature and Humidity"
#define BLYNK_AUTH_TOKEN "8qeecRJdYg3joI6fihVTFOmyhPYx7e-g"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Your WiFi credentials
//Set password to "" for open networks.
char ssid[] = "MotorolaArnob";
char pass[] = "19421942";

// DHT sensor settings
#define DHTPIN D4          // Pin where the DHT sensor is connected
#define DHTTYPE DHT11      // DHT11 or DHT22

DHT dht(DHTPIN, DHTTYPE);  // Create the DHT object

void setup() {
  // Debug console
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() 
  {
  Blynk.run();
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Blynk.virtualWrite(V0, humidity);
  Blynk.virtualWrite(V1, temperature);

  delay(3000); // Update every 3 seconds
}
