#include "interpolacaopolinomial.h"

InterpolacaoPolinomial::InterpolacaoPolinomial(LinAlg::Matrix<float> n)
{
    this->n = n;
}

InterpolacaoPolinomial::InterpolacaoPolinomial(LinAlg::Matrix<float> n, LinAlg::Matrix<float> f)
{
    this->n = n;
    this->f = f;
}

InterpolacaoPolinomial::~InterpolacaoPolinomial()
{

}

LinAlg::Matrix<float> InterpolacaoPolinomial::initVector(unsigned iniValue, double step, unsigned endValue)
{
    unsigned size = ((endValue-iniValue)/step)+1;
    //unsigned i = 0, j = 1;
    LinAlg::Matrix<float> A(1,size);
    cout<<size<<endl;
    for(unsigned i = 0; i < size; i++)
    {
        A(1,i+1) = iniValue+(step*i);
    }

    return A;
}

LinAlg::Matrix<float> InterpolacaoPolinomial::Valores_Y(LinAlg::Matrix<float> MatrizVandermonde, LinAlg::Matrix<double> Valores_X)
{
    LinAlg::Matrix<float>Valores_Y;

    return Valores_Y = MatrizVandermonde * Valores_X;
}

LinAlg::Matrix<float> InterpolacaoPolinomial::Polinomio_Vandermonde(LinAlg::Matrix<float> Valores_X, LinAlg::Matrix<float> Valores_Y)
{
    LinAlg::Matrix<float> MatVandermonde(Valores_X.getNumberOfColumns(), Valores_X.getNumberOfColumns());
    LinAlg::Matrix<float> VetorPolinomio(1,Valores_X.getNumberOfColumns());
    SistemasLineares SL;
    ////Monta a Matriz de Vandermonde
    MatVandermonde = MatrizVandermonde(Valores_X);
    cout << endl << (MatVandermonde|Valores_Y) << endl;
    ////Aplica o Metodo de Gauss
    VetorPolinomio = SL.Gauss(MatVandermonde | Valores_Y);
    cout << VetorPolinomio;
    return VetorPolinomio;
}

LinAlg::Matrix<float> InterpolacaoPolinomial::MatrizVandermonde(LinAlg::Matrix<float> Valores_X)
{
    LinAlg::Matrix<float> MatrizVandermonde = Valores_X;

    for(unsigned i = 1; i <= Valores_X.getNumberOfColumns(); ++i)
    {
        for(unsigned j = 1; j <= Valores_X.getNumberOfColumns(); ++j)
        {
            MatrizVandermonde(j,i) = pow(Valores_X(1,j), double(i - 1));
        }
    }
    return MatrizVandermonde;
}

LinAlg::Matrix<float> InterpolacaoPolinomial::Lagrange(float x)
{
    LinAlg::Matrix<float> Lx;
    float px = 0;
    for (int i = 0; i < n.getNumberOfColumns(); i++)
    {
        float p = 1;
        for(int j = 0; j <= n.getNumberOfColumns(); j++)
        {
            if(j != i)
            {
                p = ((x - n(1,j)) / (n(1,i) - n(1,j)));
                px = p*f(1,j)+px;
            }
        }
    }

    std::cout << std::endl << "f(" << x << ") = " << px;
    return Lx;
}

LinAlg::Matrix<float> InterpolacaoPolinomial::Polinomio_Lagrange(LinAlg::Matrix<float> Valores_X, LinAlg::Matrix<float> Valores_Y, float x)
{
    LinAlg::Matrix<float> VetorPolinomio(1, Valores_X.getNumberOfColumns());
    LinAlg::Matrix<float> P(1,Valores_X.getNumberOfColumns());

    for(unsigned i = 1; i <= Valores_X.getNumberOfColumns() ; ++i)
    {
        P(1,i) = 1;
        for(unsigned j = 1; j <= Valores_X.getNumberOfColumns(); ++j)
        {
            if(i != j)
                P(1, i) = ((x - Valores_X(1, j)) / (Valores_X(1, i) - Valores_X(1, j))) * P(1, i);
        }
    }

    for(unsigned i = 1; i <= Valores_X.getNumberOfColumns(); ++i)
        VetorPolinomio(1, i) = VetorPolinomio(1, i) + P(1, i) * Valores_Y(i,1);

    return VetorPolinomio;
}
