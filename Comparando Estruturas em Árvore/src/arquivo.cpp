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

void remove()
{
    cout << "\n------------------------------------------\n";
    cout << "Gostaria de pesquisar e remover valores da estrutura preenchida acima? \n";
    cout << "1 - sim\n";
    cout << "2 - não\n";
    cout << "------------------------------------------\n";
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

    string nome = arquivo();
    int decisao = 0;

    clock_t inicio = clock();
    raiz = insert_binary(nome, raiz, r);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << ">> O tempo gasto para inserir na estrutura foi " << tempo << " ." << endl;

    remove();
    cout << ">> ";
    cin >> decisao;

    if (decisao == 1)
    {
        clock_t inicio = clock();
        remove_binary(raiz);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout << "\n\n>> O tempo gasto para remover na estrutura foi " << tempo << " ." << endl;
    }
}

void avl()
{
    TreeAVL *raiz = CreateAVL(); // cria a árvore binária de pesquisa
    RecordAVL r;

    string nome = arquivo();
    int decisao = 0;

    clock_t inicio = clock();
    raiz = insert_avl(nome, raiz, r);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << ">> O tempo gasto para inserir na estrutura foi " << tempo << " ." << endl;

    remove();
    cout << ">> ";
    cin >> decisao;

    if (decisao == 1)
    {
        clock_t inicio = clock();
        remove_avl(raiz);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout << "\n\n>> O tempo gasto para remover na estrutura foi " << tempo << " ." << endl;
    }
}

void rb()
{
    TreeRB *raiz = CreateRB();
    RecordRB r;

    string nome = arquivo();
    int decisao = 0;

    clock_t inicio = clock();
    raiz = insert_rb(nome, raiz, r);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << ">> O tempo gasto para inserir na estrutura foi " << tempo << " ." << endl;

    remove();
    cout << ">> ";
    cin >> decisao;

    if (decisao == 1)
    {
        clock_t inicio = clock();
        remove_rb(raiz);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout << "\n\n>> O tempo gasto para remover na estrutura foi " << tempo << " ." << endl;
    }
}

void vetor()
{
    string nome = arquivo();
    int decisao = 0;
    vector<double> vetor;

    clock_t inicio = clock();
    vetor = insert_vetor(nome, vetor);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << ">> O tempo gasto para inserir na estrutura foi " << tempo << " ." << endl;

    remove();
    cout << ">> ";
    cin >> decisao;

    if (decisao == 1)
    {
        clock_t inicio = clock();
        remove_vetor(vetor);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout << "\n\n>> O tempo gasto para remover na estrutura foi " << tempo << " ." << endl;
    }
}

void mapa()
{
    string nome = arquivo();
    int decisao = 0;

    map<double, int> mapa;

    clock_t inicio = clock();
    insert_mapa(nome, &mapa);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << ">> O tempo gasto para inserir na estrutura foi " << tempo << " ." << endl;

    remove();
    cout << ">> ";
    cin >> decisao;

    if (decisao == 1)
    {
        clock_t inicio = clock();
        remove_mapa(&mapa);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout << "\n\n>> O tempo gasto para remover na estrutura foi " << tempo << " ." << endl;
    }
}

void umapa()
{
    string nome = arquivo();
    int decisao = 0;

    unordered_map<double, int> umapa;

    clock_t inicio = clock();
    insert_umapa(nome, &umapa);
    clock_t fim = clock();

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    cout << ">> O tempo gasto para inserir na estrutura foi " << tempo << " ." << endl;

    remove();
    cout << ">> ";
    cin >> decisao;

    if (decisao == 1)
    {
        clock_t inicio = clock();
        remove_umapa(&umapa);
        clock_t fim = clock();

        double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        cout << "\n\n>> O tempo gasto para remover na estrutura foi " << tempo << " ." << endl;
    }
}

Tree *insert_binary(string nome, Tree *raiz, Record r)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq(nome);

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;        // define chave
        r.value = 1;               // define valor
        insertTree(&raiz, r);      // insere na árvore binária
    }

    arq.close();

    return raiz;
}

TreeAVL *insert_avl(string nome, TreeAVL *raiz, RecordAVL r)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq(nome);

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;        // define chave
        r.value = 1;               // define valor
        insertTreeAVL(&raiz, r);   // insere na árvore AVL
    }

    arq.close();

    return raiz;
}

TreeRB *insert_rb(string nome, TreeRB *raiz, RecordRB r)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq(nome);

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        insertTreeRB(&raiz, &raiz, &raiz, r); // insere na árvore rubro negra
    }

    arq.close();

    return raiz;
}

vector<double> insert_vetor(string nome, vector<double> vetor)
{
    string numero;
    double num_double;
    // int i = 0;

    // abre o arquivo para leitura
    ifstream arq(nome);

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        vetor.push_back(num_double);
        // cout << vetor[i] << endl;
        //  cout << i++;
    }

    sort(vetor.begin(), vetor.end());

    arq.close();

    return vetor;
}

void insert_mapa(string nome, map<double, int> *mapa)
{
    string line, numero;
    double num_double;
    // int i = 0;

    // abre o arquivo para leitura
    ifstream arq(nome);

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        mapa->insert({num_double, 1});
    }

    arq.close();
}

void insert_umapa(string nome, unordered_map<double, int> *umapa)
{
    string numero;
    double num_double;
    // int i = 0;

    // abre o arquivo para leitura
    ifstream arq(nome);

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        umapa->insert({num_double, 1});
    }

    arq.close();
}

void remove_binary(Tree *raiz)
{
    string numero;
    double num_double;
    Tree *aux = CreateTree();
    Record r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        if (pesquisa(&raiz, &aux, r))
            removeTree(&raiz, r);
    }

    arq.close();
}

void remove_avl(TreeAVL *raiz)
{
    string numero;
    double num_double;
    TreeAVL *aux = CreateAVL();
    RecordAVL r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        if (pesquisaAVL(&raiz, &aux, r))
            removeTreeAVL(&raiz, &raiz, r);
    }

    arq.close();
}

void remove_rb(TreeRB *raiz)
{
    string numero;
    double num_double;

    TreeRB *aux = CreateRB();
    RecordRB r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        if (pesquisaRB(&raiz, &aux, r))
        {
            cout << num_double << " ";
            removeTreeRB(&raiz, r);
        }
    }

    arq.close();
}

/*void remove_rb(TreeRB *raiz)
{
    string numero;
    double num_double;
    TreeRB *aux = CreateRB();
    RecordRB r;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        r.key = num_double;
        if (pesquisaRB(&raiz, &aux, r))
            ;
        // removeRB(&raiz, &raiz, r);
    }

    arq.close();
}*/

void remove_vetor(vector<double> vetor)
{
    string numero;
    double num_double;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

    while (getline(arq, numero))
    {
        num_double = stod(numero); // transforma string em número flutuante
        if (binary_search(vetor.begin(), vetor.end(), num_double))
        {
            cout << num_double << " ";
            for (int i = 0; i < vetor.size(); i++)
            {
                if (num_double == vetor[i])
                {
                    vetor.erase(vetor.begin() + i);
                    break;
                }
            }
        }
    }

    arq.close();
}

void remove_mapa(map<double, int> *mapa)
{
    string numero;
    double num_double;
    map<double, int>::iterator itr;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

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

    arq.close();
}

void remove_umapa(unordered_map<double, int> *umapa)
{
    string numero;
    double num_double;
    unordered_map<double, int>::iterator itr;

    // abre o arquivo para leitura
    ifstream arq("src/files/consulta.txt");

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

    arq.close();
}