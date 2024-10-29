#include<DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11 
DHT dht(D4,DHTTYPE);   //class DHT   object dht 
void setup()
{
Serial.begin(9600);
dht.begin();
}
void loop() {
 // put your main code here, to run repeatedly:
int temp=dht.readTemperature();  //
int hum=dht.readHumidity();
Serial.print("temperature=");
Serial.print(temp);
Serial.println(" ");
Serial.print("humidity=");
Serial.print(hum);
delay(1000);
}