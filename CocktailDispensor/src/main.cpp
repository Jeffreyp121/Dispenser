#include <Arduino.h>
#include <Cocktail.h>
#include <Soda.h>
#include <Liquor.h>
#include <TaskHelper.h>
#include <InterCoreHandler.h>
#include <Bootloader.h>
#include <WiFi.h>

Bootloader* bootloader;

static const char* ssid = "";
static const char* password = "";

void TestLoop1(void* parameters)
{
  //Serial.print("Task 1 running on core ");
  //Serial.println(xPortGetCoreID());
  vTaskDelay(pdMS_TO_TICKS(200));
}

void TestLoop2(void* parameters)
{
  //Serial.print("Task 2 running on core ");
  //Serial.println(xPortGetCoreID());
  vTaskDelay(pdMS_TO_TICKS(200));
}

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
  vTaskDelay(pdMS_TO_TICKS(1000));
}


