#ifndef _SYSTEM_INTERCORECOMMUNICATOR_H_
#define _SYSTEM_INTERCORECOMMUNICATOR_H_

#include <Macro.h>


typedef enum
{
    INTERCORE_FIREBASE,         /* Firebase intercore communication */
}INTERCORE_COMUNICATOR;

class InterCoreCommunicator
{
    private:
        InterCoreCallback callback;
        INTERCORE_COMUNICATOR communicator;
    public:
        void TriggerCallback(void* parameters);
        InterCoreCommunicator(InterCoreCallback callback, INTERCORE_COMUNICATOR communicator);
        ~InterCoreCommunicator();
};

#endif /* _SYSTEM_INTERCORECOMMUNICATOR_H_ */