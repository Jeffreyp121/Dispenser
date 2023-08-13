#include "WifiWrapper.h"
#include <WiFi.h>

#include <Arduino.h>

WifiWrapper::WifiWrapper(std::string ssid, std::string passWord)
{
    //todo: add arguments check
    WifiWrapper::ssid = ssid;
    WifiWrapper::pass = passWord;
    WifiWrapper::status = CONNECTION_STATUS_IDLE;
}

bool WifiWrapper::Connect()
{
    static uint8_t wifiIndex = 0;
    bool result = false; 
    uint8_t networks = 0;
    
    switch(WifiWrapper::status)
    {
        case CONNECTION_STATUS_IDLE:
        WifiWrapper::status = CONNECTION_STATUS_SEARCHING;
        break;

        case CONNECTION_STATUS_SEARCHING:
        networks = WiFi.scanNetworks();
        for(uint8_t i = 0; i < networks; i++)
        {
            if(strcmp(ssid.c_str(), WiFi.SSID(i).c_str()) == 0)
            {
               WifiWrapper::status = CONNECTION_STATUS_CHECK_SIGNAL;
               wifiIndex = i;
            }
        }
        break;

        case CONNECTION_STATUS_CHECK_SIGNAL:
        if(WiFi.RSSI(wifiIndex)  > (-80))
        {
            WiFi.begin(WifiWrapper::ssid.c_str(), WifiWrapper::pass.c_str());
            WifiWrapper::status = CONNECTION_STATUS_CONNECTING;
        }
        break;

        case CONNECTION_STATUS_CONNECTING:
        if(WiFi.status() == WL_CONNECTED)
        {
            WifiWrapper::status = CONNECTION_STATUS_CONNECTED;
            
        }
        break;

        case CONNECTION_STATUS_CONNECTED:
        result = true;
       
        break;

        default:
        break;
        
    }
   
   return result;
}

bool WifiWrapper::Disconnect()
{
   return WiFi.disconnect();
}

bool WifiWrapper::GetData(uint8_t* dataBuffer, std::string address)
{
    return true;
}

bool WifiWrapper::SendData(uint8_t* dataBuffer, std::string address)
{
    return true;
}

CONNECTION_STATUS WifiWrapper::GetStatus()
{
    return WifiWrapper::status;
}

std::string WifiWrapper::GetIPAddr()
{
    return std::string(WiFi.localIP().toString().c_str());
}

WifiWrapper::~WifiWrapper()
{
    if(WifiWrapper::status == CONNECTION_STATUS_CONNECTED)
    {
        WifiWrapper::Disconnect();
    }
}