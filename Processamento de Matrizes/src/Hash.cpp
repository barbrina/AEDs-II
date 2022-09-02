#include "Hash.hpp"

void initialize(HashTable *h, int M)
{
    h->table = (DataTable *)malloc(M * sizeof(DataTable));

    for (int i = 0; i < M; i++)
    {
        h->table[i].key = NULL;
        h->table[i].data = false;
        h->table[i].LIN = 0;
        h->table[i].m = NULL;
    }

    h->M = M;
}

void insert(HashTable *h, int *key, int idx, Data **matriz, int LIN)
{
    int aux = idx;
    while (h->table[idx].key != NULL)
    {
        idx = (idx + 1) % h->M;
        if (idx == aux)
        {
            cout << "OPENED HASH IS FULL!\n"
                 << endl;
            return;
        }
    }

    h->table[idx].key = key;
    h->table[idx].LIN = LIN;
    h->table[idx].m = matriz;
}

void imprime(HashTable *h)
{
    cout << "HASH: " << endl;
    for (int i = 0; i < h->M; i++)
    {
        if (h->table[i].key != NULL)
        {
            for (int j = 0; j < h->table[i].LIN; j++)
            {
                for (int k = 0; k < h->table[i].LIN; k++)
                {
                    cout << h->table[i].m[j][k].valor << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}

bool search(HashTable *h, int *key)
{
    for (int i = 0; i < h->M; i++)
    {
        if (&h->table[i].key == &key)

            cout << "igual " << endl;
        return true;
    }
    return false;
}

int primo(int x)
{
    if (x < 2)
        return -1;
    if (x < 4)
        return 1;
    if ((x % 2) == 0)
        return 0;
    for (int i = 3; i <= floor(sqrt((double)x)); i += 2)
    {
        if ((x % i) == 0)
            return 0;
    }
    return 1;
}

// Retorna o proximo primo após x, ou x se x for primo

int proxprimo(int x)
{
    while (primo(x) != 1)
        x++;
    return x;
}