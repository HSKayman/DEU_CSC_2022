import pandas as pd
import numpy as np
import gensim
import nltk
from gensim.parsing.preprocessing import STOPWORDS, stem
from nltk.stem import WordNetLemmatizer, SnowballStemmer


def lemmatize_stemming(text):
    return stem(WordNetLemmatizer().lemmatize(text, pos='v'))
def preprocess(text):
    result = []
    for token in gensim.utils.simple_preprocess(text):
        if token not in gensim.parsing.preprocessing.STOPWORDS:
            result.append(lemmatize_stemming(token))
    return result
def category(apali,documents,documents2,data):
    pdoc=[]
    pdoc2=[]
    heading_1 =['emotional', 'response', 'attacker',
                'unwelcome', 'crime', 'severe', 'mugged', 
                'notmeanymore', 'starting', 'threat']
    heading_2 =['date', 'shoulder','apartment', 'squad', 'strange', 'morning',
               'van','club', 'escape', 'partner']
    heading_3 =['movement', 'victims', 'survivor',
               'abused', 'metooers', 'damage', 'accusations', 
               'battle', 'strength', 'suffer', 'wounds', 'trigger']
    heading_4 =['home', 'remember', 'hell', 'car', 'boyfriend', 'hotel', 'officer',
                'realtor', 'banker', 'fuck', 'weekend', 'conversation']
    heading_5=['head', 'older', 'house', 'attorney', 'military', 'hand',
              'working', 'sally', 'face', 'army', 'black']
    multiplelist = {"headline1":[],
                    "headline2":[], 
                    "headline3":[], 
                    "headline4":[], 
                    "headline5": []}
    for i in heading_1:
        multiplelist["headline1"].append(lemmatize_stemming(i))
    for i in heading_2:
        multiplelist["headline2"].append(lemmatize_stemming(i))
    for i in heading_3:
        multiplelist["headline3"].append(lemmatize_stemming(i))
    for i in heading_4:
        multiplelist["headline4"].append(lemmatize_stemming(i))
    for i in heading_5:
        multiplelist["headline5"].append(lemmatize_stemming(i))
    multiplelist_category={"headline1":[],
                           "headline2":[], 
                           "headline3":[], 
                           "headline4":[], 
                           "headline5": [],
                           "title_of_headline1":[],
                           "title_of_headline2":[],
                           "title_of_headline3":[],
                           "title_of_headline4":[],
                           "title_of_headline5":[],}
    for i in range(len(documents)):
        try:
            doc=str(object='a')
            doc = documents[documents['index'] == i].values[0][0]
            dft=preprocess(doc)
            pdoc.append(dft)
            for a in multiplelist["headline1"]:
                if a in dft:
                    multiplelist_category["headline1"].append('1')
                    break
                elif (a==multiplelist["headline1"][-1]):
                    multiplelist_category["headline1"].append('0')
                
            for a in multiplelist["headline2"]:
                if a in dft:
                    multiplelist_category["headline2"].append('2')
                    break
                elif (a==multiplelist["headline2"][-1]):
                    multiplelist_category["headline2"].append('0')
            
            for a in multiplelist["headline3"]:
                if a in dft:
                    multiplelist_category["headline3"].append('3')
                    break
                elif (a==multiplelist["headline3"][-1]):
                    multiplelist_category["headline3"].append('0')
            
            for a in multiplelist["headline4"]:
                if a in dft:
                    multiplelist_category["headline4"].append('4')
                    break
                elif (a==multiplelist["headline4"][-1]):
                    multiplelist_category["headline4"].append('0')
            
            for a in multiplelist["headline5"]:
                if a in dft:
                    multiplelist_category["headline5"].append('5')
                    break
                elif (a==multiplelist["headline5"][-1]):
                    multiplelist_category["headline5"].append('0')
        except TypeError:
            multiplelist_category["headline1"].append('-1')
            multiplelist_category["headline2"].append('-1')
            multiplelist_category["headline3"].append('-1')
            multiplelist_category["headline4"].append('-1')
            multiplelist_category["headline5"].append('-1')
            pdoc.append(" ")
        try:
            doc2=str(object='a')
            doc2 = documents2[documents2['index'] == i].values[0][0]
            dft2=preprocess(doc2)
            pdoc2.append(dft2)
            for a in multiplelist["headline1"]:
                if a in dft2:
                    multiplelist_category["title_of_headline1"].append('1')
                    break
                elif(a==multiplelist["headline1"][-1]):
                    multiplelist_category["title_of_headline1"].append('0')
                    
            for a in multiplelist["headline2"]:
                if a in dft2:
                    multiplelist_category["title_of_headline2"].append('2')
                    break
                elif(a==multiplelist["headline2"][-1]):
                    multiplelist_category["title_of_headline2"].append('0')
                    
            for a in multiplelist["headline3"]:
                if a in dft2:
                    multiplelist_category["title_of_headline3"].append('3')
                    break
                elif(a==multiplelist["headline3"][-1]):
                    multiplelist_category["title_of_headline3"].append('0')
                    
            for a in multiplelist["headline4"]:
                if a in dft2:
                    multiplelist_category["title_of_headline4"].append('4')
                    break
                elif(a==multiplelist["headline4"][-1]):
                    multiplelist_category["title_of_headline4"].append('0')
                    
            for a in multiplelist["headline5"]:
                if a in dft2:
                    multiplelist_category["title_of_headline5"].append('5')
                    break
                elif(a==multiplelist["headline5"][-1]):
                    multiplelist_category["title_of_headline5"].append('0')
            
        except TypeError:
            multiplelist_category["title_of_headline1"].append('-1')
            multiplelist_category["title_of_headline2"].append('-1')
            multiplelist_category["title_of_headline3"].append('-1')
            multiplelist_category["title_of_headline4"].append('-1')
            multiplelist_category["title_of_headline5"].append('-1')
            pdoc2.append(" ")
    df = data
    new_df = pd.DataFrame({'body': pdoc,
                           'title': pdoc2})
    df.update(new_df)
    df = df.assign(Experience_and_Memory_Emotions_for_body = multiplelist_category["headline1"])
    df = df.assign(Story_Details_for_body= multiplelist_category["headline2"])
    df = df.assign(Fight_against_harassment_being_strong_for_body = multiplelist_category["headline3"])
    df = df.assign(Story_details_2_for_body = multiplelist_category["headline4"])
    df = df.assign(Offenders_affiliation_for_body = multiplelist_category["headline5"])
    df = df.assign(Experience_and_Memory_Emotions_for_title = multiplelist_category["title_of_headline1"])
    df = df.assign(Story_Details_for_title = multiplelist_category["title_of_headline2"])
    df = df.assign(Fight_against_harassment_being_strong_for_title = multiplelist_category["title_of_headline3"])
    df = df.assign(Story_details_2_for_title = multiplelist_category["title_of_headline4"])
    df = df.assign(Offenders_affiliation_for_title = multiplelist_category["title_of_headline5"])
    df.to_csv('2_Reddit_data_meToo_LDA.csv', index=False)
    return apali
                
data = pd.read_csv('1_Reddit_data_meToo_list.csv', error_bad_lines=False);
data_text = data[['body']]
data_text2 = data[['title']]
data_text['index'] = data_text.index
data_text2['index'] = data_text2.index
documents = data_text
documents2 = data_text2
np.random.seed(2018)
nltk.download('wordnet')
print(category("Completed",documents,documents2,data))
