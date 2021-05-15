#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

char auth[]="8001f6a39fca40ccb4b9088fc7dc5029";
char ssid[] = "rc_car_nodemcu";
char pass[] = "Nks1999";
void setup() {
  
Serial.begin(11500);
Blynk.begin(auth, ssid, pass);
}

void loop() {
Blynk.run();

}
