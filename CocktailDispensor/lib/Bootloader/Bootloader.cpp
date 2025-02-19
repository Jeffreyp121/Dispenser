#include "Bootloader.h"
#include "Arduino.h"

void Bootloader::UpdateFirmware()
{
    ArduinoOTA.handle();
}

Bootloader::Bootloader()
{   
    ArduinoOTA.begin();
}

Bootloader::~Bootloader()
{

}