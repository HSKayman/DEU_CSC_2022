import pandas as pd
import numpy as np
import nltk, re, string, collections
from nltk.util import ngrams 

def n_grams(n,documents,documents2,data):
    text=" "
    for ftext in documents['body']:
        try:
            text+=" "
            text+=ftext
        except TypeError:
            continue
    try:
        text = re.sub('<.*>','',text)
        text = re.sub('ENDOFARTICLE.','',text)
        punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
        text = re.sub(punctuationNoPeriod, "", text)
        tokenized = text.split()
        esUnigram = ngrams(tokenized, 1)
        esUnigramFreq = collections.Counter(esUnigram) 
        esBigrams = ngrams(tokenized, 2)          
        esBigramFreq = collections.Counter(esBigrams)
    except:
        print("ERROR! CHECK YOUR CODES!!!")
    text2=" "
    for ftext in documents2['title']:
        try:
            text2+=" "
            text2+=ftext
        except TypeError:
            continue
    try:
        text2 = re.sub('<.*>','',text2)
        text2 = re.sub('ENDOFARTICLE.','',text2)
        punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
        text2 = re.sub(punctuationNoPeriod, "", text2)
        tokenized = text2.split()
        esUnigram = ngrams(tokenized, 1)
        esUnigramFreq2 = collections.Counter(esUnigram) 
        esBigrams = ngrams(tokenized, 2)          
        esBigramFreq2 = collections.Counter(esBigrams)
    except:
        print("ERROR! CHECK YOUR CODES!!!")
    predoc=[]
    predoc2=[]
    for i in range(len(documents['body'])):
        predoc.append(0)
        predoc2.append(0)
    for i in range(len(documents['body'])):
        predoc[i] = re.sub('<.*>','',str(documents['body'][i]))
        predoc[i] = re.sub('ENDOFARTICLE.','',predoc[i])
        punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
        predoc[i] = re.sub(punctuationNoPeriod, "", predoc[i])
        
        
        predoc2[i] = re.sub('<.*>','',str(documents2['title'][i]))
        predoc2[i] = re.sub('ENDOFARTICLE.','',predoc2[i])
        punctuationNoPeriod = "[" + re.sub("\.","",string.punctuation) + "]"
        predoc2[i] = re.sub(punctuationNoPeriod, "", predoc2[i])
        
    
    howmny=[]
    for i in range(1100):
      tyt=str(esBigramFreq.most_common(1100)[i])
      tyt = re.sub('<.*>','',tyt)
      tyt = re.sub('ENDOFARTICLE.','',tyt)
      pdN = "[" + re.sub("\.","",string.punctuation) + "]"
      tyt =re.sub(pdN, "", tyt)
      tyt2= ''.join([j for j in tyt if not j.isdigit()])
      countq=0
      for j in range(len(documents['body'])):
           try:   
               if tyt2 in predoc[j]:
                   countq+=1
           except:
               continue
      howmny.append(countq)
    howmny1=[]
    for i in range(1100):
      tyt=str(esUnigramFreq.most_common(1100)[i])
      tyt = re.sub('<.*>','',tyt)
      tyt = re.sub('ENDOFARTICLE.','',tyt)
      pdN = "[" + re.sub("\.","",string.punctuation) + "]"
      tyt =re.sub(pdN, "", tyt)
      tyt2= ''.join([j for j in tyt if not j.isdigit()])
      countq=0
      for j in range(len(documents['body'])):
           try:
               if tyt2 in predoc[j]:
                   countq+=1
           except:
               continue
      howmny1.append(countq)
    howmny2=[]
    for i in range(1100):
      tyt=str(esBigramFreq2.most_common(1100)[i])
      tyt = re.sub('<.*>','',tyt)
      tyt = re.sub('ENDOFARTICLE.','',tyt)
      pdN = "[" + re.sub("\.","",string.punctuation) + "]"
      tyt =re.sub(pdN, "", tyt)
      tyt2= ''.join([j for j in tyt if not j.isdigit()])
      countq=0
      for j in range(len(documents2['title'])):
           try:
               if tyt2 in predoc2[j]:
                   countq+=1
           except:
               continue
      howmny2.append(countq)
    howmny3=[]
    for i in range(1100):
      tyt=str(esUnigramFreq2.most_common(1100)[i])
      tyt = re.sub('<.*>','',tyt)
      tyt = re.sub('ENDOFARTICLE.','',tyt)
      pdN = "[" + re.sub("\.","",string.punctuation) + "]"
      tyt =re.sub(pdN, "", tyt)
      tyt2= ''.join([j for j in tyt if not j.isdigit()])
      countq=0
      for j in range(len(documents2['title'])):
           try:
               if tyt2 in predoc2[j]:
                   countq+=1
           except:
               continue
      howmny3.append(countq)
    
    dict1={"BiGram_Of_Body":esBigramFreq.most_common(1100),
           "How_Many_Post" :howmny,
          "UniGram_Of_Body":esUnigramFreq.most_common(1100),
          "How_Many_Post2" :howmny1,
          "BiGram_Of_Title":esBigramFreq2.most_common(1100),
          "How_Many_Post3" :howmny2,
          "UniGram_Of_Title":esUnigramFreq2.most_common(1100),
          "How_Many_Post4" :howmny3}
    df =pd.DataFrame(dict1)
    df.to_csv('3_Reddit_data_meToo_NGRAM.csv', index=False)
    return n  
      
data = pd.read_csv('2_Reddit_data_meToo_LDA.csv', error_bad_lines=False);
data_text = data[['body']]
data_text2 = data[['title']]
data_text['index'] = data_text.index
data_text2['index'] = data_text2.index
documents = data_text
documents2 = data_text2
np.random.seed(2018)
nltk.download('wordnet')
print(n_grams("Completed",documents,documents2,data))