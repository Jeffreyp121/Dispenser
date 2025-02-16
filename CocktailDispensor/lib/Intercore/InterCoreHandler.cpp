#include "InterCoreHandler.h"

static void ProxyHandler(void* parameter);
static void DelegateHandler(void* parameter);

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

InterCoreHandler::InterCoreHandler(QueueHandle_t* txQueue, QueueHandle_t* rxQueue)
{
    InterCoreHandler::rxQueue = rxQueue;
    InterCoreHandler::txQueue = txQueue;

    delegate = new TaskHelper("Delegate", DelegateHandler, 1000, 
                               NULL, xPortGetCoreID(), TASKHELPER_PRIO_HIGH);
    bool success = (NULL != delegate);

    if(true == success)
    {
        proxy = new TaskHelper("Proxy", ProxyHandler, 1000, 
                                NULL, xPortGetCoreID(), TASKHELPER_PRIO_HIGH);
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

static void ProxyHandler(void* parameter)
{
    while(true)
    {
 
    }
}

static void DelegateHandler(void* parameter)
{

}