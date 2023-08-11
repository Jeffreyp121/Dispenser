#ifndef _ICONNECTABLE_H_
#define _ICONNECTABLE_H

#include "ConnectionStatus.h"
#include <string>
#include <stdint.h>

class IConnectable
{    
    public:
        virtual bool Connect() = 0;
        virtual bool Disconnect() = 0;
        virtual bool GetData(uint8_t* dataBuffer, std::string address) = 0;
        virtual bool SendData(uint8_t* dataBuffer, std::string address) = 0;
        virtual CONNECTION_STATUS GetStatus() = 0;
        virtual std::string GetIPAddr() = 0;
        virtual ~IConnectable(){}
};

#endif  /* END ICONNECTABLE */