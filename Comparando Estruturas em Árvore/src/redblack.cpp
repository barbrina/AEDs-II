#include "redblack.hpp"

TreeRB *nill;

void inicializaTreeRB(TreeRB **raiz)
{
    nill = (TreeRB *)malloc(sizeof(TreeRB));
    nill->cor = true;
    nill->esq = NULL;
    nill->dir = NULL;
    nill->pai = NULL;
    nill->reg.key = 0;
    (*raiz) = nill;
}

TreeRB *CreateRB()
{
    return nullptr;
}

void rotacaoEsquerda(TreeRB **raiz, TreeRB *child)
{
    TreeRB *x, *y;

    x = child;
    y = child->dir;
    x->dir = y->esq;

    if (y->esq != nill)
        y->esq->pai = x;

    y->pai = x->pai;

    if (x->pai == nill)
        *raiz = y;

    else if (x == x->pai->esq)
        x->pai->esq = y;

    else if (x == x->pai->dir)
        x->pai->dir = y;

    y->esq = x;
    x->pai = y;
}

void rotacaoDireita(TreeRB **raiz, TreeRB *child)
{
    TreeRB *x, *y;

    x = child;
    y = child->esq;
    x->esq = y->dir;

    if (y->dir != nill)
        y->dir->pai = x;

    y->pai = x->pai;

    if (x->pai == nill)
        *raiz = y;

    else if (x == x->pai->dir)
        x->pai->dir = y;

    else if (x == x->pai->esq)
        x->pai->esq = y;

    y->dir = x;
    x->pai = y;
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
            if ((tio != nill) && (tio->cor == false))
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
                    rotacaoEsquerda(raiz, child);
                }

                // caso 3
                child->pai->cor = true;
                child->pai->pai->cor = false;
                rotacaoDireita(raiz, child->pai->pai);
            }
        }
        else
        {

            tio = child->pai->pai->esq;

            // caso 1
            if ((tio != nill) && (tio->cor == false))
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
                    rotacaoDireita(raiz, child);
                }

                // caso 3
                child->pai->cor = true;
                child->pai->pai->cor = false;
                rotacaoEsquerda(raiz, child->pai->pai);
            }
        }
    }

    (*raiz)->cor = true;
}

void insertTreeRB(TreeRB **t, TreeRB **pai, TreeRB **raiz, RecordRB r)
{

    if (*t == nill)
    {
        *t = (TreeRB *)malloc(sizeof(TreeRB));
        (*t)->esq = nill;
        (*t)->dir = nill;
        (*t)->pai = pai != t ? *pai : nill;
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

    if (*t == nill)
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

void transplantRB(TreeRB **t, TreeRB *aux, TreeRB *auxf)
{

    if (aux->pai == nill)
        (*t) = auxf;
    else if (aux == aux->pai->esq)
        aux->pai->esq = auxf;
    else
        aux->pai->dir = auxf;

    // return;
    auxf->pai = aux->pai;
}

void removeFixUp(TreeRB **raiz, TreeRB *filho)
{
    TreeRB *tio;

    while ((filho != *raiz) && (filho->cor))
    {
        if (filho == filho->pai->esq)
        {
            tio = filho->pai->dir;
            // caso 1
            if (!tio->cor)
            {
                tio->cor = true;
                filho->pai->cor = false;
                rotacaoEsquerda(raiz, filho->pai);
                tio = filho->pai->dir;
            }
            // caso 2
            if ((tio->esq->cor) && (tio->dir->cor))
            {
                tio->cor = false;
                filho = filho->pai;
            }
            // caso 3
            else
            {
                if (tio->dir->cor)
                {
                    tio->esq->cor = true;
                    tio->cor = false;
                    rotacaoDireita(raiz, tio);
                    tio = filho->pai->dir;
                }
                // caso 4
                tio->cor = filho->pai->cor;
                filho->pai->cor = true;
                tio->dir->cor = true;
                rotacaoEsquerda(raiz, filho->pai);
                filho = *raiz;
            }
        }
        else
        {
            tio = filho->pai->esq;
            // caso 1
            if (!tio->cor)
            {
                tio->cor = true;
                filho->pai->cor = false;
                rotacaoDireita(raiz, filho->pai);
                tio = filho->pai->esq;
            }
            // caso 2
            if ((tio->dir->cor) && (tio->esq->cor))
            {
                tio->cor = false;
                filho = filho->pai;
            }
            // caso 3
            else
            {
                if (tio->esq->cor)
                {
                    tio->dir->cor = true;
                    tio->cor = false;
                    rotacaoEsquerda(raiz, tio);
                    tio = filho->pai->esq;
                }
                // caso 4
                tio->cor = filho->pai->cor;
                filho->pai->cor = true;
                tio->esq->cor = true;
                rotacaoDireita(raiz, filho->pai);
                filho = *raiz;
            }
        }
    }

    filho->cor = true;
}

void removeTreeRB(TreeRB **t, RecordRB r)
{

    TreeRB *z = nill;
    TreeRB *x, *y;
    TreeRB *aux = *t;

    while (aux != nill && r.key != aux->reg.key)
    {
        if (r.key < aux->reg.key)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (aux->reg.key == r.key)
    {
        x = aux;
        y = aux;
        z = aux;
    }
    else
    {
        return;
    }

    cout << r.key << " ";

    y = z;
    bool y_original_color = y->cor;

    if (z->esq == nill)
    {
        x = z->dir;
        transplantRB(t, z, z->dir);
    }
    else if (z->dir == nill)
    {
        x = z->esq;
        transplantRB(t, z, z->esq);
    }
    else
    {
        y = minimoRB(z->dir);
        y_original_color = y->cor;
        x = y->dir;

        if (y->pai == z)
            x->pai = y;
        else
        {
            transplantRB(t, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }

        transplantRB(t, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }

    if (y_original_color)
        removeFixUp(t, x);

    delete z;
}

TreeRB *minimoRB(TreeRB *t)
{
    while (t->esq != nill)
        t = t->esq;

    return t;
}

void preordemRB(TreeRB *t)
{
    if (!(t == nill))
    {
        printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
        preordemRB(t->esq);
        preordemRB(t->dir);
    }
}

void centralRB(TreeRB *t)
{
    if (!(t == nill))
    {
        centralRB(t->esq);
        printf("%f \t", t->reg.key);
        centralRB(t->dir);
    }
}

void posordemRB(TreeRB *t)
{
    if (!(t == nill))
    {
        posordemRB(t->esq);
        posordemRB(t->dir);
        printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    }
}
