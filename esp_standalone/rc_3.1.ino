#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
const char* ssid = "my lot";
const char* password = "1234567890";
String  data =""; 

int enb=15;
int MC1_M1_IN1=2;
int MC1_M1_IN2=14;
int MC1_M2_IN1=12;
int MC1_M2_IN2=13;
int MC2_M1_IN1=16;
int MC2_M1_IN2=5;
int MC2_M2_IN1=4;
int MC2_M2_IN2=0;
int command[3];
void setup()
{
  Serial.begin(115200);
  pinMode(enb, OUTPUT); 

  pinMode(MC1_M1_IN1, OUTPUT); 
  pinMode(MC1_M1_IN2, OUTPUT);
  pinMode(MC1_M2_IN1, OUTPUT);
  pinMode(MC1_M2_IN2, OUTPUT);
  pinMode(MC2_M1_IN1, OUTPUT); 
  pinMode(MC2_M1_IN2, OUTPUT);
  pinMode(MC2_M2_IN1, OUTPUT);
  pinMode(MC2_M2_IN2, OUTPUT);

 analogWrite(enb, 0); 
  server.begin();
  IPAddress IP = WiFi.softAPIP();
  Serial.println("I AM WORKING");
  Serial.println(IP);
  
}

void loop()
{  
    client = server.available();
    if (!client) return; 
    data = checkClient ();
    Serial.println(data);
    command[0]=data.substring(0,1).toInt();
    command[1]=data.substring(1,2).toInt();
    command[2]=data.substring(2).toInt();

    analogWrite(enb,command[2]);

switch(command[0])
{
case 0:
if (command[1] == 4)
{
  Serial.println("4 forward");
//front tyres
                digitalWrite(MC1_M1_IN1,HIGH);
                digitalWrite(MC1_M1_IN2, LOW); 
                digitalWrite(MC1_M2_IN1,HIGH); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
                digitalWrite(MC2_M1_IN1,HIGH);
                digitalWrite(MC2_M1_IN2, LOW); 
                digitalWrite(MC2_M2_IN1,HIGH); 
                digitalWrite(MC2_M2_IN2,LOW);
}
else if (command[1] == 2)
{
    Serial.println("2 forward");
//front tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2, LOW); 
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
                digitalWrite(MC2_M1_IN1,HIGH);
                digitalWrite(MC2_M1_IN2, LOW); 
                digitalWrite(MC2_M2_IN1,HIGH); 
                digitalWrite(MC2_M2_IN2,LOW);
}
break;
case 1:
  Serial.println("forward right");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,HIGH);
                digitalWrite(MC1_M1_IN2, LOW); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,HIGH);
                digitalWrite(MC2_M1_IN2, LOW);
//Right tyres 
                digitalWrite(MC2_M2_IN1,HIGH); 
                digitalWrite(MC2_M2_IN2,LOW);
break;
case 2:
  Serial.println("right");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,HIGH);
                digitalWrite(MC1_M1_IN2, LOW); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,HIGH);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,HIGH);
                digitalWrite(MC2_M1_IN2, LOW);
//Right tyres 
                digitalWrite(MC2_M2_IN1,LOW); 
                digitalWrite(MC2_M2_IN2,HIGH);
break;
case 3:
  Serial.println("backward right");
//front tyres
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2,HIGH); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,HIGH);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,LOW);
                digitalWrite(MC2_M1_IN2,HIGH);
//Right tyres 
                digitalWrite(MC2_M2_IN1,LOW); 
                digitalWrite(MC2_M2_IN2,LOW);
break;
case 4:

if (command[1] == 4)
{
    Serial.println("4 backward");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2,HIGH); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,HIGH);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,LOW);
                digitalWrite(MC2_M1_IN2,HIGH);
//Right tyres 
                digitalWrite(MC2_M2_IN1,LOW); 
                digitalWrite(MC2_M2_IN2,HIGH);
}
if (command[1] == 2)
{
    Serial.println("2 backward");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2,LOW); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,LOW);
                digitalWrite(MC2_M1_IN2,HIGH);
//Right tyres 
                digitalWrite(MC2_M2_IN1,LOW); 
                digitalWrite(MC2_M2_IN2,HIGH);
}
break;
case 5:
  Serial.println("backward left");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2,HIGH); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,HIGH);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,LOW);
                digitalWrite(MC2_M1_IN2,LOW);
//Right tyres 
                digitalWrite(MC2_M2_IN1,LOW); 
                digitalWrite(MC2_M2_IN2,HIGH);
break;
case 6:
  Serial.println("left");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2,HIGH); 
//Right tyres
                digitalWrite(MC1_M2_IN1,HIGH); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,LOW);
                digitalWrite(MC2_M1_IN2,HIGH);
//Right tyres 
                digitalWrite(MC2_M2_IN1,HIGH); 
                digitalWrite(MC2_M2_IN2,LOW);
break;
case 7:
  Serial.println("forward left");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2, LOW); 
//Right tyres
                digitalWrite(MC1_M2_IN1,HIGH); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,HIGH);
                digitalWrite(MC2_M1_IN2, LOW);
//Right tyres 
                digitalWrite(MC2_M2_IN1,HIGH); 
                digitalWrite(MC2_M2_IN2,LOW);
break;
case 8:
  Serial.println("FULL STOPP");
//front tyres
//Left tyres
                digitalWrite(MC1_M1_IN1,LOW);
                digitalWrite(MC1_M1_IN2, LOW); 
//Right tyres
                digitalWrite(MC1_M2_IN1,LOW); 
                digitalWrite(MC1_M2_IN2,LOW);
//back tyres
//Left tyres
                digitalWrite(MC2_M1_IN1,LOW);
                digitalWrite(MC2_M1_IN2, LOW);
//Right tyres 
                digitalWrite(MC2_M2_IN1,LOW); 
                digitalWrite(MC2_M2_IN2,LOW);
break;
}
} 

String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}
