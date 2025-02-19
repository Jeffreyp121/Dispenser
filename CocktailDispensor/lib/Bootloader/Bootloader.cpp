#include "Bootloader.h"
#include "Arduino.h"

static void UpdateFirmware(void * parameters);

Bootloader::Bootloader()
{   
    task = new TaskHelper(c_taskConfigs[TASK_BOOTLOADER].name,
                          UpdateFirmware,
                          c_taskConfigs[TASK_BOOTLOADER].stackSize,
                          NULL,
                          TASK_CORE_SLAVE,
                          c_taskConfigs[TASK_BOOTLOADER].priority);
    
    if(NULL != task)
    {
        ArduinoOTA.begin();
    }
}

Bootloader::~Bootloader()
{
    if(NULL != task)
    {
        delete(task);
    }
    task = NULL;
}

static void UpdateFirmware(void* parameters)
{
   while(true)
   {
        ArduinoOTA.handle();
        vTaskDelay(pdMS_TO_TICKS(100));
   }
}