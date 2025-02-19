#ifndef _INTERCORE_INTERCOREDATA_H
#define _INTERCORE_INTERCOREDATA_H

#include "Macro.h"
#include "InterCoreCommunicator.h"

class InterCoreData
{
    private:

    public:
        INTERCORE_COMUNICATOR communicator;
        void* data;
        uint16_t size;
        InterCoreData(void* data, uint16_t size, INTERCORE_COMUNICATOR communicator);
        ~InterCoreData();
};


#endif
