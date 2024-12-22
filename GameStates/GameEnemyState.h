#ifndef GAMEENEMYSTATE_H
#define GAMEENEMYSTATE_H

#include "GameState.h"
#include "GamePlayerState.h"
#include "../Game.h"
#include "../json.hpp"

class GameEnemyState : public GameState 
{
private:
    Game& game;
    int difficulty;
    std::vector<std::pair<int, int>> previousAttacks;
    std::pair<int, int> lastHit{-1, -1};
    std::pair<int, int> currentDirection{0, 0}; 
    bool hasFoundDirection = false;

public:
    GameEnemyState(Game& game);

    bool attack (int x, int y) override;
    void endRound() override;
    bool useAbility () override;

    GameState* newStateMove() override;
    
    std::pair<int, int> calculateNextAttack();
    bool isValidAttack(int x, int y) const;

    void setDifficulty(int level);
    int getDifficulty() const;

};

#endif // GAMEENEMYSTATE_H