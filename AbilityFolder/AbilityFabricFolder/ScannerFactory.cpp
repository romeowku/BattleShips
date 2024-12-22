#include "ScannerFactory.h"

ScannerFactory::ScannerFactory(CoordHolder coordHolder, GameField& field) : coordHolder(coordHolder),
field(field) 
{}

std::unique_ptr<Ability> ScannerFactory::create() 
{
    std::cout << "Activated Scanner for 2x2\nEnter the coordinates\n";
    auto [x, y] = coordHolder.getData();
    return std::make_unique<Scanner>(field, x, y);
}

nlohmann::json ScannerFactory::toJson() 
{
    return nlohmann::json {
        {"Ability", "Scanner"}
    };
}
