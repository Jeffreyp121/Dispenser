#ifndef _SYSTEM_INTERCOREHANDLER_H_
#define _SYSTEM_INTERCOREHANDLER_H_

#include <Macro.h>
#include <TaskHelper.h>
#include "InterCoreCommunicator.h"
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
        QueueHandle_t* txQueue;
        QueueHandle_t* rxQueue;
        std::vector<InterCoreCommunicator*> transmitters;
        std::vector<InterCoreCommunicator*> receivers;
        
    public:
        InterCoreHandler(QueueHandle_t* txQueue, QueueHandle_t* rxQueue);
        bool SubscribeToInterCore(INTERCORE_DIRECTION direction, InterCoreCommunicator* communicator);
        ~InterCoreHandler();
};

#endif /* _SYSTEM_INTERCOREHANDLER_H_ */