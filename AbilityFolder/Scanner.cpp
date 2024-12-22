#include "Scanner.h"

Scanner::Scanner(GameField& field, int x, int y) : field(field), x(x), y(y) {}

    void Scanner::activate(LogHolder& logHolder)
    {   
        logHolder.setAbility(LogHolder::Ability::Scanner);
        logHolder.setXY(x, y);
        for (int i = y; i < y + 2; i++) 
        {
            for (int j = x; j < x + 2; j++) 
            {
                if (i >= 0 && j >= 0 && i < field.getHeight() && j < field.getWidth()) 
                {
                    if (field.getCell(j, i).getStatus() == Cell::CellStatus::Ship)
                        logHolder.setShipHere(true);
                }
            }
        }
    }