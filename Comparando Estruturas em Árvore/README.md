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

 |                        |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.000454  |   0.000565  |  0.000592   |   0.000766  |  0.000644   |             |               |
|       Árvore AVL        |   0.00087   |  0.000829   |   0.00086   |   0.000755  |   0.001052  |             |               |
|    Árvore Rubro Negra   |   0.000688  |  0.000592   |  0.001006   |   0.000936  |   0.000458  |             |               |
|          Vector         |     0.0008  |    0.00062  |  0.000555   |   0.000599  |   0.000503  |             |               |
|           Map           |   0.001095  |   0.001189  |   0.000896  |   0.001026  |   0.00116   |             |               |
|      Unordered Map      |   0.001198  |  0.001116   |   0.000823  |   0.001124  |   0.00108   |             |               |

</div>

Pesquisa e Remoção de um arquivo de 500 números ponto flutuante:

<div align="center">
 
 
|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.006275  |  0.006395   |  0.005752   |   0.00566   |  0.005253   |             |               |
|       Árvore AVL        |   0.007461  |   0.004426  |  0.004426   |   0.006576  |   0.00891   |             |               |
|    Árvore Rubro Negra   |   0.008835  |   0.009903  |   0.00897   |   0.006972  |   0.006877  |             |               |
|          Vector         |   0.012811  |   0.009262  |   0.012507  |   0.013101  |   0.010496  |             |               |
|           Map           |    0.0092   |   0.009689  |  0.011002   |   0.010637  |   0.012894  |             |               |
|      Unordered Map      |    0.008057 |   0.008969  |  0.008361   |   0.008865  |   0.007437  |             |               |



</div>

Inserção de um arquivo de 5000 números ponto flutuante:
 
<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.00554   |   0.00567   |   0.005143  |   0.007249  |   0.006432  |             |               |
|       Árvore AVL        |   0.009634  |  0.009166   |   0.006953  |   0.007784  |   0.007046  |             |               |
|    Árvore Rubro Negra   |   0.005589  |   0.005924  |   0.004822  |   0.00562   |   0.003766  |             |               |
|          Vector         |   0.006479  |   0.004707  |   0.006548  |   0.00058   |   0.004009  |             |               |
|           Map           |   0.006908  |   0.009252  |  0.009244   |   0.008086  |   0.007862  |             |               |
|      Unordered Map      |   0.007475  |   0.008489  |   0.005269  |  0.008002   |    0.007241 |             |               |

</div>

Remoção de um arquivo de 5000 números ponto flutuante:

<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.0083590  |   0.010444  |   0.009444  |   0.010492  |  0.009875   |             |               |
|       Árvore AVL        |   0.017379  |   0.014923  |   0.017109  |   0.015605  |   0.01541   |             |               |
|    Árvore Rubro Negra   |   0.017315  |    0.02055  |   0.020513  |    0.01666  |   0.017724  |             |               |
|          Vector         |   0.117351  |   0.113186  |   0.112088  |  0.008239   |   0.107471  |             |               |
|           Map           |   0.027272  |  0.031467   |  0.023358   |  0.030827   |  0.029114   |             |               |
|      Unordered Map      |   0.024507  |   0.025074  |   0.021256  |   0.024062  |  0.028397   |             |               |

</div>

Inserção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.073072  |  0.067931   |   0.074196  |   0.080643  |   0.073793  |             |               |
|       Árvore AVL        |   0.121564  |   0.115939  |   0.106998  |   0.09419   |   0.096649  |             |               |
|    Árvore Rubro Negra   |   0.071888  |   0.070847  |   0.069242  |   0.001724  |  0.067585   |             |               |
|          Vector         |   0.056508  |   0.057604  |   0.056282  |   0.057469  |  0.057135   |             |               |
|           Map           |   0.092687  |   0.102059  |   0.10056   |   0.113921  |   0.102057  |             |               |
|      Unordered Map      |   0.095221  |   0.093718  |   0.086654  |  0.087158   |   0.087439  |             |               |

</div>

Remoção de um arquivo de 50000 números ponto flutuante:

<div align="center">

|                         |     T1      |     T2      |     T3      |     T4      |     T5      |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.012799   |  0.014563   |   0.013569  |  0.014406   |  0.015831   |             |               |
|       Árvore AVL        |   0.030427  |  0.029804   |  0.032398   |  0.028537   |   0.031145  |             |               |
|    Árvore Rubro Negra   |   0.032185  |   0.035801  |   0.039549  |   0.00664   |  0.036546   |             |               |
|          Vector         |    2.9708   |   3.0776    |   3.07474   |   2.98938   |  2.89139    |             |               |
|           Map           |    0.05366  |   0.058299  |   0.055025  |   0.060196  |  0.055195   |             |               |
|      Unordered Map      |   0.031762  |  0.036498   |   0.037343  |  0.040638   |  0.040248   |             |               |

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


