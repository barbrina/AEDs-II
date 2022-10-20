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

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.000764   |   0.000538  |   0.000656  |   0.000619  |  0.004057   |             |               |
|       Árvore AVL        |  0.000793   |  0.000719   |   0.00075   |  0.000924   |   0.000714  |             |               |
|    Árvore Rubro Negra   |  0.000491   |  0.000585   |   0.000545  |   0.000404  |   0.00073   |             |               |
|          Vector         |   0.00065   |   0.000591  |  0.000654   |   0.000657  |  0.000678   |             |               |
|           Map           |  0.001035   |   0.000762  |  0.000884   |   0.000907  |  0.001006   |             |               |
|      Unordered Map      |  0.000929   |  0.001194   |  0.001124   |   0.001193  |  0.000943   |             |               |

</div>

Pesquisa de um arquivo de 500 números ponto flutuante:

<div align="center">
 

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.009197   |   0.006721  |   0.007748  |   0.006972  |  0.01117    |             |               |
|       Árvore AVL        |   0.006994  |   0.006652  |   0.006094  |   0.006957  |   0.007678  |             |               |
|    Árvore Rubro Negra   |  0.008644   |  0.006878   |   0.007911  |  0.004304   |  0.006647   |             |               |
|          Vector         |   0.009387  |   0.011369  |  0.009175   |   0.008984  |   0.010153  |             |              |
|           Map           |   0.009203  |   0.009008  |  0.009952   |  0.009093   |  0.008937   |             |               |
|      Unordered Map      |  0.008263   |  0.011281   |  0.007188   |   0.009342  |  0.007132   |             |               |

</div>

Remoção de um arquivo de 500 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.005749  |   0.004327  |  0.003944   |   0.004057  |  0.004742   |             |               |
|       Árvore AVL        |   0.005955  |   0.00558   |  0.006366   |   0.004593  |   0.005109  |             |               |
|    Árvore Rubro Negra   |   0.006535  |   0.005013  |  0.006956   |   0.004927  |  0.005095   |             |               |
|          Vector         |   0.010889  |  0.010623   |  0.010914   |   0.010639  |   0.010547  |             |               |
|           Map           |   0.009362  |  0.009628   |  0.009498   |   0.00891   |   0.009624  |             |               |
|      Unordered Map      |   0.00714   |   0.008161  |  0.007085   |   0.008657  |  0.007911   |             |               |

</div>

Inserção de um arquivo de 5000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.005644   |   0.004442  |  0.00519    |   0.005824  |  0.004861   |             |               |
|       Árvore AVL        |  0.006576   |  0.007042   |   0.005985  |  0.006476   |  0.006954   |             |               | 
|    Árvore Rubro Negra   |  0.006153   |  0.006194   |   0.006026  |  0.005444   |  0.007355   |             |               |
|          Vector         |   0.00588   |  0.00589    |   0.00563   |  0.006184   |  0.005939   |             |               |
|           Map           |   0.00796   |   0.0106    |   0.00826   |  0.031537   |  0.008666   |             |               |
|      Unordered Map      |  0.010811   |  0.010085   |   0.009117  |   0.009288  |  0.006834   |             |               |

</div>

Pesquisa de um arquivo de 5000 números ponto flutuante:

<div align="center">
|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.006511   |  0.007851   |   0.006362  |   0.007029  |  0.008783   |             |               |
|       Árvore AVL        |  0.007013   |  0.008676   |  0.007557   |   0.007259  |  0.006703   |             |               | 
|    Árvore Rubro Negra   |  0.007544   |   0.007723  |  0.006026   |    0.00756  |  0.007903   |             |               |
|          Vector         |  0.011331   |   0.010565  |  0.011294   |  0.010526   |   0.010875  |             |               |
|           Map           |   0.011004  |  0.011315   |  0.012466   |  0.011669   |  0.011816   |             |               |
|      Unordered Map      |  0.008879   |  0.009628   |   0.008584  |  0.009263   |  0.007215s  |             |               |

</div>

Remoção de um arquivo de 500 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.008566   |   0.008447  |  0.008279   |   0.00861   |  0.008811   |             |               |
|       Árvore AVL        |  0.012553   |   0.012891  |  0.013062   |  0.013054   |   0.012918  |             |               | 
|    Árvore Rubro Negra   |  0.017271   |  0.017946   |  0.017489   |  0.017978   |  0.016811   |             |               |
|          Vector         |  0.16561    |   0.164137  |  0.170774   |  0.166634   |  0.165677   |             |               |
|           Map           |  0.029356   |  0.030549   |   0.031537  |   0.030616  |  0.031794   |             |               |
|      Unordered Map      |  0.023283   |  0.022707   |   0.0254    |   0.02288   |   0.021084  |             |               |

