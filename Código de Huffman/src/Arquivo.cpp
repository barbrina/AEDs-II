#include "Arquivo.hpp"

void abre_arq(map<string, float> *mapa, vector<string> *palavras)
{
    string palavra;

    // Abre um arquivo de texto para Leitura
    ifstream texto("texto.txt");

    // leitura de texto.txt, palavra por palavra
    while (texto >> palavra)
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
        }

        palavras->push_back(palavra);
        palavras->push_back(" ");
    }

    texto.close();
}

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

void insere_map(map<string, float> *mapa, string palavra, float recorrencia)
{
    mapa->insert({palavra, recorrencia});
}

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

void imprime_map(map<string, float> *mapa)
{
    map<string, float>::iterator itr;

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
        cout << itr->first << " - " << itr->second << endl;
    cout << endl;
}

void imprime_multimap(multimap<float, string> *mmapa)
{
    multimap<float, string>::iterator itr;

    for (itr = mmapa->begin(); itr != mmapa->end(); ++itr)
        cout << itr->first << " - " << itr->second << endl;
    cout << endl;
}

void formula_rp(map<string, float> *mapa)
{
    map<string, float>::iterator itr;

    float max = max_valor(mapa);
    //float total = total_palavras(mapa);
    float min = min_valor(mapa);
    float formula;

    for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        float atual = itr->second;
        string palavra = itr->first;
        formula = atual / (max - min);
        atualiza_map(mapa, palavra, formula);
    }

    /*for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        float atual = itr->second;
        string palavra = itr->first;
        formula = atual / total;
        atualiza_map(mapa, palavra, formula);
    }*/

    /*for (itr = mapa->begin(); itr != mapa->end(); ++itr)
    {
        float atual = itr->second;
        string palavra = itr->first;
        formula = (atual - min) / (max - min);
        atualiza_map(mapa, palavra, formula);
    }*/
}

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

void ordena(map<string, float> &mapa, multimap<float, string> &mmapa)
{
    // Insert every (key-value) pairs from map M to multimap MM as (value-key) pairs
    for (auto &it : mapa)
    {
        mmapa.insert({it.second, it.first});
    }

    // Print the multimap
    /*for (auto &it : mmapa)
    {
        cout << it.second << ' ' << it.first << endl;
    }*/
}

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