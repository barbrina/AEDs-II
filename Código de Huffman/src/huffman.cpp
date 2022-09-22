#include "huffman.hpp"

// função para alocar um novo nó min heap com dada string e sua frequencia
MinHeapNode *novo_no(string data, float freq)
{
    MinHeapNode *temp = (MinHeapNode *)malloc(sizeof(MinHeapNode));

    temp->esq = temp->dir = NULL;
    temp->data = (char *)malloc(data.size() * sizeof(char));
    strcpy(temp->data, data.c_str());
    temp->freq = freq;

    return temp;
}

// função apra criar uma min heap de dada capacidade
MinHeap *cria_minheap(unsigned capacidade)
{
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));

    minHeap->tamanho = 0; // tamanho atual é 0
    minHeap->capacidade = capacidade;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacidade * sizeof(MinHeapNode *));

    return minHeap;
}

// função para trocar dois nós min heap
void troca_no(MinHeapNode **a, MinHeapNode **b)
{
    MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// função para encontrar a menor frequência
void minHeapify(MinHeap *minHeap, int idx)
{
    int menor = idx;
    int esq = 2 * idx + 1;
    int dir = 2 * idx + 2;

    if (esq < minHeap->tamanho && minHeap->array[esq]->freq < minHeap->array[menor]->freq)
        menor = esq;
    if (dir < minHeap->tamanho && minHeap->array[dir]->freq < minHeap->array[menor]->freq)
        menor = dir;
    if (menor != idx)
    {
        troca_no(&minHeap->array[menor], &minHeap->array[idx]);
        minHeapify(minHeap, menor);
    }
}

// função para checar se tamanho da heap é 1 ou não
int tamanho_um(MinHeap *minHeap)
{
    return (minHeap->tamanho == 1);
}

// função para extrair o menor valor do nó da heap
MinHeapNode *extrai_min(MinHeap *minHeap)
{
    MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->tamanho - 1];

    --minHeap->tamanho;
    minHeapify(minHeap, 0);

    return temp;
}

// função para inserir um novo nó na min heap
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

// função para construir a min heap
void constroi_minheap(MinHeap *minHeap)
{
    int n = minHeap->tamanho - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i) // começa da metade e vai até o 0
        minHeapify(minHeap, i);
}

// função para imprimir uma array de tamanho n, que contem a codificação das palavras
void imprime_arr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i];
    cout << "\n";
}

// função para checar se o nó é uma folha
int e_folha(MinHeapNode *root)
{
    return !(root->esq) && !(root->dir);
}

// cria uma min heap de capacidade igual ao tamanho e insere todas as palavras nele. Tamanho inicial da min heap é igual a capacidade
MinHeap *cria_constroi_minheap(string data[], float freq[], int tamanho)
{
    MinHeap *minHeap = cria_minheap(tamanho);

    for (int i = 0; i < tamanho; ++i)
    {
        minHeap->array[i] = novo_no(data[i], freq[i]);
    }

    minHeap->tamanho = tamanho;
    constroi_minheap(minHeap);

    return minHeap;
}

// função principal que constrói a árvore de huffman
MinHeapNode *arvore_huffman(string data[], float freq[], int tamanho)
{

    MinHeapNode *esq, *dir, *top;
    // passo 1: Cria uma min heap com uma capacidade igual ao tamanho
    MinHeap *minHeap = cria_constroi_minheap(data, freq, tamanho);

    // itera enquanto tamanho da heap não se torna 1
    while (!tamanho_um(minHeap))
    {
        // passo 2: Extrai os dois itens de menor frequência da min heap
        esq = extrai_min(minHeap);
        dir = extrai_min(minHeap);

        // passo 3: Cria um novo nó interno com frequência igual a soma de dois nós de frequência
        // torna os dois nós extraídos como filhos esquerda e direito de novo nós. Adiciona o nó a min heap e recebe '$', um valor especial para nós internos, não é utilizado
        top = novo_no("$", esq->freq + dir->freq);
        top->esq = esq;
        top->dir = dir;

        insere_minheap(minHeap, top);
    }

    // passo 4: O nó remanescente é
    return extrai_min(minHeap);
}

// imprime o código de huffman da raiz da árvoe de huffman. Usa uma arr[] para armazenar os códigos
void imprime_codigo(MinHeapNode *root, int arr[], int top)
{
    // atribui 0 para esquerda e recorre
    if (root->esq)
    {
        arr[top] = 0;
        imprime_codigo(root->esq, arr, top + 1);
    }

    // atribui 1 para direita e recorre
    if (root->dir)
    {
        arr[top] = 1;
        imprime_codigo(root->dir, arr, top + 1);
    }

    // se for uma folha, então contem uma das input strings, imprime a instring e o código da arr[]
    if (e_folha(root))
    {
        cout << root->data << ": ";
        imprime_arr(arr, top);
    }
}

MinHeapNode *codigo_huffman(string data[], float freq[], int tamanho)
{
    // constrói a árvore de huffman
    MinHeapNode *root = arvore_huffman(data, freq, tamanho); // aponta para o nó raiz da árvore

    int arr[MAX_TREE_HT], top = 0;
    // imprime_codigo(root, arr, top);

    return root;
}

// função para salvar a codificação da palavra no arquivo binário
void salva_arquivo(MinHeapNode *root, map<string, float> mapa, vector<string> palavras)
{
    FILE *code;
    string nome;
    code = fopen("src/files/codificado.bin", "w+");

    if (code != NULL)
    {
        map<string, float>::iterator itr;
        for (auto i : palavras)
        {
            // lê o vector palavras e pega a palavra a ser procurada na árvore
            itr = mapa.find(i);
            if (itr != mapa.end())
            {
                string nome;
                int arr[MAX_TREE_HT], top = 0;
                procura(root, itr->first, itr->second, arr, top, nome);
                fwrite(nome.c_str(), nome.size(), 1, code);
            }
        }
    }
    else
        cout << "Problema ao abrir o arquivo.\n";

    fclose(code);
}

// função recursiva para encontrar a palavra na árvore de huffman e atribui uma codificação
void procura(MinHeapNode *root, string data, float freq, int arr[], int top, string &nome)
{
    // atribui 0 para esquerda e recorre
    if (root->esq)
    {
        arr[top] = 0;
        procura(root->esq, data, freq, arr, top + 1, nome);
    }

    // atribui 1 para direita e recorre
    if (root->dir)
    {
        arr[top] = 1;
        procura(root->dir, data, freq, arr, top + 1, nome);
    }

    // se for uma folha, então contem uma das input strings, transforma a codificação (int arr[]) em uma string
    if (e_folha(root) && root->freq == freq && root->data == data)
    {
        for (int i = 0; i < top; i++)
            nome += to_string(arr[i]);
    }
}
