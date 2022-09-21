#include "Huffman.hpp"

// Função para alocar um novo nó min heap com dada string e sua frequencia
MinHeapNode *novo_no(string data, float freq)
{
    MinHeapNode *temp = (MinHeapNode *)malloc(sizeof(MinHeapNode));

    temp->esq = temp->dir = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// Uma função apra criar uma min heap de dada capacidade
MinHeap *cria_minheap(int capacidade)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));

    minHeap->tamanho = 0; // current tamanhois 0
    minHeap->capacidade = capacidade;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacidade * sizeof(MinHeapNode *));

    return minHeap;
}

// Uma função para trocar dois nós min heap
void troca_no(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Função padrão para minheapify
void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < minHeap->tamanho && minHeap->array[esq]->freq < minHeap->array[smallest]->freq)
        smallest = esq;
    if (dir < minHeap->tamanho && minHeap->array[dir]->freq < minHeap->array[smallest]->freq)
        smallest = dir;
    if (smallest != idx)
    {
        troca_no(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Uma função para checar se tamanho da heap é 1 ou não
int tamanho_um(MinHeap *minHeap)
{
    return (minHeap->tamanho == 1);
}

// Função padrão para extrair o menor valor do nó da heap
MinHeapNode *extrai_min(MinHeap *minHeap)
{
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->tamanho - 1];

    --minHeap->tamanho;
    minHeapify(minHeap, 0);

    return temp;
}

// Função para inserir um novo nó na min heap
void insere_minheap(MinHeap *minHeap, MinHeapNode *minHeapNode)
{

    ++minHeap->tamanho;
    int i = minHeap->tamanho - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Função padrão para construir a min heap
void constroi_minheap(MinHeap *minHeap)
{
    int n = minHeap->tamanho - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Função para imprimir uma array de tamanho n
void imprime_arr(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];
    cout << "\n";
}

// Função para checar se o nó é uma folha
int e_folha(MinHeapNode *root)
{
    return !(root->esq) && !(root->dir);
}

// Cria uma min heap de capacidade igual ao tamanho e insere todas as palavras nele. Tamanho inicial da min heap é igual a capacidade
MinHeap *cria_constroi_minheap(string *data, float *freq, int tamanho)
{

    MinHeap *minHeap = cria_minheap(tamanho);

    for (int i = 0; i < tamanho; i++)
    {
        minHeap->array[i] = novo_no(data[i], freq[i]);
    }

    minHeap->tamanho = tamanho;
    constroi_minheap(minHeap);

    return minHeap;
}

// Função principal que constrói a árvore de huffman
MinHeapNode *arvore_huffman(string *data, float *freq, int tamanho)
{
    MinHeapNode *esq, *dir, *top;

    // Passo 1: Cria uma min heap com uma capacidade igual ao tamanho.
    MinHeap *minHeap = cria_constroi_minheap(data, freq, tamanho);

    // Itera enquanto tamanho da heap não se torna 1
    while (!tamanho_um(minHeap))
    {
        // Passo 2: Extrai os dois itens de menor frequência da min heap
        esq = extrai_min(minHeap);
        dir = extrai_min(minHeap);

        // Passo 3: Cria um novo nó interno com frequência igual a soma de dois nós de frequência
        // Torna os dois nós extraídos como filhos esquerda e direito de novo nós. Adiciona o nó a min heap e recebe '$', um valor especial para nós internos, não é utilizado
        top = novo_no("$", esq->freq + dir->freq);
        top->esq = esq;
        top->dir = dir;

        insere_minheap(minHeap, top);
    }

    // Passo 4: O nó remanescente é
    return extrai_min(minHeap);
}

// Imprime o código de huffman da raiz da árvoe de huffman. Usa uma arr[] para armazenar os códigos
void imprime_codigo(MinHeapNode *root, int arr[], int top)
{
    // Atribui 0 para esquerda e recorre
    if (root->esq)
    {
        arr[top] = 0;
        imprime_codigo(root->esq, arr, top + 1);
    }

    // Atribui 1 para direita e recorre
    if (root->dir)
    {
        arr[top] = 1;
        imprime_codigo(root->dir, arr, top + 1);
    }

    // Se for uma folha, então contem uma das input strings, imprime a instring e o código da arr[]
    if (e_folha(root))
    {
        cout << root->data << ": ";
        imprime_arr(arr, top);
    }
}

MinHeapNode *codigo_huffman(string *data, float *freq, int tamanho)
{
    // Constrói a árvore de huffman
    MinHeapNode *root = arvore_huffman(data, freq, tamanho); // aponta para o nó raiz da árvore
    return root;
}

void salva_arquivo(MinHeapNode *root, map<string, float> mapa, vector<string> palavras)
{
    ofstream codificacao("codificado.bin", ios::binary);

    if (codificacao.is_open())
    {
        map<string, float>::iterator itr;
        for (auto i : palavras)
        {
            itr = mapa.find(i);
            if (itr != mapa.end())
            {
                int arr[MAX_TREE_HT], top = 0;
                procura(root, itr->first, itr->second, arr, top, codificacao);
            }
        }
    }
    else
        cout << "Problema ao abrir o arquivo.\n";

    codificacao.close();
}

void procura(MinHeapNode *root, string data, float freq, int arr[], int top, ofstream &codificacao)
{

    // Atribui 0 para esquerda e recorre
    if (root->esq)
    {
        arr[top] = 0;
        procura(root->esq, data, freq, arr, top + 1, codificacao);
    }

    // Atribui 1 para direita e recorre
    if (root->dir)
    {
        arr[top] = 1;
        procura(root->dir, data, freq, arr, top + 1, codificacao);
    }

    // Se for uma folha, então contem uma das input strings, imprime a instring e o código da arr[]
    if (e_folha(root) && root->freq == freq && root->data == data)
    {
        int i;
        for (i = 0; i < top; ++i)
        {
            codificacao.write(reinterpret_cast<const char *>(&arr[i]), sizeof(arr[i]));
        }
    }
}
