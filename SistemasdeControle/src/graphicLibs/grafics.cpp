#include "SistemasdeControle/headers/graphicLibs/grafics.h"

grafics::grafics()
{

}

//grafics::grafics(simFunction func)
//{

//}

//grafics::grafics(graphicProperties prop)
//{

//}

//grafics::grafics(graphicProperties prop, simFunction func)
//{
//    this->prop.setGridStatus          (prop.getGridStatus());
//    this->prop.setGraphicDataSize     (prop.getGraphicDataSize());
//    this->prop.setGraphicXposition    (prop.getGraphicXposition());
//    this->prop.setGraphicYposition    (prop.getGraphicYposition());
//    this->prop.setNumberOfClicks      (prop.getNumberOfClicks());
//    this->prop.setLastMotionPosition  (prop.getLastXMotionPosition(),
//                                       prop.getLastYMotionPosition());
//    this->prop.setLimits              (prop.getXLimitLeft(), prop.getXLimitRight(),
//                                       prop.getYLimitDown(), prop.getYLimitUp());
//    this->prop.setMotionOcurrency     (prop.getMotionOcurrency());

////    this->func.SetInputData           (func.GetInputData());
////    this->func.SetOutputData          (func.GetOutputData());
////    this->func.SetDataLimits          (func.GetDataMinLimit(),
////                                       func.GetDataMaxLimit());
////    this->func.SetDataStep            (func.GetDataStep());

////    this->func.SetFunctionCall        (func.GetFunctionCall());


//}

//grafics::grafics(double (*FunctionToCall)(double), double lMin, double lMax, double step)
//{
//    this->FunctionToCall = FunctionToCall;
//    this->lMax = lMax;
//    this->lMin = lMin;
//    this->step = step;
//    this->GraphicDataSize = 1;
//    this->GraphicXposition = 0;
//    this->GraphicYposition = 0;
//    this->NumberOfClicks = 0;
//    this->LastMotionXPosition = 0;
//    this->LastMotionYPosition = 0;
//    this->GraphicXLimit_Left = 0;
//    this->GraphicXLimit_Rigth = 40;
//    this->GraphicYLimit_Down = 0;
//    this->GraphicYLimit_Up = 40;
//    this->MotionOcurrency = false;
//}

void grafics::setData(LinAlg::Matrix<double> DataX, LinAlg::Matrix<double> DataY)
{
    this->X = DataX;
    this->Y = DataY;
}

void grafics::setData(LinAlg::Matrix<double> DataX, LinAlg::Matrix<double> DataY, LinAlg::Matrix<double> DataZ)
{
    this->X = DataX;
    this->Y = DataY;
    this->Z = DataZ;
}

void grafics::operator +=(LinAlg::Matrix<double> &mat)
{
    if(mat.getNumberOfRows() == 1)
        this->X = this->X | mat.GetRow(1);
    else if(mat.getNumberOfRows() == 2)
    {
        this->X = this->X | mat.GetRow(1);
        this->Y = this->Y | mat.GetRow(2);
    }else if(mat.getNumberOfRows() == 3){
        this->X = this->X | mat.GetRow(1);
        this->Y = this->Y | mat.GetRow(2);
        this->Y = this->Y | mat.GetRow(3);
    }
}

void grafics::clearDraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //clears the colour and depth buffers
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glPushMatrix();     	//saves the current matrix on the top of the matrix stack
    glTranslatef(0,0,-100); //translates the current matrix 0 in x, 0 in y and -100 in z

    glColor3f(0.0,0.0,0.0);
}

void grafics::DrawTitle()
{
    double fontSize = glutBitmapLength(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)prop.getTitle().c_str());
    fontSize = fontSize/prop.getTitle().length();
    double winSize = glutGet(GLUT_WINDOW_WIDTH);
//    double var = -fontSize/2*(500/winSize);
    glRasterPos2f(-fontSize*(650/winSize), prop.getYLimitUp()+2);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)prop.getTitle().c_str());
}

void grafics::DrawAxis(double ZeroXPosition, double ZeroYPosition)
{
    if(prop.isInXLimit(ZeroXPosition))
    {
        glBegin(GL_LINES);
            glVertex2f(ZeroXPosition, prop.getYLimitDown());
            glVertex2f(ZeroXPosition, prop.getYLimitUp());
        glEnd();
    }
    if(prop.isInYLimit(ZeroYPosition))
    {
        glBegin(GL_LINES);
            glVertex2f(prop.getXLimitLeft(),  ZeroYPosition);
            glVertex2f(prop.getXLimitRight(), ZeroYPosition);
        glEnd();
    }
}

