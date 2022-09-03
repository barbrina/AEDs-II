<div style="display: inline-block;">
<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> 
<img src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white"/> 
<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/> 
</a> 
</div>

# Trabalho de Aquecimento: Processamento de matrizes por segmentação de arquivo

<p> Neste trabalho, cada aluno deve implementar um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo M grande é fornecido no formato NxN com valores de ponto flutuante ou inteiros como entrada. Este é processado a partir de várias coordenadas introduzidas por um segundo arquivo, o coordenadas.txt. Em coordenadas.txt deve ser descrito por linha uma dupla de i e j correspondendo a posição inicial e final a ser lida. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10.  </p>

<p>Feito a leitura da composição de M para um tipo matriz em C, a segunda etapa é produzir a transposta de M -= MT. Feito isso, produza a multiplicação e armazene em uma hash o resultado da multiplicação como valor para a dupla de i's e j's, os quais deverão ser utilizados como chaves da hash. Assim, para cada novo calculo, antes o sistema deve consular a hash para identificar se a multiplicação já foi realizada. Em caso afirmativo, retorne apenas a resposta já calculada. Caso contrário, elabore a multiplicação e armazene o conteúdo em cache.  </p>

## Mapa não ordenado

<p>Em C++, o STL unordered_map é um contêiner associado que armazena elementos formados pela combinação de um valor-chave e um valor mapeado. O valor da chave é usado para identificar exclusivamente o elemento e o valor mapeado é o conteúdo associado à chave. Tanto a chave quanto o valor podem ser de qualquer tipo predefinido ou definido pelo usuário.</p>

<p>O unordered_map interno é implementado usando a tabela de hash , a chave fornecida para mapear é convertida em índices de uma tabela de hash, é por isso que o desempenho da estrutura de dados depende muito da função hash, mas em média, o custo de pesquisa, inserção e exclusão do a tabela hash é O (1). </p>

### Métodos em unordered_map 
<p>Muitas funções estão disponíveis que funcionam em unordered_map. os mais úteis deles são - operator =, operator [], empty e size for capacity, start e end para o iterator, find e contar para lookup, insert e apaga para modificação.</p>
<p>A biblioteca C++ 11 também fornece funções para ver a contagem de intervalos usados internamente, o tamanho dos intervalos e também a função hash usada e várias políticas de hash, mas são menos úteis em aplicativos reais. Podemos iterar sobre todos os elementos de unordered_map usando Iterator.</p>

## Desenvolvimento do problema

<p>  O problema foi desenvolvido da seguinte maneira: </p>

<p> 1) Um mapa não ordenado é criado: </p>

```unordered_map<string, vector<vector<int>>> umap;```
<p> onde string indicação do tipo de dados para a chave, e vector<vector<int>> indica o tipo de dados para o valor.</p>

<p> 2) Em seguida, a função para abertura de arquivo é chamada e nela é passada o mapa não ordenado declarado. </p>

<p> 3) Em arquivo.cpp, o coordenadas.txt é aberto e suas coordenadas são lidas e passadas para uma string, que será utilizada como chave da unordered_map, e seus valores são passados para variáveis do tipo inteiro, que serão utilizadas para calcular o tamanho da matriz. </p>

<p> 4) A matriz e sua transposta do tipo data são declaradas e criadas. </p>

<p> 5) O arquivo.txt posteriormente é aberto, e nele a matriz criada é preenchida após receber os valores das coordenadas através do método PreencherMatriz(lin, col, num, matriz); </p>

<p> 6) A sua transposta é calculada e preenchida através da matriz inicial e em seguida, a multiplicação é feita em uma nova matriz. </p>

<p> 7) Por fim, a matriz de data é transformada em uma matriz de vector por vector e ela será utilizada como valor na unordered_map. Todas as inserções na hash são mostradas na tela, assim como as não inserções, por duas coordenadas terem a mesma chave. </p>


# Compilação e Execução

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
