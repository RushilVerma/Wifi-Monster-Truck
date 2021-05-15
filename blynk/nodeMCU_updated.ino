#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>
 
int pinValue1;
int pinValue2;
int pinValue3;
int pinValue4;
int pinValue5;
int pinValue6;
 
String v2arduino; // values to arduino
 
char auth[] = "3875b24ac2a64289be4190aa1995d3a2";
//char auth[] = "9071754c22504677be807fc9dd146ea5";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "vivo Y21L";
char pass[] = "123456789";
 
SimpleTimer timer;
 
String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received characters
 
 
int firstVal, secondVal,thirdVal,fourthVal,fifthVal,sixthVal; // sensors 
// This function sends Arduino's up time every second to Virtual Pin (1).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
  
}
 
 
 
void setup()
{
  // Debug console
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 /*
     timer.setInterval(1000L,sensorvalue1); 
     timer.setInterval(1000L,sensorvalue2); 
     timer.setInterval(1000L,sensorvalue3);
     timer.setInterval(1000L,sensorvalue4); 
     timer.setInterval(1000L,sensorvalue5); 
     timer.setInterval(1000L,sensorvalue6);
     */
}
 
void loop()
{
 
  
  
   if (Serial.available() == 0 ) 
   {
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  toarduino();
  Serial.println();
   }
   
  if (Serial.available() > 0 ) 
  {
    rdata = Serial.read(); 
    myString = myString+ rdata; 
   // Serial.print(rdata);
    if( rdata == '\n')
    {
 
// new code
String l = getValue(myString, ',', 0);
String m = getValue(myString, ',', 1);
String n = getValue(myString, ',', 2);
String o = getValue(myString, ',', 3);
String p = getValue(myString, ',', 4);
String q = getValue(myString, ',', 5); 
 
 
firstVal = l.toInt();
secondVal = m.toInt();
thirdVal = n.toInt();
fourthVal = o.toInt();
fifthVal = p.toInt();
sixthVal = q.toInt();
 
  myString = "";
// end new code
    }
  }
 
}
/* 
void sensorvalue1()
{
int sdata = firstVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V10, sdata);
 
}
void sensorvalue2()
{
int sdata = secondVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V11, sdata);
 
}
 
void sensorvalue3()
{
int sdata = thirdVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V12, sdata);
 
}
void sensorvalue4()
{
int sdata = firstVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V13, sdata);
 
}
void sensorvalue5()
{
int sdata = secondVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V14, sdata);
 
}
 
void sensorvalue6()
{
int sdata = thirdVal;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V15, sdata);
 
}
*/ 
 
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
 
// in Blynk app writes values to the Virtual Pin V10
BLYNK_WRITE(V10)
{
   pinValue1 = param.asInt(); // assigning incoming value from pin V10 to a variable
 
 
}
 
 
// in Blynk app writes values to the Virtual Pin V11
BLYNK_WRITE(V11)
{
   pinValue2 = param.asInt(); // assigning incoming value from pin V10 to a variable
 
}
 
// in Blynk app writes values to the Virtual Pin V12, this is for the slider
BLYNK_WRITE(V12)
{
   pinValue3 = param.asInt(); // assigning incoming value from pin V10 to a variable
 
}
BLYNK_WRITE(V13)
{
   pinValue4 = param.asInt(); // assigning incoming value from pin V10 to a variable
 
 
}
 
 
// in Blynk app writes values to the Virtual Pin V14
BLYNK_WRITE(V14)
{
   pinValue5 = param.asInt(); // assigning incoming value from pin V10 to a variable
 
}
 
// in Blynk app writes values to the Virtual Pin V15, this is for the slider
BLYNK_WRITE(V15)
{
   pinValue6 = param.asInt(); // assigning incoming value from pin V10 to a variable
 
}
 
void toarduino()
{
v2arduino = v2arduino + pinValue1 + "," + pinValue2 + "," + pinValue3+","+ pinValue4 + "," + pinValue5 + "," + pinValue6; 
Serial.println(v2arduino); 
delay(100); 
v2arduino = ""; 
}
