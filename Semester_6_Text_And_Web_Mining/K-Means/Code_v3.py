import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans
from sklearn import preprocessing
from operator import itemgetter

df_real = pd.read_csv('data.csv')

# =============================================================================
# Scaling data points, finding centroids and clustering the scatterplots
# =============================================================================

i = 0
sumi = []
brd = len(df_real.values[0])
while(i < brd):
    j = 0
    while(j < i):
        df = preprocessing.scale(df_real.iloc[:,[i, j]].values)

# K-means algorithm to cluster the data with predetermined number of centroids
        kmeans = KMeans(n_clusters=3).fit(df)
        sumi.append([kmeans.inertia_,i,j])
        j += 1
    i += 1

# =============================================================================
# Sorting the scatterplots
# =============================================================================

sumi = sorted(sumi, key=itemgetter(0),reverse=False)

i = 0
c = 1
while(i<len(sumi)):     
    df = df_real.iloc[:,[sumi[i][1], sumi[i][2]]].values  

# K-means algorithm to cluster the data by a predetermined number of centroids
    kmeans = KMeans(n_clusters=3).fit(df)

# Determining the centroids
    centroids = kmeans.cluster_centers_
    df_t = np.transpose(df)
# The Best Scatter Draw
    if i==0:
        fig2 = plt.figure(figsize = (8, 4))
        plt.title("{} {} {} ({})".format(df_real.columns[sumi[i][1]],"<->",df_real.columns[sumi[i][2]],c))
        plt.scatter(df_t[0], df_t[1], c= kmeans.labels_.astype(float), s=50, alpha=0.5)
        plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=50)
        fig2.savefig('The Best Scatter')
        fig = plt.figure(figsize = (brd*4, brd*4))
#All Scatter Draw
    plt.subplot(brd,brd//2,c)    
    plt.title("{} {} {} ({})".format(df_real.columns[sumi[i][1]],"<->",df_real.columns[sumi[i][2]],c))
    plt.scatter(df_t[0], df_t[1], c= kmeans.labels_.astype(float), s=50, alpha=0.5)
    plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=50)
    i += 1
    c += 1

fig.savefig('ALL.png')
