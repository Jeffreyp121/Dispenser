#include "TaskHelper.h"

TaskHelper::TaskHelper(std::string name, TaskCallback callback, uint32_t stackSize,
                       void* parameters, BaseType_t coreId, TASKHELPER_PRIORITY priority)
{
    TaskHelper::taskName = name;
    TaskHelper::callback = callback;
    TaskHelper::stackSize = stackSize;
    TaskHelper::parameters = parameters;
    TaskHelper::coreId = coreId;
    TaskHelper::priority = priority;
    
    if(pdPASS != xTaskCreatePinnedToCore(callback, name.c_str(), stackSize,
                                         parameters, priority, &handle, coreId))
    {
        /* TODO: log error*/
    }
}


TaskHelper::~TaskHelper()
{
    vTaskDelete(TaskHelper::handle);
}