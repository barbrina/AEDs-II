#include "arquivo.hpp"

// função para abrir um arquivo de texto e passar seu conteúdo para o vector e sua recorrencia para a map
void abre_arq(map<string, float> *mapa, vector<string> *palavras)
{
    string palavra;
    string linha;

    ifstream texto("src/files/texto.txt");

    while (texto.is_open())
    {
        while (getline(texto, linha))
        {
            stringstream line(linha);

            while (getline(line, palavra, ' '))
            {
                // transforma palavra em lower case
                transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

                // retira as vogais se houver
                bool key = checa_vogais(palavra);

                if (key)
                    palavra.erase();
                else
                {
                    // retira pontuações se houver
                    palavra = checa_pontuacao(palavra);

                    // se não encontrar a palavra, adiciona ela no mapa
                    if (!encontra_palavra(mapa, palavra))
                        insere_map(mapa, palavra, 1);

                    palavras->push_back(palavra);
                }
            }
        }
        texto.close();
    }
}

// função para retirar as vogais do texto
bool checa_vogais(string palavra)
{
    vector<string> vogais = {"a", "e", "i", "o", "u"};

    int j = 0;
    bool key = false;

    while (key != true && j < 5)
    {
        if (palavra.compare(vogais[j]) == 0)
            return key = true;

        j++;
    }

    return key;
}

// função para retirar a pontuação das palavras
string checa_pontuacao(string palavra)
{
    for (int i = 0, len = palavra.size(); i < len; i++)
    {
        if (ispunct(palavra[i]))
        {
            palavra.erase(i--, 1);
            len = palavra.size();
        }
    }

    return palavra;
}

// função para inserir a palavra e sua recorrencia no map
void insere_map(map<string, float> *mapa, string palavra, float recorrencia)
{
    mapa->insert({palavra, recorrencia});
}

// função para encontrar a palavra no map
bool encontra_palavra(map<string, float> *mapa, string palavra)
{
    map<string, float>::iterator itr;
    itr = mapa->find(palavra);
    if (itr != mapa->end())
    {
        itr->second += 1;
        return true;
    }

    return false;
}

// função para imprimir os dados contidos na map
void imprime_map(map<string, float> *mapa)
{
    map<string, float>::iterator itr;

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
        cout << itr->first << " - " << itr->second << endl;
    cout << endl;
}

// função para imprimir os dados contidos na multimap
void imprime_multimap(multimap<float, string> *mmapa)
{
    multimap<float, string>::iterator itr;

    for (itr = mmapa->begin(); itr != mmapa->end(); ++itr)
        cout << itr->first << " - " << itr->second << endl;
    cout << endl;
}

// função para calcular a fórmula de RP / (max(RP) - min(RP))
void formula_rp(map<string, float> *mapa)
{
    map<string, float>::iterator itr;

    float max = max_valor(mapa);
    float total = total_palavras(mapa);
    float min = min_valor(mapa);
    float formula;

    // Outra fórmula a ser utilizada
    /*for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        float atual = itr->second;
        string palavra = itr->first;
        formula = atual / (max - min);
        atualiza_map(mapa, palavra, formula);
    }*/

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        float atual = itr->second;
        string palavra = itr->first;
        formula = atual / total;
        atualiza_map(mapa, palavra, formula);
    }
}

// função que retorna a quantidade de elementos dentro da map
float total_palavras(map<string, float> *mapa)
{
    map<string, float>::iterator itr;
    float total = 0;

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
        total += itr->second;

    return total;
}

// retorna o max(RP)
float max_valor(map<string, float> *mapa)
{
    map<string, float>::iterator itr;
    float max = mapa->begin()->second;

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        if (itr->second > max)
        {
            max = itr->second;
        }
    }

    return max;
}

// retorna o min(RP)
float min_valor(map<string, float> *mapa)
{
    map<string, float>::iterator itr;
    float min = mapa->begin()->second;

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        if (itr->second < min)
        {
            min = itr->second;
        }
    }

    return min;
}

// função que atualiza o valor de recorrencia após o cálculo de RP
void atualiza_map(map<string, float> *mapa, string palavra, float atual)
{
    map<string, float>::iterator itr;
    itr = mapa->find(palavra);

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        if (itr->first == palavra)
        {
            itr->second = atual;
        }
    }
}

// função que ordena a map da menor recorrencia para a maior
void ordena(map<string, float> &mapa, multimap<float, string> &mmapa)
{
    for (auto &it : mapa)
    {
        mmapa.insert({it.second, it.first});
    }
}

// função que passa os valores ordenados da multimap para a map
void passar_array(multimap<float, string> *mmapa, string data[], float freq[])
{
    multimap<float, string>::iterator itr;

    int i = 0;
    for (itr = mmapa->begin(); itr != mmapa->end(); ++itr)
    {
        // cout << itr->first << " " << itr->second << endl;
        freq[i] = itr->first;
        data[i] = itr->second;
        i++;
    }
}