</div>
Inserção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.050654   |   0.066122  |   0.076079  |  0.072097   |  0.067507   |             |               |
|       Árvore AVL        |   0.088361  |   0.094486  |   0.098818  |   0.089525  |   0.08793   |             |               | 
|    Árvore Rubro Negra   |  0.063575   |   0.06645   |  0.065516   |   0.064131  |  0.062066   |             |               |
|          Vector         |  0.059944   |   0.05573   |    0.05949  |  0.055502   |   0.05101   |             |               |
|           Map           |  0.087664   | 0.088532    | 0.088867    |  0.08275    |  0.083032   |             |               |
|      Unordered Map      |  0.067627   |    0.072097 |  0.075882   |   0.073441  |   0.079601  |             |               |
</div>

Pesquisa de um arquivo de 50000 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.010436  |   0.00744   |   0.010297  |  0.008597   |   0.0081    |             |               |
|       Árvore AVL        |  0.00665    |  0.009124   |  0.011264   |  0.00673    |  0.011849   |             |               | 
|    Árvore Rubro Negra   |  0.008045   |  0.008898   |  0.008062   |  0.008457   |  0.006077   |             |               |
|          Vector         |  0.010481   |  0.014666   |   0.010119  |  0.010789   |  0.013553   |             |               |
|           Map           |  0.011151   |   0.010778  | 0.01075     |  0.01091    |  0.016518   |             |               |
|      Unordered Map      |   0.006398  | 0.005876    |  0.007945   |  0.006909   |   0.006213  |             |               |
 
</div>

Remoção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.014771   |  0.012557   |  0.015321   |  0.012875   |  0.015293   |             |               |
|       Árvore AVL        |   0.026788  |  0.025523   |  0.026165   |  0.022178   |  0.028153   |             |               | 
|    Árvore Rubro Negra   |  0.032819   |   0.03043   |  0.034257   |  0.026354   |   0.032657  |             |               |
|          Vector         |  3.50027    |  3.77001    |   3.51045   |  3.51056    |     3.475   |             |               |
|           Map           |  0.051083   |  0.052205   |  0.051429   |  0.051722   |  0.056262   |             |               |
|      Unordered Map      |  0.032663   |  0.035902   |    0.034709 |  0.033384   | 0.030918    |             |               |

</div>

Inserção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.635613   |   0.784688  |0.730763     |0.745904     |0.76805      |             |               |
|       Árvore AVL        |0.911839     |0.896133     |0.972168     |0.917467     |0.957403     |             |               | 
|    Árvore Rubro Negra   |0.658957     |0.625627     |0.65871      |0.642942     |0.640374     |             |               |
|          Vector         |0.45212      |0.443821     |0.445571     |0.445728     |0.437731     |             |               |
|           Map           |0.807353     |0.751685     |0.759954     |0.92795      |0.766622     |             |               |
|      Unordered Map      |0.600294     |0.582994     |0.610187     |0.600314     |0.597288     |             |               |
</div>

Pesquisa de um arquivo de 50000 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.006047   | 0.008432    |0.010765     |0.007588     |0.007489     |             |               |
|       Árvore AVL        |0.008011     |0.007911     |0.010638     |0.008032     |0.009449     |             |               | 
|    Árvore Rubro Negra   |0.008729     |0.007548     |0.007579     |0.007955     |0.008037     |             |               |
|          Vector         |0.011521     |0.011712     |0.012095     |0.011444     |0.012114     |             |               |
|           Map           |0.013554     |0.013234     |0.013475     |0.022202     |0.013721     |             |               |
|      Unordered Map      |0.006586     |0.006495     |0.006676     |0.006553     |0.006546     |             |               |
 
</div>

Remoção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.012725   |0.016414     |0.015906     |0.017777     |0.015922     |             |               |
|       Árvore AVL        |0.033542     |0.032908     |0.034129     |0.034799     |0.032466     |             |               | 
|    Árvore Rubro Negra   |0.03609      |0.038004     |0.038087     |0.041365     |0.038116     |             |               |
|          Vector         |28.6715      |28.29        |29.4865      |29.1053      |28.5992      |             |               |
|           Map           |0.067147     |0.063261     |0.06127      |0.071188     |0.060832     |             |               |
|      Unordered Map      |0.037267     |0.033994     |0.033242     |0.036448     |0.037531     |             |               |

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


