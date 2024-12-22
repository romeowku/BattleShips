#include "ShipManager.h"

ShipManager::ShipManager(int numShips, const std::vector<int>& sizes) : numShips(numShips), shipSizes(sizes) 
{
    for (int i = 0; i < numShips; i++) { ships.emplace_back(sizes[i], i); }
}

int ShipManager::getNumShips() const { return numShips; }

Ship& ShipManager::getShip(int index) 
{
    if (index < 0 || index >= numShips) 
    {
        throw std::out_of_range("There is no such ship index. (method getShip)");
    }
    return ships[index];
}

bool ShipManager::hasAliveShips() const 
{
    for (const auto& ship : ships) 
    {
        if (!ship.isDestroyed()) { return true; }
    }
    return false;
}

std::vector<int> ShipManager::getSizes()
{
    std::vector<int> sizes;
    for (int i = 0; i < numShips; i++) { sizes.emplace_back(ships[i].getLength()); }
    return sizes;
}

nlohmann::json ShipManager::toJson() 
{
    nlohmann::json sizes = nlohmann::json::array();

    for (int i = 0; i < numShips; i++) 
    {
        sizes.push_back(ships[i].getLength());
    }

    return nlohmann::json
    {
        {"nums", numShips},
        {"sizes", sizes}
    };
}

void ShipManager::fromJson(nlohmann::json& j) 
{
    numShips = j.at("nums").get<int>();
    std::vector<int> sizes = j.at("sizes").get<std::vector<int>>();
    ships.clear();

    for (int i = 0; i < numShips; i++) 
    {
        ships.emplace_back(Ship(sizes[i], i));
    }
}

void ShipManager::reset()
{
    ships.clear();
    for (int i = 0; i < numShips; i++) {
        ships.emplace_back(shipSizes[i], i);
    }
}