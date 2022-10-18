#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>

using namespace std;

typedef struct RecordRB RecordRB;
typedef struct TreeRB TreeRB;

struct RecordRB
{
    double key;
};

struct TreeRB
{
    RecordRB reg;
    TreeRB *esq, *dir;
    TreeRB *pai; // específico para rubro negra
    bool cor;    // específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};

TreeRB *CreateRB();

void rotacaoEsquerda(TreeRB **raiz, TreeRB *child);
void rotacaoDireita(TreeRB **raiz, TreeRB *child);

void insertFixUp(TreeRB **raiz, TreeRB *child);
void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, RecordRB r);
bool pesquisaRB(TreeRB **t, TreeRB **aux, RecordRB r);
void transplantRB(TreeRB **t, TreeRB *aux, TreeRB *auxf);
void removeFixUp(TreeRB **raiz, TreeRB *filho);
void removeTreeRB(TreeRB **t, RecordRB r);

TreeRB *minimoRB(TreeRB *t);
void preordemRB(TreeRB *t);
void centralRB(TreeRB *t);
void posordemRB(TreeRB *t);

#endif

/*typedef struct TreeRB TreeRB;

struct TreeRB
{
    float valor;
    TreeRB *pai;
    TreeRB *esq, *dir;
    int cor; // 1 para vermelho, 0 para preto
};

void inicializaTreeRB(TreeRB *t, TreeRB *pai);
TreeRB *pesquisaTreeRB(TreeRB *t, int key);
void deleteFix(TreeRB *x);
void transplantRB(TreeRB *u, TreeRB *v);
void deleteNode(TreeRB *raiz, TreeRB *t, int key);
void insertFix(TreeRB *z);

TreeRB *CreateRB(TreeRB *t);
void preordem(TreeRB *t);
void central(TreeRB *t);
void posordem(TreeRB *t);

TreeRB *minimoRB(TreeRB *t);
TreeRB *maximoRB(TreeRB *t);
TreeRB *successor(TreeRB *x);
TreeRB *predecessor(TreeRB *x);
void rotacionaEsquerda(TreeRB *t, TreeRB *x);
void rotacionaDireita(TreeRB *t, TreeRB *x);
void insertTreeRB(TreeRB *raiz, int key);*/
