#include "redblack.hpp"

TreeRB *nill;

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

    else
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

    else
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

    return;
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
            if (!tio->cor)
            {
                tio->cor = true;                   // caso 1
                filho->pai->cor = false;           // caso 1
                rotacaoEsquerda(raiz, filho->pai); // caso 1
                tio = filho->pai->dir;             // caso 1
            }

            if ((tio->esq->cor) && (tio->dir->cor))
            {
                tio->cor = false;   // caso 2
                filho = filho->pai; // caso 2
            }
            else
            {
                if (tio->dir->cor)
                {
                    tio->esq->cor = true;      // caso 3
                    tio->cor = false;          // caso 3
                    rotacaoDireita(raiz, tio); // caso 3
                    tio = filho->pai->dir;     // caso 3
                }

                tio->cor = filho->pai->cor;        // caso 4
                filho->pai->cor = true;            // caso 4
                tio->dir->cor = true;              // caso 4
                rotacaoEsquerda(raiz, filho->pai); // caso 4
                filho = *raiz;                     // caso 4
            }
        }
        else
        {
            tio = filho->pai->esq;

            if (!tio->cor)
            {
                tio->cor = true;                  // caso 1
                filho->pai->cor = false;          // caso 1
                rotacaoDireita(raiz, filho->pai); // caso 1
                tio = filho->pai->esq;            // caso 1
            }

            if ((tio->dir->cor) && (tio->dir->cor))
            {
                tio->cor = false;   // caso 2
                filho = filho->pai; // caso 2
            }
            else
            {
                if (tio->esq->cor)
                {
                    tio->dir->cor = true;       // caso 3
                    tio->cor = false;           // caso 3
                    rotacaoEsquerda(raiz, tio); // caso 3
                    tio = filho->pai->esq;      // caso 3
                }

                tio->cor = filho->pai->cor;       // caso 4
                filho->pai->cor = true;           // caso 4
                tio->esq->cor = true;             // caso 4
                rotacaoDireita(raiz, filho->pai); // caso 4
                filho = *raiz;                    // caso 4
            }
        }
    }

    filho->cor = true;
}

