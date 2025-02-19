#ifndef _SYSTEM_INTERCOREHANDLER_H_
#define _SYSTEM_INTERCOREHANDLER_H_

#include <Macro.h>
#include <TaskHelper.h>
#include <TaskConfiguration.h>
#include "InterCoreCommunicator.h"
#include "InterCoredata.h"
#include <vector>

typedef enum
{
    INTERCORE_TRANSMIT,
    INTERCORE_RECEIVE
}INTERCORE_DIRECTION;

class InterCoreHandler
{
    private:
        TaskHelper* proxy;
        TaskHelper* delegate;
        QueueHandle_t* proxyQueue;
        QueueHandle_t* delegateQueue;
        std::vector<InterCoreCommunicator*> transmitters;
        std::vector<InterCoreCommunicator*> receivers;
        TASK_CORE coreId;
        
    public:
        InterCoreHandler(TASK_CORE coreId, QueueHandle_t* proxyQueue, QueueHandle_t* delegateQueue);
        bool SendToCore(InterCoreData data, INTERCORE_DIRECTION direction);
        bool SubscribeToInterCore(INTERCORE_DIRECTION direction, InterCoreCommunicator* communicator);
        static void ProxyHandler(void* parameter);
        static void DelegateHandler(void* parameter);
        ~InterCoreHandler();
};

#endif /* _SYSTEM_INTERCOREHANDLER_H_ */