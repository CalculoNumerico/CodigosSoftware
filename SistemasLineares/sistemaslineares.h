#ifndef SISTEMASLINEARES_H
#define SISTEMASLINEARES_H
//#include <Matrix>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;
class SistemasLineares
{
    LinAlg::Matrix<float> X0;

//    void setUni(LinAlg::Matrix<float> A, LinAlg::Matrix<float> B);

    void PivotParcial(LinAlg::Matrix<float> &MatrizUni, int cols);

    void PivotCompleto(LinAlg::Matrix<float> &MatrizUni, int cols);
    float Abs(float Valor);

public:
    SistemasLineares();
    ~SistemasLineares();

    void setX0(LinAlg::Matrix<float> InicialStep);

    void ConvDiv(LinAlg::Matrix<float> MatrizUni);
//       LinAlg::Matrix<float> Gauss(LinAlg::Matrix<float> A, LinAlg::Matrix<float> B);
    LinAlg::Matrix<float> Gauss(LinAlg::Matrix<float> MatrizUni);

//        LinAlg::Matrix<float> GaussJacobi(LinAlg::Matrix<float> A, LinAlg::Matrix<float> B);
    LinAlg::Matrix<float> GaussJacobi(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations, float MinPrecision);

//        LinAlg::Matrix<float> GaussSeidel(LinAlg::Matrix<float> A, LinAlg::Matrix<float> B);
    LinAlg::Matrix<float> GaussSeidel(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations, float MinPrecision);

};
#endif // SISTEMASLINEARES_H
