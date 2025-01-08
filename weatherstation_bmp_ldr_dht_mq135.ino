#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>

#define DHTPIN D3       // DHT11 data pin
#define DHTTYPE DHT11   // Define the DHT sensor type

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP280 bmp;    // Create a BMP280 object

void setup() {
  Serial.begin(115200);

  // Initialize sensors
  dht.begin();
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor!");
    while (1); // Stop execution if BMP280 is not found
  }

  Serial.println("Sensors initialized. Reading data...");
}

void loop() {
  // Read data from sensors
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float pressure = bmp.readPressure() / 100.0; // Convert to hPa
  float gas = analogRead(A0); // MQ135
  int ldrValue = analogRead(A0); // LDR

  // Print sensor values to Serial Monitor
  Serial.println("====================================");
  Serial.print("Temperature (DHT11): "); Serial.print(temperature); Serial.println(" *C");
  Serial.print("Humidity (DHT11): "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Pressure (BMP280): "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("Gas Level (MQ135): "); Serial.println(gas);
  Serial.print("LDR Value: "); Serial.println(ldrValue);
  Serial.println("====================================");

  delay(2000); // Wait for 2 seconds before reading again
}
