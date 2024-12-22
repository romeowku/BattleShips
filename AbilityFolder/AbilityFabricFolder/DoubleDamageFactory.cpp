#include "DoubleDamageFactory.h"

std::unique_ptr<Ability> DoubleDamageFactory::create() 
{
    std::cout << "Activated Double Damage\n";
    return std::make_unique<DoubleDamage>();
}

nlohmann::json DoubleDamageFactory::toJson() 
{
    return nlohmann::json {
        {"Ability", "DoubleDamage"}
    };
}