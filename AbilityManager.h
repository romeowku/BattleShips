#ifndef ABILITY_MANAGER_H
#define ABILITY_MANAGER_H

#include "AbilityFabricFolder/DoubleDamageFactory.h"
#include "AbilityFabricFolder/ScannerFactory.h"
#include "AbilityFabricFolder/AbilityFactory.h"
#include "AbilityFabricFolder/RandomFireFactory.h"
#include "Holders/CoordHolder.h"
#include <iostream>
#include <random>
#include <queue>
#include <algorithm>

class GameField;
class AbilityFactory;

class AbilityManager
{
private:
    CoordHolder coordHolder;
    GameField& field;
    LogHolder& logHolder;
    std::queue<std::unique_ptr<AbilityFactory>> queueAbilities;
    std::vector<std::unique_ptr<AbilityFactory>> factories;

private:
    void initializeFactories();
    void fillQueue();

public:
    AbilityManager(GameField& field, LogHolder& logHolder);
    
    void addRandomAbility();
    void useAbility();

    nlohmann::json toJson();
    void fromJson (nlohmann::json& j);
};

#endif