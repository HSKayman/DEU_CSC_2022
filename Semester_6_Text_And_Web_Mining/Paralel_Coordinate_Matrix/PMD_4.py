import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import pandas as pd
import numpy as np
from math import factorial
from matplotlib import ticker
from scipy import spatial
from sklearn import preprocessing
import operator
import itertools
from pprint import pprint as p


def sorting(gdf):
    subset = list(itertools.permutations([i for i in range(len(gdf.columns.values))], 3))
    subsetw2 = list(itertools.combinations([i for i in range(len(gdf.columns.values))], 2))
    gdf=preprocessing.normalize(np.transpose(gdf.values))
    i=0
    result=[]
    while(i<len(subsetw2)):
        j=0
        sumi=0
        while(j<len(gdf[0])):
            sumi+=spatial.distance.euclidean([0,gdf[subsetw2[i][0]][j]],
                                             [1,gdf[subsetw2[i][1]][j]])
            j+=1
        result.append([subsetw2[i][0],subsetw2[i][1],sumi])
        i+=1
    realresult=[]
    for x in subset:
        i=0
        sumi=0
        while(i<len(x)-1):
            if(x[i]<x[i+1]):
                mini=x[i]
                maxi=x[i+1]
            else:
                mini=x[i+1]
                maxi=x[i]
            for j,k,l in result:
                if mini==j and maxi==k:
                    sumi+=l
                    break
            i+=1
        realresult.append([sumi,x[0],x[1],x[2]])
    realresult=sorted(realresult, key=operator.itemgetter(2,0), reverse=False)[::2]
    i=0
    a=factorial(len(gdf)-1)//(2*factorial(len(gdf)-3))
    while(i<len(realresult)):
        if i%a==0:
            cmd=realresult[i][0]
        realresult[i].append(cmd)
        i+=1
    return sorted(realresult,key=operator.itemgetter(4),reverse=False)

df_real=pd.read_csv('Auto.csv')
subset=sorting(df_real)
c=0
ctrl=subset[0][2]
count=0
count2=0
p(subset)
#imglist=[]
while(c<len(subset)):
    
    df = df_real.iloc[:,[subset[c][1],subset[c][2],subset[c][3]]]    
    cols = list(df.columns.values)
    x = [i for i, _ in enumerate(cols)]
    colours ='#00ff00'
    # Setting up parallel coordinates[i for i in range(len(lst))]
    fig, axes = plt.subplots(1,len(x)-1, sharey=False, figsize=(10,5))
    
    # calculating min max and range of the second coordinate
    min_max_range = {}
    for col in cols:
        min_max_range[col] = [df[col].min(), df[col].max(), np.ptp(df[col])]
        df[col] = np.true_divide(df[col] - df[col].min(), np.ptp(df[col]))
    
    # Assigning colours
    for i, ax in enumerate(axes):
        for idx in df.index:
            ax.plot(x, df.loc[idx, cols], colours)
        ax.set_xlim([x[i], x[i+1]])
    
    # =============================================================================
    # Defining tickers for parallel coordinates
    # =============================================================================
    
    def set_ticks_for_axis(dim, ax, ticks):
        min_val, max_val, val_range = min_max_range[cols[dim]]
        step = val_range / float(ticks-1)
        tick_labels = [round(min_val + step * i, 2) for i in range(ticks)]
        norm_min = df[cols[dim]].min()
        norm_range = np.ptp(df[cols[dim]])
        norm_step = norm_range / float(ticks-1)
        ticks = [round(norm_min + norm_step * i, 2) for i in range(ticks)]
        ax.yaxis.set_ticks(ticks)
        ax.set_yticklabels(tick_labels)
    
    for dim, ax in enumerate(axes):
        ax.xaxis.set_major_locator(ticker.FixedLocator([dim]))
        set_ticks_for_axis(dim, ax, ticks=6)
        ax.set_xticklabels([cols[dim]])
    
    # Assigning labels for tickets
    ax = plt.twinx(axes[-1])
    dim = len(axes)
    ax.xaxis.set_major_locator(ticker.FixedLocator([x[-2], x[-1]]))
    set_ticks_for_axis(dim, ax, ticks=6)
    ax.set_xticklabels([cols[-2], cols[-1]])
    
    # Combining coordinates and plotting results
    
    plt.subplots_adjust(wspace=0)
    plt.show()
    
    if(ctrl!=subset[c][2]):
        count=1
        count2+=1
        ctrl=subset[c][2]
        fig.savefig('{}_{}'.format(count2,count))
        #imglist.append('{}_{}.png'.format(count2,count))
    else:
        count+=1
        fig.savefig('{}_{}'.format(count2,count))
        #imglist.append('{}_{}.png'.format(count2,count))
    c+=1
plt.tight_layout()

