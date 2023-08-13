#include "FirebaseWrapper.h"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

FirebaseWrapper::FirebaseWrapper(std::string user, std::string pass, std::string apiKey, std::string url)
    :user(user),
    pass(pass),
    apiKey(apiKey),
    url(url)
{
    FirebaseWrapper::status = CONNECTION_STATUS_IDLE;
    config.api_key = apiKey;
    config.database_url = url;
}

bool FirebaseWrapper::Connect()
{
    if(Firebase.signUp(&config,&auth, "", ""))
    {
        FirebaseWrapper::status = CONNECTION_STATUS_CONNECTED;
    }

    config.token_status_callback = tokenStatusCallback;
    Firebase.begin(&config,&auth);
    Firebase.reconnectWiFi(true);
}

bool FirebaseWrapper::Disconnect()
{

}

bool FirebaseWrapper::SendData(DATABASE_OBJECT_TYPE type, JsonDocument& data)
{
    String jsonString;
    serializeJson()
    serializeJson(data,&jsonString);
  
    switch(type)DATABASE_OBJECT_TYPE_DRINK
    {
        case DATABASE_OBJECT_TYPE_COCKTAIL:
        Firebase.RTDB.setJSON(&fbdo, COCKTAIL_URL,)
        break;

        case DATABASE_OBJECT_TYPE_DRINK:
        break;
    }
}

std::vector<JsonObject> FirebaseWrapper(DATABASE_OBJECT_TYPE type)
{

}

CONNECTION_STATUS FirebaseWrapper::GetConnection()
{
    return FirebaseWrapper::status;
}

FirebaseWrapper::~FirebaseWrapper()
{

}