#include "arquivo.hpp"

void cria_arqs()
{
    string line;

    // cria e abre arquivos vazios para escrito
    ofstream arq1("src/files/500000.txt");
    ofstream arq2("src/files/50000.txt");
    ofstream arq3("src/files/5000.txt");
    ofstream arq4("src/files/500.txt");
    ofstream consulta("src/files/consulta.txt");

    // escreve no arquivo 500.000 números flutuantes aleatórios
    for (int i = 0; i < 500000; i++)
    {
        /*static default_random_engine r;
        static uniform_real_distribution<> dis(0, 10);
        float num = dis(r);*/

        float num = (float)rand() / (float)(RAND_MAX / 10);
        float novo = (float)rand() / (float)(RAND_MAX / 10);

        arq1 << num << "\n";
        if (i < 9000)
            consulta << num << "\n";
        if (i < 50000)
            arq2 << num << "\n";
        if (i < 5000)
            arq3 << num << "\n";
        if (i < 1000)
            consulta << novo << "\n";
        if (i < 500)
            arq4 << num << "\n";
    }

    arq1.close();
    arq2.close();
    arq3.close();
    arq4.close();
}

void menu()
{
    cout << "\n------------------------------------------\n";
    cout << "Digite o número da estrutura desejada: \n";
    cout << "1 - Árvore Binária de Busca\n";
    cout << "2 - Árvore AVL\n";
    cout << "3 - Árvore Rubro Negra\n";
    cout << "4 - Vector\n";
    cout << "5 - Map\n";
    cout << "6 - Unordored map\n";
    cout << "7 - Sair\n";
    cout << "------------------------------------------\n";
    cout << ">> ";
}

string arquivo()
{
    int tam;

    do
    {
        cout << "\n------------------------------------------\n";
        cout << "Digite qual o tamanho do arquivo para preencher a estrutura: \n";
        cout << "1 - 500\n";
        cout << "2 - 5000\n";
        cout << "3 - 50000\n";
        cout << "4 - 500000\n";
        cout << "------------------------------------------\n";

        cout << ">> ";
        cin >> tam;
        cout << endl;

    } while (tam > 4 && tam < 1);

    if (tam == 1)
        return "src/files/500.txt";
    else if (tam == 2)
        return "src/files/5000.txt";
    else if (tam == 3)
        return "src/files/50000.txt";
    else
        return "src/files/500000.txt";
}

void binary()
{
    Tree *raiz = CreateTree(); // cria a árvore binária de pesquisa
    Record r;

    double tempo_insert, tempo_search, tempo_remove;
    string nome = arquivo();

    raiz = insert_binary(nome, raiz, r, tempo_insert);
    search_binary(raiz, tempo_search);
    remove_binary(raiz, tempo_remove);

    cout << ">> O tempo gasto na árvore binária de busca foi:  " << endl;
    cout << ">> inserção: " << tempo_insert << "s" << endl;
    cout << ">> pesquisa: " << tempo_search << "s" << endl;
    cout << ">> remoção: " << tempo_remove << "s" << endl;
}

void avl()
{
    TreeAVL *raiz = CreateAVL(); // cria a árvore binária de pesquisa
    RecordAVL r;

    double tempo_insert, tempo_search, tempo_remove;
    string nome = arquivo();

    raiz = insert_avl(nome, raiz, r, tempo_insert);
    search_avl(raiz, tempo_search);
    remove_avl(raiz, tempo_remove);

    cout << ">> O tempo gasto na árvore avl foi:  " << endl;
    cout << ">> inserção: " << tempo_insert << "s" << endl;
    cout << ">> pesquisa: " << tempo_search << "s" << endl;
    cout << ">> remoção: " << tempo_remove << "s" << endl;
}

void rb()
{
    // TreeRB *raiz = CreateRB();
    TreeRB *raiz;
    inicializaTreeRB(&raiz);
    RecordRB r;

    double tempo_insert, tempo_search, tempo_remove;
    string nome = arquivo();

    raiz = insert_rb(nome, raiz, r, tempo_insert);
    search_rb(raiz, tempo_search);
    remove_rb(raiz, tempo_remove);

    cout << ">> O tempo gasto na árvore rubro negra foi:  " << endl;
    cout << ">> inserção: " << tempo_insert << "s" << endl;
    cout << ">> pesquisa: " << tempo_search << "s" << endl;
    cout << ">> remoção: " << tempo_remove << "s" << endl;
}

void vetor()
{
    vector<double> vetor;

    string nome = arquivo();
    double tempo_insert, tempo_search, tempo_remove;

    vetor = insert_vetor(nome, vetor, tempo_insert);
    search_vetor(vetor, tempo_search);
    remove_vetor(vetor, tempo_remove);

    cout << ">> O tempo gasto na estrutura vector foi:  " << endl;
    cout << ">> inserção: " << tempo_insert << "s" << endl;
    cout << ">> pesquisa: " << tempo_search << "s" << endl;
    cout << ">> remoção: " << tempo_remove << "s" << endl;
}

void mapa()
{
    map<double, int> mapa;

    string nome = arquivo();
    double tempo_insert, tempo_search, tempo_remove;

    insert_mapa(nome, &mapa, tempo_insert);
    search_mapa(&mapa, tempo_search);
    remove_mapa(&mapa, tempo_remove);

    cout << ">> O tempo gasto na estrutura map foi:  " << endl;
    cout << ">> inserção: " << tempo_insert << "s" << endl;
    cout << ">> pesquisa: " << tempo_search << "s" << endl;
    cout << ">> remoção: " << tempo_remove << "s" << endl;
}

