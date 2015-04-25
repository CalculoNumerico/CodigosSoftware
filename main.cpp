<<<<<<< HEAD
#include <iostream>
#include "Conversao/conversao.h"
#include "PontoFlutuante/pontflutuante.h"
#include "SistemasLineares/sistemaslineares.h"
#include <sstream>
=======
#include <Conversoes/conversions.h>
#include <SistemasdeControle/headers/graphicLibs/grafics.h>
#include <ctime>
>>>>>>> 501e0e5c5a2bf5d0fdf5f1104bd3c9d2a3df0763

using namespace std;

<<<<<<< HEAD
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
=======
using namespace Conv;
int main(int argc, char *argv[])
{
    //Teste de conversão como Namespace//////////////
    cout<<DecBin(3,5)<<"\n";            //11
    cout<<BinDec("1111","0")<<"\n";     //15
    //...///////////////////////////////////////////////

    //TimeEvent(argc, argv);        //Teste da biblioteca gráfica
>>>>>>> 501e0e5c5a2bf5d0fdf5f1104bd3c9d2a3df0763
    return 0;
}

