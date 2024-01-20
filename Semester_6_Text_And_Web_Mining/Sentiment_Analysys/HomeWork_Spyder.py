# -*- coding: utf-8 -*-
"""
Created on Fri Apr 30 12:48:58 2021

@author: suca
"""

# =============================================================================
# Required Library
# =============================================================================

import pandas as pd
import nltk
from nltk.corpus import stopwords
from nltk.stem.porter import *
from textblob import TextBlob,Word
import matplotlib.pyplot as plt
import os
import numpy as np

# =============================================================================
# File Read Operation and Translate
# =============================================================================

RawDataFrame=[]
IndexName=[]
for i in os.listdir("metinler/"):
    file = open("metinler/{}".format(i), "r", encoding='iso8859-9')#turkishcode
    IndexName.append("{}".format(i))
    filetext=file.read()
    file.close()
    RawDataFrame.append("".join(TextBlob(filetext).translate(to = "en")))
dataframe=pd.DataFrame(RawDataFrame,columns=["Comments"])
dataframe['filename']=IndexName


# =============================================================================
# # =============================================================================
# # TextBlob's Translate Service has limit so i needed to save the file because i can't call when i want
# # =============================================================================
# dataframe.to_csv("Translated.csv")# There is limit so i read it
# 
# # =============================================================================
# # TextBlob Read Operation For The Saved File
# # =============================================================================
# dataframe=pd.read_csv("Translated.csv", header = 0 , index_col = 0, squeeze = True)
# dataframe.columns=["Comments","filename"]
# df=dataframe["Comments"]
# 
#Please Unless you need, you should not use code because they may damaged my translated.cv file 
# =============================================================================

# =============================================================================
# Cleanning Operations For Text
# =============================================================================

df=df.apply(lambda x: " ".join(x.lower() for x in x.split()))
df=df.replace('[^\w\s:)(]','',regex=True)#regex emojiler haric
df=df.replace('\d+','',regex=True)#regex
sw=stopwords.words("english")
df=df.apply(lambda x: " ".join(x for x in x.split() if x not in sw))
df=df.apply(lambda x: TextBlob(x).words)

#stemmer = PorterStemmer()
#df=df.apply(lambda x: " ".join(stemmer.stem(word) for word in x))
df=df.apply(lambda x: " ".join(Word.lemmatize(word) for word in x))

# =============================================================================
# Sentiment Point Giver Func
# =============================================================================

def sentiments_score(df):
    result_score=[]
    result_class=[]
    for i in df:
        textB = TextBlob(i)
        sentiments_score = textB.sentiment.polarity
        result_score.append(sentiments_score)
        
        if sentiments_score <0.00:
            result_class.append('Negative')

        elif sentiments_score >0.00:
            result_class.append('Positive')

        else:
            result_class.append('Notre')
            
    return result_score,result_class


# =============================================================================
# Looking at Rate between Sentiments
# =============================================================================
BiggerData=pd.DataFrame(df.values,columns=['Data'])
BiggerData['Score'],BiggerData['Class']=sentiments_score(df)
BiggerData["FileName"]=dataframe["filename"]
print(BiggerData.groupby("Class").count()["Score"])

# =============================================================================
# Print All Data
# =============================================================================

with pd.option_context('display.max_rows', None, 'display.max_columns', None):  # more options can be specified also
    print(BiggerData[["FileName","Class"]])

# =============================================================================
# Data Visulations
# =============================================================================

fig, axs = plt.subplots(2, figsize=(10, 10))
axs[0].bar(BiggerData.index,BiggerData["Score"],color=BiggerData.Class.map({"Pozitive": 'g', "Negative": 'r',"Notre":'b'}))
axs[1].pie(BiggerData.groupby("Class").count()["Score"],labels =['Negative','Notre','Pozitive'],colors=('r','c','g'))

plt.show()

# =============================================================================
# Instant Polarity Computer
# =============================================================================

def instantCompute(word):
    print(TextBlob(word).translate(to = "en"))
    return TextBlob(word).translate(to = "en").sentiment.polarity
print(instantCompute(input("If you want,you can enter a word but it must be turkish: ")))












