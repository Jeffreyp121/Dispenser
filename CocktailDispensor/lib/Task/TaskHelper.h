#ifndef _SYSTEM_TASKHELPER_H_
#define _SYSTEM_TASKHELPER_H_

#include <Macro.h>
#include <Arduino.h>

typedef enum
{
   TASKHELPER_PRIO_HIGH     = configMAX_PRIORITIES - 5,
   TASKHELPER_PRIO_MEDIUM   = configMAX_PRIORITIES - (2 * 5),
   TASKHELPER_PRIO_LOW      = configMAX_PRIORITIES - ( 3 * 5),
}TASKHELPER_PRIORITY;

class TaskHelper
{
    private:
        std::string taskName;
        TaskCallback callback;
        uint32_t stackSize;
        void* parameters;
        TaskHandle_t handle;
        BaseType_t coreId;
        TASKHELPER_PRIORITY priority;
    public:
        TaskHelper(std::string name, TaskCallback callback, uint32_t stackSize,
                  void* parameters, BaseType_t coreId, TASKHELPER_PRIORITY priority);
        ~TaskHelper();
};

#endif /* _SYSTEM_TASKHELPER_H_ */