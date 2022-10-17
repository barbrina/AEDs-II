#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child);
void rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child);

void insertFixUp(TreeRB **raiz, TreeRB *child);
void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, RecordRB r);
bool pesquisaRB(TreeRB **t, TreeRB **aux, RecordRB r);
TreeRB *minimoRB(TreeRB *x);
void transplanteRB(TreeRB **t, TreeRB *z, TreeRB *filho);
void removeTreeRB(TreeRB **t, TreeRB *x, TreeRB *y, TreeRB *z);
void consertaRB(TreeRB **t, TreeRB *x, TreeRB *z);

void preordem(TreeRB *t);
void central(TreeRB *t);
void posordem(TreeRB *t);

#endif