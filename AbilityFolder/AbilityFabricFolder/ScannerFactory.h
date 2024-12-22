#ifndef SCANNER_FACTORY_H
#define SCANNER_FACTORY_H

#include "AbilityFactory.h"
#include "../AbilityFolder/Scanner.h"
#include "../Holders/CoordHolder.h"
#include "../FieldCombined/GameField.h"

class ScannerFactory : public AbilityFactory 
{

protected:
    CoordHolder coordHolder;
    GameField& field;
public:
    ScannerFactory(CoordHolder coordHolder, GameField& field);
    std::unique_ptr<Ability> create() override;
    nlohmann::json toJson() override;
};

#endif