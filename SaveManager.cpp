#include "SaveManager.h"
#include "Game.h"
#include <sstream>

SaveManager::SaveManager(Game& game) : game(game) {}

void SaveManager::placeShips(const nlohmann::json& ships, GameField& field, ShipManager& shipManager) 
{
    std::vector<bool> placedShips(shipManager.getNumShips(), false);
    
    for (const auto& ship : ships) 
    {
        int index = ship[0];
        int x = ship[1];
        int y = ship[2];
        //std::cout << "( << x << ", " << y << )" << " " << ship[3] << '\n';
        Ship::Orientation orientation = ship[3] == 0 ? Ship::Orientation::Horizontal : Ship::Orientation::Vertical;
        
        if (placedShips[index]) { continue; }
        
        field.placeShip(&shipManager.getShip(index), x, y, orientation);
        placedShips[index] = true;
    }
}

nlohmann::json SaveManager::saveGame() 
{
    return nlohmann::json {
        {"PField", game.getPlayerField().toJson()},
        {"EField", game.getEnemyField().toJson()},
        {"PlSManager", game.getPlayerShipManager().toJson()},
        {"EnSManager", game.getEnemyShipManager().toJson()},
        {"AbManager", game.getAbilityManager().toJson()},
        {"CurrentRound", game.getCurrentRound()}
    };
}

void SaveManager::loadGame(nlohmann::json& j) 
{

    game.getPlayerShipManager().fromJson(j["PlSManager"]);
    game.getEnemyShipManager().fromJson(j["EnSManager"]);

    game.getPlayerField().fromJson(j["PField"]);
    game.getEnemyField().fromJson(j["EField"]);

    placeShips(j["PField"]["Ship"], game.getPlayerField(), game.getPlayerShipManager());
    placeShips(j["EField"]["Ship"], game.getEnemyField(), game.getEnemyShipManager());

    auto playerCells = j["PField"]["Field"];
    auto enemyCells = j["EField"]["Field"];
    int height = j["PField"]["height"];
    int width = j["PField"]["width"];

    std::vector<std::vector<Cell>>& PlField = game.getPlayerField().getField();
    std::vector<std::vector<Cell>>& EnField = game.getEnemyField().getField();
    
    for (int y = 0; y < height; y++) 
    {    
        for (int x = 0; x < width; x++) 
        {
            PlField[y][x].fromJson(playerCells[y][x]);
            EnField[y][x].fromJson(enemyCells[y][x]);
        }
    }

    game.getAbilityManager().fromJson(j["AbManager"]);
    game.setCurrentRound(j["CurrentRound"]);
}

std::string SaveManager::getHash(const std::string& data) 
{
    std::hash<std::string> hash_fn;
    size_t hash = hash_fn(data);
    std::stringstream ss;
    ss << std::hex << hash;
    return ss.str();
}

void SaveManager::save(std::string name) 
{
    std::ofstream file(name);
    if (file.is_open()) {
        std::string data = saveGame().dump(4);
        std::string hash = getHash(data);

        file << "{ \"data\": " << data << ", \"hash\": \"" << hash << "\" }";
        file.close();
    } else {
        throw std::runtime_error("Failed to open file for saving");
    }
}

void SaveManager::load(std::string name) 
{
    std::ifstream file(name);
    if (file.is_open()) {
        nlohmann::json j;
        file >> j;

        std::string data = j["data"].dump(4);
        std::string expectedHash = j["hash"];
        std::string actualHash = getHash(data);
        std::cout << expectedHash << " " << actualHash << '\n';
        if (expectedHash != actualHash) {
            throw ModifySaveFileException();
        }

        loadGame(j["data"]);
        file.close();
    } else {
        throw std::runtime_error("Failed to open file for loading");
    }
}


std::istream& operator>> (std::istream& is, SaveManager& sm) 
{
    nlohmann::json j;
    is >> j;

    sm.loadGame(j);

    return is;
}


std::ostream& operator<< (std::ostream& os, SaveManager& sm) 
{
    os << sm.saveGame().dump(4);
    return os;
}