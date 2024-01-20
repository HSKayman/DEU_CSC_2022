import itertools
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import preprocessing
import numpy as np
from scipy import spatial

# =============================================================================
# Calculating the distances between each class for all combinations
# =============================================================================

def controlofdistance(x,gdf):
    df = np.transpose(gdf)
    df[1] = preprocessing.scale(df[1])
    df[2] = preprocessing.scale(df[2])
    sumi = []
    for i in x:
        j = 0
        sumi.append([i,0,0])
        count = 0
        while(j < len(df[0])):
            if(df[0][j] == i):
                sumi[-1][1] += df[1][j]
                sumi[-1][2] += df[2][j]
                count += 1
            j += 1
        sumi[-1][1] /= count
        sumi[-1][2] /= count
    
    result = []            
    for i,j in list(itertools.combinations(x,2)):
        k = 0
        while(k < len(sumi)):
            if(i == sumi[k][0]):
                distance = [sumi[k][1],sumi[k][2]]
            if(j == sumi[k][0]):
                distanceII = [sumi[k][1],sumi[k][2]]
            k += 1
        result.append([i,j,spatial.distance.euclidean(distance,distanceII)])
    return result

# =============================================================================
# Identifying the ones with the largest distance
# =============================================================================

def bestpoint(gdf):
    j = 0
    maxi = []
    while(j < len(gdf[0][2])):
        maxi.append([gdf[0][2][j][0],gdf[0][2][j][1],0,0,0])
        j += 1
    j = 0
    while(j < len(gdf)):
        i = 0        
        while(i < len(gdf[0][2])):
            if(gdf[j][2][i][2] > maxi[i][2]):
                maxi[i][2] = gdf[j][2][i][2]
                maxi[i][3] = gdf[j][0]
                maxi[i][4] = gdf[j][1]
                
            i += 1
        j += 1
    return maxi

# =============================================================================
# Reading the data
# =============================================================================

df_real = pd.read_csv('wine.csv')
brd = len(df_real.values[0])

oth = []
for x in df_real["0"]:
    if not x in oth:
        oth.append(x)
distofall = []
i = 1
while(i < brd):
    j = 1
    while(j < i):
        distofall.append([j,i,controlofdistance(oth,df_real.iloc[:,[0,i, j]].values)])
        j += 1
    i += 1

# Printing the best combinations
print(bestpoint(distofall))

# Plotting all scatterplots
i = 1
c = 1
fig = plt.figure(figsize = (brd*4, brd*4))
while(i < brd):
    j = 1
    while(j < i):
        df = df_real.iloc[:,[i, j]].values  
        df_t = np.transpose(df)
        plt.subplot(brd-1,brd-1,c)  
        plt.scatter(df_t[0], df_t[1], c = df_real["0"], s=50, alpha=0.5)
        plt.title("{} {} {}".format(df_real.columns[i],"<->",df_real.columns[j]))
        c += 1
        j += 1
    c += brd-j
    i += 1
fig.savefig("All Scatter")

# Plotting the best scatterplots
fig2 = plt.figure(figsize = (2*x,4*x))
c = 1
for q,y,z,a,b in bestpoint(distofall):
    df = df_real.iloc[:,[0,a, b]].values
    j = 0
    rem = []
    while(j < len(df)):
        if(df[j][0] != q and df[j][0] != y):
            rem.append(j) 
        j += 1
    df = np.delete(df, rem,0)
    df_t = np.transpose(df)
    plt.subplot(x,x//2,c)  
    plt.scatter(df_t[1], df_t[2], c= df_t[0], s=50, alpha=0.5)
    plt.title("{}-{} ==>{} {} {}".format(q,y,df_real.columns[a],"<->",df_real.columns[b]))
    c += 1
fig2.savefig("Best Scatter")