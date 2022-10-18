#ifndef AVL_HPP
#define AVL_HPP

#include <stdio.h>
#include <stdlib.h>

typedef struct RecordAVL RecordAVL;
typedef struct TreeAVL TreeAVL;

struct RecordAVL
{
    float key;
    int value;
};

struct TreeAVL
{
    RecordAVL reg;
    TreeAVL *left, *right;
    int weight;
};

TreeAVL *CreateAVL();
void insertTreeAVL(TreeAVL **t, RecordAVL r);
bool pesquisaAVL(TreeAVL **t, TreeAVL **aux, RecordAVL r);
int isInTree(TreeAVL *t, RecordAVL r);

// muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeTreeAVL(TreeAVL **t, TreeAVL **f, RecordAVL r);
void antecessor(TreeAVL **t, TreeAVL *aux);
void rebalanceTree(TreeAVL **t);

void preordemAVL(TreeAVL *t);
void centralAVL(TreeAVL *t);
void posordemAVL(TreeAVL *t);

int getWeight(TreeAVL **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(TreeAVL **t);
void rotacaoSimplesEsquerda(TreeAVL **t);
void rotacaoDuplaDireita(TreeAVL **t);
void rotacaoDuplaEsquerda(TreeAVL **t);

#endif