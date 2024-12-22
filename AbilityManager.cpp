#include "AbilityManager.h"

AbilityManager::AbilityManager(GameField& field, LogHolder& logHolder) : field(field), logHolder(logHolder)
{
    initializeFactories();
    fillQueue();
}

void AbilityManager::initializeFactories() 
{
    factories.push_back(std::make_unique<DoubleDamageFactory>());
    factories.push_back(std::make_unique<RandomFireFactory>(field));
    factories.push_back(std::make_unique<ScannerFactory>(coordHolder, field));
}

void AbilityManager::fillQueue()
{
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(factories.begin(), factories.end(), rng);
    for (auto& factory : factories) 
    {
        queueAbilities.push(std::move(factory));
    }
}

void AbilityManager::addRandomAbility() 
{
    if (factories.empty()) {
        initializeFactories();
    }
    int randomIndex = rand() % factories.size();
    
    auto* factory = factories[randomIndex].get();
    if (dynamic_cast<DoubleDamageFactory*>(factory)) 
    {
        queueAbilities.push(std::make_unique<DoubleDamageFactory>());
    
    } else if (dynamic_cast<RandomFireFactory*>(factory)) {
        queueAbilities.push(std::make_unique<RandomFireFactory>(field));
    
    } else if (dynamic_cast<ScannerFactory*>(factory)) {
        queueAbilities.push(std::make_unique<ScannerFactory>(coordHolder, field));
    }
}

void AbilityManager::useAbility() 
{
    if (queueAbilities.empty()) 
    {
        throw AbilityException();
    }

    AbilityFactory* ability = queueAbilities.front().get();
    ability->create()->activate(logHolder);
    queueAbilities.pop();
}

nlohmann::json AbilityManager::toJson() 
{
    nlohmann::json abilities = nlohmann::json::array();
    
    std::queue<std::unique_ptr<AbilityFactory>> tempQueue;
    
    while (!queueAbilities.empty()) {
        abilities.push_back(queueAbilities.front()->toJson());
        tempQueue.push(std::move(queueAbilities.front()));
        queueAbilities.pop();
    }

    while (!tempQueue.empty()) {
        queueAbilities.push(std::move(tempQueue.front()));
        tempQueue.pop();    
    }

    return nlohmann::json {
        {"Abilities", abilities}
    };
}

void AbilityManager::fromJson(nlohmann::json& j) 
{
    while (!queueAbilities.empty()) {
        queueAbilities.pop();
    }
    factories.clear();
    
    auto abilities = j["Abilities"];

    for (const auto& item : abilities) 
    {
        std::string abilityType = item["Ability"];
        if (abilityType == "RandomFire") {
            queueAbilities.push(std::make_unique<RandomFireFactory>(field));
        } else if (abilityType == "DoubleDamage") {
            queueAbilities.push(std::make_unique<DoubleDamageFactory>());
        } else if (abilityType == "Scanner") {
            queueAbilities.push(std::make_unique<ScannerFactory>(coordHolder, field));
        }
    }
}