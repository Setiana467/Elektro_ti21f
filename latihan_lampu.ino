/*************************************************************

  This sketch shows how to read values from Virtual Pins

  App project setup:
    Slider widget (0...100) on Virtual Pin V1
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLbxLtxS2c"
#define BLYNK_DEVICE_NAME "led on off"
#define BLYNK_AUTH_TOKEN "4Z7ueeL4cqhDMbTFaemAVpFJe6MnEMfV"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "asdf";
char pass[] = "12345678";


// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
  digitalWrite(D4,param.asInt());

}
BLYNK_WRITE(V1)
{
  digitalWrite(D1,param.asInt());

}

void setup()
{
  pinMode(D4,OUTPUT);
  pinMode(D1,OUTPUT);
  
  // Debug console
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}
