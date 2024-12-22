#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "../ShipCombined/ShipManager.h"
#include "Cell.h"
#include "../Exceptions.h"
#include "../Holders/LogHolder.h"

class GameField 
{
    
private:
    int width, height;
    std::vector<std::vector<Cell>> field;
    ShipManager& shipManager;
    bool destroyed = false;
    bool isPlaceValid(int length, int x, int y, Ship::Orientation orientation);
public:

    GameField(int width, int height, ShipManager& shipManager);
    GameField(const GameField &other);
    GameField(GameField &&other) noexcept;
    GameField &operator=(const GameField &other);
    GameField &operator=(GameField &&other) noexcept;

    nlohmann::json toJson();
    void fromJson (nlohmann::json& j);

    void updateField();
    ShipManager& getShipManager();
    bool hasShipsAlive() const;
    Cell& getCell(int x, int y);
    int getWidth();
    int getHeight();
    std::vector<std::vector<Cell>>& getField();
    void placeShip(Ship* ship, int x, int y, Ship::Orientation orientation);
    bool attackCell(int x, int y, LogHolder* logHolder = nullptr);
    void printShip();
};

#endif

