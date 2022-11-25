<div align="justify">

<img align="right" width="100" height="100" src="img/twitter_icon.png">

# Analisando conexões de perfis pessoais do Twitter

<div style="display: inline-block;">
<img src="https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white"/> 
<img src="https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white"/> 
</a> 
</div>

## 1. Grafos

A ideia básica de grafos surgiu com o matemático Leonhard Euler no século XVIII (1735). Ele usou grafos para resolver o famoso problema das 7 pontes de Konigsberg.


<div align="center">
 <p> </p>
 <img src="img/cidade.webp">
  <p> </p>
 <figcaption>Configuração das pontes na cidade de Königsberg. </figcaption>
 <p> </p>
</div>

> *A cidade de Königsberg, na Prússia, foi definida em ambos os lados do rio Pregel , e incluía duas grandes ilhas — Kneiphof e Lomse — que estavam conectadas entre si, ou às duas porções continentais da cidade, por 7 pontes. O problema era planejar um passeio pela cidade que cruzasse cada uma dessas pontes uma vez e apenas uma vez.*

A solução de Euler foi primeiro remover tudo que fosse irrelevante ao problema, ou seja, remover as cidades próximas, ruas conectadas e deixou apenas o que precisava em vértices que se ligavam baseado nas rotas possíveis. Isso permitiu a ele formular o problema de forma abstrata, iniciando o que temos hoje em teoria dos grafos.

Por que é necessário saber teoria dos grafos? Para responder esta pergunta, utilizaremos um exemplo de aplicação muito comum atualmente. Suponha que um ponto representa uma pessoa, e que linhas entre esses pontos representam relações juntando pares de pessoas que você segue. Então no final para cada pessoa que você seguir vai ter uma ligação. Se for analisado o perfil de uma das pessoas que você segue, ela tem um conjunto de pessoas que também segue outros. Algo que poderia ser usado com esse grafo, é recomendar seguidores. Essa lógica é usada para a maioria das redes sociais!

## 2. Twitter

> Twitter é uma plataforma para as pessoas conversarem sobre assuntos do momento, um lugar que cria uma audiência muito engajada, que fica ao nosso alcance — seja por meios orgânicos ou anúncios pagos.

Jenny Broekemeier, Gerente de Mídias Sociais Pagas da MANSCAPED, Inc.

Trata-se de uma rede social, bastante difundida, onde seu usuário poder realizar publicações, chamados de tweets que podem conter, textos, imagens, vídeos, hiperlinks ou todos deles integrados. Essas publicações podem ser visualizadas por diversos usuários e que eventualmente poderão republicar aquela "mensagem" em uma operação conhecida como retweet.

### 2.1 API

Para consumir dados do Twitter, não é necessário ter acesso aos servidores e bancos de dados internos do Twitter, também não é preciso entender como o Twitter é codificado. É necessário um intermediário entre o usuário e o back-end do Twitter, um intermediário em que o clinte pode solicitar (com alguns parâmetros) para obter alguns dados ou interagir com os serviços do Twitter. Em poucas palavras, uma API é isso: simplesmente uma junção entre dois aplicativos independentes que se comunicam entre si. Como abstração, a API do Twitter simplifica a integração com terceiros (desenvolvedores, aplicativos, outras APIs, etc.).


<div align="center">
 <p> </p>
 <img src="img/API twitter.png">
   <p> </p>
 <figcaption>Funcioamento da API.</figcaption>
 <p> </p>
 <p> </p>
</div>

Aqui está o que se pode fazer com a API do Twitter:

- Pesquisar tweets programaticamente com base em hashtags, palavras-chave, geolocalização, etc.
- Criar bots do Twitter que retuitam automaticamente uma lista de contas predefinidas
- Transmitir tweets em tempo real com base em uma série de filtros
- Seguir automaticamente uma lista de usuários
- etc.

Logo, a API permite que você execute programaticamente qualquer ação que executaria manualmente na interface.

