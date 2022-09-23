<img align="right" width="100" height="100" src="img/binarytree.png">

# Código de Huffman

## Árvore Binária

<p align="justify"> Uma árvore binária (= binary tree) é um conjunto de registros que satisfaz certas condições. Os registros serão chamados nós (poderiam também ser chamados células).  Cada nó tem um endereço.  Suporemos por enquanto que cada nó tem apenas três campos:  um número inteiro e dois ponteiros para nós.  Os nós podem, então, ser definidos assim: </p>

<div align="center">
 <p> </p>
 <img src="img/conteudo.png">
 <p> </p>
</div>

<p align="justify"> O campo conteudo é a "carga útil" do nó;  os dois outros campos servem apenas para dar estrutura à árvore.  O campo esq de cada nó contém NULL ou o endereço de outro nó.  Uma hipótese análoga vale para o campo dir. Se o campo esq de um nó P é o endereço de um nó E, diremos que E é o filho esquerdo de P.  Analogamente, se P.dir é igual a &D, diremos que D é o filho direito de P.  Se um nó F é filho (esquerdo ou direito) de P, diremos que P é o pai de F.  Uma folha (= leaf) é um nó que não tem filho algum. </p>

<p align="justify"> É muito conveniente confundir, verbalmente, cada nó com seu endereço.  Assim, se x é um ponteiro para um nó (ou seja, se x é do tipo *noh), dizemos  "considere o nó x"  em lugar de  "considere o nó cujo endereço é x". A figura abaixo mostra dois exemplos de árvores binárias. A seguir, uma representação esquemática de uma árvore binária cujos nós contêm os números 2, 7, 5, etc. </p>

<div align="center">
 <p> </p>
 <img src="img/tree.png">
 <p> </p>
</div>

## Árvore de Huffman

<p align="justify"> Trata-se de uma codificação de caracteres que permite compactar arquivos de texto, ou seja, representar um arquivo de texto A por um arquivo de bits B bem menor. O algoritmo de Huffman calcula uma tabela de códigos sob medida para o arquivo A de modo que o arquivo B seja o menor possível. O algoritmo de Huffman é um bom exemplo de algoritmo guloso.</p>


> **Algoritmo guloso**
> Estratégia gulosa é aquela usada por um montanhista que decide caminhar sempre "para cima", na direção de "maior subida", na esperança de assim chegar ao pico mais alto da montanha. (Como todos sabemos, essa estratégia nem sempre produz o resultado esperado). Um algoritmo guloso escolhe, em cada iteração, o objeto mais "apetitoso" que vê pela frente. (A definição de "apetitoso" é estabelecida a priori, antes da execução do algoritmo.) O objeto escolhido passa a fazer parte da solução que o algoritmo constrói.

<p align="justify"> De maneira informal, a codificação Huffman é um algoritmo de compressão de dados sem perdas. A ideia é atribuir códigos de comprimento variável aos caracteres de entrada, sendo que os comprimentos dos códigos atribuídos são baseados nas frequências dos caracteres correspondentes. O caractere mais frequente recebe o menor código e o caractere menos frequente recebe o maior código.
 
<p align="justify"> Os códigos de comprimento variável atribuídos aos caracteres de entrada são códigos de prefixo, significa que ***os códigos (sequências de bits) são atribuídos de tal forma que o código atribuído a um caractere não é o prefixo do código atribuído a nenhum outro caractere.*** É assim que o Huffman Coding garante que não haja ambiguidade ao decodificar o fluxo de bits gerado. </p>

<p align="justify"> Para entender os códigos de prefixo, usaremos um contra-exemplo. Sejam quatro caracteres a, b, c e d, e seus códigos de comprimento variável correspondentes sejam 00, 01, 0 e 1. Essa codificação leva à ambiguidade porque o código atribuído a c é o prefixo dos códigos atribuídos a a e b. Se o fluxo de bits compactado for 0001, a saída descompactada poderá ser “cccd” ou “ccb” ou “acd” ou “ab”. </p>

### Desempenho

<p align="justify"> Se a fila-com-prioridades for implementada como um vetor ordenado, cada execução de inserir na fila e extrair o mínimo elemento consumirá $Ο(m)$ unidades de tempo, sendo m o número de células na fila Q. Como $m ≤ n$ e há n repetições do bloco de linhas 1 a 7 e n−1 repetições do bloco de linhas 9 a 15, o consumo de tempo total do algoritmo será $Ο(n²)$.  Se a fila-com-prioridades for implementada como um min-heap (veja um dos exercícios abaixo), cada execução de Insere-na-Fila e Extrai-Min consumirá $O(n lg n)$ unidades de tempo. Com isso, o consumo total será de </p>

$O(n lg n)$

<p> unidades de tempo.  </p>

### Aplicação

