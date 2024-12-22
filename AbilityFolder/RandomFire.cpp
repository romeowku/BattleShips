#include "RandomFire.h"

RandomFire::RandomFire(GameField& field) : field(field) 
{}

void RandomFire::activate(LogHolder& logHolder)
{
    logHolder.setAbility(LogHolder::Ability::Random);
    logHolder.setXY(-1, -1);
    int numShips = field.getShipManager().getNumShips();
    
    std::vector<int> undestroyedShips;
    for (int i = 0; i < numShips; ++i) 
    {
        if (!field.getShipManager().getShip(i).isDestroyed()) {
            undestroyedShips.push_back(i);
        }
    }

    if (undestroyedShips.empty()) { return; }

    int randomShipIndex = undestroyedShips[rand() % undestroyedShips.size()];
    Ship& randomShip = field.getShipManager().getShip(randomShipIndex);

    std::vector<int> undamagedSegments;
    for (int i = 0; i < randomShip.getLength(); ++i)
    {
        if (randomShip.getSegment(i) != Ship::SegmentState::Destroyed)
        {
            undamagedSegments.push_back(i);
        }
    }

    if (!undamagedSegments.empty())
    {
        int random_segment = undamagedSegments[rand() % undamagedSegments.size()];
        randomShip.hitSegment(random_segment, 1);
    }
}