#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

const char* ssid = "my lot";
const char* password = "1234567890";
int command[3];
String data="";
void setup()
{
  Serial.begin(9600);
WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
  }
Serial.print((WiFi.localIP()));
server.begin();
}
void loop()
{

    if (!server.available()){
      return; 
      Serial.println("server connected");
    }
    while(!client.available()){
      delay(1); 
      Serial.println("client connected");
    }
//Serial.println("enter the command");
while (Serial.available()== 0)
    data = client.readStringUntil('\r');
data.remove(0,19);
Serial.println(data);
}
