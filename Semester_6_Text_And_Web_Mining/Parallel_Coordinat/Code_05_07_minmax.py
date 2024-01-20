# =============================================================================
# importing relevant libraries
# =============================================================================

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
from matplotlib import ticker
from scipy import spatial
from sklearn import preprocessing 
import itertools
import sys

# =============================================================================
# Reading input file
# =============================================================================

dfreal = pd.read_csv('Auto.csv')
subset = list(itertools.combinations([i for i in range(len(dfreal.columns.values))], 2))
permuteset = list(itertools.permutations([i for i in range(len(dfreal.columns.values))]))

# The threshold
th = 0.0275

c = 0
outlier = []

# =============================================================================
# Finding outliers for a given level of threshold at each pair of coordinates
# =============================================================================                

def dfclut(lst,th):
    lst = np.transpose(lst)
    j = 0
    count=0
    while(j < len(lst[0])):
        k = 0
        diseuc=[]
        while(k < len(lst[0])):
            if not j == k:
                diseuc.append(spatial.distance.euclidean([lst[0][k],lst[1][k]],[lst[0][j],lst[1][j]]))
            k += 1
        for i in preprocessing.minmax_scale(diseuc):
            if(not i==0 and abs(i) < th):
                break
        else:
            count += 1              
        j += 1
    return count

# =============================================================================
# Marking outliers
# =============================================================================                

def thisdfclut(lst,th):
    nrm = len(lst[0])
    lst = np.transpose(lst)
    i = 0
    r = []
    while(i < nrm-1):
        j = 0
        gr=[]
        while(j < len(lst[0])):
            k = 0
            diseuc=[]
            while(k < len(lst[0])):
                if not j == k:
                    diseuc.append(spatial.distance.euclidean([lst[i][k],lst[i+1][k]],[lst[i][j],lst[i+1][j]]))
                k += 1
            for l in preprocessing.minmax_scale(diseuc):
                 if(not l==0 and abs(l) < th):
                        gr.append(0)
                        break
            else:
                gr.append(1)    
            r.append(gr)
            j += 1
        i+=1
    return r

# =============================================================================
# Counting the number of outliers for all combinations of coordinates
# =============================================================================

while(c < len(subset)):
    cols = list(subset[c])
    lst = dfreal.iloc[:,cols].values
    outlier.append([cols,dfclut(lst,th)])
    print(outlier[-1])
    c+=1

# =============================================================================
# Identifying the order that has the minimum number of outliers
# =============================================================================

mini = sys.maxsize
for x in permuteset:
    c = 0
    count = 0
    while(c < len(x)-1):
        if x[c] > x[c+1]:    
            i = 0
            while(i < len(subset)):
                if(outlier[i][0][0] == x[c+1] and outlier[i][0][1] == x[c]):
                    count += outlier[i][1]
                    break
                i += 1
        else:
            i = 0
            while(i < len(subset)):
                if(outlier[i][0][0] == x[c] and outlier[i][0][1] == x[c+1]):
                    count += outlier[i][1]
                    break
                i+=1
        c += 1
    if mini > count:
        mini = count
        mincols = x
drawlist = [list(permuteset[0]),list(permuteset[0]),list(mincols)]

# =============================================================================
# Drawing parallel coordinates
# =============================================================================

c = 0
while(c < len(drawlist)): 
    cols = drawlist[c].copy()
    df = dfreal.iloc[:,cols]
    if not c == 0:
        lst = df.values
        thisoutlier = thisdfclut(lst,th)
    cols = list(df.columns.values)
    x = [i for i, _ in enumerate(cols)]
    colours ='#00ff00'
    rcolours ='#ff0000'

    # Setting up parallel coordinates[i for i in range(len(lst))]
    fig, axes = plt.subplots(1, len(x)-1, sharey=False, figsize=(10,5))

    # calculating min max and range of the second coordinate
    min_max_range = {}
    for col in cols:
        min_max_range[col] = [df[col].min(), df[col].max(), np.ptp(df[col])]
        df[col] = np.true_divide(df[col] - df[col].min(), np.ptp(df[col]))

    # Assigning colours
    for i, ax in enumerate(axes):
        for idx in df.index:
            if c==0:
                ax.plot(x, df.loc[idx, cols], colours)
            else:
                if thisoutlier[i][idx]==1 or thisoutlier[i+1][idx]==1 : 
                    ax.plot(x, df.loc[idx, cols], rcolours)
                else:
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
    c += 1