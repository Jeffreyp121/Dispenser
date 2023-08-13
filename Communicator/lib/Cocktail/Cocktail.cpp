#include "Cocktail.h"

Cocktail::Cocktail(std::string name)
    :name(name)
{
}

bool Cocktail::AddDrink(Drink drink)
{
    Cocktail::Drinks.push_back(drink);
}

bool Cocktail::DeleteDrink(Drink drink)
{
    int8_t index = -1;
    for(auto & element : Cocktail::Drinks)
    {
        if(element.GetName() == drink.GetName())
        {
            break;
        }
        index++;
    }
    
    if(index == (-1))
    {
        return false;
    }

    Cocktail::Drinks.erase(Cocktail::Drinks.begin() + index);
}

std::string Cocktail::GetName() const
{
    return Cocktail::name;
}
std::vector<Drink> Cocktail::GetDrinks() const
{
    return Cocktail::Drinks;
}

JsonDocument Cocktail::Serialize()
{

    doc["Name"] = Cocktail::name;
    JsonArray drinks;

    for(auto & elements: Cocktail::Drinks)
    {
        drinks.add(elements.Serialize());
    }
    doc.add(drinks);
    return doc.to<JsonObject>();
}

Cocktail::~Cocktail()
{

}