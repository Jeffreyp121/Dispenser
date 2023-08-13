#ifndef _COCKTAIL_H
#define _COCKTAIL_H

#include <vector>
#include <string>

#include "Drink.h"

class Cocktail
{
    private:
        std::vector<Drink> Drinks;
        std::string name;
        uint16_t totalMl;
        static Cocktail Deserialize(std::string jsonString);
    public:
        Cocktail(std::string name);
        bool AddDrink(Drink drink);
        bool DeleteDrink(Drink drink);
        std::string GetName() const;
        std::vector<Drink> GetDrinks() const;
        std::string Serialize();
        ~Cocktail();
};

#endif

