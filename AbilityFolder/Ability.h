#ifndef ABILITY_H
#define ABILITY_H

#include "../Holders/LogHolder.h"

class Ability 
{
public:
    virtual void activate(LogHolder& logHolder) = 0;
    virtual ~Ability() = default;
};

#endif