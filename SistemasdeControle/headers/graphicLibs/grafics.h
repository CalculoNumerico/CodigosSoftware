#ifndef GRAFICS_H
#define GRAFICS_H
#include "SistemasdeControle/headers/graphicLibs/glview.h"
#include <math.h>
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/graphicLibs/graphicproperties.h"
//#include "SistemasdeControle/headers/modelLibs/simfunction.h"

class grafics : public GlView
{
private:
//    template <class Type>
    LinAlg::Matrix<double> X,Y,Z;

    graphicProperties prop;
    //simFunction func;
    void clearDraw();
    void DrawTitle();
    void DrawXLabel();
    void DrawYLabel();
    void DrawAxis(double ZeroXPosition = -40,
                  double ZeroYPosition =  0);
    void DrawGrid();
    void DrawData();
    void DrawGraphic();
    void DrawStepMark();
    void DrawLineMarks(double Position, double MarkSize, bool isX);
//    void ZoomIn();
//    void ZoomOut();
    void DrawFunction();

public:
    grafics();
//    grafics(simFunction func);
    grafics(graphicProperties prop);
//    grafics(graphicProperties prop, simFunction func);

    //template<typename Type>
    void setData(LinAlg::Matrix<double> DataX, LinAlg::Matrix<double> DataY);
    //template<typename Type>
    void setData(LinAlg::Matrix<double> DataX, LinAlg::Matrix<double> DataY, LinAlg::Matrix<double> DataZ);
    LinAlg::Matrix<double> getData();
    void operator += (LinAlg::Matrix<double> &mat);

    void display();
    void MouseClickProcess(int button, int state, int x, int y);
    void MotionFunc(int x, int y);
    void PassiveMotionFunc(int x, int y);
};

#endif // GRAFICS_H
