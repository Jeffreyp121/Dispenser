#include "Drink.h"

static  const size_t CAPACITY = JSON_OBJECT_SIZE(sizeof(Drink));
static  StaticJsonDocument<CAPACITY> doc;

Drink::Drink(std::string name, uint16_t amountML)
    :name(name),
    milliliters(amountML)
{}

void Drink::Increase(uint16_t amountMl)
{
    Drink::milliliters += amountMl;
}

void Drink::Decrease(uint16_t amountMl)
{
    Drink::milliliters -= amountMl;
} 

std::string Drink::GetName() const
{
    return Drink::name;
}

Drink::~Drink()
{
}

std::string Drink::Serialize()
{
    JsonObject object = doc.to<JsonObject>();
    object["Name"] = Drink::name.c_str();
    object["ML"] = Drink::milliliters;  
    std::string jsonString;
    serializeJson(doc, jsonString);
    return jsonString;
}

Drink Drink::Deserialize(std::string jsonString)
{
    
    deserializeJson(doc,jsonString);
    JsonObject json = doc.to<JsonObject>();

    return Drink(json["Name"],  json["ML"]);
}