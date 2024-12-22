#include "Game.h"
#include <chrono>
#include <thread>

Game::Game() : numShips(5), ships({1, 1, 2, 3, 4}), enemyShipManager(ShipManager(numShips, ships)), 
            playerShipManager(ShipManager(numShips, ships)), enemyField(GameField(11, 11, enemyShipManager)),  
        playerField(GameField(11, 11, playerShipManager)), logHolder(LogHolder()), abilityManager(AbilityManager(enemyField, logHolder)), 
    state(nullptr), saveManager(*this)
{}

void Game::placeShips(const std::vector<std::pair<std::pair<int, int>, int>>& params) 
{
    for (size_t i = 0; i < params.size(); i++) 
    {
        const auto& param = params[i];
        int x = param.first.first;
        int y = param.first.second;
        Ship::Orientation orientation = (param.second == 0) ? Ship::Orientation::Horizontal : Ship::Orientation::Vertical;
        try
        {
            playerField.placeShip(&playerShipManager.getShip(i), x, y, orientation);
        } catch (ShipPlacementException& e) {
            std::cerr << e.what() << '\n';
            return;
        }
    }
}

void Game::placeEnemyShipsRandom() 
{
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < enemyShipManager.getNumShips(); i++) 
    {
        bool placed = false;
        while (!placed) {
            std::uniform_int_distribution<> disX(0, enemyField.getWidth());
            std::uniform_int_distribution<> disY(0, enemyField.getHeight());
            int x = disX(gen);
            int y = disY(gen);

            std::uniform_int_distribution<> disOrientation(0, 1);
            Ship::Orientation orientation = disOrientation(gen) == 0 ? Ship::Orientation::Horizontal : Ship::Orientation::Vertical;

            try 
            {
                enemyField.placeShip(&enemyShipManager.getShip(i), x, y, orientation);
                placed = true;
                std::cout << "Ship " << i << " placed at (" << x << ", " << y << ") " << "Orientation: " << static_cast<int>(orientation) << '\n';
            } catch (ShipPlacementException& e) {
                placed = false;
                continue;
            }
        }
    }
}

void Game::saveGame(std::string name) {
    try
    {
        saveManager.save(name + ".json");
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Game::loadGame(std::string name) 
{
    try
    {
        saveManager.load(name + ".json");
        return true;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return false;
    }
}

bool Game::isNewRound() { return _isNewRound; }
bool Game::isNewGame() { return _isNewGame; }
bool Game::isPlayerLose() { return _isPlayerLose; }
bool Game::isEnemyLose() { return _isEnemyLose; }
int Game::getCurrentRound() { return _currentRound; }
GameState* Game::getState() { return state; }

void Game::changeState() { state = state->newStateMove(); }