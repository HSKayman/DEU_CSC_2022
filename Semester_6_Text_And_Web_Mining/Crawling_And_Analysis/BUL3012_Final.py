# -*- coding: utf-8 -*-
"""
Created on Tue Jun 22 21:54:09 2021

@author: suca
"""

# =============================================================================
# =============================================================================
# =============================================================================
# # # Import Firt Module
# =============================================================================
# =============================================================================
# =============================================================================
#!pip install selenium
import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
import networkx as nx


# =============================================================================
# Prepare Selenium
# =============================================================================
chrome_options = Options()
chrome_options.add_argument("--headless") 
chrome_path = './chromedriver.exe'
driver = webdriver.Chrome(executable_path=chrome_path, options=chrome_options)



Links=["https://www.deu.edu.tr/"]
#f = open("All_Sub_Links.txt", "r")
#Links.extend(f.readlines())
#f.close()
# =============================================================================
# =============================================================================
# # Crawling And Create Huge Graph
# =============================================================================
# =============================================================================
G = nx.Graph()
count=0
G.add_node(Links[count])
try:
    while count< len(Links):
        try:
# =============================================================================
#             Acces Website    
# =============================================================================
            driver.get(Links[count])
            elems = driver.find_elements_by_xpath("//a[@href]")
        
            #Write Website 
            pageSource = driver.page_source
            fileToWrite = open("./All_Website_Link/{}.html".format(count), "w",encoding='utf-8')
            fileToWrite.write(pageSource)
            fileToWrite.close()
            
            #Find New Link that Inside The Links
            for elem in elems:
                try:
                    link=elem.get_attribute("href")
                    if link:# check null
                        if "deu.edu" in link  and not( #the html must include deu.edu
                           "mailto" in link or #eleminate social media
                           "whatsapp" in link or
                           "facebook" in link or
                           "addtoany" in link or
                           "twitter" in link or
                           link[-1]=='#' or #eleminate nj
                           link=="javascript:void(0);" or #eleminate js
                           link=="javascript:void(0)" or
                           '.jpg' in link or #eleminate multimedia
                           'css' in link or
                           'json' in link or
                           '.jpeg' in link or
                           '.png' in link or
                           '.rar' in link or
                           '.zip' in link or
                           link.count('/')>5 or #eleminate deep html
                           '/feed/' in link or #eleminate not essential page
                           'lang=en' in link or #eleminate en page
                           'google.' in link or #eleminate big site
                           '.pdf' in link or #eleminate file format
                           '.doc' in link or
                           '.odt' in link or
                           'wp-content' in link or 
                           '/en/' in link or #eleminate en page
                           'acikerisim.deu.edu.tr' in link or #high resource page
                           'katalog.deu.edu.tr/search?' in link or
                            ('debis.deu.edu.tr/ders-katalog/' in link and
                             '/2020-2021/tr' not in link) or
                           'online.deu.edu.tr' in link or #eleminate login page
                           'onlinetip.deu.edu.tr' in link):#chech everything
                            if link in Links:
                                 G.add_edge(Links[count],link)
                            else:
                                if 50000>(len(Links)):
                                    Links.append(link)
                                    G.add_node(link)
                                    G.add_edge(Links[count],link)
                                else:
                                    break
                except Exception:
                    continue    
        except Exception as e:
            print("!!!{}. Index and {} Link else went wrong with {}".format(count,Links[count],e))
            continue
        finally:
            print("Completed :%{}\nRight Now On: {}. Index\nQue: {}".format((count/len(Links))*100,count,len(Links)))
            count+=1
finally:
    driver.quit()



#Write All Crawded Site
with open("All_Sub_Links.txt", 'w') as f:
    for link in Links:
        f.write("%s\n" % link)
f.close()
print(len(Links))





# =============================================================================
# =============================================================================
# =============================================================================
# # # Import Second Module
# =============================================================================
# =============================================================================
# =============================================================================
#!pip install TurkishStemmer
#!pip install wordcloud
#!pip install textblob
#nltk.download('punkt')
from TurkishStemmer import TurkishStemmer
from wordcloud import WordCloud
import pandas as pd
import nltk
from textblob import TextBlob,Word
import matplotlib.pyplot as plt
import os
import numpy as np
from PIL import Image
import nltk



# =============================================================================
# Read Datas
# =============================================================================
Links=[]
f = open("All_Sub_Links.txt", "r")
Links.extend(f.readlines())
f.close()
RawDataFrame=[]
Name=[]
for i in os.listdir("All_Website_Link/"):#
    file = open("All_Website_Link/{}".format(i), "r" ,encoding='utf-8')#
    Name.append("{}".format(Links[int(i[:-5])]))
    RawDataFrame.append(file.read())
    file.close()
    
