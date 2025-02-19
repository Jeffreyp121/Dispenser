#include <Arduino.h>
#include <Cocktail.h>
#include <Soda.h>
#include <Liquor.h>
#include <Bootloader.h>
#include <WiFi.h>

Bootloader* bootloader;

static const char* ssid = "";
static const char* password = "";

void setup() 
{
  IPAddress local_IP(192, 168, 178, 184);
  // Set your Gateway IP address
  IPAddress gateway(192, 168, 178, 1);
  
  IPAddress subnet(255, 255, 0, 0);
  IPAddress primaryDNS(8, 8, 8, 8);   //optional
  IPAddress secondaryDNS(8, 8, 4, 4); //optional

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) 
  {
    Serial.println("STA Failed to configure");
  }
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
  bootloader = new Bootloader();
}

void loop() 
{
  bootloader->UpdateFirmware();
}