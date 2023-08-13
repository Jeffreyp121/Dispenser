#ifndef _FIREBASEWRAPPER_H
#define _FIREBASEWRAPPER_H

#include "IDataBase.h"
#include <string>
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

#define COCKTAIL_URL "Cocktails/"
#define DRINK_URL    "Drinks/"

class FirebaseWrapper: public IDataBase
{
    private:
        std::string user;
        std::string pass; 
        std::string apiKey;
        std::string url;
        CONNECTION_STATUS status;
    public:
        FirebaseWrapper(std::string user, std::string pass, std::string apiKey, std::string url);
        bool Connect();
        bool Disconnect();
        bool SendData(DATABASE_OBJECT_TYPE type, JsonObject&  data);
        std::vector<JsonObject> ReadData(DATABASE_OBJECT_TYPE type);
        CONNECTION_STATUS GetConnection();
        ~FirebaseWrapper();
};

#endif