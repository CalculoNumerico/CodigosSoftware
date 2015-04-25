#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
namespace Conv {
    string DecBin(double decVal, int maxRep);
    string BinDec(string binInt, string binDec);
}
class Conversions
{
public:
    Conversions();
    ~Conversions();

    //string DecBin(double decVal, int maxRep);
    //string BinDec(string binInt, string binDec);
};
#endif // CONVERSIONS_H
