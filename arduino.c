

1 of 11
codes
Inbox
x

yamiki kousalya <yamikikousalya@gmail.com>
Attachments
7:54 PM (58 minutes ago)
to me


Attachments area

yamiki kousalya <yamikikousalya@gmail.com>
Attachments
8:19 PM (33 minutes ago)
to me

   
Translate message
Turn off for: Malay


On Wed, Jul 17, 2019 at 7:54 PM yamiki kousalya <yamikikousalya@gmail.com> wrote:


2 Attachments

#include<SoftwareSerial.h>
#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>   
LiquidCrystal lcd(7,6,5,4,3,2); 
SoftwareSerial s(8,9);
int sensorValue = 0;        // value read from the pot
int outputValue = 0;   
const int PulseWire = 0; 
const int analogOutPin = A1;
const int LED13 = 13;     
int Threshold = 550;
PulseSensorPlayground pulseSensor;  
void setup() {   
Serial.begin(9600);
s.begin(9600);
lcd.begin(16,2); 
lcd.setCursor(0, 0);
lcd.println("Heart beat checker");
delay(2000);
pulseSensor.analogInput(PulseWire);   
pulseSensor.blinkOnPulse(LED13);    
pulseSensor.setThreshold(Threshold);    
if (pulseSensor.begin()) {
Serial.println("We created a pulseSensor Object !"); 
}
}
void loop() {
int myBPM = pulseSensor.getBeatsPerMinute();
if (pulseSensor.sawStartOfBeat()) {            
Serial.println("?  A HeartBeat Happened ! "); 
Serial.print("BPM: ");                        
Serial.println(myBPM);
lcd.clear();  
lcd.setCursor(0, 0);
lcd.println("   Pulse Rate   "); 
lcd.setCursor(0, 1);
lcd.print("Beat Per Min:");                       
lcd.print(myBPM);
 s.write(myBPM);
  delay(1000);
delay(100);
}
}
[3/1, 13:23] Likitha: #include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SPI.h>
#include <Wire.h>
const char* ssid = "INDIAN";
const char* password = "asdfghjkl";
#define FIREBASE_HOST "wireless-biomedical.firebaseio.com"
#define FIREBASE_AUTH "j5f1jHtBrzZZRuug0IjRql2SQIR4RZuL1sgOZhno"
float outputValue = 0;  
WiFiServer server(80);
int data;
void setup(){
  Serial.begin(9600); 
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
}
server.begin();
Serial.println("WiFi connected");
Serial.println("Server started");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop(){
 data = Serial.read();
 Serial.println(data);
 if(data>0){
Firebase.setFloat("Heartbeat", data);  
 }

delay(100);
}