## 3. Social network analysis ou Análise de rede social
 
A noção de rede social refere-se historicamente à abordagem estrutural de estudo dos grupos sociais. O conceito, que tem suas raízes na Sociologia há quase um século, principalmente através do trabalho do Jakob Moreno, ainda na década de 30, que sistematicamente coletou e analisou as interações sociais de alunos de escolhas, é uma das principais bases do que ele chamava de Sociometria. Na base, rede social significava a visão de um grupo social através de suas relações, considerando o grafo (estrutura de rede) como construto para tal.


<div align="center">
 <p> </p>
 <img src="img/evolucao de grupos.jpeg">
  <p> </p>
 <figcaption>Um dos grafos originais do Moreno, do livro "Who shall survive" (1934). </figcaption>
 <p> </p>
</div>

 Outros autores, depois de Moreno, também se apropriaram do conceito para seus estudos e setaram outras bases para o que depois veio a se tornar a Análise de Redes Sociais. Mas foi apenas na década de 90 que aconteceu uma mudança radical: Com o surgimento da mídia digital e a transformação das interações sociais em dados, novas formas de estudar esses grupos sociais, principalmente de forma mais massiva (a análise de redes sociais era feita com trabalho de coleta de dados mais "formiguinha" até então). Essa nova abordagem, muito mais interdisciplinar, vai ser inaugurada por autores como Barabási e Christakis, entre outros, e notadamente, vai também originar outras novas "subáreas" de estudo em áreas que tradicionalmente não estudavam dados sociais (como a Ciência Social Computacional, por exemplo).
 
Quando transformamos essa discussão para as redes sociais online ou as redes sociais na internet, o que temos é uma mudança importante entre uma estrutura mediada principalmente pelas relações institucionais e interpessoais e uma estrutura mediada pelas relações mediadas pela tecnologia digital. Eu costumo dizer que, nessa mudança, essas redes ganham “superpoderes”, tais como:

- A possibilidade de conexão mais “individual” e por interesse, não limitada pela localização geográfica;
- A posssibilidade de conexões massivas, em grande escala (uma vez que essas conexões podem ser mantidas pelas ferramentas sem a necessidade de interação social), assim permitindo que as pessoas tenham centenas ou milhares de “amigos” — o fenômeno dos “influenciadores”, por exemplo;
- A possibilidade de participação em conversações globais e de acesso a conteúdos que não necessariamente estariam disponíveis devido à complexificação das conexões sociais;
- A possibilidade de ser alguém diferente, ter mais de um “perfil”, brincar com a própria identidade (o que também possibilita que coisas que não poderiam ser atores em redes sociais offline, como um perfil robô, por exemplo, agora possam ser).
 
 
## 3. O Algoritmo

### 3.1 Problema Proposto 

### 3.2 Estrutura dos arquivos

### 3.3 Instalação

Para rodar este código, é necessário instalar algumas bibliotecas.

```
pip3 install networkx
pip3 install tweepy
pip3 install community
pip3 install python-louvain
```

### 3.3 Bibliotecas utilizadas

https://github.com/barbrina/AEDs-II/blob/ec4f340603c80c50ced61438448984aa963f7396/Analisando%20conex%C3%B5es%20do%20Twitter/src/twitter.py#L1-L7

As ferramentas utilizadas foram:

- Tweepy — um tipo de API RESTful especificamente para o Twitter
- NetworkX — uma biblioteca Python para estudar gráficos e redes.
- Pandas — biblioteca de manipulação e análise de dados
- Matplotlib — biblioteca de plotagem
- JSON — tipo de arquivo
- Gephi — um pacote de software de análise e visualização de rede de código aberto

### 3.4 Estrutura do algoritmo

Irei explicar as etapas que segui para extrair dados do Twitter. Em primeiro lugar, você deve obter as credenciais da API do Twitter no site do desenvolvedor do Twitter, que são a chave da API, a chave secreta da API, o token de acesso e o segredo do token de acesso.

