#include <Arduino.h>
#include "WifiWrapper.h"

IConnectable*  wifiWrapper = nullptr;
unsigned long prevTime = 0;
unsigned long interval = 100;

void setup() {
  Serial.begin(115200);
  wifiWrapper = new WifiWrapper("inputssd", "inputPass");
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
    Serial.println(wifiWrapper->GetIPAddr().c_str());
  }
}

