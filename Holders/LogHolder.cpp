#include "LogHolder.h"

void LogHolder::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}
void LogHolder::setShipHere(bool isHere)
{
    this->isHere = isHere;
}

std::pair<int, int> LogHolder::getData()
{
    return {x, y};
}

LogHolder::Ability LogHolder::getLastAbility()
{
    return ability;
}

void LogHolder::printLastAbility()
{
    switch(ability)
    {
        case LogHolder::Ability::Scanner:
            std::cout << "Used Scanner at" << '(' << x << ',' << y << ')';
            std::cout << " to" << '(' << x + 1 << ',' << y + 1 << ")\n";
            
            if(isHere)
            {
                std::cout << "Ship found here!\n";
                isHere = false;
            } else {
                std::cout << "Ship not found here?\n";
            }
            break;
        case LogHolder::Ability::Random:
            std::cout << "Used RandomFire " << abilities.RandomFire << ".\n";
            break;
        
        case LogHolder::Ability::DoublePassive:
            std::cout << "Used DoubleDamage " << '(' << x << ',' << y << ")\n";
            break;
        case LogHolder::Ability::DoubleActive:
            std::cout << "DoubleDamage activated\n";
            break;
        default:
            std::cout << "You don't use any ability\n";
            break;
    } 
}

void LogHolder::setAbility(Ability ability)
{
    this->ability = ability;

    if(ability != LogHolder::Ability::DoublePassive)
    {    
        switch(ability)
        {
            case LogHolder::Ability::Scanner:
                abilities.Scanner++;
                break;
            
            case LogHolder::Ability::Random:
                abilities.RandomFire++;
                break;
            
            case LogHolder::Ability::DoubleActive:
                abilities.DoubleDamage++;
                break;
            
            default:
                break;
        }
    }
}

void LogHolder::printCountOfAbilites()
{
    std::cout << "Used DoubleDamage " << abilities.DoubleDamage << ".\n";
    std::cout << "Used Scanner " << abilities.Scanner << ".\n";
    std::cout << "Used RandomFire " << abilities.RandomFire << ".\n";
}