<p align="justify"> A principal aplicação prática do algoritmo de Huffman é o cálculo de códigos binários para compressão de arquivos, ou seja, a transformação de um arquivo de caracteres em uma sequência de bits que ocupa pouco espaço. A ideia é usar poucos bits para representar os caracteres mais frequentes e mais bits para representar os mais raros. No caso deste projeto, a idea é análoga a esta, apenas trocando a representação de caracteres mais frequentes para palavras mais frequentes do texto. </p>


## O Algoritmo

### Estrutura dos arquivos

<p align="justify"> O código apresenta um arquivo makefile, um script que consta as instruções de como gerar um binário, e uma pasta src. A pasta src apresenta cinco arquivos, sendo eles o main.c, responsável pela chamada das principais funções, e os arquivos arquivo.hpp, arquivo.cpp, huffman.hpp e huffman.cpp. Os dois primeiros arquivos, arquivo.hpp e arquivo.cpp, são responsáveis pela leitura do arquivo de texto, tratamento das palavras e inserção das mesmas no map. Os dois últimos, huffman.hpp e huffman.cpp, são responsáveis pela criação da min-heap, da árvore de huffman e a leitura e salvamento da codificação no arquivo binário. A pasta src também apresenta uma pasta files, onde consta o arquivo de texto, texto.txt, que será comprimido e o arquivo binário codificado.bin, já com a codificação. </p>

### Estrutura do algoritmo

<p align="justify"> O código é dividido em dois pedaços, o primeiro onde o arquivo é lido e as palavras são tratadas, e o segundo, onde a árvore é criada e a codificação é enviara para o arquivo binário. Dessa forma, explicarei separadamente os dois principais arquivos do algoritmo na ordem a qual eles são excecutados: o arquivo.cpp e o huffman.hpp.

#### arquivo.cpp

Na main, a primeira função a ser chamada é `abre_arq(map <string, float> *mapa, vector<string> *palavras)` e são repassados como parâmetros um ponteiro map de string e float, e um ponteiro vector de string que foram criados na main.
 
 ```c
 map<string, float> mapa;
vector<string> palavras;

abre_arq(&mapa, &palavras);
 ```
 
Nesta função, o arquivo de leitura texto.txt é aberto, as palavras são lidas, tokenizadas e tratadas. Em seguida, as palavras são inseridas no vector de palavras e no map pela função `encontra_palavra(map <string, float> *mapa, string palavra)` e recebem como valor mapeado o 1. As palavras que estão sendo inseridas pela segunda ou mais vezes não são adicionadas novamente, apenas são incrementadas no ponto flutuante. Por fim, o arquivo é fechado.
 
https://github.com/barbrina/AEDs-II/blob/86e05e2ec36d252bfbf6585394437bddf9c14ec1/C%C3%B3digo%20de%20Huffman/src/arquivo.cpp#L4-L42
 
Após a conclusão da leitura de todas as palavras na main, a formula de RP é calculada através da função `formula_rp(map<string, float> *mapa)` e para ela é passado como parâmetro o ponteiro de map com a palavras e a recorrência das mesmas. A fórmula utilizada para o cálculo de recorrência foi a seguinte:
 
$$ x = {RP(atual) \over RP(máx) - RP(mín)} $$

Após pegar a recorrencia da palavra atual e dividi-la pela subtração da recorrencia da palavra de maior recorrencia, através do método  float `float max_valor(map<string, float> *mapa)` e pela de menor recorrencia `float min_valor(map<string, float> *mapa)`, o resultado nos dá a frequência que é atualizada na própria map.
 
Na main, o multimap é criado com os valores de float, representando a frequência e a string representando a palavra. Em seguida, a função ordena  `void ordena(map<string, float> &mapa, multimap<float, string> &mmapa)` é chamada, passando como parâmetro o map e o multimap. O objetivo desta função é passar todos os valores contidos em map, para multimap e ordenar as palavras em relação a frequência das mesmas, ao invés da ordem alfabética.
 
 ```c
 string *data = new string[mmapa.size()]; // cria lista de palavras
 float *freq = new float[mmapa.size()];   // cria lista de frequencias
 passar_array(&mmapa, data, freq); // passa os valores da multimap para as listas
```
 
Uma string de ponteiro e um float de ponteiro são criados e alocados dinamicamente na main. A função `void passar_array(multimap<float, string> *mmapa, string data[], float freq[])`  com os parâmetros das listas mencionadas anteriormente e o multimap. O multimap é percorrido e as palavras e a frequência das mesmas são repassadas para estas listas, de modo a serem usadas posteriormentes para a criação da árvore de huffman.

#### huffman.cpp

<p> </p>

## Compilação e Execução


O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
|  `make r`              | Apaga, builda e executa o programa                                                                |

</div>

## Referências 

<p> P. Feofiloff. **Análise de Algoritmos**. Internet: http://www.ime.usp.br/~pf/analise_de_algoritmos/, 1999–2009 </p>
<p> P. Feofiloff. **Código de Huffman**. Internet: [http://www.ime.usp.br/~pf/analise_de_algoritmos/](https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/huffman.html#sec:recursive-structure), 1999–2009 </p>


