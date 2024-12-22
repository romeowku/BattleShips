#ifndef CELL_H
#define CELL_H

#include "../ShipCombined/Ship.h"
#include "../json.hpp"

class Cell 
{

public:
    enum class CellStatus { Unknown, Empty, Ship };

private:
    int x, y;  // координаты клетки
    Cell::CellStatus status; // состояние клетки
    Ship* ship;  // указатель на корабль (если есть)
    int shipIndex;  // индекс сегмента корабля в случае удара
public:

    Cell(int x, int y);
    
    Cell::CellStatus getStatus() const;
    Ship::Orientation getOrientation() const;
    void setStatus(Cell::CellStatus newStatus);
    Ship* getShip() const;
    void setShip(Ship* newShip, int index);
    int getShipIndex() const;
    nlohmann::json toJson();
    void fromJson (nlohmann::json& j);
    void updateCell();
    int getIndex() const;
    int getStatusShip();

};

#endif