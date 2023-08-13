#ifndef _IDATABASE_H
#define _IDATABASE_H

#include <string>
#include <stdint.h>
#include <ArduinoJson.h>
#include <vector>

#include "ConnectionStatus.h"
#include "DataBaseTypes.h"

class IDataBase
{
public:
    virtual bool Connect() = 0;
    virtual bool Disconnect() = 0;
    virtual bool SendData(DATABASE_OBJECT_TYPE type, JsonObject&  data) =0;
    virtual std::vector<JsonObject> ReadData(DATABASE_OBJECT_TYPE type) =0;
    virtual CONNECTION_STATUS GetConnection() = 0;
    virtual ~IDataBase(){};
};

#endif