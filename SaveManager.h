#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include <string>
#include <fstream>
#include "json.hpp"
#include "FieldCombined/GameField.h"
#include "ShipCombined/ShipManager.h"

// прямая декларация
class Game;

class SaveManager {
private:
    Game& game;
    void placeShips(const nlohmann::json& ships, GameField& field, ShipManager& shipManager);

public:
    SaveManager(Game& game);
    nlohmann::json saveGame();
    void loadGame(nlohmann::json& j);
    void save(std::string name);
    void load(std::string name);
    std::string getHash(const std::string& data);
    friend std::istream& operator>> (std::istream& is, SaveManager& save);
    friend std::ostream& operator<< (std::ostream& os, SaveManager& save);
};

#endif
