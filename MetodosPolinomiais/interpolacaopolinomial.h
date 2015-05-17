#ifndef INTERPOLACAOPOLINOMIAL_H
#define INTERPOLACAOPOLINOMIAL_H

#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/polynom.h"
#include "SistemasLineares/sistemaslineares.h"

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
    LinAlg::Matrix<float> MatrizVandermonde(LinAlg::Matrix<float> Valores_X);//Função só pra mostrar a Matriz
    LinAlg::Matrix<float> Valores_Y(LinAlg::Matrix<float> MatrizVandermonde, LinAlg::Matrix<double> Valores_X);//Função para calcular Vetor_Y. |Ax = y| OBS: essa função não é assim é apenas a inicial enquanto polynom não foi incluida corretamente.
    LinAlg::Matrix<float> Polinomio_Vandermonde(LinAlg::Matrix<float> Valores_X, LinAlg::Matrix<float> Valores_Y);//Função para calcular Vetor_A.
    LinAlg::Matrix<float> Lagrange(float x);
    LinAlg::Matrix<float> Polinomio_Lagrange(LinAlg::Matrix<float> Valores_X, LinAlg::Matrix<float> Valores_Y, float x);
    //LinAlg::Matrix<float> Newton();
};

#endif // INTERPOLACAOPOLINOMIAL_H
