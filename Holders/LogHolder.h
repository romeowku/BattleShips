#ifndef LOG_HOLDER_H
#define LOG_HOLDER_H

#include "InfoHolder.h"
#include <vector>

class LogHolder : public InfoHolder
{
private:
    typedef struct CountOfAbility
    {
        int DoubleDamage;
        int Scanner;
        int RandomFire;
    
    }CountOfAbility;

public:
    enum class Ability {DoubleActive, DoublePassive, Scanner, Random};

private:
    int x, y;
    CountOfAbility abilities;
    LogHolder::Ability ability = LogHolder::Ability::DoublePassive;
    bool isHere = false;
    std::pair<int, int> getData();
public:

    void printCountOfAbilites();
    void setXY(int x, int y);
    void setAbility(Ability ability);
    void setShipHere(bool isHere);
    void printLastAbility();
    LogHolder::Ability getLastAbility();
};

#endif