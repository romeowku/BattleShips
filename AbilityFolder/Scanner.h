#ifndef SCANNER_H
#define SCANNER_H

#include "Ability.h"
#include "../Holders/LogHolder.h"
#include "../FieldCombined/GameField.h"

class GameField;

class Scanner : public Ability 
{
private:
    GameField& field;
    int x, y;

public:
    Scanner(GameField& field, int x, int y);
    void activate(LogHolder& logHolder) override;

};
#endif