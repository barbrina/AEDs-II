#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef struct data
{
    int valor;
} Data;

void CriarMatriz(int LIN, int COL, Data **m);
void PreencherMatriz(int i, int j, int num, Data **m);
void ImprimirMatriz(int LIN, int COL, Data **m);
void MatrizTransposta(int LIN, int COL, Data **m, Data **t);
Data **MultiplicacaoMatriz(int LIN, int COL, Data **m, Data **t, Data **r);

#endif