dataframe=pd.DataFrame(RawDataFrame,columns=["Body"])
dataframe['WebPage']=Name
df=dataframe['Body']

# =============================================================================
# Pre-Process
# =============================================================================
df=df.apply(lambda x: " ".join(x.lower() for x in x.split()))
df=df.replace('<script([\S\s]*?)>([\S\s]*?)<\/script>',' ',regex=True)#script tag
df=df.replace('<style([\S\s]*?)>([\S\s]*?)<\/style>',' ',regex=True)#style tag
df=df.replace('<[a-zA-Z\/][^>]*>',' ',regex=True)# html tag


df=df.replace('[^\w\s:)(]','',regex=True)
df=df.replace('\d+','',regex=True)

f = open("StopWord.txt", "r",encoding='utf-8')
sw=f.read().splitlines()
f.close()
stemmer = TurkishStemmer()

df=df.apply(lambda x: " ".join(stemmer.stem(x) for x in x.split() if x not in sw))
df=df.apply(lambda x: TextBlob(x).words)
dataframe["Body"]=df



# =============================================================================
# Calculate Frequency
# =============================================================================
Frequency={}
count=0
for i in dataframe["Body"]:
    for j in set(i):
        if j in Frequency.keys():
            Frequency[j][0]+=i.count(j)
            Frequency[j][1]+=1
        else:
            Frequency[j]=[i.count(j),1]

Frequency=sorted(Frequency.items(), key=lambda x: x[1][0],reverse=True)
with open("Frequency.csv", 'w' ,encoding='utf-8') as f:
    f.write("{},{},{}".format("Word","Frequency","Frequency For Page"))
    for i in Frequency:
        f.write("{},{},{}\n".format(i[0],i[1][0],i[1][1]))
f.close()         

# =============================================================================
# Plt Show
# =============================================================================

wordcloud = WordCloud(max_font_size = 50,
                     max_words = 100, 
                     background_color = "white").generate(" ".join(x for x in np.transpose(Frequency[:100])[0]))
plt.figure()
plt.imshow(wordcloud, interpolation = "bilinear")
plt.axis("off")
plt.show()

wordcloud.to_file("HighFreq_Words.png");
deu_mask = np.array(Image.open("deu.png"))
masked_cloud = WordCloud(background_color = "white",
                     max_words = 1000, 
                     mask = deu_mask, 
                     contour_width = 3,
                     contour_color = "firebrick")

masked_cloud.generate(" ".join(x for x in np.transpose(Frequency[:100])[0]))

masked_cloud.to_file("deu_mask.png")

plt.figure(figsize = [10,10])
plt.imshow(masked_cloud, interpolation = "bilinear")
plt.axis("off")
plt.show()







# =============================================================================
# =============================================================================
# # Centrality Analysy
# =============================================================================
# =============================================================================

# =============================================================================
# Calculate Betweenness Closenness Degree Centrality
# =============================================================================
betweenness_centrality=nx.betweenness_centrality(G)
betweenness_centrality=sorted(betweenness_centrality.items(), key=lambda x: x[1],reverse=True)

closeness_centrality=nx.closeness_centrality(G)
closeness_centrality=sorted(closeness_centrality.items(), key=lambda x: x[1],reverse=True)

degree_centrality=nx.degree_centrality(G)
degree_centrality=sorted(degree_centrality.items(), key=lambda x: x[1],reverse=True)

# =============================================================================
# Print Centrality Analysy
# =============================================================================
with open("betweenness_centrality.csv", 'w' ,encoding='utf-8') as f:
    for i in betweenness_centrality:
        f.write("{},{}\n".format(i[0],i[1]))
f.close() 

with open("closeness_centrality.csv", 'w' ,encoding='utf-8') as f:
    for i in closeness_centrality:
        f.write("{},{}\n".format(i[0],i[1]))
f.close() 

with open("degree_centrality.csv", 'w' ,encoding='utf-8') as f:
    for i in degree_centrality:
        f.write("{},{}\n".format(i[0],i[1]))
f.close() 

with open("centrality.csv", 'w' ,encoding='utf-8') as f:
    f.write("{},{},{},{},{},{}\n".format("WebPage","degree_centrality","WebPage","betweenness_centrality","WebPage","closeness_centrality"))
    i=0
    while i<len(degree_centrality):
        f.write("{},{},{},{},{},{}\n".format(degree_centrality[i][0],degree_centrality[i][1],betweenness_centrality[i][0],betweenness_centrality[i][1],closeness_centrality[i][0],closeness_centrality[i][1]))
        i+=1
f.close() 









