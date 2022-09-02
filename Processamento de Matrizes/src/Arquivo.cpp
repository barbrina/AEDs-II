#include "Arquivo.hpp"

int arqTam()
{

    string coordenada;
    ifstream coordenadas("coordenadas.txt");

    int i = 0;
    while (getline(coordenadas, coordenada))
    {
        i++;
    }
    return i;
}

void Abre_arq(int tamanho)
{

    HashTable ha;

    int M = proxprimo(2 * tamanho);
    initialize(&ha, M);

    string coordenada, arquivo;
    int aux;                   // declara inteiro auxiliar
    int i_1, i_2, j_1, j_2;    // declara coordenadas
    int i = 0, j = 0, tam = 0; // declara posição de leitura no arquivo
    int lin, col;

    // Abre um arquivo de coordenadas para Leitura
    ifstream coordenadas("coordenadas.txt");

    // leitura de coordenadas.txt
    while (getline(coordenadas, coordenada))
    {
        // Declara matriz, sua transposta e a matriz resultante da multiplicação
        Data **matriz, **transversa, **mult;

        ifstream arquivos("arquivo.txt");
        istringstream c(coordenada);

        aux = 0; // define auxiliar para recomeçar a contagem da coordenada na linha

        for (int num; c >> num;) // responsável por pegar as coordenadas
        {
            if (aux == 0)
                i_1 = num;
            else if (aux == 1)
                j_1 = num;
            else if (aux == 2)
                i_2 = num;
            else if (aux == 3)
                j_2 = num;
            aux++;
        }

        int key[4] = {i_1, j_1, i_2, j_2};
        int v = (i_1 + j_1) * (i_2 + j_2);
        int idx = hash(v, M);

        // search(&ha, key);

        // Define e declara tamanho da matriz
        int LIN = i_2 - i_1 + 1;
        int COL = j_2 - j_1 + 1;

        // Declara uma matriz com tamanho LIN X COL
        matriz = new Data *[LIN];
        transversa = new Data *[COL];
        mult = new Data *[LIN];

        for (int k = 0; k < LIN; k++)
            matriz[k] = new Data[COL];
        for (int k = 0; k < COL; k++)
            transversa[k] = new Data[LIN];
        for (int k = 0; k < LIN; k++)
            mult[k] = new Data[LIN];

        // Cria a matriz e sua transversa
        CriarMatriz(LIN, COL, matriz);
        CriarMatriz(COL, LIN, transversa);
        CriarMatriz(LIN, LIN, mult);

        lin = 0, i = 0;

        // para de ler o arquivo.txt quando não há mais necessidade
        while (getline(arquivos, arquivo) && lin <= i_2)
        {

            istringstream a(arquivo);
            col = 0, j = 0;

            // da linha i_1 até a linha i_2
            if (i >= i_1 && i <= i_2)
            {
                // responsável por pegar os valores de cada coordenada
                for (int num; a >> num;)
                {
                    // da coluna j_1 até a coluna j_2
                    if (j >= j_1 && j <= j_2)
                    {
                        PreencherMatriz(lin, col, num, matriz);
                        col++;
                    }
                    else if (j > j_2)
                    {
                        break;
                    }
                    j++;
                }
                lin++;
            }
            i++;
        }

        // Faz a transposta e calcula a multiplicação
        MatrizTransposta(LIN, COL, matriz, transversa);
        mult = MultiplicacaoMatriz(LIN, COL, matriz, transversa, mult);

        insert(&ha, key, idx, mult, LIN);

        arquivos.close();
    }
    coordenadas.close();

    // imprime(&ha);
}