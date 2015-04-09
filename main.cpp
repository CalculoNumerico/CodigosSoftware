#include <conversions.h>
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

int main(int argc, char *argv[])
{

        TimeEvent(argc, argv);
//    LinAlg::Matrix<double> In, Out;
//    In  = "0";
//    grafics *plot = new grafics();
//    plot->setData(In, Out);
//    for(double i = 0; i < 5; i++)
//       *plot += i;
//    glutTimerFunc( 10, TimeEvent, 1);
//    cout<<plot->getData();
//    glutInit(&argc, argv);
//    grafics *plot = new grafics();
//    plot->setData(In, Out);
//    plot->setInstance(plot);
//    plot->startFramework(argc,argv);

//    grafics *plot2 = new grafics();
//    plot2->setData(In2, Out2);
//    plot2->setInstance(plot2);
//    plot2->startFramework(argc,argv);
//    glutMainLoop();
//    Conversions *conv = new Conversions();
//    double valNumb;
//    string val;
//    cin >> valNumb;
//    std::cout << conv->DecBin(valNumb, 0);
    return 0;
}
