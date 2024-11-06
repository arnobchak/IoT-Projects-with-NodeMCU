IoT Projects with NodeMCU ESP8266 Arduino Board
This repository contains multiple IoT projects using the NodeMCU ESP8266 board to read data from various sensors and publish it to an MQTT broker for monitoring or control. The setup includes sensors for light (LDR), distance (Ultrasonic), temperature and humidity (DHT22/11), OLED display, LED control, air quality monitoring, push buttons, and motion detection. Additionally, we integrate ThingSpeak as a visualization platform for real-time data tracking.

Project Overview
Each project involves connecting a specific sensor to the NodeMCU ESP8266, reading sensor data, and then publishing it to an MQTT broker. Using ThingSpeak, you can visualize and analyze sensor data trends over time, accessible from anywhere with internet access.

Table of Contents
Requirements
Hardware Components
Setup
Project Details
Light Sensor (LDR)
Ultrasonic Sensor (HC-SR04)
Temperature and Humidity Sensor (DHT22/11)
OLED Display (128x64 I2C)
LED Control (3 LED Lights)
Air Quality Sensor (MQ135)
Push Buttons
MPU6050 Accelerometer and Gyroscope
MQTT Setup
ThingSpeak Integration
License
Requirements
Arduino IDE (configured with the ESP8266 board)
MQTT Broker (e.g., HiveMQ, Mosquitto, or any other broker)
ThingSpeak account (for cloud-based data visualization)
Libraries:
ESP8266WiFi.h
PubSubClient.h
DHT.h (for temperature and humidity)
Adafruit_SSD1306.h and Adafruit_GFX.h (for OLED display)
Wire.h and Adafruit_MPU6050.h (for MPU6050)
Hardware Components
NodeMCU ESP8266 board
LDR (Light Dependent Resistor) sensor
HC-SR04 Ultrasonic sensor
DHT22/11 Temperature and Humidity sensor
128x64 I2C OLED Display
3 LED lights (for visual indicators)
MQ135 Air Quality sensor
2 Push Buttons
MPU6050 Accelerometer and Gyroscope sensor
Setup
Connect each sensor to the NodeMCU ESP8266 according to the pin configurations below.
Install necessary libraries in the Arduino IDE.
Configure WiFi, MQTT, and ThingSpeak settings in the Arduino sketches provided.
Upload the sketches to the NodeMCU and monitor the data published to the MQTT topics or ThingSpeak.
Pin Configurations
LDR: Connect to analog pin A0.
Ultrasonic Sensor: Trigger pin to D5, Echo pin to D6.
DHT22/11: Data pin to D4.
OLED Display: SDA to D2, SCL to D1.
LED Lights: Connect each LED to a digital pin (e.g., D7, D8, D9).
Air Quality Sensor (MQ135): Analog pin A0 (if using LDR and MQ135 together, add an analog multiplexer).
Push Buttons: Connect to digital pins (e.g., D10 and D11).
MPU6050: SDA to D2, SCL to D1 (I2C bus, shared with OLED if applicable).
Project Details
Light Sensor (LDR)
The Light Dependent Resistor (LDR) measures ambient light and publishes the value to the MQTT topic /ldr/value every 2 seconds. Data can also be sent to ThingSpeak for real-time and historical analysis.

Ultrasonic Sensor (HC-SR04)
The HC-SR04 Ultrasonic Sensor measures distance and publishes data to the MQTT topic /ultrasonic/distance, as well as to ThingSpeak.

Temperature and Humidity Sensor (DHT22/11)
The DHT22/11 sensor reads temperature and humidity, publishing values to MQTT topics /temperature/value and /humidity/value. ThingSpeak channels can also be configured to monitor both parameters.

OLED Display (128x64 I2C)
The OLED Display shows sensor readings locally. It can display multiple sensor readings by updating the code to read and print values from each sensor.

LED Control (3 LED Lights)
Three LED lights can be used as status indicators and controlled via MQTT topics to signal conditions, such as sensor thresholds or warnings.

Air Quality Sensor (MQ135)
The MQ135 Air Quality Sensor measures air quality (e.g., CO2 levels) and publishes the reading to the MQTT topic /airquality/value. ThingSpeak can be used to visualize trends in air quality over time.

Push Buttons
Two push buttons can be configured to send commands or control actions over MQTT, such as toggling LEDs, activating alerts, or triggering specific events.

MPU6050 Accelerometer and Gyroscope
The MPU6050 sensor measures acceleration and angular velocity, useful for detecting motion or orientation. The readings can be published to MQTT topics like /mpu6050/accel and /mpu6050/gyro, with additional ThingSpeak channels for motion analysis.

MQTT Setup
Choose an MQTT broker, such as HiveMQ or Mosquitto. Update the MQTT broker address in each sketch.
Define MQTT topics for each sensor as outlined in the project details.
Monitor sensor data in real-time using an MQTT client or create a dashboard using platforms like Node-RED or Home Assistant.
ThingSpeak Integration
Create a ThingSpeak account and set up channels for each sensor you plan to monitor.
Add fields in each channel for specific sensor data (e.g., temperature, humidity, light, air quality).
In each Arduino sketch, configure ThingSpeak settings:
Include the WiFiClient library and configure the API key for each ThingSpeak channel.
Use ThingSpeak’s writeField or writeMultipleFields functions to send sensor data.
Visualize data by creating widgets and charts on the ThingSpeak dashboard.
License
This project is open-source and free to use under the MIT License. Contributions and improvements are welcome!

Happy IoT Experimenting! If you have any questions or run into issues, feel free to open an issue on GitHub.