void grafics::DrawGraphic()
{
    double ZeroXFunction = 0,
           ZeroYFunction = 0;//ZeroYFunction = ((prop.getYLimitUp() + prop.getYLimitDown()/2));
    LinAlg::Matrix<double> NormInput = X, NormOutput = Y;


    //NormInput  = prop.getGraphicDataSize()*func.GetInputData().normalize(prop.getXLimitRight(), prop.getXLimitLeft()) - prop.getGraphicXposition();
    //NormOutput = prop.getGraphicDataSize()*func.GetOutputData().normalize(prop.getYLimitUp(),   prop.getYLimitDown()) + prop.getGraphicYposition();


        for (int i = 1; i <= NormInput.getNumberOfRows(); i++)
        {
            glColor3f(double(i-1),double(i-1)/4,double(i-1)/2);
            glBegin(GL_LINE_STRIP);
            for(int j = 1; j <= NormInput.getNumberOfColumns(); j++)
            {
                if(j < NormInput.getNumberOfColumns())
                {
//                    if((func.GetInputData()(i,j)  > 0.0 && func.GetInputData()(i,j+1)  < 0.0) || (func.GetInputData()(i,j)  < 0.0 && func.GetInputData()(i,j+1)  > 0.0))
//                        ZeroYFunction = (NormInput(i,j) + NormInput(i,j+1))/2;
//                    else if(func.GetInputData()(i,j)  == 0.0)
//                        ZeroYFunction = NormInput(i,j);
//                    if((func.GetOutputData()(i,j)  > 0.0 && func.GetOutputData()(i,j+1)  < 0.0) || (func.GetOutputData()(i,j)  < 0.0 && func.GetOutputData()(i,j+1)  > 0.0))
//                        ZeroXFunction = (NormOutput(i,j)+NormOutput(i,j+1))/2;
//                    else if(func.GetOutputData()(i,j)  == 0.0)
//                        ZeroXFunction = NormOutput(i,j);
                }

                if(prop.isInGraphicRegion(NormInput(i,j), NormOutput(i,j)))
                    glVertex2f(NormInput(i,j), NormOutput(i,j));
            }
            glEnd();
        }

    glColor3f(0.0,0.0,0.0);
    this->DrawAxis(ZeroXFunction, ZeroYFunction);
}

void grafics::DrawFunction()
{
//    if(func.GetFunctionCall() != NULL)
//        func.GenerateDataFunction();
    DrawGraphic();
}

void grafics::DrawStepMark()
{
    double MarkXDistance = 5, MarkYDistance = 6;
    double winXSize = glutGet(GLUT_WINDOW_WIDTH), winYSize = glutGet(GLUT_WINDOW_HEIGHT);
    double MarkYSize = 700/winXSize, MarkXSize = 500/winYSize;

    for (double i = MarkXDistance; i <= prop.getXLimitRight(); i += MarkXDistance)
    {
        DrawLineMarks(i, MarkXSize, true);
        for(double j = i/5; j <= prop.getXLimitRight(); j += i/5)
            DrawLineMarks(j, MarkXSize/2, true);
    }

    for (double i = -MarkYDistance; i >= prop.getYLimitDown(); i -= MarkYDistance)
    {
        DrawLineMarks(-i, MarkYSize, false);
        for(double j = (i/5); j >= prop.getYLimitDown(); j += i/5)
            DrawLineMarks(j, MarkYSize/2, false);
    }
}

void grafics::DrawLineMarks(double Position, double MarkSize, bool isX)
{
    if(isX){
        //Marks the positive side for X Axis
        glBegin(GL_LINE_STRIP);
            glVertex2f(Position, -MarkSize);
            glVertex2f(Position, MarkSize);
        glEnd();

        //Marks the negative side for X Axis
        glBegin(GL_LINE_STRIP);
            glVertex2f(-Position, -MarkSize);
            glVertex2f(-Position, MarkSize);
        glEnd();
    }
    else
    {
        if(-Position < prop.getYLimitUp())
        {
            //Marks the positive side for Y Axis
            glBegin(GL_LINE_STRIP);
                glVertex2f(-MarkSize, -Position);
                glVertex2f(MarkSize, -Position);
            glEnd();
        }
            //Marks the negative side for Y Axis
            glBegin(GL_LINE_STRIP);
                glVertex2f(-MarkSize, Position);
                glVertex2f(MarkSize, Position);
            glEnd();
    }
}

