#ifndef CONSOLERENDERER_H
#define CONSOLERENDERER_H
#include <iostream>
#include "FieldCombined/GameField.h"

class ConsoleRenderer
{
private:
    void printOptionField(GameField& field, int x, int y, bool player) const;

public:
    void printField(GameField& field, bool player) const;
    void printMessage(const std::string& message);
    void printNumShips(ShipManager& shipManager);

};


#endif