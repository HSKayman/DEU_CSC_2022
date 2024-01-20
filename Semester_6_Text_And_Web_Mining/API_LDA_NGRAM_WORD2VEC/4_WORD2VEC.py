import pandas as pd
import numpy as np
from gensim.parsing.preprocessing import STOPWORDS, stem
from nltk.stem import WordNetLemmatizer, SnowballStemmer
import gensim
import nltk

def lemmatize_stemming(text):
    return stem(WordNetLemmatizer().lemmatize(text, pos='v'))
def preprocess(text):
    result = []
    for token in gensim.utils.simple_preprocess(text):
        if token not in gensim.parsing.preprocessing.STOPWORDS:
            result.append(lemmatize_stemming(token))
    return result
def doc2vec(result,documents,documents2,data): 
    processed_docs=documents['body'].fillna('').astype(str).map(preprocess)
    law=["men", "story", "result", "sex", "harassment", "metoo", "movement", "timesup", "woman", "abuse", "victims","rape"]
    law2=[]
    for i in law:
        law2.append(lemmatize_stemming(i))
    multiplelist2={"1":[], "2":[], "3":[], "4":[], "5":[], "6":[], "7":[], "8":[],
                   "9":[], "10":[], "11":[],"12":[]}
    count=1
    for a in law2:
        for i in  processed_docs:
            if a in i:
                for j in i:
                    multiplelist2["{}".format(count)].append(j)
        count+=1
    c={"1":[], "2":[], "3":[], "4":[], "5":[], "6":[], "7":[], "8":[],
       "9":[], "10":[], "11":[],"12":[]}
    c2={"1":[], "2":[], "3":[], "4":[], "5":[], "6":[], "7":[], "8":[],
       "9":[], "10":[], "11":[],"12":[]}
    count=1
    while count<13:
        for i in multiplelist2["{}".format(count)]:        
            c["{}".format(count)].append(multiplelist2["{}".format(count)].count(i))
            c2["{}".format(count)].append(i)
            for j in multiplelist2["{}".format(count)]:
                if i==j:
                    multiplelist2["{}".format(count)].remove(j)
        
        for i in range(len(c["{}".format(count)])):
            j=i
            while j<len(c["{}".format(count)]):
                if c["{}".format(count)][j]>c["{}".format(count)][i]:
                    c["{}".format(count)][j],c["{}".format(count)][i]=c["{}".format(count)][i],c["{}".format(count)][j]
                    c2["{}".format(count)][j],c2["{}".format(count)][i]=c2["{}".format(count)][i],c2["{}".format(count)][j]
                j+=1
        
        count+=1 
    multiplelist2={"1":[], "2":[], "3":[], "4":[], "5":[], "6":[], "7":[], "8":[],
                   "9":[], "10":[], "11":[],"12":[]}
    count=1
    processed_docs=documents2['title'].fillna('').astype(str).map(preprocess)
    for a in law2:
        for i in  processed_docs:
            if a in i:
                for j in i:
                    multiplelist2["{}".format(count)].append(j)
        count+=1
    ct={"1":[], "2":[], "3":[], "4":[], "5":[], "6":[], "7":[], "8":[],
       "9":[], "10":[], "11":[],"12":[]}
    c2t={"1":[], "2":[], "3":[], "4":[], "5":[], "6":[], "7":[], "8":[],
       "9":[], "10":[], "11":[],"12":[]}
    count=1
    while count<13:
        for i in multiplelist2["{}".format(count)]:        
            ct["{}".format(count)].append(multiplelist2["{}".format(count)].count(i))
            c2t["{}".format(count)].append(i)
            for j in multiplelist2["{}".format(count)]:
                if i==j:
                    multiplelist2["{}".format(count)].remove(j)
        
        for i in range(len(ct["{}".format(count)])):
            j=i
            while j<len(c2t["{}".format(count)]):
                if ct["{}".format(count)][j]>ct["{}".format(count)][i]:
                    ct["{}".format(count)][j],ct["{}".format(count)][i]=ct["{}".format(count)][i],ct["{}".format(count)][j]
                    c2t["{}".format(count)][j],c2t["{}".format(count)][i]=c2t["{}".format(count)][i],c2t["{}".format(count)][j]
                j+=1    
        count+=1 
    count=1
    while count<13:
        while 10>=len(c["{}".format(count)]):
            c["{}".format(count)].append(" ")
        while 10>=len(c2["{}".format(count)]):
            c2["{}".format(count)].append(" ")
        while 10>=len(ct["{}".format(count)]):
            ct["{}".format(count)].append(" ")
        while 10>=len(c2t["{}".format(count)]):
            c2t["{}".format(count)].append(" ")
        count+=1 
    multiplelist = {"men_of_title":c2t["1"][:10], 
                     "count1":ct["1"][:10],
                    "story_of_title":c2t["2"][:10],
                    "count2":ct["2"][:10],
                    "result_of_title":c2t["3"][:10],
                    "count3":ct["3"][:10],
                    "sex_of_title":c2t["4"][:10],
                    "count4":ct["4"][:10],
                    "harassment_of_title":c2t["5"][:10],
                    "count5":ct["5"][:10],
                    "metoo_of_title":c2t["6"][:10],
                    "count6":ct["6"][:10],
                    "movement_of_title":c2t["7"][:10],
                    "count7":ct["7"][:10],
                    "timesup_of_title":c2t["8"][:10],
                    "count8":ct["8"][:10],
                    "woman_of_title":c2t["9"][:10],
                    "count9":ct["9"][:10],
                    "abuse_of_title":c2t["10"][:10],
                    "count10":ct["10"][:10],
                    "witchtims_of_title":c2t["11"][:10],
                    "count11":ct["11"][:10],
                    "rape_of_title":c2t["12"][:10],
                    "count12":ct["12"][:10],
                    "men_of_body":c2["1"][:10],
                    "count13":c["1"][:10],
                    "story_of_body":c2["2"][:10],
                    "count14":c["2"][:10],
                    "result_of_body":c2["3"][:10],
                    "count15":c["3"][:10],
                    "sex_of_body":c2["4"][:10],
                    "count16":c["4"][:10],
                    "harassment_of_body":c2["5"][:10],
                    "count17":c["5"][:10],
                    "metoo_of_body":c2["6"][:10],
                    "count18":c["6"][:10],
                    "movement_of_body":c2["7"][:10],
                    "count19":c["7"][:10],
                    "timesup_of_body":c2["8"][:10],
                    "count20":c["8"][:10],
                    "woman_of_body":c2["9"][:10],
                    "count21":c["9"][:10],
                    "abuse_of_body":c2["10"][:10],
                    "count22":c["10"][:10],
                    "victims_of_body":c2["11"][:10],
                    "count23":c["11"][:10],
                    "rape_of_body":c2["12"][:10],
                    "count24":c["12"][:10]} 
    df =pd.DataFrame(multiplelist)
    df.to_csv('4_Reddit_data_meToo_WORD2VEC.csv', index=False)
    
    return result
        
data = pd.read_csv('1_Reddit_data_meToo_list.csv', error_bad_lines=False);
data_text = data[['body']]
data_text2 = data[['title']]
data_text['index'] = data_text.index
data_text2['index'] = data_text2.index
documents = data_text
documents2 = data_text2
np.random.seed(2018)
nltk.download('wordnet')
print(doc2vec("Completed",documents,documents2,data))
