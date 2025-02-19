#include "InterCoreHandler.h"

bool InterCoreHandler::SendToCore(InterCoreData data, INTERCORE_DIRECTION direction)
{
    bool success = false;

    if(direction == INTERCORE_TRANSMIT)
    {
        success = (pdTRUE == xQueueSend(*proxyQueue, &data, 100U));
    }
    else
    {
        success = (pdTRUE == xQueueSend(*delegateQueue, &data, 100U));
    }

    return success;
}

bool InterCoreHandler::SubscribeToInterCore(INTERCORE_DIRECTION direction, InterCoreCommunicator* communicator)
{
    bool success = (NULL != communicator);

    if(true == success)
    {
        switch (direction)
        {
            case INTERCORE_TRANSMIT:
                InterCoreHandler::transmitters.push_back(communicator);
                break;

            case INTERCORE_RECEIVE:
                InterCoreHandler::receivers.push_back(communicator);
                break;
    
            default:
                success = false;
                break;
        }
    }

    return success;

}

InterCoreHandler::InterCoreHandler(TASK_CORE coreId, QueueHandle_t* proxyQueue, QueueHandle_t* delegateQueue)
{
    if(NULL == proxyQueue || NULL == delegateQueue)
    {
        return;
    }

    InterCoreHandler::coreId = coreId;
    InterCoreHandler::proxyQueue = proxyQueue;
    InterCoreHandler::delegateQueue = delegateQueue;

    delegate = new TaskHelper(c_taskConfigs[TASK_INTERCORE_DELEGATE].name, 
                              DelegateHandler,
                              c_taskConfigs[TASK_INTERCORE_DELEGATE].stackSize,
                              NULL,
                              coreId, c_taskConfigs[TASK_INTERCORE_DELEGATE].priority);
    bool success = (NULL != delegate);

    if(true == success)
    {
        proxy = new TaskHelper(c_taskConfigs[TASK_INTERCORE_PROXY].name, 
                                ProxyHandler,
                                c_taskConfigs[TASK_INTERCORE_PROXY].stackSize,
                                NULL,
                                coreId, c_taskConfigs[TASK_INTERCORE_PROXY].priority);
        success = (NULL != proxy);
    }

    /* TODO: add logging */
}

InterCoreHandler::~InterCoreHandler()
{
    free(InterCoreHandler::delegate);
    delegate = NULL;

    free(InterCoreHandler::proxy);
    proxy = NULL;
}

void InterCoreHandler::ProxyHandler(void* parameter)
{
    InterCoreData* receivedValue; 
    while(true)
    {
        if (xQueueReceive(*InterCoreHandler::delegateQueue, receivedValue, portMAX_DELAY) == pdTRUE) {
            Serial.printf("Core 1: Received %d from Core 0\n", *reinterpret_cast<uint8_t*>(receivedValue->data));
        }
    }
}

void InterCoreHandler::DelegateHandler(void* parameter)
{

}