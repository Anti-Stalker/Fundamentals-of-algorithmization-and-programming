#ifndef ICEDATA_H
#define ICEDATA_H

#include <map>

class IceData
{
public:
    IceData();
    int getCompressionStrength(double thickness);

private:
    std::map<double, int> iceStrengths;
};

#endif // ICEDATA_H
