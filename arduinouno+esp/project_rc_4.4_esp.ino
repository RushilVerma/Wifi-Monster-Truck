#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);

const char* ssid = "my lot";
const char* password = "1234567890";

String data="";
void setup()
{
  Serial.begin(115200);
  server.begin();
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while (!(WiFi.status() == WL_CONNECTED))
  {
    delay(300);
    Serial.print("..");
  }
Serial.println (WiFi.localIP());
}
void loop()
{      
  client=server.available();
  if(!client)
      return; 
   data = checkClient ();
   Serial.println(data);
}
String checkClient(void)
{   
    while(!client.available()) delay(1); 
    String data = client.readStringUntil('\r');
    data.remove(0,19);
    return data;
    
}