void grafics::DrawGrid()
{
    double GridXDistance = (abs(prop.getXLimitRight() - prop.getXLimitLeft())/abs(prop.getXLimitRight()));
    double GridYDistance = (abs(prop.getYLimitUp() - prop.getYLimitDown())/abs(prop.getYLimitUp()));

    glPointSize(1.0);
    glBegin(GL_POINTS);
        for (double i = prop.getXLimitLeft(); i <= prop.getXLimitRight(); i += GridXDistance)
            for (double j = prop.getYLimitDown(); j <= prop.getYLimitUp() ; j += GridYDistance)
                glVertex2f(i, j);
    glEnd();
    glPointSize(3.0);
}

void grafics::DrawXLabel()
{
    double fontSize = glutBitmapLength(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)prop.getXLabel().c_str());
    fontSize = fontSize/prop.getXLabel().length();
    double winSize = glutGet(GLUT_WINDOW_WIDTH);

    glRasterPos2f(fontSize, -40);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)prop.getXLabel().c_str());
}

void grafics::DrawYLabel()
{
    double fontSize = glutBitmapLength(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)prop.getYLabel().c_str());
    fontSize = fontSize/prop.getYLabel().length();
    double winSize = glutGet(GLUT_WINDOW_HEIGHT);

    glRasterPos2f(fontSize, -40);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glutBitmapString(GLUT_BITMAP_HELVETICA_12,(const unsigned char*)prop.getYLabel().c_str());
}

void grafics::display()
{
    this->clearDraw();
    this->DrawTitle();
    this->DrawFunction();
    this->DrawStepMark();
    this->DrawXLabel();
    if(prop.getGridStatus() == true)
        this->DrawGrid();

    glPopMatrix();          //retrieves our saved matrix from the top of the matrix stack
    glutSwapBuffers();      //swaps the front and back buffers
}

void grafics::MouseClickProcess(int button, int state, int x, int y)
{
    double XDistance = (prop.getXLimitRight() - prop.getXLimitLeft())/2;
    double YDistance = (prop.getYLimitUp() - prop.getYLimitDown())/2;
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2) -1)*XDistance;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*YDistance;

    if(prop.getMotionOcurrency() == false)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        {
            prop.setXClicks(1, prop.getNumberOfClicks() + 1, a);
            prop.setYClicks(1, prop.getNumberOfClicks() + 1, b);

            prop.setGraphicDataSize ( prop.getGraphicDataSize()  + 0.2);
            prop.setGraphicXposition( prop.getGraphicXposition() + prop.getXClicks()(1, prop.getNumberOfClicks() + 1));
            prop.setGraphicYposition( prop.getGraphicYposition() + prop.getYClicks()(1, prop.getNumberOfClicks() + 1));
            prop.setNumberOfClicks  (prop.getNumberOfClicks()    + 1);
        }
        else if (button == GLUT_RIGHT_BUTTON && prop.getNumberOfClicks() > 0 && state == GLUT_UP)
        {
            prop.setGraphicDataSize ( prop.getGraphicDataSize()  - 0.2);
            prop.setNumberOfClicks  ( prop.getNumberOfClicks()   - 1);
            prop.setGraphicXposition( prop.getGraphicXposition() - prop.getXClicks()(1, prop.getNumberOfClicks() + 1));
            prop.setGraphicYposition( prop.getGraphicYposition() - prop.getYClicks()(1, prop.getNumberOfClicks() + 1));
        }
        else if(button == GLUT_RIGHT_BUTTON && prop.getNumberOfClicks() == 0)
        {
            prop.setGraphicXposition(0);
            prop.setGraphicYposition(0);
        }
    }

    else
        prop.setMotionOcurrency(false);
}

void grafics::MotionFunc(int x, int y)
{
    double XDistance = double(prop.getXLimitRight() - prop.getXLimitLeft())/2;
    double YDistance = double(prop.getYLimitUp()    - prop.getYLimitDown())/2;
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2)  -1)*XDistance;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*YDistance;

    prop.setGraphicXposition( prop.getGraphicXposition() + (prop.getLastXMotionPosition() - a)/XDistance);
    prop.setGraphicYposition( prop.getGraphicYposition() + (prop.getLastYMotionPosition() - b)/YDistance);
    prop.setMotionOcurrency(true);
}

void grafics::PassiveMotionFunc(int x, int y)
{
    double XDistance = double(prop.getXLimitRight() - prop.getXLimitLeft())/2;
    double YDistance = double(prop.getYLimitUp()    - prop.getYLimitDown())/2;
    double a = (double(x)/(glutGet(GLUT_WINDOW_WIDTH)/2)  -1) *XDistance;
    double b = (double(y)/(glutGet(GLUT_WINDOW_HEIGHT)/2) -1)*YDistance;

    prop.setLastMotionPosition(a, b);
}
