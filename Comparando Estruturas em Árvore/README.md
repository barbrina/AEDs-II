<div align="justify">

<img align="right" width="100" height="100" src="img/binarytree.png">

# Comparando Estruturas em Árvore

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

 Cinco leituras foram feitas em cada tipo de arquivo para termos a média e o desvio padrão do tempo necessário para inserção e remoção
 
 Inserção de um arquivo de 500 números ponto flutuante:
 
<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Remoção de um arquivo de 500 números ponto flutuante:

<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Inserção de um arquivo de 5000 números ponto flutuante:
 
<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Remoção de um arquivo de 5000 números ponto flutuante:

<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Inserção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Remoção de um arquivo de 50000 números ponto flutuante:

<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Inserção de um arquivo de 500000 números ponto flutuante:
 
<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Remoção de um arquivo de 500000 números ponto flutuante:

<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |             |             |             |             |             |             |               |
|       Árvore AVL        |             |             |             |             |             |             |               |
|    Árvore Rubro Negra   |             |             |             |             |             |             |               |
|          Vector         |             |             |             |             |             |             |               |
|           Map           |             |             |             |             |             |             |               |
|      Unordered Map      |             |             |             |             |             |             |               |

</div>

Temos como resultado a seguinte tabela

<div align="center">

|                         |   500.txt   |   5000.txt  |  50000.txt  |  500000.txt |
|-------------------------|-------------|-------------|-------------|-------------|
| Árvore Binária de Busca |             |             |             |             |
|       Árvore AVL        |             |             |             |             |
|    Árvore Rubro Negra   |             |             |             |             |
|          Vector         |             |             |             |             |
|           Map           |             |             |             |             |
|      Unordered Map      |             |             |             |             |

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


