#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Feb  1 01:14:51 2020

@author: suca
"""
# =============================================================================
# importing relevant libraries
# =============================================================================
from matplotlib import pyplot as plt
from matplotlib import ticker
import seaborn as sns
import pandas as pd
import numpy as np

# =============================================================================
# Read to necessary data 
# =============================================================================
with open('Data.txt','r') as f:
    Lines=f.readlines()
Index=str(Lines[0][:-1])
Order_Index = list(map(int, Lines[1].split()))
Order_Index2 = list(map(int, Lines[2].split()))
Method_Num= int(Lines[3])
f.close()
Color=pd.read_csv('Color_Map.csv').values

#Draw To Scatter Plot 
Constant_Data_Frame=pd.read_csv('{}/{}_pp.csv'.format(Index,Index))
SP=Constant_Data_Frame.iloc[:,Order_Index2]
sns_plot=sns.pairplot(SP)
sns_plot.savefig("{}/{}_Metric_{}_SP.png".format(Index,Index,Method_Num))

#Draw To Parallel Coordinat 
Constant_Data_Frame=Constant_Data_Frame.iloc[:,Order_Index]
cols = list(Constant_Data_Frame.columns.values)
x = [i for i, _ in enumerate(cols)]
colours ='#00ff00'
rcolours ='#ff0000'

# Setting up parallel coordinates[i for i in range(len(lst))]
fig, axes = plt.subplots(1, len(x)-1, sharey=False, figsize=(int(len(cols))*2,int(len(cols))))

# calculating min max and range of the second coordinate
min_max_range = {}
for col in cols:
    min_max_range[col] = [Constant_Data_Frame[col].min(), Constant_Data_Frame[col].max(), np.ptp(Constant_Data_Frame[col])]
    Constant_Data_Frame[col] = np.true_divide(Constant_Data_Frame[col] - Constant_Data_Frame[col].min(), np.ptp(Constant_Data_Frame[col]))

# Assigning colours
for i, ax in enumerate(axes):
    for idx in Constant_Data_Frame.index:
        if Color[i][idx]==1:
            ax.plot(x, Constant_Data_Frame.loc[idx, cols], rcolours)
        else:
            ax.plot(x, Constant_Data_Frame.loc[idx, cols], colours)
    ax.set_xlim([x[i], x[i+1]])

# =============================================================================
# Defining tickers for parallel coordinates
# =============================================================================
def set_ticks_for_axis(dim, ax, ticks):
    min_val, max_val, val_range = min_max_range[cols[dim]]
    step = val_range / float(ticks-1)
    tick_labels = [round(min_val + step * i, 2) for i in range(ticks)]
    norm_min = Constant_Data_Frame[cols[dim]].min()
    norm_range = np.ptp(Constant_Data_Frame[cols[dim]])
    norm_step = norm_range / float(ticks-1)
    ticks = [round(norm_min + norm_step * i, 2) for i in range(ticks)]
    ax.yaxis.set_ticks(ticks)
    ax.set_yticklabels(tick_labels)

for dim, ax in enumerate(axes):
    ax.xaxis.set_major_locator(ticker.FixedLocator([dim]))
    set_ticks_for_axis(dim, ax, ticks=6)
    ax.set_xticklabels([cols[dim]])

# Assigning labels for tickets
ax = (plt.twinx(axes[-1]))
ax.xaxis.set_major_locator(ticker.FixedLocator([x[-2], x[-1]]))
set_ticks_for_axis(len(axes), ax, ticks=6)
ax.set_xticklabels([cols[-2], cols[-1]])

# Combining coordinates and plotting results
plt.subplots_adjust(wspace=0)    
fig.savefig("{}/{}_Metric_{}_PCP.png".format(Index,Index,Method_Num))
print("Figure for Metric_{} is ready".format(Method_Num))
