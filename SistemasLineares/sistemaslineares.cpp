#include "sistemaslineares.h"

SistemasLineares::SistemasLineares()
{
}
SistemasLineares::~SistemasLineares()
{
}

void SistemasLineares::PivotParcial(LinAlg::Matrix<float> &MatrizUni, int cols)
{
    SistemasLineares A;
    LinAlg::Matrix<float> AUX;

        for(int i = cols + 1; i <= MatrizUni.getNumberOfRows(); i++){
            if(abs(MatrizUni(cols,cols)) < abs(MatrizUni(i,cols)))
            {
//                AUX = LinAlg::Matrix<float>::GetRow(cols);
//                LinAlg::Matrix<float>::SwapRows(cols,i);
//                LinAlg::Matrix<float>::SwapRows(i,AUX);
            }
      }
}

LinAlg::Matrix<float> SistemasLineares::Gauss(LinAlg::Matrix<float> MatrizUni)
{
     LinAlg::Matrix<float> MatrizGauss;
    //Laço para contagem das colunas de MatrizUni.
    for(unsigned i = 1; i < MatrizUni.getNumberOfColumns(); i++)
    {   //Laço para contagem das linhas de MatrizUni.
        for(unsigned j = i + 1; j <= MatrizUni.getNumberOfRows();  j++)
        {
            float m = MatrizUni(j,i)/MatrizUni(i,i);
            //Laço para contagem das colunas da equação.
            for(unsigned z = i ; z <= MatrizUni.getNumberOfColumns(); z++)
                MatrizUni(j,z) = MatrizUni(j,z) - m*MatrizUni(i,z);
        }
    }

    MatrizGauss = LinAlg::Zeros<float>(1, MatrizUni.getNumberOfRows());
    float R;
    for(unsigned i = 1; i <= MatrizUni.getNumberOfRows(); ++i)
    {
        unsigned k = MatrizUni.getNumberOfRows() - i + 1;
        R = 0;
        for(unsigned j = k + 1; j <= MatrizUni.getNumberOfColumns() - 1; ++j)
                R = R + MatrizUni(k, j) * MatrizGauss(1, j);

        MatrizGauss(1, k) = (MatrizUni(k, MatrizUni.getNumberOfColumns()) - R) / MatrizUni(k, k);
    }

    return MatrizGauss;
    }

LinAlg::Matrix<float> SistemasLineares::GaussJacobi(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations, float MinPrecision)
{
    //Matriz Resposta
    LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns() - 1);
    LinAlg::Matrix<float> C (MatrizUni.getNumberOfRows(), MatrizUni.getNumberOfColumns() - 1);
    LinAlg::Matrix<float> g (MatrizUni.getNumberOfRows(), 1);
    LinAlg::Matrix<float> x0(MaxIterations,MatrizUni.getNumberOfColumns() -1);

    //    //Deixa o vetor de chute inicial padronizado como vetor linha
    if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
        ~this->X0;
    //    //Insere o chute inicial na Matriz resposta
    for(int i = 1; i < MatrizRes.getNumberOfColumns() - 1; i++)
        x0(1,i) = this->X0(1,i);

    for(int i = 1; i <= MatrizUni.getNumberOfRows(); i++)
    {
        for(int j = 1; j < MatrizUni.getNumberOfColumns(); j++)
        {
            if(i != j)
                C(i,j) = - MatrizUni(i,j)/MatrizUni(i,i);
        }
        g(i,1) = MatrizUni(i,1) / MatrizUni(i,i);
    }

//    cout<<"\n"<<C<<"\n";
//    cout<<g<<"\n";
//    cout<<x0<<"\n";

    for(int k = 1; k <=MatrizUni.getNumberOfRows(); k++)
    {
        for(int z = 1; z < MatrizUni.getNumberOfColumns() - 1; z++)
        {
            x0(k,z+1) =  (C(k,z) * x0(1,z)) + g(k,1);
        }
//        if(abs(MatrizRes(,z+1) - MatrizRes(,z)) < MinPrecision)
//        {
//            break;
//        }

    }

    return MatrizRes;
}
//    //Deixa o vetor de chute inicial padronizado como vetor linha
//    if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
//        ~this->X0;
//    //Insere o chute inicial na Matriz resposta
//    for(int i = 1; i < MatrizRes.getNumberOfColumns(); i++)
//        MatrizRes(1,i) = this->X0(1,i);

//    //Laço para contar as linhas da Matriz Resposta
//    for(int k = 2; k < MaxIterations+1; k++)
//         {
//             //Laço para contar as colunas da MatrizRes, MatrizErro e linhas da MatrizUni.
//             for(int i = 1; i < MatrizUni.getNumberOfColumns(); i++)
//             {
//                 //Divisão dos termos independentes das funções
//                 MatrizRes(k,i) = MatrizUni(i, MatrizUni.getNumberOfColumns())/MatrizUni(i,i);

//                 //Laço para contar as colunas da MatrizUni
//                 for(int j = 1; j < MatrizUni.getNumberOfColumns(); j++)
//                 {
//                     if(i != j)
//                         //calculando a formula de JACOBI.
//                         MatrizRes(k,i) -= ((MatrizUni(i,j)*MatrizRes(k-1,i)))/MatrizUni(i,i);
//                 }

//                 //Verifica se o valor de erro d(k) é o maior encontrado
//                 if(abs(MatrizRes(k,i) - MatrizRes(k-1,i)) > MatrizRes(k-1, MatrizRes.getNumberOfColumns()))
//                     MatrizRes(k-1, MatrizRes.getNumberOfColumns()) = abs(MatrizRes(k,i) - MatrizRes(k-1,i));
//             }

//             //Limita o numero de iterações até a precisão ser obtida
//             if(MatrizRes(k-1, MatrizRes.getNumberOfColumns()) < MinPrecision)
//                 k = MaxIterations+1;
//         }


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

void SistemasLineares::CritLinhas(LinAlg::Matrix<float> MatrizUni)
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
        {
            cout<<"O sistema não possui solução para qualquer valor inicial de X0";
            break;
        }
    }
}

void SistemasLineares::CritSassenfeld(LinAlg::Matrix<float> MatrizUni)
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
        {
            cout<<"O sistema não possui solução para qualquer valor inicial de X0";
            break;
        }
    }
}

