import pandas as pd
import numpy as np
from nltk.tokenize import RegexpTokenizer
def Tokenziering(string):
    tokenizer = RegexpTokenizer(r'\w+')
    raw = string.lower()
    tokens = tokenizer.tokenize(raw)
    return tokens

df_real=pd.read_csv("Imdb_list.csv")
df=np.transpose(df_real.values)
all_genres=[]
for i in df[4]:
    for j in Tokenziering(i):
        if not j in all_genres:
            all_genres.append(j)

i=0
sort=[]
while(i<len(all_genres)):
    j=0
    group=[]
    while(j<len(df[4])):
        for x in Tokenziering(df[4][j]):
            if x==all_genres[i]:
                group.append(j)
                break
        j+=1
    sort.append(group)
    i+=1
i=0
print(sort)
while(i<len(sort)):
    df= df_real.iloc[sort[i],]
    df.to_csv('{}_imdb_list.csv'.format(all_genres[i]), index=False)
    i+=1 
                        
                    
            
            
        