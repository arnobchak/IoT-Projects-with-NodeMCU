#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// Create an instance of the BMP280 sensor
Adafruit_BMP280 bmp;

// I2C pins for NodeMCU ESP8266
#define SDA_PIN D2  // Connect to SDA on BMP280
#define SCL_PIN D1  // Connect to SCL on BMP280

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  Serial.println(F("BMP280 Sensor Initialization"));

  // Initialize I2C communication
  Wire.begin(SDA_PIN, SCL_PIN);

  // Check if the BMP280 sensor is connected
  if (!bmp.begin(0x76)) { // 0x76 is the default I2C address for BMP280
    Serial.println(F("Could not find a valid BMP280 sensor, check connections!"));
    while (1); // Stay here if initialization fails
  }

  // Configure the sensor
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,   // Normal mode
                  Adafruit_BMP280::SAMPLING_X2,   // Temperature oversampling x2
                  Adafruit_BMP280::SAMPLING_X16,  // Pressure oversampling x16
                  Adafruit_BMP280::FILTER_X16,    // Filtering x16
                  Adafruit_BMP280::STANDBY_MS_500 // Standby time 500ms
                 );

  Serial.println(F("BMP280 sensor initialized successfully!"));
}

void loop() {
  // Read temperature and pressure
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure(); // Pressure in Pascals
  float altitude = bmp.readAltitude(1013.25); // Approx. sea level pressure in hPa

  // Print the readings
  Serial.print(F("Temperature: "));
  Serial.print(temperature);
  Serial.println(F(" °C"));

  Serial.print(F("Pressure: "));
  Serial.print(pressure / 100.0); // Convert Pascals to hPa
  Serial.println(F(" hPa"));

  Serial.print(F("Altitude: "));
  Serial.print(altitude);
  Serial.println(F(" meters"));

  Serial.println(F("-------------------------------"));

  // Wait 2 seconds before the next reading
  delay(2000);
}
