#ifndef SHIP_H
#define SHIP_H
#include <iostream>
#include <vector>
#include <stdexcept>

class Ship 
{
public:
    enum class Orientation { Horizontal, Vertical };
    enum class SegmentState { Whole, Damaged, Destroyed };
private:
    int length;
    Orientation orientation;
    std::vector<SegmentState> segments;
    int index;

public:
    Ship(int length, int index);
    int getIndex() const;
    void setOrientation(Orientation orientation);
    SegmentState getSegment(int index) const;
    void setSegmentStatus(int state, int index);
    void hitSegment(int index, int damage);
    int getLength() const;
    bool isDestroyed() const;
    void updateSegment(int index);
    Orientation getOrientation() const;
};

#endif
