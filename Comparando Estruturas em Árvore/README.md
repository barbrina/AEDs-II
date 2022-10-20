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

 Cinco leituras foram feitas em cada tipo de arquivo para termos a média e o desvio padrão do tempo necessário para inserção e remoção
 
 Inserção de um arquivo de 500 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.000764   |   0.000538  |   0.000656  |   0.000619  |  0.004057   |  0.001327   |   0.001528    |
|       Árvore AVL        |  0.000793   |  0.000719   |   0.00075   |  0.000924   |   0.000714  |  0.000780	  |   0.000086    |
|    Árvore Rubro Negra   |  0.000491   |  0.000585   |   0.000545  |   0.000404  |   0.00073   |  0.000551	  |   0.000121    |
|          Vector         |   0.00065   |   0.000591  |  0.000654   |   0.000657  |  0.000678   |  0.000646	  |   0.000033    |
|           Map           |  0.001035   |   0.000762  |  0.000884   |   0.000907  |  0.001006   |  0.000919	  |   0.000108    |
|      Unordered Map      |  0.000929   |  0.001194   |  0.001124   |   0.001193  |  0.000943   |  0.001077	  |   0.000132    |

</div>

Pesquisa de um arquivo de 500 números ponto flutuante:

<div align="center">
 

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.009197   |   0.006721  |   0.007748  |   0.006972  |  0.01117    |  0.008362	  |    0.001843   |
|       Árvore AVL        |   0.006994  |   0.006652  |   0.006094  |   0.006957  |   0.007678  |  0.006875	  |    0.000576   |
|    Árvore Rubro Negra   |  0.008644   |  0.006878   |   0.007911  |  0.004304   |  0.006647   |  0.006877	  |    0.001648   |
|          Vector         |   0.009387  |   0.011369  |  0.009175   |   0.008984  |   0.010153  |  0.009814	  |    0.000976   |
|           Map           |   0.009203  |   0.009008  |  0.009952   |  0.009093   |  0.008937   |  0.009239	  |    0.000411   |
|      Unordered Map      |  0.008263   |  0.011281   |  0.007188   |   0.009342  |  0.007132   |  0.008641   |   	0.001731   |

</div>

Remoção de um arquivo de 500 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.005749  |   0.004327  |  0.003944   |   0.004057  |  0.004742   |  0.0045638  |	  0.000730    |
|       Árvore AVL        |   0.005955  |   0.00558   |  0.006366   |   0.004593  |  0.005109   |  0.0055206  |	  0.000696    |
|    Árvore Rubro Negra   |   0.006535  |   0.005013  |  0.006956   |   0.004927  |  0.005095   |  0.0057052	 |   0.000963    |
|          Vector         |   0.010889  |  0.010623   |  0.010914   |   0.010639  |  0.010547   |  0.0107224  |	  0.00016     |
|           Map           |   0.009362  |  0.009628   |  0.009498   |   0.00891   |  0.009624   |  0.0094044  |	  0.000297    |
|      Unordered Map      |   0.00714   |   0.008161  |  0.007085   |   0.008657  |  0.007911   |  0.0077908  |	  0.00067     |

</div>

Inserção de um arquivo de 5.000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.005644   |   0.004442  |  0.00519    |   0.005824  |  0.004861   |  0.0051922  |	  0.000565    |
|       Árvore AVL        |  0.006576   |  0.007042   |   0.005985  |  0.006476   |  0.006954   |  0.0066066  |  	0.000423    | 
|    Árvore Rubro Negra   |  0.006153   |  0.006194   |   0.006026  |  0.005444   |  0.007355   |  0.0062344	 |   0.000695    |
|          Vector         |   0.00588   |  0.00589    |   0.00563   |  0.006184   |  0.005939   |  0.0059046	 |   0.000197    |
|           Map           |   0.00796   |   0.0106    |   0.00826   |  0.031537   |  0.008666   |  0.0134046	 |   0.010188    |
|      Unordered Map      |  0.010811   |  0.010085   |   0.009117  |   0.009288  |  0.006834   |  0.009227	  |   0.001499    |

