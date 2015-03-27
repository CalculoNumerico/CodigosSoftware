#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <math.h>
#include <iostream>
#include <string>

using namespace std;
class Conversions
{
public:
    Conversions();
    ~Conversions();

    string DecBin(double decVal, int maxRep);
    string BinDec(string binInt, string binDec);
};

#endif // CONVERSIONS_H
