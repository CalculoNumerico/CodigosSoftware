#include "Conversao/conversao.h"
#include "PontoFlutuante/pontflutuante.h"
#include "SistemasLineares/sistemaslineares.h"

using namespace std;

int main()
{
//Exemplo da classe ponto flutuante//
    PontFlutuante a;
    a.setArm(7.5,10,-5,5);
    a.setNum(7.5,10,-5,5);

    a.printArm();
    a.printNum();
//----------------------------------------------------------------//

//Exemplo da classe conversao//
   string s;
   s =  Conv::DecBin(7.5, 5);
   cout<<s<<"\n\n";
   //ou.
   cout<<Conv::DecBin(7.5, 5)<<"\n\n";
//------------------------------------------------//

//Exempo da classe SistemasLineares//
    SistemasLineares b;
    LinAlg::Matrix<float> A(3,4), X0(1,3);
    LinAlg::Ones(A);
    b.setX0(X0);
    cout<<b.GaussSeidel(A, 3, 0.5, false)<<"\n";
//--------------------------------------------------//
}

