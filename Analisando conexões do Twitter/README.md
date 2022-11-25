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
</div>

Aqui está o que se pode fazer com a API do Twitter:

- Pesquisar tweets programaticamente com base em hashtags, palavras-chave, geolocalização, etc.
- Criar bots do Twitter que retuitam automaticamente uma lista de contas predefinidas
- Transmitir tweets em tempo real com base em uma série de filtros
- Seguir automaticamente uma lista de usuários
- etc.

Logo, a API permite que você execute programaticamente qualquer ação que executaria manualmente na interface.

## 3. SNA (Social Network Analysis)
 
## 3. O Algoritmo

### 3.1 Problema Proposto 

### 3.2 Estrutura dos arquivos

### 3.3 Bibliotecas utilizadas

https://github.com/barbrina/AEDs-II/blob/16db07d586ac314277d98428a3cc1acde9fdb912/Analisando%20conex%C3%B5es%20do%20Twitter/src/twitter.py#L1-L8

As ferramentas utilizadas foram:

- Tweepy — um tipo de API RESTful especificamente para o Twitter
- NetworkX — uma biblioteca Python para estudar gráficos e redes.
- Pandas — biblioteca de manipulação e análise de dados
- Matplotlib — biblioteca de plotagem
- JSON — tipo de arquivo
- Gephi — um pacote de software de análise e visualização de rede de código aberto
- Scipy — 

### 3.4 Estrutura do algoritmo

Irei explicar as etapas que segui para extrair dados do Twitter. Em primeiro lugar, você deve obter as credenciais da API do Twitter no site do desenvolvedor do Twitter, que são a chave da API, a chave secreta da API, o token de acesso e o segredo do token de acesso.

## 4. Exemplo
 
## 5. Compilação e Execução

</div>

## 6. Referências Bibliogŕaficas

Mota M., **_Grafos — Conceitos Básicos_**. Internet: https://medium.com/20-21/grafos-ac48e874570

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
