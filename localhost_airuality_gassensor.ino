#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "MotorolaArnob";         // Your WiFi SSID
const char* password = "19421942"; // Your WiFi password
const char* mqtt_server = "192.168.131.171"; // MQTT broker (example)
const char* topic = "gas/value";

const int MQ135_PIN = A0;  // MQ-135 connected to A0 pin

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  pinMode(MQ135_PIN, INPUT);

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

  int sensorValue = analogRead(MQ135_PIN);  // Read analog value
  String message = String(sensorValue);
  client.publish(topic, message.c_str());
  Serial.print("Air Quality Value: ");
  Serial.println(sensorValue);              // Print value
  delay(5000); // Publish every 2 seconds
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("NodeMCUClient")) {
      Serial.println("connected");
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}