void umapa()
{
    unordered_map<double, int> umapa;

    string nome = arquivo();
    double tempo_insert, tempo_search, tempo_remove;

    insert_umapa(nome, &umapa, tempo_insert);
    search_umapa(&umapa, tempo_search);
    remove_umapa(&umapa, tempo_remove);

    cout << ">> O tempo gasto na estrutura unordered map foi:  " << endl;
    cout << ">> inserção: " << tempo_insert << "s" << endl;
    cout << ">> pesquisa: " << tempo_search << "s" << endl;
    cout << ">> remoção: " << tempo_remove << "s" << endl;
}

Tree *insert_binary(string nome, Tree *raiz, Record r, double &tempo)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq(nome);

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;        // define chave
        r.value = 1;               // define valor
        insertTree(&raiz, r);      // insere na árvore binária
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();

    return raiz;
}

TreeAVL *insert_avl(string nome, TreeAVL *raiz, RecordAVL r, double &tempo)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq(nome);

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;        // define chave
        r.value = 1;               // define valor
        insertTreeAVL(&raiz, r);   // insere na árvore AVL
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();

    return raiz;
}

TreeRB *insert_rb(string nome, TreeRB *raiz, RecordRB r, double &tempo)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq(nome);

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        insertTreeRB(&raiz, &raiz, &raiz, r); // insere na árvore rubro negra
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();

    return raiz;
}

vector<double> insert_vetor(string nome, vector<double> vetor, double &tempo)
{
    string numero;
    double num_double;
    // int i = 0;

    // abre o arquivo para leitura
    ifstream arq(nome);

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        vetor.push_back(num_double);
        // cout << vetor[i] << endl;
        // cout << i++;
    }

    sort(vetor.begin(), vetor.end());
    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();

    return vetor;
}

void insert_mapa(string nome, map<double, int> *mapa, double &tempo)
{
    string line, numero;
    double num_double;
    // int i = 0;

    // abre o arquivo para leitura
    ifstream arq(nome);

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        mapa->insert({num_double, 1});
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void insert_umapa(string nome, unordered_map<double, int> *umapa, double &tempo)
{
    string numero;
    double num_double;
    // int i = 0;

    // abre o arquivo para leitura
    ifstream arq(nome);

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        umapa->insert({num_double, 1});
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void search_binary(Tree *raiz, double &tempo)
{
    string numero;
    double num_double;
    Tree *aux = CreateTree();
    Record r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        pesquisa(&raiz, &aux, r);
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void search_avl(TreeAVL *raiz, double &tempo)
{
    string numero;
    double num_double;
    TreeAVL *aux = CreateAVL();
    RecordAVL r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        pesquisaAVL(&raiz, &aux, r);
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void search_rb(TreeRB *raiz, double &tempo)
{
    string numero;
    double num_double;
    RecordRB r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        pesquisaRB(&raiz, r);
    }

    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void search_vetor(vector<double> vetor, double &tempo)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        binary_search(vetor.begin(), vetor.end(), num_double);
    }
    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void search_mapa(map<double, int> *mapa, double &tempo)
{
    string numero;
    double num_double;
    map<double, int>::iterator itr;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        itr = mapa->find(num_double);
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void search_umapa(unordered_map<double, int> *umapa, double &tempo)
{
    string numero;
    double num_double;
    unordered_map<double, int>::iterator itr;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        itr = umapa->find(num_double);
    }

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void remove_binary(Tree *raiz, double &tempo)
{
    string numero;
    double num_double;
    Tree *aux = CreateTree();
    Record r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();
    cout << "Valores removidos: \n";
    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        removeTree(&raiz, r);
    }
    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void remove_avl(TreeAVL *raiz, double &tempo)
{
    string numero;
    double num_double;
    TreeAVL *aux = CreateAVL();
    RecordAVL r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();
    cout << "Valores removidos: \n";
    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        removeTreeAVL(&raiz, &raiz, r);
    }
    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void remove_rb(TreeRB *raiz, double &tempo)
{
    string numero;
    double num_double;
    RecordRB r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();
    cout << "Valores removidos: \n";
    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        removeTreeRB(&raiz, r);
    }

    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void remove_vetor(vector<double> vetor, double &tempo)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();
    cout << "Valores removidos: \n";
    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        for (int i = 0; i < vetor.size(); i++)
        {
            if (num_double == vetor[i])
            {
                cout << num_double << " ";
                vetor.erase(vetor.begin() + i);
                break;
            }
        }
    }
    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void remove_mapa(map<double, int> *mapa, double &tempo)
{
    string numero;
    double num_double;
    map<double, int>::iterator itr;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();
    cout << "Valores removidos: \n";
    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        itr = mapa->find(num_double);
        if (itr != mapa->end())
        {
            cout << itr->first << " ";
            mapa->erase(num_double);
        }
    }
    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}

void remove_umapa(unordered_map<double, int> *umapa, double &tempo)
{
    string numero;
    double num_double;
    unordered_map<double, int>::iterator itr;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    clock_t inicio = clock();
    cout << "Valores removidos: \n";
    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        itr = umapa->find(num_double);
        if (itr != umapa->end())
        {
            cout << itr->first << " ";
            umapa->erase(num_double);
        }
    }
    cout << "\n\n";

    clock_t fim = clock();
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    arq.close();
}