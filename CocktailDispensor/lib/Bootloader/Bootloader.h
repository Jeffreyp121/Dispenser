#ifndef _BOOTLOADER_BOOTLOADER_H_
#define _BOOTLOADER_BOOTLOADER_H_

#include <ArduinoOTA.h>
#include "TaskHelper.h"

class Bootloader
{
    private:
        TaskHelper* task;

    public:
        Bootloader();
        ~Bootloader();
};

#endif /* _BOOTLOADER_BOOTLOADER_H_ */
