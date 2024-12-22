#ifndef DOUBLE_DAMAGE_FACTORY_H
#define DOUBLE_DAMAGE_FACTORY_H

#include "AbilityFactory.h"
#include "../AbilityFolder/DoubleDamage.h"

class DoubleDamageFactory : public AbilityFactory 
{
public:
    std::unique_ptr<Ability> create() override;
    nlohmann::json toJson() override;
};

#endif