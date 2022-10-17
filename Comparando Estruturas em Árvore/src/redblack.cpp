#include "redblack.hpp"

TreeRB *CreateRB()
{
    return NULL;
}

void insertFixUp(TreeRB **raiz, TreeRB *child)
{
    TreeRB *tio;

    while ((child != *raiz) && (child->pai->cor == false))
    {

        if (child->pai == child->pai->pai->esq)
        {

            tio = child->pai->pai->dir;

            // caso 1:
            if ((tio != NULL) && (tio->cor == false))
            {
                child->pai->cor = true;
                tio->cor = true;
                child->pai->pai->cor = false;
                child = child->pai->pai;
            }
            else
            {

                // caso 2
                if (child == child->pai->dir)
                {
                    child = child->pai;
                    rotacaoSimplesEsquerda(raiz, child);
                }

                // caso 3
                child->pai->cor = true;
                child->pai->pai->cor = false;
                rotacaoSimplesDireita(raiz, child->pai->pai);
            }
        }
        else
        {

            tio = child->pai->pai->esq;

            // caso 1
            if ((tio != NULL) && (tio->cor == false))
            {
                child->pai->cor = true;
                tio->cor = true;
                child->pai->pai->cor = false;
                child = child->pai->pai;
            }
            else
            {

                // caso 2
                if (child == child->pai->esq)
                {
                    child = child->pai;
                    rotacaoSimplesDireita(raiz, child);
                }

                // caso 3
                child->pai->cor = true;
                child->pai->pai->cor = false;
                rotacaoSimplesEsquerda(raiz, child->pai->pai);
            }
        }
    }

    (*raiz)->cor = true;
}

void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, RecordRB r)
{

    if (*t == NULL)
    {
        *t = (TreeRB *)malloc(sizeof(TreeRB));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->pai = pai != t ? *pai : NULL;
        (*t)->cor = false; // false: vermelho  true:preto
        (*t)->reg = r;
        insertFixUp(raiz, *t);
    }
    else
    {

        if (r.key < (*t)->reg.key)
        {
            insertTreeRB(&(*t)->esq, t, raiz, r);
            return;
        }

        if (r.key > (*t)->reg.key)
        {
            insertTreeRB(&(*t)->dir, t, raiz, r);
            return;
        }
    }
}

bool pesquisaRB(TreeRB **t, TreeRB **aux, RecordRB r)
{

    if (*t == NULL)
    {
        // printf("[ERROR]: Node not found!");
        return false;
    }

    if ((*t)->reg.key > r.key)
    {
        pesquisaRB(&(*t)->esq, aux, r);
        return true;
    }
    if ((*t)->reg.key < r.key)
    {
        pesquisaRB(&(*t)->dir, aux, r);
        return true;
    }

    *aux = *t;
    return true;
}

TreeRB *minimoRB(TreeRB *x)
{
    while (x->esq != NULL) // trocar para nill
        x = x->esq;

    return x;
}

void transplanteRB(TreeRB **t, TreeRB *z, TreeRB *filho)
{
    if (z->pai == NULL)
        (*t) = filho;
    else if (z == z->pai->esq)
        z->pai->esq = filho;
    else
        z->pai->dir = filho;

    filho->pai = z->pai;
}

void removeTreeRB(TreeRB **t, TreeRB *x, TreeRB *y, TreeRB *z)
{
    y = z;
    bool cor_original = y->cor;

    if (z->esq == NULL)
    {
        x = z->dir;
        transplanteRB(t, z, z->dir);
    }
    else if (z->dir == NULL)
    {
        x = z->esq;
        transplanteRB(t, z, z->esq);
    }
    else
    {
        y = minimoRB(z->dir);
        cor_original = y->cor;
        x = y->dir;

        if (y->pai == z)
            x->pai = y;
        else
        {
            transplanteRB(t, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }

        transplanteRB(t, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }
    if (cor_original)
    {
    }
}

void consertaRB(TreeRB **t, TreeRB *x, TreeRB *z)
{
    while (z != (*t) && x->cor)
    {
        if (x == x->pai->esq)
        {
            z = x->pai->dir;
            if (!z->cor)
            {
                z->cor = false;                    // caso 1
                x->pai->cor = true;                // caso 1
                rotacaoSimplesEsquerda(t, x->pai); // caso 1
                z = x->pai->dir;                   // caso 1
            }
            else if (z->esq->cor && z->dir->cor)
            {
                z->cor = false; // caso 2
                x = x->pai;     // caso 2
            }
            else if (z->dir->cor)
            {
                z->dir->cor = true;          // caso 3
                z->cor = false;              // caso 3
                rotacaoSimplesDireita(t, z); // caso 3
                z = x->pai->dir;             // caso 3
            }
            else
            {
                z->cor = x->pai->cor;              // caso 4
                x->pai->cor = true;                // caso 4
                z->dir->cor = true;                // caso 4
                rotacaoSimplesEsquerda(t, x->pai); // caso 4
                x = (*t);                          // caso 4
            }
        }
        else
        {
            z = x->pai->esq;
            if (!z->cor)
            {
                z->cor = false;                   // caso 1
                x->pai->cor = true;               // caso 1
                rotacaoSimplesDireita(t, x->pai); // caso 1
                z = x->pai->esq;                  // caso 1
            }
            else if (z->dir->cor && z->esq->cor)
            {
                z->cor = false; // caso 2
                x = x->pai;     // caso 2
            }
            else if (z->esq->cor)
            {
                z->dir->cor = true;           // caso 3
                z->cor = false;               // caso 3
                rotacaoSimplesEsquerda(t, z); // caso 3
                z = x->pai->esq;              // caso 3
            }
            else
            {
                z->cor = x->pai->cor;             // caso 4
                x->pai->cor = true;               // caso 4
                z->esq->cor = true;               // caso 4
                rotacaoSimplesDireita(t, x->pai); // caso 4
                x = (*t);                         // caso 4
            }
        }
    }
    x->cor = true;
}

void rotacaoSimplesEsquerda(TreeRB **raiz, TreeRB *child)
{
    TreeRB *x, *y;

    x = child;
    y = child->dir;
    x->dir = y->esq;

    if (y->esq != NULL)
        y->esq->pai = x;

    y->pai = x->pai;

    if (x->pai == NULL)
        *raiz = y;

    else
    {

        if (x == x->pai->esq)
            x->pai->esq = y;

        else
            x->pai->dir = y;
    }

    y->esq = x;
    x->pai = y;
}

void rotacaoSimplesDireita(TreeRB **raiz, TreeRB *child)
{
    TreeRB *x, *y;

    x = child;
    y = child->esq;
    x->esq = y->dir;

    if (y->dir != NULL)
        y->dir->pai = x;

    y->pai = x->pai;

    if (x->pai == NULL)
    {
        *raiz = y;
    }

    else
    {

        if (x == x->pai->dir)
            x->pai->dir = y;

        else
            x->pai->esq = y;
    }

    y->dir = x;
    x->pai = y;
}

void preordem(TreeRB *t)
{
    if (!(t == NULL))
    {
        printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
        preordem(t->esq);
        preordem(t->dir);
    }
}

void central(TreeRB *t)
{
    if (!(t == NULL))
    {
        central(t->esq);
        printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
        central(t->dir);
    }
}

void posordem(TreeRB *t)
{
    if (!(t == NULL))
    {
        posordem(t->esq);
        posordem(t->dir);
        printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    }
}