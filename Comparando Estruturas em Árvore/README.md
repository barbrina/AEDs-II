<div align="justify">

<img align="right" width="100" height="100" src="img/binarytree.png">

# Comparando Estruturas

<div style="display: inline-block;">
<img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white"/> 
<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/> 
</a> 
</div>

## 1. Estruturas

### 1.1 Árvore de Busca Binária

### 1.2 Árvore AVL

### 1.3 Árvore Rubro Negra

### 1.4 Vector

### 1.5 Map

### 1.6 Unordered Map

## 2. O Algoritmo

### 2.1 Problema Proposto 

<p align="justify"> Até o momento trabalhamos com três modelos de árvore, binária, avl e redblack. Chegou o momento de compararmos tais estruturas, observando seu comportamento sob diferentes volumes de dados. Para tanto, elabore arquivos que contenham 500 , 5000 , 50.000 , 500.000 entradas numéricas do tipo ponto flutuante. Para tanto, tente evitar repetições de valores em grande escala para que possamos ter uma estrutura profunda. Considere produzir os menores a partir dos maiores volumes de forma randômica. Feito a isso, vamos testar os seguintes processos:

1) Qual o tempo gasto com pesquisa para um arquivo de entrada com 10.000 consultas. Considere como consulta a busca de um determinado número na estrutura escolhida. Para cada pesquisa, é preciso remover o elemento da árvore, retornando esse número para o usuário. Então, considere o processo de remoção como parte final do processo. 

2) Qual o tempo necessário para montar a estrutura em memória. 

3) Qual o ganho dessas estruturas ao compará-las a vetores ordenados e aplicados à pesquisa binária. Qual o tempo gasto com a ordenação do vetor? Foi possível produzi-lo em memória? 

4) Adotando como estrutura o map e unorder_map do C++, há ganhos maiores nesse processo de pesquisa?</p>


### 2.2 Estrutura dos arquivos

O código apresenta um arquivo makefile (um script que consta as instruções de como gerar um binário) e uma pasta src. A pasta src apresenta onze (11) arquivos, sendo eles o main.c, responsável pela chamada das principais funções, e os arquivos arquivo.hpp, arquivo.cpp, binary.hpp, binary.cpp, avl.hpp, avl.cpp, fila.hpp, fila.cpp e a redblack.hpp, redblack.cpp. Na pasta src, também temos um pasta files, que contém todos os quatro arquivos txt para leitura e o arquivo txt de consulta. Os dois primeiros arquivos na pasta src, arquivo.hpp e arquivo.cpp, são responsáveis pela criação dos cinco arquivos de número ponto flutuante, e a inserção e remoção destes arquivos nas estruturas mencionados em  **1. Estruturas**. Os arquivos restantes são os arquivos onde estão contidos as estruturas de árvore de busca binária (binary.hpp, binary.cpp), a árvore avl (avl.hpp, avl.cpp, fila.hpp, fila.cpp) e a árvore rubro negra (redblack.hpp, redblack.cpp). 

### 2.3 Bibliotecas utilizadas

https://github.com/barbrina/AEDs-II/blob/978c0498e5b92eb0f0425e8956e99e5cf933c866/Comparando%20Estruturas%20em%20%C3%81rvore/src/arquivo.hpp#L4-L13

### 2.4 Estrutura do algoritmo


## 3. Resultados e Análises

As estruturas foram chamadas cinco vezes para cada tipo de arquivo e para cada tipo de método, inserção, pesquisa ou remoção. O tempo gasto para cada um dos processos foi armazenado e uma tabela com seus valores e suas respectivas incertezas estarão demonstradas a seguir. Os valores em negrito são os menores e os maiores tempos para cada tipo de método e arquivo e a discussão sobre os dados encontrados foi realizada.

### 3.1 Inserção

Para os dados de inserção, temos como resultado a seguinte tabela:

<div align="center">

