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
    string DecBin(float decVal, int maxRep);//Converte de Decimal para Binario.
    int getExp(float decVal, int maxRep);
    string DecBin(int Dec, int Inf, int Sup);//Converte de Decimal para Binario.
    string BinDec(string binInt, string binDec);//Converte de Binario para Decimal.
}

#endif // CONVERSAO_H