</div>

Pesquisa de um arquivo de 5.000 números ponto flutuante:

<div align="center">
 
|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.006511   |  0.007851   |   0.006362  |   0.007029  |  0.008783   |  0.0073072	 |   0.001010    |
|       Árvore AVL        |  0.007013   |  0.008676   |  0.007557   |   0.007259  |  0.006703   |  0.0074416	 |   0.000758    | 
|    Árvore Rubro Negra   |  0.007544   |   0.007723  |  0.006026   |    0.00756  |  0.007903   |  0.0073512  |   0.000755    |
|          Vector         |  0.011331   |   0.010565  |  0.011294   |  0.010526   |   0.010875  |  0.0109182	 |   0.000385    |
|           Map           |   0.011004  |  0.011315   |  0.012466   |  0.011669   |  0.011816   |  0.011654	  |   0.000553    |
|      Unordered Map      |  0.008879   |  0.009628   |   0.008584  |  0.009263   |  0.007215   |  0.0087138  |  	0.000926    |

</div>

Remoção de um arquivo de 5.000 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.008566   |   0.008447  |  0.008279   |   0.00861   |  0.008811   |  0.0085426	 |   0.000197    |
|       Árvore AVL        |  0.012553   |   0.012891  |  0.013062   |  0.013054   |   0.012918  |  0.0128956	 |   0.000207    | 
|    Árvore Rubro Negra   |  0.017271   |  0.017946   |  0.017489   |  0.017978   |  0.016811   |  0.017499	  |   0.000489    |
|          Vector         |  0.16561    |   0.164137  |  0.170774   |  0.166634   |  0.165677   |  0.1665664	 |   0.002516    |
|           Map           |  0.029356   |  0.030549   |   0.031537  |   0.030616  |  0.031794   |  0.0307704	 |   0.000963    |
|      Unordered Map      |  0.023283   |  0.022707   |   0.0254    |   0.02288   |   0.021084  |  0.0230708	 |   0.001548    |
 

</div>
Inserção de um arquivo de 50.000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.050654   |   0.066122  |   0.076079  |  0.072097   |  0.067507   |  0,0664918  |   	0,009687   |
|       Árvore AVL        |   0.088361  |   0.094486  |   0.098818  |   0.089525  |   0.08793   |  0,091824	  |    0,004702   | 
|    Árvore Rubro Negra   |  0.063575   |   0.06645   |  0.065516   |   0.064131  |  0.062066   |  0,0643476	 |    0,001705   |
|          Vector         |  0.059944   |   0.05573   |    0.05949  |  0.055502   |   0.05101   |  0,0563352  |   	0,003619   |
|           Map           |  0.087664   | 0.088532    | 0.088867    |  0.08275    |  0.083032   |  0,086169	  |    0,003026   |
|      Unordered Map      |  0.067627   |    0.072097 |  0.075882   |   0.073441  |   0.079601  |  0,0737296  |   	0,004447   |

</div>

Pesquisa de um arquivo de 50.000 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |   0.010436  |   0.00744   |   0.010297  |  0.008597   |   0.0081    |  0.008974	  |   0.001337    |
|       Árvore AVL        |  0.00665    |  0.009124   |  0.011264   |  0.00673    |  0.011849   |  0.0091234  |  	0.002442    | 
|    Árvore Rubro Negra   |  0.008045   |  0.008898   |  0.008062   |  0.008457   |  0.006077   |  0.0079078	 |   0.001081    |
|          Vector         |  0.010481   |  0.014666   |   0.010119  |  0.010789   |  0.013553   |  0.0119216  |	  0.002049    |
|           Map           |  0.011151   |   0.010778  | 0.01075     |  0.01091    |  0.016518   |  0.0120214	 |   0.002519    |
|      Unordered Map      |   0.006398  | 0.005876    |  0.007945   |  0.006909   |   0.006213  |  0.0066682  |  	0.000806    |

