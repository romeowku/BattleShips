#ifndef GAME_H
#define GAME_H

#include "FieldCombined/GameField.h"
#include "GameStates/GameState.h"
#include "AbilityManager.h"
#include "ShipCombined/ShipManager.h"
#include "UserInput.h"
#include "SaveManager.h"

class Game 
{
private:
    int numShips;
    std::vector <int> ships;
    
    ShipManager enemyShipManager;
    ShipManager playerShipManager;
    GameField enemyField;
    GameField playerField;
    LogHolder logHolder;
    AbilityManager abilityManager;
    GameState* state = nullptr;
    SaveManager saveManager;

    bool _isNewRound;
    bool _isNewGame;
    int _currentRound = 1;
    bool _isPlayerLose;
    bool _isEnemyLose;

public:
    Game();
    void changeState();

    void placeShips(const std::vector<std::pair<std::pair<int, int>, int>>& params);
    void placeEnemyShipsRandom();

    void saveGame(std::string name);
    bool loadGame(std::string name);

    void setNewRound(bool isNewRound) { this->_isNewRound = isNewRound; }
    void setNewGame(bool isNewGame) { this->_isNewGame = isNewGame; }
    void setPlayerLose(bool isPlayerLose) { this->_isPlayerLose = isPlayerLose; }
    void setEnemyLose(bool isEnemyLose) { this->_isEnemyLose = isEnemyLose; }
    void setCurrentRound(int currentRound) { this->_currentRound = currentRound; }
    void setState(GameState* state) { this->state = state; }

    bool isNewRound();
    bool isNewGame();
    bool isPlayerLose();
    bool isEnemyLose();
    int getCurrentRound();
    GameState* getState();

    ShipManager& getPlayerShipManager() { return playerShipManager; }
    ShipManager& getEnemyShipManager() { return enemyShipManager; }
    GameField& getPlayerField() { return playerField; }
    GameField& getEnemyField() { return enemyField; }
    LogHolder& getLogHolder() { return logHolder; }
    AbilityManager& getAbilityManager() { return abilityManager; }
};

#endif
