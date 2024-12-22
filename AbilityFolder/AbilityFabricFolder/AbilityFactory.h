#ifndef ABILITY_FACTORY_H
#define ABILITY_FACTORY_H

#include <memory>
#include "../AbilityFolder/Ability.h"
#include "../Holders/InfoHolder.h"
#include "../json.hpp"

class GameField;
class LogHolder;

class AbilityFactory 
{
protected:
    InfoHolder infoHolder;

public:
    virtual ~AbilityFactory() = default;
    virtual std::unique_ptr<Ability> create() = 0;
    virtual nlohmann::json toJson () = 0;
};

#endif