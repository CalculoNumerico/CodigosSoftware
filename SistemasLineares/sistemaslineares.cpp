#include "sistemaslineares.h"

SistemasLineares::SistemasLineares()
{
}
SistemasLineares::~SistemasLineares()
{
}

void SistemasLineares::PivotParcial(LinAlg::Matrix<float> MatrizUni)
{
}

void SistemasLineares::PivotCompleto(LinAlg::Matrix<float> MAtrizUni)
{
}

void SistemasLineares::setX0(LinAlg::Matrix<float> InicialStep)
{
    this->X0 = InicialStep;
}

LinAlg::Matrix<float> SistemasLineares::Gauss(LinAlg::Matrix<float> MatrizUni)
{
}

LinAlg::Matrix<float> SistemasLineares::GaussJacobi(LinAlg::Matrix<float> MatrizUni)
{
}

LinAlg::Matrix<float> SistemasLineares::GaussSeidel(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations, float MinPrecision, bool ShowSteps)
{
    //float x1, dk;
    LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns());

    //Deixa o vetor de chute inicial padronizado como vetor linha
    if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
    {
        ~this->X0;
    }
    //Insere o chute inicial na Matriz resposta
    for(int i = 1; i < MatrizRes.getNumberOfColumns(); i++){
        MatrizRes(1,i) = this->X0(1,i);
    }

    for(int k = 2; k <= MaxIterations; k++)
    {
        for(int i = 1; i < MatrizUni.getNumberOfColumns(); i++)
        {
            float aux = 0;
            //MatrizRes(k,i) = MatrizUni(i, MatrizUni.getNumberOfColumns())/MatrizUni(i,i);
            for(int j = 1; j < i; j++)
            {
                aux += (MatrizUni(i,j)*MatrizRes(k, j));
                //MatrizRes(k,i) -= (MatrizUni(i,j)*MatrizRes(k, j))/MatrizUni(i,i);
            }
            for(int j = i+1; j < MatrizUni.getNumberOfColumns(); j++)
            {
                aux += (MatrizUni(i,j)*MatrizRes(k-1, j));
                //MatrizRes(k,i) -= (MatrizUni(i,j)*MatrizRes(k-1, j))/MatrizUni(i,i);
            }
            MatrizRes(k,i) = (MatrizUni(i, MatrizUni.getNumberOfColumns()) - aux)/MatrizUni(i,i);
        }
    }
    return MatrizRes;
}

