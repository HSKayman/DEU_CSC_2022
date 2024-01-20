import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans
from sklearn import preprocessing
from operator import itemgetter



  
df_real = pd.read_csv('data.csv')
# =============================================================================
# hepsini yapma
# =============================================================================
i=0
sumi=[]
c=1
brd=len(df_real.values[0])
fig=plt.figure(figsize=(brd*4, brd*4))
while(i<brd):
    j=0
    while(j<i):
        #kolon sabitleme
        df=df_real.iloc[:,[i, j]].values
        #kmeans algoritmasi
        kmeans = KMeans(n_clusters=3).fit(df)
        centroids = kmeans.cluster_centers_
        #sentroid ve hangi ikilisinin ismini yazma
        print("{} {} {}".format(df_real.columns[i],"<->",df_real.columns[j]))
        print(centroids)
        #diger gerekli islemler
        sumi.append([kmeans.inertia_,i,j])
        df_t= np.transpose(df)
        plt.subplot(brd,brd,c)
        c+=1
        plt.title("{} {} {}".format(df_real.columns[i],"<->",df_real.columns[j]))
        plt.scatter(df_t[0], df_t[1], c= kmeans.labels_.astype(float), s=50, alpha=0.5)
        plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=50)
        j+=1
    c+=brd-j
    i+=1
#ekrana bastirip exportlama
plt.show()
fig.savefig('all.png')
# =============================================================================
# sumofallsquares scale edip siralam
# =============================================================================
sumi=np.transpose(sumi)
sumi[0]=preprocessing.scale(sumi[0])
sumi=np.transpose(sumi)
sumi=sorted(sumi, key=itemgetter(0),reverse=False)
# =============================================================================
# ilk dortluyu yapma
# =============================================================================
i=0
f=True
fig2=plt.figure(figsize=(10, 10))
while(True):
        #kolon sabitleme
        df= df_real.iloc[:,[sumi[i][1], sumi[i][2]]].values  
        #kmeans algoritmasi
        kmeans = KMeans(n_clusters=3).fit(df)
        centroids = kmeans.cluster_centers_
        #diger gerekli islemler
        df_t= np.transpose(df)
        
        plt.scatter(df_t[0], df_t[1], c= kmeans.labels_.astype(float), s=50, alpha=0.5)
        plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=50)
        plt.title("{} {} {}".format(df_real.columns[sumi[i][1]],"<->",df_real.columns[sumi[i][2]]))
        if i==0 and f:
            fig2.savefig('first.png')
            f=False
            i-=1
        i+=1
        if i==4:
            break
        plt.subplot(2,2,i+1)
plt.show()
fig2.savefig('first 4.png')