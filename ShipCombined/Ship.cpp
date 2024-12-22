#include "Ship.h"

Ship::Ship(int length, int index) 
    : length(length), orientation(orientation), segments(length, SegmentState::Whole), index(index)
{
    if (length < 1 || length > 4) 
    {
        throw std::invalid_argument("There is no such ship length. (class Ship)");
    }
}

int Ship::getIndex() const { return index; }

void Ship::setOrientation(Ship::Orientation orientation) 
    { this->orientation = orientation; }

Ship::Orientation Ship::getOrientation() const 
    { return orientation; }

Ship::SegmentState Ship::getSegment(int index) const 
{
    if (index < 0 || index >= length) 
    {
        throw std::out_of_range("There is no such segment index. (method getSegment)");
    }
    return segments[index];
}

void Ship::setSegmentStatus(int state, int index) 
{
    switch (state)
    {
    case 2:
        segments[index] = SegmentState::Whole;
        break;

    case 1:
        segments[index] = SegmentState::Damaged;
        break;

    case 0:
        segments[index] = SegmentState::Destroyed;
        break;
    
    default:
        break;
    }
}

void Ship::hitSegment(int index, int damage) 
{
    if (index < 0 || index >= length) 
    {
        throw std::out_of_range("There is no such segment index. (method hitSegment)");
    }
    switch (segments[index]) 
    {
    case Ship::SegmentState::Whole:
        segments[index] = (damage == 2) ? Ship::SegmentState::Destroyed : Ship::SegmentState::Damaged;
        break;
    case Ship::SegmentState::Damaged:
        segments[index] = Ship::SegmentState::Destroyed;
        break;
    default: 
        return;
    }
}

int Ship::getLength() const 
    { return length; }

bool Ship::isDestroyed() const 
{
    for (const auto& segment : segments) 
    {
        if (segment != Ship::SegmentState::Destroyed) { return false; }    
    }
    return true;
}

void Ship::updateSegment(int index) 
    { segments[index] = Ship::SegmentState::Whole; }
