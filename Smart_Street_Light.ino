#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber = 1721577;                // Channel ID
const char * myCounterReadAPIKey = "8LI40ICUVFAQVB9M";      // Read API Key
const int fieldNumber = 1;                                 // The field you wish to read
const int ldrPin=A0;
const int lightPin=D1;         
int vehicle_passed=0;
boolean vehicle_gone=false;
void setup()
{
pinMode(ldrPin,INPUT);
pinMode(lightPin,OUTPUT);
  Serial.begin(9600);
  Serial.println();

  WiFi.begin("Gresi","@12345678");                 // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }


  ThingSpeak.begin(client);
}

void loop() 
{
  int rawData = analogRead(ldrPin);
Serial.println(rawData);
if(rawData < 250)
{ digitalWrite(lightPin,HIGH);
if(vehicle_gone==false)
{
  vehicle_passed=vehicle_passed+1;
  vehicle_gone=true;}
  
int A = ThingSpeak.writeField(counterChannelNumber,fieldNumber,vehicle_passed,myCounterReadAPIKey);
}
else
{
  digitalWrite(lightPin,LOW);
  vehicle_gone=false;}
delay(100);
}
