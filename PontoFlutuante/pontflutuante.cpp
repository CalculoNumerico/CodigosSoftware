#include "pontflutuante.h"

PontFlutuante::PontFlutuante()
{
    this->precisao = 0;
    this->Arm = "";
    this->Num = "";
}

PontFlutuante::~PontFlutuante()
{
}

void PontFlutuante::setArm(double Dec, int Mant, int Inf, int Sup)
{
    string result;
    string ExpBin;

    //Converte o valor Decimal.
    result = Conv::DecBin(Dec, Mant);

    //Converte o Exponencial.
    ExpBin = setExp(this->Valor_Exp,Inf, Sup);

    //Adcionando a mantissa.
    while(result.length() <= Mant + 1)
        result +="0";

    //Adcionando o sinal da mantissa.
    if(Dec < 0)
        result = "1" + result;

    else if (Dec >= 0)
        result = "0" + result;

    //Adcionando o Exponencial.
    if(Dec>1 || (Dec*(-1)) > 1)
        result = result + "0" + ExpBin;

    else
        result =
                result + "1" + ExpBin;

     this->Arm = result;
}

void PontFlutuante::setNum(double Dec, int Mant, int Inf, int Sup)
{
    string result;
    string ExpBin;

    //Converte o valor Decimal.
    result = Conv::DecBin(Dec,Mant);

    //Converte o Exponencial.
    ExpBin = setExp(Valor_Exp,Inf,Sup);

    //Adcionando a mantissa.
    while(result.length() <= Mant + 1)
        result +="0";

    //Adcionando o sinal da mantissa.
    if(Dec < 0)
        result = "- 0," + result;

    else if(Dec >= 0)
        result = "0," + result;

    //Adcionando o Exponencial.
    if(Dec>1 || (Dec*(-1)) > 1)
        result = result + "x2^" + ExpBin;

    else
        result = result + "x2^-" + ExpBin;

     this->Num = result;
}

string PontFlutuante::setExp(int Exp, int Inf, int Sup)
{
    string exp = Conv::DecBin(Exp, Inf, Sup);
    return exp;
}

string PontFlutuante::getArm()
{
    return Arm;
}

string PontFlutuante::getNum()
{
    return this->Num;
}

void PontFlutuante::printArm()
{
    cout<<this->Arm<<"\n\n";
}
void PontFlutuante::printNum()
{
    cout<<this->Num<<"\n\n";
}