</div>

Remoção de um arquivo de 50.000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.014771   |  0.012557   |  0.015321   |  0.012875   |   0.015293  |   0.008974	 |    0.001337   |
|       Árvore AVL        |   0.026788  |  0.025523   |  0.026165   |  0.022178   |   0.028153  |   0.0091234	|    0.002442   | 
|    Árvore Rubro Negra   |  0.032819   |   0.03043   |  0.034257   |  0.026354   |   0.032657  |   0.0079078	|    0.001081   |
|          Vector         |  3.50027    |  3.77001    |   3.51045   |  3.51056    |   3.475     |   0.0119216	|    0.002049   |
|           Map           |  0.051083   |  0.052205   |  0.051429   |  0.051722   |   0.056262  |   0.0120214	|    0.002519   |
|      Unordered Map      |  0.032663   |  0.035902   |    0.034709 |  0.033384   |   0.030918  |   0.0066682	|    0.000806   |

</div>

Inserção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.635613   |   0.784688  |0.730763     |0.745904     |   0.76805   |  0.7330036	 |   0.058215    |
|       Árvore AVL        |0.911839     |0.896133     |0.972168     |0.917467     |   0.957403  |  0.931002	  |   0.032241    | 
|    Árvore Rubro Negra   |0.658957     |0.625627     |0.65871      |0.642942     |   0.640374  |  0.645322	  |   0.013993    |
|          Vector         |0.45212      |0.443821     |0.445571     |0.445728     |   0.437731  |  0.4449942	 |   0.005142    |
|           Map           |0.807353     |0.751685     |0.759954     |0.92795      |   0.766622  |  0.8027128	 |   0.073213    |
|      Unordered Map      |0.600294     |0.582994     |0.610187     |0.600314     |   0.597288  |  0.5982154	 |   0.009806    |

</div>

Pesquisa de um arquivo de 50000 números ponto flutuante:

<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.006047   | 0.008432    |0.010765     |0.007588     |0.007489     |  0.0080642  |  	0.001736    |
|       Árvore AVL        |0.008011     |0.007911     |0.010638     |0.008032     |0.009449     |  0.0088082	 |   0.001204    | 
|    Árvore Rubro Negra   |0.008729     |0.007548     |0.007579     |0.007955     |0.008037     |  0.0079696	 |   0.000477    |
|          Vector         |0.011521     |0.011712     |0.012095     |0.011444     |0.012114     |  0.0117772  | 	 0.000314    |
|           Map           |0.013554     |0.013234     |0.013475     |0.022202     |0.013721     |  0.0152372  |  	0.003897    |
|      Unordered Map      |0.006586     |0.006495     |0.006676     |0.006553     |0.006546     |  0.0065712	 |   0.000067    |

</div>

Remoção de um arquivo de 50000 números ponto flutuante:
 
<div align="center">

|                         |     T1(s)   |     T2(s)   |     T3(s)   |     T4(s)   |     T5(s)   |    Média    | Desvio Padrão |
|-------------------------|-------------|-------------|-------------|-------------|-------------|-------------|---------------|
| Árvore Binária de Busca |  0.012725   |0.016414     |0.015906     |0.017777     |0.015922     |  0.0157488  |  	0.001854    |
|       Árvore AVL        |0.033542     |0.032908     |0.034129     |0.034799     |0.032466     |  0.0335688	 |   0.000933    | 
|    Árvore Rubro Negra   |0.03609      |0.038004     |0.038087     |0.041365     |0.038116     |  0.0383324	 |   0.001900    |
|          Vector         |28.6715      |28.29        |29.4865      |29.1053      |28.5992      |  28.8305	   |   0.468181    |
|           Map           |0.067147     |0.063261     |0.06127      |0.071188     |0.060832     |  0.0647396  |  	0.004384    |
|      Unordered Map      |0.037267     |0.033994     |0.033242     |0.036448     |0.037531     |  0.0356964 	|   0.001957    |

</div>

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


