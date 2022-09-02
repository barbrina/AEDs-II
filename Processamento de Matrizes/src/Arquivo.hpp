#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include "Matriz.hpp"

using namespace std;

void Abre_arq(unordered_map<string, vector<vector<int>>> *umap);
void transforma(Data **m, int LIN, unordered_map<string, vector<vector<int>>> *umap, string coordenada);
bool encontra(unordered_map<string, vector<vector<int>>> *umap, string coordenada);
void imprime(vector<vector<int>> *umap);
void imprimetudo(unordered_map<string, vector<vector<int>>> *umap);

#endif