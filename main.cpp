#include "Conversao/conversao.h"
#include "PontoFlutuante/pontflutuante.h"
#include "SistemasLineares/sistemaslineares.h"
#include "MetodosPolinomiais/interpolacaopolinomial.h"

using namespace std;



int main()
{
//Exemplo da classe ponto flutuante//
//    PontFlutuante p;
//    p.setArm(7.5,10,-5,5);
//    p.setNum(7.5,10,-5,5);

//    p.printArm();
//    p.printNum();
//----------------------------------------------------------------//

//Exemplo da classe conversao//

//   string c;
//   c =  Conv::DecBin(2.7, 5);
//   cout<<c<<"\n\n";
   //ou.
   //cout<<Conv::BinDec(7.5, 5)<<"\n\n";
//------------------------------------------------//

//Exempo da classe SistemasLineares - GaussSeidel//
//    SistemasLineares G;
//    LinAlg::Matrix<float> A(3,4), X0(1,4);
//    G.setX0(X0);
//    //A = "10,-1,2,0,6;-1,11,-1,3,25;2,-1,10,-1,-11;0,3,-1,8,15";
//    A = "5,1,1,2;1,6,1,2;1,1,7,2";
//    cout<<A;
//    cout<<endl<<G.GaussSeidel(A, 5, 0.05)<<endl;
//--------------------------------------------------//

//Exemplo da classe InterpolacaoPolinomial//
    LinAlg::Matrix<float> A("0,1,3"), f("-5,1,25"), x;
    InterpolacaoPolinomial polynom(A, f);// = new InterpolacaoPolinomial(A);
    x = polynom.initVector(1,1,600);
    cout<<x;
    //polynom.Lagrange(0);
//-------------------------------------------------//
}