#### 3.4.1 Criação de um aplicativo do Twitter e configurção das credenciais

Para poder reproduzir as etapas a seguir é necessário ter uma conta no Twitter. Para usar a API do Twitter, primeiro precisa-se registrar como desenvolvedor do Twitter, no site dos desenvolvedores. Uma vez registrado, e necessário criar um aplicativo do Twitter que irá configurar um monte de credenciais: essas credenciais serão usadas posteriormente pela biblioteca Tweepy para autenticação. Visto que as credenciais são pessoais, neste trabalho **EXPLICAR AQUI**.


<div align="center">
 <p> </p>
 <img src="img/twitter - API.png">
  <p> </p>
 <figcaption>Portal do desenvolvedor do Twitter. </figcaption>
 <p> </p>
</div>


#### 3.4.2 Conexão à API do Twitter



## 4. Exemplo
 
## 5. Compilação e Execução

</div>

## 6. Referências Bibliográficas

Mota M. **_Grafos — Conceitos Básicos_**. Internet: https://medium.com/20-21/grafos-ac48e874570

Recuero R. **_Mídia social, plataforma digital, site de rede social ou rede social? Não é tudo a mesma coisa?_**. Internet: https://medium.com/@raquelrecuero/m%C3%ADdia-social-plataforma-digital-site-de-rede-social-ou-rede-social-n%C3%A3o-%C3%A9-tudo-a-mesma-coisa-d7b54591a9ec, 2019;

Jain S, Sinha A. **_Identification of influential users on Twitter: a novel weighted correlated influence measure for Covid-19_**. Chaos, Solitons & Fractals, 2020.

Ferreira M. **_Coletando dados do Twitter utilizando Python - Parte 1_**. Internet: https://www.linkedin.com/pulse/coletando-dados-do-twitter-utilizando-python-parte-1-mauro-ferreira/, 2021.

Besbes A. **_How To Extract Data From The Twitter API Using Python_**. Internet: https://towardsdatascience.com/how-to-extract-data-from-the-twitter-api-using-python-b6fbd7129a33, 2022.

Galarnyk M. **_How to Access Data from the Twitter API using Tweepy (Python)_**. Internet: https://towardsdatascience.com/how-to-access-data-from-the-twitter-api-using-tweepy-python-e2d9e4d54978, 2022.

Tijesunimi O. **_Mining Data on Twitter_**. Internet: https://medium.com/@tijesunimiolashore/mining-data-on-twitter-3c7969207e75, 2020.

Hedden S. **_How to download and visualize your Twitter network_**. Internet: https://towardsdatascience.com/how-to-download-and-visualize-your-twitter-network-f009dbbf107b, 2021.

Popova J. **_Network Analysis and Community Detection on Political Tweets_**. Internet: https://medium.com/mlearning-ai/network-analysis-and-community-detection-on-political-tweets-9e0f21294e31, 2022.

Shaham F. **_Generating A Twitter Ego-Network & Detecting Communities_**. Internet: https://towardsdatascience.com/generating-twitter-ego-networks-detecting-ego-communities-93897883d255

Hammer L. **_Guide: Analyzing Twitter Networks with Gephi 0.9.1_** Internet: https://medium.com/@Luca/guide-analyzing-twitter-networks-with-gephi-0-9-1-2e0220d9097d

Aric A. Hagberg, Daniel A. Schult and Pieter J. Swart, **_Exploring network structure, dynamics, and function using NetworkX_**, in Proceedings of the 7th Python in Science Conference (SciPy2008), Gäel Varoquaux, Travis Vaught, and Jarrod Millman (Eds), (Pasadena, CA USA), pp. 11–15, Aug 2008

Parika P. **_Analysis Of Twitter Social Network_**. Internet: https://medium.com/social-media-theories-ethics-and-analytics/analysis-of-twitter-social-network-d5023e1a1aa, 2020. 
