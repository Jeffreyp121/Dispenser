#ifndef _BOOTLOADER_BOOTLOADER_H_
#define _BOOTLOADER_BOOTLOADER_H_

#include <ArduinoOTA.h>

class Bootloader
{
    private:


    public:
        void UpdateFirmware();
        Bootloader();
        ~Bootloader();
};

#endif /* _BOOTLOADER_BOOTLOADER_H_ */
