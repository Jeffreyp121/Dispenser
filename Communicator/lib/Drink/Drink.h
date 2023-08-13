#ifndef _DRINK_H
#define _DRINK_H

#include <stdint.h>
#include <string>
#include <ArduinoJson.h>

class Drink
{
private:
    std::string name;
    uint16_t milliliters;
    static Drink Deserialize(std::string jsonString);
public:
    Drink(std::string name, uint16_t amountML);
    std::string GetName() const;
    void Increase(uint16_t amountMl);
    void Decrease(uint16_t amountMl);    
    ~Drink();

    std::string Serialize();
};


#endif