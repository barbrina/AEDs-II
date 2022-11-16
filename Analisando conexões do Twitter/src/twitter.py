from community import community_louvain
import matplotlib.pyplot as plt
import networkx as nx
import tweepy
import json
import pandas as pd

# Aqui utilizamos a função open para abrir nosso arquivo e a
# biblioteca json para carregar nosso arquivo para uma variável chamada info.
credenciais = open('credenciais.json').read()
info = json.loads(credenciais)

consumer_key = info['API_ACCESS_BARBARA']
consumer_secret = info['API_ACCESS_SECRET_BARBARA']
access_key = info['ACCESS_TOKEN_BARBARA']
access_secret = info['ACCESS_TOKEN_SECRET_BARBARA']

# Setup tweepy to authenticate with Twitter credentials:
autorizacao = tweepy.OAuthHandler(consumer_key, consumer_secret)
autorizacao.set_access_token(access_key, access_secret)

# Agora temos nossa variável chamada api onde guardamos uma instância do tweepy e
# com ela que iremos trabalhar a partir de agora.
api = tweepy.API(autorizacao, wait_on_rate_limit=True)

me = api.get_user(screen_name="Barbrinass")
print(me.id)

user_list = [me.id]
follower_list = []
for user in user_list:
    followers = []
    try:
        for page in tweepy.Cursor(api.get_follower_ids, user_id=user).pages():
            followers.extend(page)
            print(len(followers))
    except tweepy.TweepError:
        print("error")
        continue
    follower_list.append(followers)

df = pd.DataFrame(columns=['source', 'target'])  # Empty DataFrame
# Set the list of followers as the target column
df['target'] = follower_list[0]
df['source'] = me.id  # Set my user ID as the source

G = nx.from_pandas_edgelist(df, 'source', 'target')  # Turn df into graph
pos = nx.spring_layout(G)  # specify layout for visual

f, ax = plt.subplots(figsize=(10, 10))
plt.style.use('ggplot')
nodes = nx.draw_networkx_nodes(G, pos, alpha=0.8)
nodes.set_edgecolor('k')

nx.draw_networkx_labels(G, pos, font_size=8)
nx.draw_networkx_edges(G, pos, width=1.0, alpha=0.2)
nx.draw(G)
plt.show()


# Use the list of followers we extracted in the code above i.e. my 62 followers
user_list = list(df['target'])
for userID in user_list:
    print(userID)
    followers = []
    follower_list = []

    # fetching the user
    user = api.get_user(user_id=userID)

    # fetching the followers_count
    followers_count = user.followers_count
    print(followers_count)

    try:
        for page in tweepy.Cursor(api.get_follower_ids, user_id=userID).pages():
            followers.extend(page)
            print(len(followers))
            if followers_count >= 5000:  # Only take first 5000 followers
                break
            if not followers.protected:
                break
    except tweepy.TweepError:
        print("error")
        continue
    follower_list.append(followers)
    tmp = []
    temp = pd.DataFrame(columns=['source', 'target'])
    temp['target'] = follower_list[0]
    temp['source'] = userID
    tmp.append(temp)
    #df = df.append(temp)
    df.to_csv("networkOfFollowers.csv")
df = pd.concat(tmp)

df = pd.read_csv("networkOfFollowers.csv")  # Read into a df
