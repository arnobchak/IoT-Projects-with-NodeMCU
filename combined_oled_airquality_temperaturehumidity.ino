#include <Adafruit_SSD1306.h>
#include <splash.h>

#include<OakOLED.h> //OLED library
#include<DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(D4,DHTTYPE);
OakOLED oled;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
oled.begin();//we need to initialize the OLED object using the begin() function.
oled.clearDisplay();//clear all text
oled.setTextSize(2);//Sets the size of text that follows. The default size is “1”. Each change in size increases the text by 10 pixels in height.
oled.setTextColor(1);//set the text color
oled.setCursor(0,0); //set the coordinates to start writing text
//oled.println("Hello World"); //prints the message
//oled.display(); //calls this method to display character on the screen
}
void loop()
{
int temp=dht.readTemperature();  //
int hum=dht.readHumidity();
Serial.print("temperature=");
Serial.print(temp);
oled.print(temp);
oled.println(" temp");
Serial.println(" ");
Serial.print("humidity=");
Serial.print(hum);
oled.print(hum);
oled.println(" hum");
oled.display();
delay(1000);
}