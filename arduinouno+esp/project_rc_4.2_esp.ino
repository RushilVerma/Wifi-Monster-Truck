
#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
const char* ssid = "my lot";
const char* password = "1234567890";
String  data =""; 

/* define L298N or L293D motor control pins */
int leftMotorForward = 2;     /* GPIO2(D4) -> IN3   */
int rightMotorForward = 15;   /* GPIO15(D8) -> IN1  */
int leftMotorBackward = 0;    /* GPIO0(D3) -> IN4   */
int rightMotorBackward = 13;  /* GPIO13(D7) -> IN2  */


/* define L298N or L293D enable pins */
int rightMotorENB = 14; /* GPIO14(D5) -> Motor-A Enable */
int leftMotorENB = 12;  /* GPIO12(D6) -> Motor-B Enable */

void setup()
{
  Serial.begin(115200);
  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT); 
  pinMode(leftMotorBackward, OUTPUT);  
  pinMode(rightMotorBackward, OUTPUT);
  pinMode(leftMotorENB, OUTPUT); 
  pinMode(rightMotorENB, OUTPUT);
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
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
