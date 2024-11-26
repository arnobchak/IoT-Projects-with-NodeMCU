#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN D2
const char* ssid     = "MotorolaArnob";   //replace with your own SSID
const char* password = "19421942";    //replace with your own password
const char* mqtt_server ="192.168.131.171"; //broker.hivemq.com(MQTT Broker)
DHT dht(DHTPIN, DHT11);

WiFiClient espClient;   //ESP object
PubSubClient client(espClient);    //ESP (MQTT client)
long lastMsg = 0;
int temp,humi;
//int value = 0;1

void setup() {
  //pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  dht.begin();
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266ClientNodeMCU")) //Client ID MQTT
     {
      Serial.println("connected");
      // Once connected, publish an announcement...
    } else {
      Serial.print("failed to connect");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();   // stay connected with the server
  humi = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("temp=");
  Serial.print(temp);
  Serial.println("hum=");
  Serial.print(humi);
  if (isnan(temp) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;
  }
  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    Serial.print("Publish message: ");
    Serial.println(temp);
    client.publish("tempNode",String(temp).c_str()); //topic,varaible
    delay(100);
    Serial.print("Publish message: ");
    Serial.println(humi);
    client.publish("humiNode",String(humi).c_str());
    delay(100);
  }
delay(1000);
}