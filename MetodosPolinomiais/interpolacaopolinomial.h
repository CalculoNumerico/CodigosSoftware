#ifndef INTERPOLACAOPOLINOMIAL_H
#define INTERPOLACAOPOLINOMIAL_H

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

using namespace std;
class InterpolacaoPolinomial
{
    unsigned order;
    LinAlg::Matrix<float> n, f;

public:
    InterpolacaoPolinomial(LinAlg::Matrix<float> n);
    InterpolacaoPolinomial(LinAlg::Matrix<float> n, LinAlg::Matrix<float> f);
    ~InterpolacaoPolinomial();

    LinAlg::Matrix<float> initVector(unsigned iniValue, double step, unsigned endValue);
    LinAlg::Matrix<float> MatrizVandermonde(LinAlg::Matrix<float> Valores_X);
    LinAlg::Matrix<float> Lagrange(float x);
    //LinAlg::Matrix<float> Newton();


};

#endif // INTERPOLACAOPOLINOMIAL_H
