#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <sstream>
#include <time.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

#include "avl.hpp"
#include "binary.hpp"
#include "redblack.hpp"

using namespace std;

void cria_arqs(); // função para criar os arquivos de 500, 5000, 50000, 500000 números e consulta
void menu();      // mostra o menu
void remove();    // mostra se o usuário deseja remover
string arquivo(); // retorna string com o nome do arquivo

void binary(); // conjunto de funções presentes na árvore binária de busca
void avl();    // conjunto de funções presentes na árvore AVL
void rb();     // conjunto de funções presentes na árvore Rubro Negra

void vetor(); // conjunto de funções presentes em um vector
void mapa();  // conjunto de funções presentes em um map
void umapa(); // conjunto de funções presentes em um unordered map

Tree *insert_binary(string nome, Tree *raiz, Record r);       // função para abrir aquivo e inserir valores na árvore binária de busca
TreeAVL *insert_avl(string nome, TreeAVL *raiz, RecordAVL r); // função para abrir aquivo e inserir valores na árvore AVL
void insert_rb(string nome);                                  // função para abrir aquivo e inserir valores na árvore Rubro Negra

vector<double> insert_vetor(string nome, vector<double> vetor);  // função para abrir aquivo e inserir valores em um vector
void insert_mapa(string nome, map<double, int> *mapa);             // função para abrir aquivo e inserir valores em um map
void insert_umapa(string nome, unordered_map<double, int> *umapa); // função para abrir aquivo e inserir valores em um unordered map

void remove_binary(Tree *raiz); // função para remover valores na árvore binária de busca
void remove_avl(TreeAVL *raiz); // função para remover valores na árvore AVL
void remove_rb(TreeRB *raiz);   // função para remover valores na árvore Rubro Negra

void remove_vetor(vector<double> vetor);              // função para remover valores em um vector
void remove_mapa(map<double, int> *mapa);             // função para remover valores em um map
void remove_umapa(unordered_map<double, int> *umapa); // função para remover valores em um unordered map

#endif