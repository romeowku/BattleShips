#ifndef GAMEDISPLAY_H
#define GAMEDISPLAY_H
#include "FieldCombined/GameField.h"
#include <iostream>

template <typename GameRenderer>
class GameDisplay 
{
private:
    GameRenderer renderer;

public:
    GameDisplay(GameRenderer& renderer) : renderer(renderer) {}

    void displayField(GameField& field, bool player) { renderer.printField(field, player); }
    void displayMessage(const std::string& message) { renderer.printMessage(message); }
    void displayShips(ShipManager& shipManager) { renderer.printNumShips(shipManager); }


};

#endif