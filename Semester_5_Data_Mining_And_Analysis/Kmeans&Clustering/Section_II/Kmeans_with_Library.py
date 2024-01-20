import pandas as pd
from sklearn.cluster import KMeans as km
import numpy as np
import seaborn as sns
#data okuma
df=pd.read_csv("Final-data.txt")
# k ve model olusturma
k=int(input("k:"))
a=km(n_clusters=k).fit(df)

#Perfomance
TCSS=np.sum((df.values-np.sum(df.values,axis=0)/len(df))**2)
WCSS=np.zeros(k)
for index,i in enumerate(a.labels_):
    WCSS[i]+=np.sum((df.values[index]-a.cluster_centers_[i])**2)**0.5

BCSS=TCSS-np.sum(WCSS)
dist=[]
for i in a.cluster_centers_:
    for j in a.cluster_centers_:
        dist.append(np.sum((i-j)**2)**0.5)
       
DunnIndex=np.min(WCSS)/np.max(dist)
#####################################################
#sonuclari yazma
c=np.zeros(k)
f = open("sonuc.txt", "w")
for i in range(len(a.labels_)):
    f.write("Kayit "+str(i)+":\t"+"Kume "+str(a.labels_[i])+"\n")
    c[a.labels_[i]]+=1
    
for i in range(len(c)):
    f.write("Kume "+str(i)+":\t"+str(c[i])+" kayit\n")
    
f.write("WCSS:"+str(np.sum(WCSS))+"\n")
f.write("BCSS:"+str(np.sum(BCSS))+"\n")
f.write("Dunn Index:"+str(np.sum(DunnIndex))+"\n")
f.close()
#gorsellestirme
df["clus"]=a.labels_
sns.pairplot(df, hue="clus")