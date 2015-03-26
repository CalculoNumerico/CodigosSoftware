#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <math.h>
#include <iostream>

using namespace std;
class Conversions
{
public:
    Conversions();
    ~Conversions();

    string DecBin(double decVal, int maxRep);
    string BinDec(string decVal);
};

#endif // CONVERSIONS_H
