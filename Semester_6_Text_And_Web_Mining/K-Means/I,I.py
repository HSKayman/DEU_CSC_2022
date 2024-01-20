import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans
from sklearn import preprocessing
from scipy.spatial.distance import euclidean
from operator import itemgetter
  
df_real = pd.read_csv('data.csv')
#en yakin sentroide bagli kontroluuu
def dtrmnt(x,y,z):  #x===indexe gore hangi centroide bagli    
                    #y===sentroid kordinat dizisi      z===df
    i=0
    result=[]
    while(i<len(x)):
        j=0
        dst=[]
        while(j<len(y)):
           dst.append(euclidean(y[j],z[i]))
           j+=1
        result.append(min(dst)==euclidean(y[x[i]],z[i]))# result dizisine boolen append       
        i+=1
    print(result) #true false 
i=0
sumi=[]
c=0
while(i<len(df_real.values[0])):
    j=0
    while(j<i):
        df= preprocessing.scale(df_real.iloc[:,[i, j]].values)  #standardize etmek
        kmeans = KMeans(n_clusters=3).fit(df)
        centroids = kmeans.cluster_centers_
        print(centroids)
        dtrmnt(kmeans.labels_,centroids,df)# fonksiyon girdisi
        sumi.append([kmeans.inertia_,i,j])# kmeans.inertia_ tum uzakliklarin toplami
                                        #ama veriler onceden standartize edilmeli
        df_t= np.transpose(df)
        plt.scatter(df_t[0], df_t[1], c= kmeans.labels_.astype(float), s=50, alpha=0.5)
        plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=50)
        plt.title("{} {} {}".format(df_real.columns[i],"<->",df_real.columns[j]))
        plt.show()
        j+=1
    i+=1
'''#standardize edildikten sonra mesafesi toplamlarinin en kucuk olanin indexi verilmesi
print(sumi)
print("a")
sumi=sorted(sumi, key=itemgetter(0),reverse=False)
print(sumi)
#print(list(sumi[0]).index(min(list(sumi[0]))))
'''