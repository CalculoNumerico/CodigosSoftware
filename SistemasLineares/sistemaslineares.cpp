#include "sistemaslineares.h"

SistemasLineares::SistemasLineares()
{
}
SistemasLineares::~SistemasLineares()
{
}

void SistemasLineares::setX0(LinAlg::Matrix<float> InicialStep)
{
    this->X0 = InicialStep;
}

void SistemasLineares::PivotParcial(LinAlg::Matrix<float> &MatrizUni, int cols)
{
    SistemasLineares A;
    LinAlg::Matrix<float> AUX;

        for(int i = cols + 1; i <= MatrizUni.getNumberOfRows(); i++){
            if(Abs(MatrizUni(cols,cols)) < Abs(MatrizUni(i,cols)))
            {
//                AUX = LinAlg::Matrix<float>::GetRow(cols);
//                LinAlg::Matrix<float>::SwapRows(cols,i);
//                LinAlg::Matrix<float>::SwapRows(i,AUX);
            }
      }
}

void SistemasLineares::PivotCompleto(LinAlg::Matrix<float> &MAtrizUni, int cols)
{
}

LinAlg::Matrix<float> SistemasLineares::Gauss(LinAlg::Matrix<float> MatrizUni)
{

}

LinAlg::Matrix<float> SistemasLineares::GaussJacobi(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations, float MinPrecision)
{
    //Matriz Resposta
    LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns());

    //Deixa o vetor de chute inicial padronizado como vetor linha
    if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
        ~this->X0;
    //Insere o chute inicial na Matriz resposta
    for(int i = 1; i < MatrizRes.getNumberOfColumns(); i++)
        MatrizRes(1,i) = this->X0(1,i);

    //Laço para contar as linhas da Matriz Resposta
    for(int k = 2; k < MaxIterations+1; k++)
         {
             //Laço para contar as colunas da MatrizRes, MatrizErro e linhas da MatrizUni.
             for(int i = 1; i < MatrizUni.getNumberOfColumns(); i++)
             {
                 //Divisão dos termos independentes das funções
                 MatrizRes(k,i) = MatrizUni(i, MatrizUni.getNumberOfColumns())/MatrizUni(i,i);

                 //Laço para contar as colunas da MatrizUni
                 for(int j = 1; j < MatrizUni.getNumberOfColumns(); j++)
                 {
                     if(i != j)
                         //calculando a formula de JACOBI.
                         MatrizRes(k,i) -= ((MatrizUni(i,j)*MatrizRes(k-1,i)))/MatrizUni(i,i);
                 }

                 //Verifica se o valor de erro d(k) é o maior encontrado
                 if(abs(MatrizRes(k,i) - MatrizRes(k-1,i)) > MatrizRes(k-1, MatrizRes.getNumberOfColumns()))
                     MatrizRes(k-1, MatrizRes.getNumberOfColumns()) = abs(MatrizRes(k,i) - MatrizRes(k-1,i));
             }

             //Limita o numero de iterações até a precisão ser obtida
             if(MatrizRes(k-1, MatrizRes.getNumberOfColumns()) < MinPrecision)
                 k = MaxIterations+1;
         }
         return MatrizRes;


}

LinAlg::Matrix<float> SistemasLineares::GaussSeidel(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations, float MinPrecision)
{

        LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns());

        //Deixa o vetor de chute inicial padronizado como vetor linha
        if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
        {
            ~this->X0;
        }
        //Insere o chute inicial na Matriz resposta
        for(int i = 1; i < MatrizRes.getNumberOfColumns(); i++){
            MatrizRes(1,i) = this->X0(1,i);
        }

        //Laço para contar as linhas da Matriz Resposta
        for(int k = 2; k <= MaxIterations; k++)
        {
            //Laço para contar as colunas da MatrizRes e linhas da MatrizUni.
            for(int i = 1; i < MatrizUni.getNumberOfColumns(); i++)
            {
                float aux = 0;

                //Verificação das variáveis atualizadas (mesma linha)
                for(int j = 1; j < i; j++)
                {
                    aux += (MatrizUni(i,j)*MatrizRes(k, j));
                }

                //Verificação das variaveis não atualizadas (linha anterior)
                for(int j = i+1; j < MatrizUni.getNumberOfColumns(); j++)
                {
                    aux += (MatrizUni(i,j)*MatrizRes(k-1, j));
                }

                //Aplicação da formula geral (Bi-x1-x2)/Aii
                MatrizRes(k,i) = (MatrizUni(i, MatrizUni.getNumberOfColumns()) - aux)/MatrizUni(i,i);

                //Verifica se o valor de erro d(k) é o maior encontrado
                if(abs(MatrizRes(k,i) - MatrizRes(k-1,i)) > MatrizRes(k-1, MatrizRes.getNumberOfColumns()))
                    MatrizRes(k-1, MatrizRes.getNumberOfColumns()) = abs(MatrizRes(k,i) - MatrizRes(k-1,i));
            }

            //Limita o numero de iterações até a precisão ser obtida
            if(MatrizRes(k-1, MatrizRes.getNumberOfColumns()) < MinPrecision)
                k = MaxIterations+1;
        }
        return MatrizRes;
    }

float SistemasLineares::Abs(float Valor)
{
    if(Valor < 0)
           Valor = -Valor;

    return Valor;
}

void SistemasLineares::ConvDiv(LinAlg::Matrix<float> MatrizUni)
{
    LinAlg::Matrix<float> Ress(1,MatrizUni.getNumberOfRows());
    for(int i = 0; i <= MatrizUni.getNumberOfRows(); i++)
    {
        for(int j = 0; j <= MatrizUni.getNumberOfColumns(); j++)
        {
            if(i != j)
            {
                Ress(1, i) += MatrizUni(i,j)/MatrizUni(i,i);
            }
        }
        if(Ress(1, i) > 1)
            cout<<"Esse sistema Diverge";
    }
}
