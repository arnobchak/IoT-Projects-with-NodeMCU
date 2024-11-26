#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "MotorolaArnob";           // Your WiFi SSID
const char* password = "19421942";            // Your WiFi password
const char* mqtt_server = "192.168.131.171"; // MQTT broker (example)
const char* topic = "ultrasonic/distance";    // MQTT topic for distance data

WiFiClient espClient;
PubSubClient client(espClient);

const int trigPin = D2;                       // Ultrasonic sensor Trigger pin
const int echoPin = D1;                       // Ultrasonic sensor Echo pin

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calculate the distance in cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  String message = String(distance);
  client.publish(topic, message.c_str());

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

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
