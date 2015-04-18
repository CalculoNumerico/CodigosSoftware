#include "conversions.h"

namespace Conv {
    string DecBin(double decVal, int maxRep){
        string resultado;

        //cout<<resultado<<endl;
        int numInt = (int)decVal;
        double numDec = decVal - numInt;    //Parte decimal do valor a ser convertido
        int cont = 0;                       //Contador para a parte fracionada

        //Condição para conversão da base
        while(numInt != 1)
        {
            int resto = numInt%2;
            string resAnterior = resultado;
            std::ostringstream strs;
            strs << resto;
            resultado = strs.str() + resAnterior;
            numInt = (numInt - resto)/2;
        }

        string resAnterior = resultado;
        std::ostringstream strs;
        strs << numInt;
        resultado = strs.str() + resAnterior;

        if(numDec != 0)
            resultado += ".";
           // ui->numBin->setText(ui->numBin->text() + ".");

        while(cont != maxRep && numDec != 0)
        {
            int partInt = (int)(numDec*2);
           // ui->numBin->setText(ui->numBin->text() + QString::number(partInt));
            std::ostringstream strs;
            strs << numInt;
            resultado += strs.str();
            numDec = (numDec*2) - partInt;

            cont++;
        }

        return resultado;
    }

    string BinDec(string binInt, string binDec)
    {
        int indice = 0;
        double Resultado = 0;
        for(int i = binInt.length()-1; i >= 0; i--)
        {
            Resultado += double(binInt.at(i)-48)*pow(2,indice);
            indice++;
        }

        indice = -1;
        for(int i = 0; i <= binDec.length()-1; i++)
        {
            Resultado += double(binDec.at(i)-48)*pow(2,indice);
            indice--;
        }

        //ui->numDec->setText(QString::number(Resultado));
        std::ostringstream strs;
        strs << Resultado;

        return strs.str();
    }
}

Conversions::Conversions()
{

}

Conversions::~Conversions()
{

}
