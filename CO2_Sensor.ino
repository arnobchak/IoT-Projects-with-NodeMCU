#include <Wire.h>
#include <SensirionI2CScd4x.h>

// Create an instance of the SCD4X sensor
SensirionI2CScd4x scd4x;

void setup() {
  // Initialize Serial for debugging
  Serial.begin(9600);
  while (!Serial) {
    // Wait for the Serial Monitor to open
  }

  // Initialize I2C communication
  Wire.begin(D2, D1); // SDA = D2, SCL = D1 for NodeMCU ESP8266

  // Initialize the SCD4X sensor
  scd4x.begin(Wire);
  Serial.println("Initializing SCD4X Sensor...");

  if (scd4x.startPeriodicMeasurement() != 0) {
    Serial.println("Error: Could not start periodic measurements. Check wiring.");
    while (1); // Stop execution if initialization fails
  }

  Serial.println("SCD4X Sensor initialized successfully!");
}

void loop() {
  // Wait for measurement to complete (SCD4X default is every 5 seconds)
  delay(5000);

  // Variables to store sensor readings
  uint16_t co2;
  float temperature;
  float humidity;

  // Read measurements from the sensor
  if (scd4x.readMeasurement(co2, temperature, humidity) != 0) {
    Serial.println("Error: Failed to read data from the sensor.");
    return;
  }

  if (co2 == 0) {
    Serial.println("Invalid reading. Sensor might be stabilizing...");
    return;
  }

  // Print measurements to Serial Monitor
  Serial.print("CO2: ");
  Serial.print(co2);
  Serial.print(" ppm, ");

  Serial.print("Temperature: ");
  Serial.print(temperature, 2);
  Serial.print(" °C, ");

  Serial.print("Humidity: ");
  Serial.print(humidity, 2);
  Serial.println(" %RH");
}
