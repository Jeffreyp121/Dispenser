#include <Arduino.h>
#include "WifiWrapper.h"
#include "GPIO_Pin.h"

IConnectable*  wifiWrapper = nullptr;
GPIO_Pin* led;

unsigned long prevTime = 0;
unsigned long interval = 100;

void setup() {
  Serial.begin(115200);

   try
  {
    led = new GPIO_Pin(2,PIN_MODE_OUTPUT);
  }catch(std::invalid_argument& e)
  {
    Serial.println(e.what());
  }
  wifiWrapper = new WifiWrapper("Thuis1", "Leesbril123");
 

  prevTime = millis();
}

void loop() {
  if(wifiWrapper->GetStatus() != CONNECTION_STATUS_CONNECTED)
  {
    if((millis() - prevTime))
    {
      wifiWrapper->Connect();
      prevTime = millis(); 
    }
  }
  else
  {
    //Serial.println(wifiWrapper->GetIPAddr().c_str());
    led->SetPinStatus(ON);
  }
}

