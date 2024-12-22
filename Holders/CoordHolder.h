#ifndef COORD_HOLDER_H
#define COORD_HOLDER_H

#include "InfoHolder.h"
#include "CoordReader.h"

class CoordHolder : public InfoHolder
{
protected:
    CoordReader* coordReader;

public:
    std::pair<int, int> getData()
    {
        return coordReader->readCoordinates();
    }

};

#endif