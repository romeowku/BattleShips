#ifndef RANDOM_FIRE_H
#define RANDOM_FIRE_H

#include "../FieldCombined/GameField.h"
#include "Ability.h"
#include "../Holders/LogHolder.h"

class GameField;

class RandomFire : public Ability 
{
private:
    GameField& field;

public:
    RandomFire(GameField& field);
    void activate(LogHolder& logHolder) override;

};

#endif