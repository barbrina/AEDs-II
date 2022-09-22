<img align="right" width="100" height="100" src="img/binarytree.png">

# Código de Huffman

## Árvore Binária

<p> Uma árvore binária (= binary tree) é um conjunto de registros que satisfaz certas condições. Os registros serão chamados nós (poderiam também ser chamados células).  Cada nó tem um endereço.  Suporemos por enquanto que cada nó tem apenas três campos:  um número inteiro e dois ponteiros para nós.  Os nós podem, então, ser definidos assim: </p>

<div align="center">
 <p> </p>
 <img src="img/conteudo.png">
 <p> </p>
</div>

<p> O campo conteudo é a "carga útil" do nó;  os dois outros campos servem apenas para dar estrutura à árvore.  O campo esq de cada nó contém NULL ou o endereço de outro nó.  Uma hipótese análoga vale para o campo dir. Se o campo esq de um nó P é o endereço de um nó E, diremos que E é o filho esquerdo de P.  Analogamente, se P.dir é igual a &D, diremos que D é o filho direito de P.  Se um nó F é filho (esquerdo ou direito) de P, diremos que P é o pai de F.  Uma folha (= leaf) é um nó que não tem filho algum. </p>

<p> É muito conveniente confundir, verbalmente, cada nó com seu endereço.  Assim, se x é um ponteiro para um nó (ou seja, se x é do tipo *noh), dizemos  "considere o nó x"  em lugar de  "considere o nó cujo endereço é x". A figura abaixo mostra dois exemplos de árvores binárias. A seguir, uma representação esquemática de uma árvore binária cujos nós contêm os números 2, 7, 5, etc. </p>

<div align="center">
 <p> </p>
 <img src="img/tree.png">
 <p> </p>
</div>

## Árvore de Huffman

<p> Trata-se de uma codificação de caracteres que permite compactar arquivos de texto, ou seja, representar um arquivo de texto A por um arquivo de bits B bem menor. O algoritmo de Huffman calcula uma tabela de códigos sob medida para o arquivo A de modo que o arquivo B seja o menor possível. O algoritmo de Huffman é um bom exemplo de algoritmo guloso. O texto desta página é uma versão melhorada da seção 3, capítulo 16, de CLRS.  </p>


> **Algoritmo guloso**
> Estratégia gulosa é aquela usada por um montanhista que decide caminhar sempre "para cima", na direção de "maior subida", na esperança de assim chegar ao pico mais alto da montanha. (Como todos sabemos, essa estratégia nem sempre produz o resultado esperado). Um algoritmo guloso escolhe, em cada iteração, o objeto mais "apetitoso" que vê pela frente. (A definição de "apetitoso" é estabelecida a priori, antes da execução do algoritmo.) O objeto escolhido passa a fazer parte da solução que o algoritmo constrói.

<p> </p>

#### Desempenho

<p> Se a fila-com-prioridades for implementada como um vetor ordenado, cada execução de inserir na fila e extrair o mínimo elemenrp consumirá Ο(m) unidades de tempo, sendo m o número de células na fila Q. Como m ≤ n e há n repetições do bloco de linhas 1 a 7 e n−1 repetições do bloco de linhas 9 a 15, o consumo de tempo total do algoritmo será $Ο(n²)$.  Se a fila-com-prioridades for implementada como um min-heap (veja um dos exercícios abaixo), cada execução de Insere-na-Fila e Extrai-Min consumirá $O(n lg n)$ unidades de tempo. Com isso, o consumo total será de </p>


$O(n lg n)$

<p> unidades de tempo.  </p>


## Desenvolvimento do Problema
  
## Compilação e Execução


O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>

# Contato

<div>
<p align="justify"> Bárbara Gualberto</p>
<a href="https://t.me/barbrinas">
<img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 
 <a href="[https://www.linkedin.com/in/thaissa-vitoria-daldegan-6a84b9153/](https://www.linkedin.com/in/barbara-gualberto/)">
<img align="center"  src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>
</div>
