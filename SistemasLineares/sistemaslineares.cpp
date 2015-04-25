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
    //int colum = MatrizUni.getNumberOfColumns();
    float x1, dk;
    LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns());
    //MatrizRes(MaxIterations,colum);
    //MatrizRes = this->X0;
   // do
    //{
        for(int k = 2; k < MaxIterations+1; k++)
        {
            for(int i = 1; i < MatrizUni.getNumberOfColumns()-1; i++)
            {
                cout<<endl<<MatrizUni(i, MatrizUni.getNumberOfColumns())/MatrizUni(i,i)<<" ";
                MatrizRes(k,i) = MatrizUni(i, MatrizUni.getNumberOfColumns())/MatrizUni(i,i);
                for(int j = 1; j < MatrizUni.getNumberOfColumns()-1; j++)
                {
                    if(i != j){
                        MatrizRes(k,i) += ((MatrizUni(i,j)*MatrizRes(k-1,i))*-1)/MatrizUni(i,i);
                        cout<<((MatrizUni(i,j)*MatrizRes(k-1,i))*-1);
                        cout<<"R";
                    }
                    //cout<<i<<endl<<MatrizRes<<endl;
                }
            }
        }
        return MatrizRes;
   // }
    //while(dk > MinPrecision);
//    if(ShowSteps)
//    {

//    }
//    else
//    {

//    }
}

