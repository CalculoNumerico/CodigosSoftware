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

//Exempo da classe SistemasLineares - GaussSeidel//
    SistemasLineares G;
    LinAlg::Matrix<float> A(4,5), X0(1,4);
    //LinAlg::Ones(A);
    G.setX0(X0);
    A = "10,-1,2,0,6;-1,11,-1,3,25;2,-1,10,-1,-11;0,3,-1,8,15";
    //A = "4,2,1,2;-2,7,1,0;1,-1,5,1";
    cout<<A;
    cout<<endl<<G.GaussSeidel(A, 5, 0.01, false)<<endl;
//--------------------------------------------------//
}

