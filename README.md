NodeMCU ESP8266 IoT Projects with MQTT, ThingSpeak, and Node-RED
This repository provides a collection of IoT projects using the NodeMCU ESP8266 board to interface with various sensors. It demonstrates how to read sensor data, publish it to an MQTT broker, visualize it on ThingSpeak, and control it through Node-RED. This setup enables real-time monitoring, remote control, and customized automation.

Project Overview with Node-RED Integration
Each project demonstrates connecting a sensor to the NodeMCU ESP8266, reading its data, and publishing it to an MQTT broker. With Node-RED, you can create interactive dashboards to monitor data and control devices, enhancing the monitoring and automation capabilities beyond basic MQTT and ThingSpeak.

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
Node-RED Setup
ThingSpeak Integration
License
Requirements
Arduino IDE (configured for the ESP8266 board)
MQTT Broker (e.g., HiveMQ, Mosquitto)
ThingSpeak account (for cloud-based data visualization)
Node-RED (for interactive dashboards and automation)
Required Libraries
ESP8266WiFi.h
PubSubClient.h
DHT.h (for temperature and humidity sensors)
Adafruit_SSD1306.h and Adafruit_GFX.h (for OLED display)
Wire.h and Adafruit_MPU6050.h (for MPU6050 sensor)
Hardware Components
NodeMCU ESP8266 board
Various sensors (LDR, HC-SR04, DHT22/11, MQ135, MPU6050)
OLED Display (128x64 I2C)
LEDs (3 lights for visual indicators)
Push Buttons
Setup
Connect each sensor to the NodeMCU ESP8266 using the pin configurations provided.
Install required libraries in the Arduino IDE.
Configure WiFi, MQTT, and ThingSpeak settings in each Arduino sketch as specified.
Upload the sketches to the NodeMCU and monitor data through MQTT, Node-RED, or ThingSpeak.
Node-RED Setup
Step 1: Install Node-RED
Install Node-RED on your computer, Raspberry Pi, or server by following the Node-RED installation guide.
Start Node-RED by running:
bash
Copy code
node-red
Access the Node-RED editor at http://localhost:1880.
Step 2: Add Required Nodes
Open the Node-RED editor, go to Manage Palette.
Install these nodes:
node-red-dashboard (for UI elements)
node-red-contrib-mqtt-broker (if using an embedded MQTT broker)
Step 3: Create a Flow for Sensor Data
Use MQTT input nodes for each sensor topic (e.g., /ldr/value, /temperature/value) to receive data.
Add UI elements such as gauges, charts, or text nodes to display data.
Link MQTT output nodes for control actions (e.g., toggling LEDs) via topics like /led/control.
Step 4: Set Up Automation
Define custom rules in Node-RED:

Use switch nodes for condition-based actions (e.g., turning on LEDs if the light level is low).
Trigger notifications when air quality is below a threshold.
Example Flow:

plaintext
Copy code
MQTT Input Node (/ldr/value) --> Switch Node (Threshold) --> LED Control (via MQTT Output)
Optional: Send Data to ThingSpeak via Node-RED
You can also push data to ThingSpeak from Node-RED:

Use HTTP request nodes to call the ThingSpeak API.
Configure periodic updates or trigger updates based on conditions.
Example Node-RED Dashboard Setup
An example dashboard could include:

A gauge for light levels from the LDR.
A chart to track temperature and humidity over time.
Controls for LEDs and alerts based on sensor thresholds.
Project Details
Light Sensor (LDR)
The LDR measures ambient light and publishes the value to the MQTT topic /ldr/value every 2 seconds. Data is also sent to ThingSpeak for real-time and historical analysis.

Ultrasonic Sensor (HC-SR04)
The HC-SR04 measures distance and publishes data to /ultrasonic/distance, as well as to ThingSpeak.

Temperature and Humidity Sensor (DHT22/11)
The DHT22/11 publishes temperature and humidity data to MQTT topics /temperature/value and /humidity/value, and ThingSpeak can monitor these parameters as well.

OLED Display (128x64 I2C)
The OLED Display locally shows sensor readings. Code can be adjusted to display multiple sensor values.

LED Control (3 LED Lights)
The LEDs act as visual indicators and can be controlled via MQTT topics for conditions like thresholds or warnings.

Air Quality Sensor (MQ135)
The MQ135 measures air quality, such as CO2 levels, and publishes to /airquality/value. ThingSpeak can track trends in air quality over time.

Push Buttons
Two push buttons can be configured to control actions over MQTT, such as toggling LEDs, triggering alerts, or initiating events.

MPU6050 Accelerometer and Gyroscope
The MPU6050 provides acceleration and angular velocity data, publishing to /mpu6050/accel and /mpu6050/gyro. ThingSpeak channels can be set up for motion analysis.

MQTT Setup
Select an MQTT broker, such as HiveMQ or Mosquitto, and update the broker address in each sketch.
Define MQTT topics for each sensor as per project details.
Use an MQTT client or create a dashboard with Node-RED or Home Assistant to monitor data in real-time.
ThingSpeak Integration
Create a ThingSpeak account and channels for each sensor.
Set up fields in each channel for specific sensor data (e.g., temperature, humidity, light, air quality).
In each Arduino sketch, configure ThingSpeak settings:
Include the WiFiClient library and set up the API key for each ThingSpeak channel.
Use ThingSpeak’s writeField or writeMultipleFields functions to send sensor data.
Visualize data by creating widgets and charts on the ThingSpeak dashboard.
License
This project is open-source under the MIT License. Contributions and improvements are welcome!
