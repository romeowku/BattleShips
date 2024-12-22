#include "GameField.h"

GameField::GameField(int width, int height, ShipManager& shipManager) : width(width), height(height), shipManager(shipManager)
{
    if (width <= 0 || height <= 0) throw FieldSizeException();

    field.resize(height, std::vector<Cell>(width, Cell(0, 0)));

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) { field[i][j] = Cell(j, i); }
    }
}

GameField::GameField(const GameField &other) : width(other.width), height(other.height), field(other.field), shipManager(other.shipManager)
{}

GameField::GameField(GameField &&other) noexcept : width(other.width), height(other.height), field(std::move(other.field)), shipManager((other.shipManager))
{}

GameField &GameField::operator=(const GameField &other)
{
    if(this != &other)
    {
        width = other.width;
        height = other.height;
        field = other.field;
        shipManager = other.shipManager;
    }
    return *this;
}

GameField &GameField::operator=(GameField &&other) noexcept
{
    if (this != &other)
    {
        width = other.width;
        height = other.height;
        field = std::move(other.field);
        shipManager = std::move(other.shipManager);
    }
    return *this;

}

ShipManager& GameField::getShipManager() { return shipManager; }

void GameField::updateField() 
{
    for ( int y = 0; y < height; ++y ) 
    {
        for ( int x = 0; x < width; ++x ) { field[y][x].updateCell(); }
    }
}

bool GameField::hasShipsAlive() const { return shipManager.hasAliveShips(); }

Cell& GameField::getCell(int x, int y) { return field[y][x]; }

int GameField::getWidth() { return width; }

int GameField::getHeight() { return height; }

std::vector<std::vector<Cell>>& GameField::getField() { return field; }

bool GameField::isPlaceValid(int length, int x, int y, Ship::Orientation orientation) 
{
    if (x < 0 || x >= width || y < 0 || y >= height) { return false; }
    if (orientation == Ship::Orientation::Horizontal && x + length > width) { return false; }
    if (orientation == Ship::Orientation::Vertical && y + length > height) { return false; }

    for (int i = -1; i <= 1; i++) 
    {
        for (int j = 0; j < length + 2; j++) 
        {
            int neighborX = (orientation == Ship::Orientation::Horizontal) ? x + j - 1 : x + i;
            int neighborY = (orientation == Ship::Orientation::Horizontal) ? y + i : y + j - 1;

            if (neighborX >= 0 && neighborX < width && neighborY >= 0 && neighborY < height) 
            {
                if (field[neighborY][neighborX].getStatus() == Cell::CellStatus::Ship 
                    || (field[neighborY][neighborX].getStatus() == Cell::CellStatus::Ship 
                    && neighborX != x && neighborY != y))  { return false; }
            }
        }
    }
    return true;
}

bool GameField::attackCell(int x, int y, LogHolder* logHolder) 
{
    if (x < 0 || x >= width || y < 0 || y >= height) { throw AttackOutException(); }
    Ship* ship = field[y][x].getShip();

    if (ship != nullptr) 
    {
        if(ship->isDestroyed()) { return false; }
        int segmentIndex = field[y][x].getShipIndex();
        
        if (logHolder != nullptr)
        {       
            if(logHolder->getLastAbility() == LogHolder::Ability::DoubleActive)
            {
                logHolder->setXY(x, y);
                logHolder->setAbility(LogHolder::Ability::DoublePassive);
                
                if(ship->getSegment(segmentIndex) == Ship::SegmentState::Damaged)
                {
                    ship->hitSegment(segmentIndex, 1);
                } else {
                    ship->hitSegment(segmentIndex, 2);
                }
            } else {
                ship->hitSegment(segmentIndex, 1);
            }
        } else {
            ship->hitSegment(segmentIndex, 1);
        }
        field[y][x].setStatus(Cell::CellStatus::Ship);
        
        if(ship->isDestroyed()) { return true; }
    
    } else {
        field[y][x].setStatus(Cell::CellStatus::Empty);
    }
    return false;
}

void GameField::placeShip(Ship* ship, int x, int y, Ship::Orientation orientation) 
{
    int length = ship->getLength();

    if (!isPlaceValid(length, x, y, orientation)) 
    { 
        throw ShipPlacementException(); 
    }

    for (int i = 0; i < length; i++) {
        int xOffset = (orientation == Ship::Orientation::Horizontal) ? i : 0;
        int yOffset = (orientation == Ship::Orientation::Vertical) ? i : 0;
        
        ship->setOrientation(orientation);
        field[y + yOffset][x + xOffset].setShip(ship, i);
        field[y + yOffset][x + xOffset].setStatus(Cell::CellStatus::Ship);
    }
}

nlohmann::json GameField::toJson() {
    nlohmann::json jField = nlohmann::json::array();
    nlohmann::json ships = nlohmann::json::array();

    for (int y = 0; y < height; y++) {
        nlohmann::json jRow = nlohmann::json::array();

        for (int x = 0; x < width; x++) {
            jRow.push_back((field[y][x]).toJson());

            if ((field[y][x]).getShipIndex() != -1) {
                nlohmann::json shipData = nlohmann::json::array();
                shipData.push_back((field[y][x]).getIndex());
                shipData.push_back(x);
                shipData.push_back(y);
                shipData.push_back((field[y][x]).getOrientation());
                ships.push_back(shipData);
            }
        }
        jField.push_back(jRow);
    }

    return nlohmann::json{
        {"width", width},
        {"height", height},
        {"Field", jField},
        {"Ship", ships}
    };
}


void GameField::fromJson(nlohmann::json& j) 
{
    width = j.at("width").get<int>();
    height = j.at("height").get<int>();
    field.clear();
    field = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell(0, 0)));
}

void printShip() 
{
    std::cout << "                           __       \n";
    std::cout << "                          |  \\     \n";
    std::cout << "     _______________      |___\\_____\n";
    std::cout << "     \\              \\    /         /\n";
    std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "   \\                                       /\n";
    std::cout << "    \\_____________________________________/\n";
}
