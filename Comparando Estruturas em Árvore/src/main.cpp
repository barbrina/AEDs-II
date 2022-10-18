#include "arquivo.hpp"

int main()
{
    string nome;
    int estrutura = 0, decisao = 0;

    // cria_arqs();

    do
    {
        menu();
        cin >> estrutura;

        if (estrutura == 1)
            binary();
        else if (estrutura == 2)
            avl();
        else if (estrutura == 3)
            rb();
        else if (estrutura == 4)
            vetor();
        else if (estrutura == 5)
            mapa();
        else if (estrutura == 6)
            umapa();

    } while (estrutura != 7);

    return 0;
}