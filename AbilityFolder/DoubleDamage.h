#ifndef DOUBLE_DAMAGE_H
#define DOUBLE_DAMAGE_H

#include "Ability.h"
#include "../Holders/LogHolder.h"


class DoubleDamage : public Ability 
{
public:
    void activate(LogHolder& logHolder) override;

};

#endif