|                         |                   500.txt                 |   5000.txt  |  50000.txt  |  500000.txt |
|-------------------------|-------------------------------------------|-------------|-------------|-------------|
| Árvore Binária de Busca |__1.33×10<sup>-3</sup> ± 1.53×10<sup>-3</sup>__|__5.19×10<sup>-3</sup> ± 5.65×10<sup>-4</sup>__|6.65×10<sup>-2</sup> ± 9.69×10<sup>-3</sup>|7.33×10<sup>-1</sup> ± 5.82×10<sup>-2</sup>|
|       Árvore AVL        |7.80×10<sup>-4</sup> ± 8.64×10<sup>-5</sup>|6.61×10<sup>-3</sup> ± 4.23×10<sup>-4</sup>|__9.18×10<sup>-2</sup> ± 4.70×10<sup>-3</sup>__|__9.31×10<sup>-1</sup> ± 3.22×10<sup>-2</sup>__|
|    Árvore Rubro Negra   |__5.51×10<sup>-4</sup> ± 1.21×10<sup>-4</sup>__|6.23×10<sup>-3</sup> ± 6.95×10<sup>-4</sup>|6.43×10<sup>-2</sup> ± 1.71×10<sup>-3</sup>|6.45×10<sup>-1</sup> ± 1.40×10<sup>-2</sup>|
|          Vector         |6.46×10<sup>-4</sup> ± 3.26×10<sup>-5</sup>|5.90×10<sup>-3</sup> ± 1.97×10<sup>-4</sup>|__5.63×10<sup>-2</sup> ± 3.62×10<sup>-3</sup>__|__4.45×10<sup>-1</sup> ± 5.14×10<sup>-3</sup>__|
|           Map           |9.19×10<sup>-4</sup> ± 1.08×10<sup>-4</sup>|__1.34×10<sup>-2</sup> ± 1.02×10<sup>-2</sup>__|8.62×10<sup>-2</sup> ± 3.03×10<sup>-3</sup>|8.03×10<sup>-1</sup> ± 7.32×10<sup>-2</sup> |
|      Unordered Map      |1.08×10<sup>-3</sup> ± 1.32×10<sup>-4</sup>|9.23×10<sup>-3</sup> ±1.50×10<sup>-3</sup>|7.37×10<sup>-2</sup> ± 4.45×10<sup>-3</sup>|5.98×10<sup>-1</sup> ± 9.81×10<sup>-3</sup>|

Para o arquivo de 500 números, a inserção que apresentou menor resultado, como apresentado e negrito, foi a árvore rubro negra. O tempo de inserção, apesar de pequeno, na ordem de casa 10<sup>-4</sup>, também esteve próximo dos valores encontrados pelo vector (segundo tempo mais rápido) e pela árvore AVL (terceiro tempo mais rápido). A árvore rubro negra e a AVL ser uma das mais rápidas não é surpreentende, visto que as árvores de busca balanceadas são uma das estruturas mais eficientes que conhecemos, e estudadas neste trabalho. O vector estar em segunda posição pode parecer um resultado interessante de primeira, mas o método de inserção utilizado, o push back, apresenta um "tempo amortizado constante".
 
 
</div>

### 3.1 Pesquisa

Para os dados de pesquisa, temos como resultado a seguinte tabela:
<div align="center">

|                         |                    500.txt              |   5000.txt  |  50000.txt  |  500000.txt |
|-------------------------|-----------------------------------------|-------------|-------------|-------------|
| Árvore Binária de Busca |8.36×10<sup>-3</sup> ± 1.84×10<sup>-3</sup>|__7.31×10<sup>-3</sup> ± 1.01×10<sup>-3</sup>__|8.97×10<sup>-3</sup> ± 1.34×10<sup>-3</sup>|8.06×10<sup>-3</sup> ± 1.74×10<sup>-3</sup>|
|       Árvore AVL        |__6.88×10<sup>-3</sup> ± 5.76×10<sup>-4</sup>__|7.44×10<sup>-3</sup> ± 7.58×10<sup>-4</sup>|9.12×10<sup>-0</sup> ± 2.44×10<sup>-3</sup>|8.81×10<sup>-3</sup>±1.20×10<sup>-3</sup>|
|    Árvore Rubro Negra   |6.88×10<sup>-3</sup> ± 1.65×10<sup>-3</sup>|7.35×10<sup>-3</sup> ± 7.55×10<sup>-4</sup>|7.91×10<sup>-0</sup> ± 1.08×10<sup>-3</sup>|7.97×10<sup>-3</sup>±4.77×10<sup>-4</sup>|
|          Vector         |__9.81×10<sup>-3</sup> ± 9.76×10<sup>-4</sup>__|1.09×10<sup>-2</sup> ± 3.85×10<sup>-4</sup>|1.19×10<sup>-0</sup> ± 2.05×10<sup>-3</sup>|1.18×10<sup>-2</sup>±3.14×10<sup>-4</sup>|
|           Map           |9.24×10<sup>-3</sup> ± 4.11×10<sup>-4</sup>|__1.17×10<sup>-2</sup> ± 5.53×10<sup>-4</sup>__|__1.20×10<sup>-0</sup> ± 2.52×10<sup>-3</sup>__|__1.52×10<sup>-2</sup> ± 3.90×10<sup>-3</sup>__|
|      Unordered Map      |8.64×10<sup>-3</sup> ± 1.73×10<sup>-3</sup>|8.71×10<sup>-3</sup> ± 9.26×10<sup>-4</sup>|__6.67×10<sup>-0</sup> ± 8.06×10<sup>-4</sup>__|__6.57×10<sup>-3</sup> ± 6.70×10<sup>-5</sup>__|

