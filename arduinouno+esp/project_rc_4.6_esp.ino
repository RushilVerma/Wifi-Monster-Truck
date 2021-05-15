#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

const char* ssid = "my lot";
const char* password = "1234567890";

String  data =""; 

void setup()
{
  Serial.begin(115200);
  server.begin();
}

void loop()
{  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
    Serial.println(data);
} 

String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  
    Serial.println(request);
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
