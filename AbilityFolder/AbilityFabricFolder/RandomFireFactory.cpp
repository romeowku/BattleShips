#include "RandomFireFactory.h"

RandomFireFactory::RandomFireFactory(GameField& field) : field(field)
{}

std::unique_ptr<Ability> RandomFireFactory::create() 
{
    std::cout << "Random fire activated\n"; 
    return std::make_unique<RandomFire>(field);
}

nlohmann::json RandomFireFactory::toJson() 
{
    return nlohmann::json { 
        {"Ability", "RandomFire"} 
    };
}
