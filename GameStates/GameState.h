#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

class GameState 
{
public:
    virtual bool attack(int x, int y) = 0;
    virtual void endRound() = 0;
    virtual bool useAbility() = 0;
    virtual GameState* newStateMove() = 0;
    virtual ~GameState() = default;
};

#endif
