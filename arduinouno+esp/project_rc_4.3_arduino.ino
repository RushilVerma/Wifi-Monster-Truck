 #include <SoftwareSerial.h>
SoftwareSerial wifi(2,3); //tx,rx of nodemcu

int MC1_M1_enb=11;
int MC1_M2_enb=10;
int MC2_M1_enb=9;
int MC2_M2_enb=6;
int MC1_M1_IN1=13;
int MC1_M1_IN2=12;
int MC1_M2_IN1=8;
int MC1_M2_IN2=7;
int MC2_M1_IN1=5;
int MC2_M1_IN2=4;
int MC2_M2_IN1=1;
int MC2_M2_IN2=0;
int command[3];

void setup()
{
  Serial.begin(9600);
  wifi.begin(115200);
  pinMode(MC1_M1_enb, OUTPUT); 
  pinMode(MC1_M2_enb, OUTPUT); 
  pinMode(MC2_M1_enb, OUTPUT); 
  pinMode(MC2_M2_enb, OUTPUT); 

  pinMode(MC1_M1_IN1, OUTPUT); 
  pinMode(MC1_M1_IN2, OUTPUT);
  pinMode(MC1_M2_IN1, OUTPUT);
  pinMode(MC1_M2_IN2, OUTPUT);
  pinMode(MC2_M1_IN1, OUTPUT); 
  pinMode(MC2_M1_IN2, OUTPUT);
  pinMode(MC2_M2_IN1, OUTPUT);
  pinMode(MC2_M2_IN2, OUTPUT);

 analogWrite(MC1_M1_enb, 0); 
 analogWrite(MC1_M2_enb, 0);
 analogWrite(MC2_M1_enb, 0); 
 analogWrite(MC2_M2_enb, 0);
Serial.println(wifi.readString());
}
void loop()
{
while (wifi.available()== 0);
String data = wifi.readString();
Serial.println(data);
command[0]=data.substring(0,1).toInt();
command[1]=data.substring(1,2).toInt();
command[2]=data.substring(2).toInt();

analogWrite(MC1_M1_enb,command[2]);
analogWrite(MC1_M2_enb,command[2]);
analogWrite(MC2_M1_enb,command[2]);
analogWrite(MC2_M2_enb,command[2]);

Serial.println(command[0]);
Serial.println(command[1]);
Serial.println(command[2]);

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
