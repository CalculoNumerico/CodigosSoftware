#include <Conversoes/conversions.h>
#include <SistemasdeControle/headers/graphicLibs/grafics.h>
#include <ctime>

// This creates the spinning of the cube.
void TimeEvent(int argc, char *argv[])
{
    grafics *plot = new grafics();
    LinAlg::Matrix<double> data(2,1);
    data = "0;0";
    plot->setData(data.GetRow(1), data.GetRow(2));
    clock_t t;
    t = clock();

    for(double i = 0; i < 500; i++){
        Sleep(5);
        data(1,1) = i;
        data(2,1) = i;
        *plot += data;
    }

    plot->setInstance(plot);
    plot->startFramework(argc,argv);
}

using namespace Conv;
int main(int argc, char *argv[])
{
    //Teste de conversão como Namespace//////////////
    cout<<DecBin(3,5)<<"\n";            //11
    cout<<BinDec("1111","0")<<"\n";     //15
    //...///////////////////////////////////////////////

    //TimeEvent(argc, argv);        //Teste da biblioteca gráfica
    return 0;
}
