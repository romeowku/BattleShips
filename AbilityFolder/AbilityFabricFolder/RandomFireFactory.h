#ifndef RANDOM_FIRE_FACTORY_H
#define RANDOM_FIRE_FACTORY_H

#include "AbilityFactory.h"
#include "../AbilityFolder/RandomFire.h"
#include "../FieldCombined/GameField.h"

class RandomFireFactory : public AbilityFactory 
{
protected:
    GameField& field;

public:
    RandomFireFactory(GameField& field);
    std::unique_ptr<Ability> create() override;
    nlohmann::json toJson() override;
};

#endif