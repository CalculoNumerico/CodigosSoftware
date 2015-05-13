#include "conversao.h"

namespace Conv
{
//Função de conversão decimal binario.
string DecBin(float decVal, int maxRep)
{
    string resultadoInt;
    string resultadoFrac;
    string result;

        int numInt = (int)decVal;
        float numDec = decVal - numInt;    //Parte decimal do valor a ser convertido
        int cont = 0;                       //Contador para a parte fracionada

        //Situação para quando o Valor for negativo.
        if(numInt < 0)
        {
            numInt *= -1;
            numDec *= -1;
        }
        //--------------------------------------------------//

        //Condição para conversão da parte inteira.
        while(numInt != 1)
        {
            int resto = numInt%2;
            string resAnterior = resultadoInt;
            std::ostringstream strs;
            strs << resto;
            resultadoInt = strs.str() + resAnterior;
            numInt = (numInt - resto)/2;
        }

        string resAnterior = resultadoInt;
        std::ostringstream strs;
        strs << numInt;
        resultadoInt = strs.str() + resAnterior;
        //----------------------------------------------------------------//
        //Converção da parte fracionaria.
        while(cont != maxRep && numDec != 0)
        {
            int partInt = (int)(numDec*2);

            std::ostringstream strs;
            strs << numInt;
            resultadoFrac = strs.str();
            numDec = (numDec*2) - partInt;
        cont++;
        }
        //----------------------------------------------------------------//
        result = resultadoInt + resultadoFrac;

        if(decVal < 0)
            result = "-" + result;

        return result;
}

    //Função para retorna o valor do exp do ponto flutuante.
    int getExp(float decVal, int maxRep)
    {
        string resultadoInt;
        string resultadoFrac;
        int result;

        int numInt = (int)decVal;
        float numDec = decVal - numInt;    //Parte decimal do valor a ser convertido
        int cont = 0;                       //Contador para a parte fracionada

        //Condição para conversão da parte inteira.
        while(numInt != 1)
        {
            int resto = numInt%2;
            string resAnterior = resultadoInt;
            std::ostringstream strs;
            strs << resto;
            resultadoInt = strs.str() + resAnterior;
            numInt = (numInt - resto)/2;
        }

        string resAnterior = resultadoInt;
        std::ostringstream strs;
        strs << numInt;
        resultadoInt = strs.str() + resAnterior;
        //----------------------------------------------------------------//
        //Converção da parte fracionaria.
        while(cont != maxRep && numDec != 0)
        {
            int partInt = (int)(numDec*2);

            std::ostringstream strs;
            strs << numInt;
            resultadoFrac = strs.str();
            numDec = (numDec*2) - partInt;
            cont++;
        }

        //----------------------------------------------------------------//
        ////Armazenando o exp////
        if(numInt > 0)// se o valor for maior que 0.
            result  = resultadoInt.length();


        else if(numInt == 0)// se o valor for igual a 0.
            result  = resultadoFrac.length();
        ////----------------------------------------------------------------////

        return result;
    }

    //Converçao do exp
    string DecBin(int Dec, int Inf, int Sup)
    {
        string resultado;
        int numInt = Dec;

            //Condição para conversão da base
           if(Dec <= Sup && Dec >= Inf)
           {
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
           }
           else if(Dec > Sup && Dec < Inf)
               cout<<"Erro com o valor do exp, limites superior ou inferior.";

           return resultado;
    }

    //Conver;áo de binario para decimal
    string BinDec(string binInt, string binDec)
    {
        int indice = 0;
        double Resultado = 0;

            //Convercáo da parte inteira
            for(int i = binInt.length()-1; i >= 0; i--)
            {
                Resultado += float(binInt.at(i)-48)*pow(2,indice);
                indice++;
            }
            //----------------------------------------------------------------//

            //Convercáo da parte fracionaria
            indice = -1;
            for(int i = 0; i <= binDec.length()-1; i++)
            {
                Resultado += float(binDec.at(i)-48)*pow(2,indice);
                indice--;
            }
            //----------------------------------------------------------------//

            std::ostringstream strs;
            strs << Resultado;

            return strs.str();
    }
}