void removeTreeRB(TreeRB **t, RecordRB r)
{
    TreeRB *z = nill;
    TreeRB *x, *y;

    while ((*t) != nill)
    {
        if ((*t)->reg.key == r.key)
            z = (*t);
        if ((*t)->reg.key <= r.key)
            (*t) = (*t)->dir;
        else
            (*t) = (*t)->esq;
    }

    if (z == nill)
    {
        cout << "Chave não foi encontrada na árvore" << endl;
        return;
    }

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

/*void consertaRB(TreeRB **t, TreeRB *x, TreeRB *z)
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
}*/

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
        printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
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

/*void inicializaTreeRB(TreeRB *t, TreeRB *pai)
{
    t->valor = 0;
    t->pai = pai;
    t->esq = nill;
    t->dir = nill;
    t->cor = 0; // vermelho: 1 preto: 0
}

TreeRB *pesquisaTreeRB(TreeRB *t, int key)
{
    if (t == nill || key == t->valor)
        return t;

    if (key < t->valor)
    {
        return pesquisaTreeRB(t->esq, key);
    }
    return pesquisaTreeRB(t->dir, key);
}

// Balancear a árvore t após a eliminação
// página 232 - Algoritmos - Cormen
void deleteFix(TreeRB *raiz, TreeRB *filho)
{
    TreeRB *tio;

    while ((filho != raiz) && (filho->cor == 0))
    {
        if (filho == filho->pai->esq)
        {
            tio = filho->pai->dir;
            if (tio->cor == 1)
            {
                tio->cor = 0;                        // caso 1
                filho->pai->cor = 1;                 // caso 1
                rotacionaEsquerda(raiz, filho->pai); // caso 1
                tio = filho->pai->dir;               // caso 1
            }

            if ((tio->esq->cor == 0) && (tio->dir->cor == 0))
            {
                tio->cor = 1;       // caso 2
                filho = filho->pai; // caso 2
            }
            else
            {
                if (tio->dir->cor == 0)
                {
                    tio->esq->cor = 0;           // caso 3
                    tio->cor = 1;                // caso 3
                    rotacionaDireita(raiz, tio); // caso 3
                    tio = filho->pai->dir;       // caso 3
                }

                tio->cor = filho->pai->cor;          // caso 4
                filho->pai->cor = 0;                 // caso 4
                tio->dir->cor = 0;                   // caso 4
                rotacionaEsquerda(raiz, filho->pai); // caso 4
                filho = raiz;                        // caso 4
            }
        }
        else
        {
            tio = filho->pai->esq;

            if (tio->cor == 1)
            {
                tio->cor = 0;                       // caso 1
                filho->pai->cor = 1;                // caso 1
                rotacionaDireita(raiz, filho->pai); // caso 1
                tio = filho->pai->esq;              // caso 1
            }

            if (tio->dir->cor == 0 && tio->dir->cor == 0)
            {
                tio->cor = 1;       // caso 2
                filho = filho->pai; // caso 2
            }
            else
            {
                if (tio->esq->cor == 0)
                {
                    tio->dir->cor = 0;            // caso 3
                    tio->cor = 1;                 // caso 3
                    rotacionaEsquerda(raiz, tio); // caso 3
                    tio = filho->pai->esq;        // caso 3
                }

                tio->cor = filho->pai->cor;         // caso 4
                filho->pai->cor = 0;                // caso 4
                tio->esq->cor = 0;                  // caso 4
                rotacionaDireita(raiz, filho->pai); // caso 4
                filho = raiz;                       // caso 4
            }
        }
    }

    filho->cor = 0;
}

void transplantRB(TreeRB *raiz, TreeRB *u, TreeRB *v)
{

    if (u->pai == nill)
        raiz = v;
    else if (u == u->pai->esq)
        u->pai->esq = v;
    else
        u->pai->dir = v;

    v->pai = u->pai;
}

void deleteNode(TreeRB *t, int key)
{
    TreeRB *z = nill;
    TreeRB *x, *y;

    while (t != nill)
    {
        if (t->valor == key)
            z = t;
        if (t->valor <= key)
            t = t->dir;
        else
            t = t->esq;
    }

    if (z == nill)
    {
        cout << "Chave não foi encontrada na árvore" << endl;
        return;
    }

    y = z;
    int y_original_color = y->cor;

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

    delete z;

    if (y_original_color == 0)
        deleteFix(t, x);
}

// Balancea a árvore t após a inserção
// página 226 - Algoritmos - Cormen
void insertFix(TreeRB *t, TreeRB *z)
{
    TreeRB *y;

    while (z->pai->cor == 1)
    {
        if (z->pai == z->pai->pai->dir)
        {
            y = z->pai->pai->esq;

            if (y->cor == 1)
            {
                y->cor = 0;           // caso 1
                z->pai->cor = 0;      // caso 1
                z->pai->pai->cor = 1; // caso 1
                z = z->pai->pai;      // caso 1
            }
            else
            {
                if (z == z->pai->esq)
                {
                    z = z->pai;             // caso 2
                    rotacionaDireita(t, z); // caso 2
                }
                z->pai->cor = 0;                   // caso 3
                z->pai->pai->cor = 1;              // caso 3
                rotacionaEsquerda(t, z->pai->pai); // caso 3
            }
        }
        else
        {
            y = z->pai->pai->dir;

            if (y->cor == 1)
            {
                y->cor = 0;           // caso 1
                z->pai->cor = 0;      // caso 1
                z->pai->pai->cor = 1; // caso 1
                z = z->pai->pai;      // caso 1
            }
            else
            {
                if (z == z->pai->dir)
                {
                    z = z->pai;              // caso 2
                    rotacionaEsquerda(t, z); // caso 2
                }
                z->pai->cor = 0;                  // caso 3
                z->pai->pai->cor = 1;             // caso 3
                rotacionaDireita(t, z->pai->pai); // caso 3
            }
        }
        if (z == t)
            break;
    }
    t->cor = 0;
}

TreeRB *CreateRB(TreeRB *t)
{
    nill = new TreeRB;
    nill->cor = 0;
    nill->esq = nill;
    nill->dir = nill;
    t = nill;
    return t;
}

void preordem(TreeRB *t)
{
    if (t != nill)
    {
        cout << t->valor << " ";
        preordem(t->esq);
        preordem(t->dir);
    }
}

void central(TreeRB *t)
{
    if (t != nill)
    {
        central(t->esq);
        cout << t->valor << " ";
        central(t->dir);
    }
}

void posordem(TreeRB *t)
{
    if (t != nill)
    {
        posordem(t->esq);
        posordem(t->dir);
        cout << t->valor << " ";
    }
}

TreeRB *minimoRB(TreeRB *t)
{
    while (t->esq != nill)
    {
        t = t->esq;
    }
    return t;
}

TreeRB *maximoRB(TreeRB *t)
{
    while (t->dir != nill)
    {
        t = t->dir;
    }
    return t;
}

// página 208 - Algoritmos - Cormen
TreeRB *successor(TreeRB *x)
{
    if (x->dir != nill)
    {
        return minimoRB(x->dir);
    }

    TreeRB *y = x->pai;
    while (y != nill && x == y->dir)
    {
        x = y;
        y = y->pai;
    }
    return y;
}

// página 208 - Algoritmos - Cormen
TreeRB *predecessor(TreeRB *x)
{
    if (x->esq != nill)
    {
        return maximoRB(x->esq);
    }

    TreeRB *y = x->pai;
    while (y != nill && x == y->esq)
    {
        x = y;
        y = y->pai;
    }

    return y;
}

// página 224 - Algoritmo - Cormen
void rotacionaEsquerda(TreeRB *t, TreeRB *x)
{
    TreeRB *y;

    y = x->dir;      // define y
    x->dir = y->esq; // faz da subárvore esquerda de y a subárvore direita de x

    if (y->esq != nill)
        y->esq->pai = x;

    y->pai = x->pai; // liga o pai de x a y

    if (x->pai == nill)
        t = y;
    else if (x == x->pai->esq)
        x->pai->esq = y;
    else
        x->pai->dir = y;

    y->esq = x; // coloca x à esquerda de y
    x->pai = y;
}

// página 224 - Algoritmos - Cormen
void rotacionaDireita(TreeRB *t, TreeRB *x)
{
    TreeRB *y;

    y = x->esq;      // define y
    x->esq = y->dir; // faz a subárvore esquerda de y a subárvore direita de x

    if (y->dir != nill)
        y->dir->pai = x;

    y->pai = x->pai; // liga o pai de x a y

    if (x->pai == nill)
        t = y;
    else if (x == x->pai->dir)
        x->pai->dir = y;
    else
        x->pai->esq = y;

    y->dir = x; // coloca x a direita de y
    x->pai = y;
}

// Inserting a t
// página 225 - Algoritmos - Cormen
void insertTreeRB(TreeRB *raiz, int key)
{
    TreeRB *t = new TreeRB;
    t->pai = nill;
    t->valor = key;
    t->esq = nill;
    t->dir = nill;
    t->cor = 1;

    TreeRB *y = nill;
    TreeRB *x = raiz;

    while (x != nill)
    {
        y = x;
        if (t->valor < x->valor)
            x = x->esq;
        else
            x = x->dir;
    }

    t->pai = y;

    if (y == nill)
        raiz = t;
    else if (t->valor < y->valor)
        y->esq = t;
    else
        y->dir = t;

    if (t->pai == nill)
    {
        t->cor = 0;
        return;
    }

    if (t->pai->pai == nill)
        return;

    insertFix(raiz, t);
}
*/