# =============================================================================
# importing relevant libraries
# =============================================================================

import plotly.offline as py
import plotly.figure_factory as ff
from scipy.stats import pearsonr
import itertools
#import imgkit
import numpy as np
import pandas as pd
from operator import itemgetter
import sys

# =============================================================================
# Ordering data according to Pearson correlations
# =============================================================================

def combine(df2,high,df3):
    subset = list(itertools.combinations(high, 2))
    permuteset = list(itertools.permutations(high))
    i = 0
    willsort = []
    while(i < len(subset)):
        willsort.append([pearsonr(df2[subset[i][0]],df2[subset[i][1]]),subset[i]])
        print(df3.columns[willsort[-1][1][0]],df3.columns[willsort[-1][1][1]],
                  willsort[-1][0][0])
        i += 1
    maxi = -1*sys.maxsize
    for x in permuteset:
        c = 0
        count = 0
        while(c < len(x)-1):
            if x[c] > x[c+1]:    
                i = 0
                while(i < len(subset)):
                    if(willsort[i][1][0] == x[c+1] and willsort[i][1][1] == x[c]):
                        count += willsort[i][0][0]
                        break
                    i += 1
            else:
                i = 0
                while(i < len(subset)):
                    if(willsort[i][1][0] == x[c] and willsort[i][1][1] == x[c+1]):
                        count += willsort[i][0][0]
                        break
                    i+=1
            c += 1
        
        if maxi < count:
            maxi = count
            sortu = x
    return sortu

# =============================================================================
# Ordering whole data
# =============================================================================

def sort(rst,df2,df3):
    result1 = []
    for a,b,c in rst:
        if not a:
            result1.append(b)
    result1 = combine(df2,result1.copy(),df3)
    result2 = []
    for a,b,c in rst:
        if a:
            result2.append([b,c])
    result2 = [i for i,j in sorted(result2, key=itemgetter(1),reverse=True)]
    return list(result1) + list(result2)

# =============================================================================
# Defining whether the series is high or low cardinal
# =============================================================================

def highorlow(df,df3):
    df2= np.transpose(df.values)
    i = 0
    result = []
    while(i < len(df2)):
        j = 0
        count = []
        while(j < len(df2[0])):
            if not df2[i][j] in count:
                count.append(df2[i][j])
            j += 1
        result.append([len(count)<(len(df2[i]))**0.5,i,len(count)])
        i += 1
    return sort(result,df2,df3)

# =============================================================================
# Reading input file
# =============================================================================

df =  pd.read_csv('Auto.csv')

# =============================================================================
# Prinitng the results
# =============================================================================

# Printing figures for raw data
fig = ff.create_scatterplotmatrix(df, height=int(len(df.columns))*150, width=int(len(df.columns))*150)
py.plot(fig,filename = 'Scatterplot Matrix for Raw Data')

# Printing figures for ordered data
df= df.iloc[:,highorlow(df,df)]
fig = ff.create_scatterplotmatrix(df, height=int(len(df.columns))*150, width=int(len(df.columns))*150)
py.plot(fig,filename = 'Scatterplot Matrix for Ordered Data')