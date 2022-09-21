#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include "Huffman.hpp"

using namespace std;

void abre_arq(map<string, float> *mapa, vector<string> *palavras);
bool checa_vogais(string palavra);
string checa_pontuacao(string palavra);
bool encontra_palavra(map<string, float> *mapa, string palavra);
void insere_map(map<string, float> *mapa, string palavra, float recorrencia);
void imprime_map(map<string, float> *mapa);
void imprime_multimap(multimap<float, string> *mmapa);
void formula_rp(map<string, float> *mapa);
float total_palavras(map<string, float> *mapa);
float max_valor(map<string, float> *mapa);
float min_valor(map<string, float> *mapa);
void atualiza_map(map<string, float> *mapa, string palavra, float atual);
void ordena(map<string, float> &mapa, multimap<float, string> &mmapa);
void passar_array(multimap<float, string> *mmapa, string data[], float freq[]);

#endif