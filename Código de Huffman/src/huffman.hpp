#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <algorithm>
#include <sstream>
#include <string>
#include <string.h>
#include <map>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <cstdlib>

#define MAX_TREE_HT 1000

using namespace std;

// árvore de huffman
typedef struct MinHeapNode
{
    char *data;             // ponteiro para uma cadeia de caracters
    float freq;             // frequência da string
    MinHeapNode *esq, *dir; // filhos esquerdo e direito do nó
} MinHeapNode;

// a Min Heap: Coleção de nós de min heap
typedef struct MinHeap
{
    unsigned tamanho;    // tamanho atual da min heap
    unsigned capacidade; // capacidade da min heap
    MinHeapNode **array; // lista de ponteiros para nós da min heap
} MinHeap;

MinHeapNode *novo_no(string data, float freq);
MinHeap *cria_minheap(unsigned capacidade);
void troca_no(MinHeapNode **a, MinHeapNode **b);
void minHeapify(MinHeap *minHeap, int idx);
int tamanho_um(MinHeap *minHeap);
MinHeapNode *extrai_min(MinHeap *minHeap);
void insere_minheap(MinHeap *minHeap, MinHeapNode *minHeapNode);
void constroi_minheap(MinHeap *minHeap);
void imprime_arr(int arr[], int n);
int e_folha(MinHeapNode *root);
MinHeap *cria_constroi_minheap(string data[], float freq[], int tamanho);
MinHeapNode *arvore_huffman(string data[], float freq[], int tamanho);
void imprime_codigo(MinHeapNode *root, int arr[], int top);
MinHeapNode *codigo_huffman(string data[], float freq[], int tamanho);
void salva_arquivo(MinHeapNode *root, map<string, float> mapa, vector<string> palavras);
void procura(MinHeapNode *root, string data, float freq, int arr[], int top, string &nome);

#endif