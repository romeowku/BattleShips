#ifndef INFO_HOLDER_H
#define INFO_HOLDER_H

#include <iostream>
class InfoHolder
{

public:
    virtual ~InfoHolder() = default;
    std::pair<int, int> getData();

};

#endif