#ifndef SHIP_MANAGER_H
#define SHIP_MANAGER_H

#include "Ship.h"
#include "../json.hpp"

class ShipManager 
{
private:
    int numShips;
    std::vector<Ship> ships;
    std::vector<int> shipSizes;

public:
    ShipManager(int numShips, const std::vector<int>& sizes);
    Ship& getShip(int index);
    int getNumShips() const;
    bool hasAliveShips() const;
    std::vector<int> getSizes();
    void reset();
    nlohmann::json toJson();
    void fromJson(nlohmann::json& j);
};

#endif
