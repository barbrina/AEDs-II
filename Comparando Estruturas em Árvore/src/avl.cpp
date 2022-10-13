#include "avl.hpp"

TreeAVL *CreateTreeAVL()
{
	return NULL;
}

void insertTreeAVL(TreeAVL **t, RecordAVL r)
{

	if (*t == NULL)
	{
		*t = (TreeAVL *)malloc(sizeof(TreeAVL));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = r;
	}
	else
	{

		if (r.key < (*t)->reg.key)
		{
			insertTreeAVL(&(*t)->left, r);
			if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2)
			{
				if (r.key < (*t)->left->reg.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}

		if (r.key > (*t)->reg.key)
		{
			insertTreeAVL(&(*t)->right, r);
			if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2)
			{
				if (r.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}

	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}

void pesquisa(TreeAVL **t, TreeAVL **aux, RecordAVL r)
{

	if (*t == NULL)
	{
		printf("[ERROR]: Node not found!");
		return;
	}

	if ((*t)->reg.key > r.key)
	{
		pesquisa(&(*t)->left, aux, r);
		return;
	}
	if ((*t)->reg.key < r.key)
	{
		pesquisa(&(*t)->right, aux, r);
		return;
	}

	*aux = *t;
}

int isInTree(TreeAVL *t, RecordAVL r)
{

	if (t == NULL)
	{
		return 0;
	}

	return t->reg.key == r.key || isInTree(t->left, r) || isInTree(t->right, r);
}

void antecessor(TreeAVL **t, TreeAVL *aux)
{

	if ((*t)->right != NULL)
	{
		antecessor(&(*t)->right, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void rebalanceTree(TreeAVL **t)
{
	int balance;
	int left = 0;
	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if ((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if ((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t);
}

void removeTreeAVL(TreeAVL **t, TreeAVL **f, RecordAVL r)
{
	TreeAVL *aux;

	if (*t == NULL)
	{
		printf("[ERROR]: Record not found!!!\n");
		return;
	}

	if (r.key < (*t)->reg.key)
	{
		removeTreeAVL(&(*t)->left, t, r);
		return;
	}
	if (r.key > (*t)->reg.key)
	{
		removeTreeAVL(&(*t)->right, t, r);
		return;
	}

	if ((*t)->right == NULL)
	{
		aux = *t;
		*t = (*t)->left;
		free(aux);
		rebalanceTree(f);
		return;
	}

	if ((*t)->left != NULL)
	{
		antecessor(&(*t)->left, *t);
		rebalanceTree(t);
		rebalanceTree(f);
		return;
	}

	aux = *t;
	*t = (*t)->right;
	free(aux);
	rebalanceTree(t);
	rebalanceTree(f);
}

void preordemAVL(TreeAVL *t)
{
	if (!(t == NULL))
	{
		printf("%f:%d\t", t->reg.key, t->weight);
		preordemAVL(t->left);
		preordemAVL(t->right);
	}
}

void centralAVL(TreeAVL *t)
{
	if (!(t == NULL))
	{
		centralAVL(t->left);
		printf("%f\t", t->reg.key);
		centralAVL(t->right);
	}
}

void posordemAVL(TreeAVL *t)
{
	if (!(t == NULL))
	{
		posordemAVL(t->left);
		posordemAVL(t->right);
		printf("%f\t", t->reg.key);
	}
}

int getWeight(TreeAVL **t)
{
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right)
{
	if (left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(TreeAVL **t)
{
	TreeAVL *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(TreeAVL **t)
{
	TreeAVL *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(TreeAVL **t)
{
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(TreeAVL **t)
{
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}
