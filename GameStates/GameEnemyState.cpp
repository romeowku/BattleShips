#include "GameEnemyState.h"
#include "../Exceptions.h"
#include <random>
#include <algorithm>

GameEnemyState::GameEnemyState (Game& game) : game(game), difficulty(1) 
{}

bool GameEnemyState::attack(int x, int y) 
{
    std::pair<int, int> next = calculateNextAttack();
    previousAttacks.push_back({next.first, next.second});
    game.getPlayerField().attackCell(next.first, next.second, nullptr);  
    if (!game.getPlayerShipManager().hasAliveShips()) 
    {
        game.changeState();
        endRound();
        return true;
    }
    game.changeState();
    return false;
}

void GameEnemyState::endRound() 
{ 
    std::cout << "Game Over, wanna try again?\n"; 
    game.getEnemyField().updateField(); 
    game.getPlayerField().updateField();
    game.getPlayerShipManager().reset();
    game.getEnemyShipManager().reset();
}

std::pair<int, int> GameEnemyState::calculateNextAttack() 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    const int fieldSize = game.getPlayerField().getWidth();
    std::uniform_int_distribution<> dis(0, fieldSize - 1);

    /*if (difficulty == 1) {
        while (true) {
            int x = dis(gen);
            int y = dis(gen);
            if (isValidAttack(x, y)) {
                return {x, y};
            }
        }
    } else {*/
        if (previousAttacks.empty() || lastHit.first == -1) {
            while (true) {
                int x = dis(gen);
                int y = dis(gen);
                if (isValidAttack(x, y)) {
                    return {x, y};
                }
            }
        }


        auto playerField = game.getPlayerField();
        auto lastAttack = previousAttacks.back();

        if (playerField.getCell(lastAttack.first, lastAttack.second).getShip() != nullptr && 
            !(playerField.getCell(lastAttack.first, lastAttack.second).getShip()->isDestroyed())) 
            {
            lastHit = lastAttack;
        } else if (playerField.getCell(lastAttack.first, lastAttack.second).getShip()->isDestroyed()) {
            lastHit = {-1, -1};
            hasFoundDirection = false;
            currentDirection = {0, 0};
        }

        if (lastHit.first != -1) 
        {
            if (!hasFoundDirection) 
            {
                std::vector<std::pair<int, int>> directions = {
                    {-1, 0}, {1, 0}, {0, -1}, {0, 1}  // влево, вправо, вверх, вниз
                };
                
                for (const auto& dir : directions) 
                {
                    int newX = lastHit.first + dir.first;
                    int newY = lastHit.second + dir.second;
                    
                    if (isValidAttack(newX, newY)) 
                    {
                        currentDirection = dir;
                        hasFoundDirection = true;
                        return {newX, newY};
                    }
                }
                
                lastHit = {-1, -1};
                hasFoundDirection = false;
            } else {
                int newX = lastHit.first + currentDirection.first;
                int newY = lastHit.second + currentDirection.second;
                
                if (isValidAttack(newX, newY)) 
                {
                    return {newX, newY};
                } else {
                    lastHit = {-1, -1};
                    hasFoundDirection = false;
                    currentDirection = {0, 0};
                }
            }
        }
        
        while (true) 
        {
            int x = dis(gen);
            int y = dis(gen);
            if (isValidAttack(x, y)) { return {x, y}; }
        }
    }

bool GameEnemyState::isValidAttack(int x, int y) const 
{
    const int fieldSize = game.getPlayerField().getWidth();
    if (x < 0 || x >= fieldSize || y < 0 || y >= fieldSize) {
        return false;
    }
    
    return std::find(previousAttacks.begin(), previousAttacks.end(), std::make_pair(x, y)) == previousAttacks.end();
}

void GameEnemyState::setDifficulty(int level) 
{
    if (level < 1 || level > 3) { std::cerr <<  ChooseDifficultyException().what() << '\n'; }
    difficulty = level;
}

int GameEnemyState::getDifficulty() const { return difficulty; }

GameState* GameEnemyState::newStateMove() { return new GamePlayerState(game); }

bool GameEnemyState::useAbility() { std::cerr << BotAbilityException().what() << '\n'; }