</div>


### 3.3 Remoção

Para os dados de remoção, temos como resultado a seguinte tabela:
<div align="center">

|                         |                     500.txt                   |                  5000.txt                 |             50000.txt                      |               500000.txt                  |
|-------------------------|-----------------------------------------------|-------------------------------------------|-------------|-------------|
| Árvore Binária de Busca |__4.56×10<sup>-3</sup> ± 7.30×10<sup>-4</sup>__|__8.54×10<sup>-3</sup> ± 1.97×10<sup>-4</sup>__|8.97×10<sup>-3</sup> ± 1.34×10<sup>-3</sup>|__1.57×10<sup>-2</sup> ± 1.85×10<sup>-3</sup>__|
|       Árvore AVL        |5.52×10<sup>-3</sup> ± 6.96×10<sup>-4</sup>|1.29×10<sup>-2</sup> ± 2.07×10<sup>-4</sup>|9.12×10<sup>-3</sup> ± 2.44×10<sup>-3</sup>|3.36×10<sup>-2</sup> ± 9.33×10<sup>-4</sup>|
|    Árvore Rubro Negra   |5.71×10<sup>-3</sup> ± 9.63×10<sup>-4</sup>|1.75×10<sup>-2</sup> ± 4.89×10<sup>-4</sup>|7.91×10<sup>-3</sup> ± 1.08×10<sup>-3</sup>|3.83×10<sup>-2</sup> ± 1.90×10<sup>-3</sup>|
|          Vector         |__1.07×10<sup>-2</sup> ± 1.67×10<sup>-4</sup>__|__1.67×10<sup>-1</sup> ± 2.52×10<sup>-4</sup>__|1.19×10<sup>-2</sup> ± 2.05×10<sup>-3</sup>|__2.88×10<sup>1</sup> ± 4.68×10<sup>-1</sup>__|
|           Map           |9.40×10<sup>-3</sup> ± 2.97×10<sup>-4</sup>|3.08×10<sup>-2</sup> ± 9.63×10<sup>-4</sup>|__1.20×10<sup>-2</sup> ± 2.52×10<sup>-3</sup>__|6.47×10<sup>-2</sup> ± 4.38×10<sup>-3</sup>|
|      Unordered Map      |7.79×10<sup>-3</sup> ± 6.75×10<sup>-4</sup>|2.31×10<sup>-2</sup> ± 1.55×10<sup>-4</sup>|__6.68×10<sup>-3</sup> ± 8.06×10<sup>-4</sup>__|3.57×10<sup>-2</sup> ± 1.96×10<sup>-3</sup>|

</div>


## 4. Conclusão
 
## 5. Compilação e Execução

O algoritmo disponibilizado possui um arquivo makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
|  `make r`              | Apaga, builda e executa o programa                                                                |

</div>


## 6. Referências Bibliogŕaficas

P. Feofiloff. **_Análise de Algoritmos_**. Internet: http://www.ime.usp.br/~pf/analise_de_algoritmos/, 1999–2009
 

</div>


