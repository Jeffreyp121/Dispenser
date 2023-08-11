#ifndef _WIFI_WRAPPER_H_
#define _WIFI_WRAPPER_H_

#include "IConnectable.h"

#include <stdint.h>
#include <string>


class WifiWrapper : public IConnectable
{
    public:
        WifiWrapper(std::string ssid, std::string passWord);
        bool Connect();
        bool Disconnect();
        bool GetData(uint8_t* dataBuffer, std::string address);
        bool SendData(uint8_t* dataBuffer, std::string address);
        CONNECTION_STATUS GetStatus();
        std::string GetIPAddr();
        ~WifiWrapper();

    private:
        CONNECTION_STATUS status;
        std::string ssid;
        std::string pass;

    /* data */
};



#endif  /* END Wifi */