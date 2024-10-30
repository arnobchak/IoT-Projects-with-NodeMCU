#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <MPU6050.h>

const char* ssid = "MotorolaArnob";            // Your WiFi SSID
const char* password = "19421942";             // Your WiFi password
const char* mqtt_server = "broker.hivemq.com"; // MQTT broker (example)
const char* topic = "gyroscope/data";          // MQTT topic for gyroscope data

WiFiClient espClient;
PubSubClient client(espClient);
MPU6050 mpu;

void setup() {
  Serial.begin(115200);

  // Initialize I2C communication for MPU6050
  Wire.begin();
  mpu.initialize();
  
  // Check if MPU6050 is connected
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected successfully.");
  } else {
    Serial.println("MPU6050 connection failed!");
  }

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read gyroscope data
  int16_t gx, gy, gz;
  mpu.getRotation(&gx, &gy, &gz);

  // Create message string with gyro values
  String message = "Pitch: " + String(gx) + " Roll: " + String(gy) + " Yaw: " + String(gz);
  client.publish(topic, message.c_str());

  Serial.print("Gyroscope Data -> ");
  Serial.println(message);
  
  delay(2000); // Publish every 2 seconds
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("NodeMCUClient")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
