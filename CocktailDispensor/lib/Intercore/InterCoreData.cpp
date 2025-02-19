#include "InterCoredata.h"

InterCoreData::InterCoreData(void* data, uint16_t size, INTERCORE_COMUNICATOR communicator)
{
    if(NULL == data)
    {
        return;
    }

    InterCoreData::data = data;
    InterCoreData::communicator = communicator;
}

InterCoreData::~InterCoreData()
{

}