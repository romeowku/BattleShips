#ifndef BATTLESHIPS_GAMEPLAYERSTATE_H
#define BATTLESHIPS_GAMEPLAYERSTATE_H

#include "GameState.h"
#include "../Game.h"
#include "GameEnemyState.h"

class GamePlayerState : public GameState 
{
private:
    Game& game;

public:
    GamePlayerState(Game& game);
    bool attack(int x, int y) override;
    bool useAbility() override;
    GameState* newStateMove() override;
    void endRound() override;
};

#endif
