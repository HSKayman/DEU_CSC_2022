from bs4 import BeautifulSoup
from requests import get
import pandas as pd
multiplelist = {"Name":[],
                 "Director":[], 
                 "IMDB Rating":[], 
                 "Number Of Votes":[],
                 "Genres":[],
                 "Year":[]
                 }
maincount=1
while(True):
    print("--",maincount,"--")
    normal_number = maincount
    url ="https://www.imdb.com/search/title/?title_type=feature&countries=tr&sort=num_votes,desc&count=250&start={}&ref_=adv_nxt".format(maincount)
    response = get(url)
    html_soup = BeautifulSoup(response.text, 'html.parser')
    movie_containers = html_soup.find_all('div', class_ = 'lister-item mode-advanced')
    for i in movie_containers:
        print(maincount)
        maincount+=1
        try:
            if i.h3.a.text is not None:
                multiplelist["Name"].append(i.h3.a.text)
            else:
                multiplelist["Name"].append(" ")
        except:
            multiplelist["Name"].append(" ")
        try:
            if i.h3.find('span', class_ = 'lister-item-year text-muted unbold').text is not None:
                multiplelist["Year"].append(i.h3.find('span', class_ = 'lister-item-year text-muted unbold').text)
            else:
                multiplelist["Year"].append(" ")
        except:
            multiplelist["Year"].append(" ")
        try:    
            if i.strong.text is not None:
                multiplelist["IMDB Rating"].append(float(i.strong.text))
            else:
                multiplelist["IMDB Rating"].append(" ")    
        except:
            multiplelist["IMDB Rating"].append(" ")
        try:
            if i.p.find('span', class_ = 'genre').text is not None:
                multiplelist["Genres"].append(i.p.find('span', class_ = 'genre').text)
            else:
                multiplelist["Genres"].append(" ")
        except:
            multiplelist["Genres"].append(" ")
        try:
            if i.find('span', attrs = {'name':'nv'})['data-value'] is not None:
                multiplelist["Number Of Votes"].append(i.find('span', attrs = {'name':'nv'})['data-value'])
            else:
                multiplelist["Number Of Votes"].append(" ")
        except:
            multiplelist["Number Of Votes"].append(" ")
        try:
            if i.find_all(['p'])[2].a.text is not None:
                multiplelist["Director"].append(i.find_all(['p'])[2].a.text)
            else:
                multiplelist["Director"].append(" ")
        except:
            multiplelist["Director"].append(" ")
    if normal_number ==maincount :
        break
df =pd.DataFrame(multiplelist)
df.to_csv('Imdb_list.csv', index=False)



