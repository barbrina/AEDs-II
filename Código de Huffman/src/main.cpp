#include "arquivo.hpp"

int main()
{
    map<string, float> mapa;
    vector<string> palavras;

    MinHeapNode *root;

    abre_arq(&mapa, &palavras);
    formula_rp(&mapa);             // calcula a fórmula RP / (max(RP) - min(RP)) e atualiza o mapa
    multimap<float, string> mmapa; // cria a multimap
    ordena(mapa, mmapa);           // ordena a multimap pelo valor da recorrência

    string *data = new string[mmapa.size()]; // cria lista de palavras
    float *freq = new float[mmapa.size()];   // cria lista de frequencias

    passar_array(&mmapa, data, freq); // passa os valores da multimap para as listas

    int tamanho = mapa.size();
    root = codigo_huffman(data, freq, tamanho);
    salva_arquivo(root, mapa, palavras);

    return 0;
}