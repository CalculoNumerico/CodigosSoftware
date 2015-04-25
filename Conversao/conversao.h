#ifndef CONVERSAO_H
#define CONVERSAO_H

#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include "PontoFlutuante/pontflutuante.h"

using namespace std;

namespace Conv
{

    string DecBin(double decVal, int maxRep);
    string DecBin(int Dec, int Inf, int Sup);

    string BinDec(string binInt, string binDec);
}

class Conversao
{

public:
    Conversao();
    ~Conversao();

};

#endif // CONVERSAO_H
