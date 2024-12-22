#include "Cell.h"

Cell::Cell(int x, int y) : x(x), y(y), status(Cell::CellStatus::Unknown), ship(nullptr), shipIndex(-1) {}

Cell::CellStatus Cell::getStatus() const { return status; }

void Cell::setStatus(Cell::CellStatus newStatus) { status = newStatus; }

Ship* Cell::getShip() const { return ship; }

void Cell::setShip(Ship* newShip, int index) {
    ship = newShip;
    shipIndex = index;
}

Ship::Orientation Cell::getOrientation() const { return ship->getOrientation(); }

int Cell::getStatusShip() 
{
    if (status != CellStatus::Ship) { return -1; }
    Ship::SegmentState status = ship->getSegment(shipIndex);
    
    switch (status)
    {
    case Ship::SegmentState::Whole: return 2;
    case Ship::SegmentState::Damaged: return 1;
    case Ship::SegmentState::Destroyed: return 0;
    default: return -1;
    }
}

nlohmann::json Cell::toJson() 
{
    return nlohmann::json{
        {"status", static_cast<int>(status)},
        {"health", status == CellStatus::Ship ? getStatusShip() : -1}
    };
}

void Cell::fromJson(nlohmann::json& j) 
{
    status = static_cast<CellStatus>(j["status"].get<int>());
    if (status == CellStatus::Ship && ship != nullptr) {
        int health = j["health"].get<int>();
        if (health != -1) {
            ship->setSegmentStatus(health, shipIndex);
        }
    }
}

int Cell::getShipIndex() const { return shipIndex; }

int Cell::getIndex() const { return ship->getIndex(); }

void Cell::updateCell() 
{
    if (ship != nullptr && shipIndex != -1) { 
        ship = nullptr;
        shipIndex = -1;
    }
    status = Cell::CellStatus::Unknown;
}