#include "Matriz.hpp"

void CriarMatriz(int LIN, int COL, Data **m)
{
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            m[i][j].valor = 0;
        }
    }
}

void PreencherMatriz(int i, int j, int num, Data **m)
{
    m[i][j].valor = num;
}

void ImprimirMatriz(int LIN, int COL, Data **m)
{
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << m[i][j].valor << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void MatrizTransposta(int LIN, int COL, Data **m, Data **t)
{
    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            t[j][i].valor = m[i][j].valor;
        }
    }
}

Data **MultiplicacaoMatriz(int LIN, int COL, Data **m, Data **t, Data **r)
{

    for (int i = 0; i < LIN; i++)
    {
        for (int j = 0; j < LIN; j++)
        {
            int num = 0;
            for (int k = 0; k < COL; k++)
            {
                num += m[i][k].valor * t[k][j].valor;
            }
            PreencherMatriz(i, j, num, r);
        }
    }
    return r;
}
