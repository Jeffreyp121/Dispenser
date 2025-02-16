#include "InterCoreCommunicator.h"

void InterCoreCommunicator::TriggerCallback(void* parameters)
{
    callback(parameters);
}

InterCoreCommunicator::InterCoreCommunicator(InterCoreCallback callback, INTERCORE_COMUNICATOR communicator)
{
    InterCoreCommunicator::callback = callback;
    InterCoreCommunicator::communicator = communicator;
}

InterCoreCommunicator::~InterCoreCommunicator()
{
    /* nothing to do yet */
}