#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Jan 24 12:59:47 2020

@author: suca
"""
# =============================================================================
# importing relevant libraries
# =============================================================================
import plotly.figure_factory as ff
from scipy.stats import pearsonr
import matplotlib.pyplot as plt
from operator import itemgetter
from pyod.models.knn import KNN
from matplotlib import ticker
import plotly.offline as py
import imgkit
import pandas as pd
import numpy as np
import itertools
#threshold
thold = 0.055
def Count_Outlier(Constant_Data_Frame,th=0.1):#0.0275
    # =============================================================================
    # Marking outliers
    # =============================================================================
    def Def_Outliers(Constant_Data_Frame,index):
        nonlocal th
        i=0
        result=[]
        while i<int(len(index))-1:
            Tenative_Data_Frame=Constant_Data_Frame.iloc[:,[index[i],index[i+1]]].values
            clf = KNN()
            clf.fit(Tenative_Data_Frame)
            result.append(clf.labels_)
            i+=1
        sumi=0
        for i in result:
            for j in i:
                sumi+=j
        return [result,sumi/(int(len(Constant_Data_Frame))*int(len(index)))]
    # =============================================================================
    # Ordering Axes
    # =============================================================================
    def Like_Kurtosis(Sorted_Cor,Colums_Len):
        List=Sorted_Cor[0][:2]
        i=1
        while Colums_Len>int(len(List)):
            if Sorted_Cor[i][0]==List[0]:
                if not Sorted_Cor[i][1] in List:
                    List.insert(0,Sorted_Cor[i][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][1]==List[0]:
                if not Sorted_Cor[i][0] in List:   
                    List.insert(0,Sorted_Cor[i][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][0]==List[-1]:
                if not Sorted_Cor[i][1] in List:
                    List.append(Sorted_Cor[i][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            elif Sorted_Cor[i][1]==List[-1]:
                if not Sorted_Cor[i][0] in List:  
                    List.append(Sorted_Cor[i][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            i+=1
        print(List)
        return List
    # =============================================================================
    # Ordering data according to Compute_All_Outlier
    # =============================================================================
    def Compute_All_Outlier(Constant_Data_Frame):
        subset = list(itertools.combinations([i for i in range(len(Constant_Data_Frame.columns.values))], 2))
        i=0
        cor=[]
        while(i<len(subset)):
            Tenative_Data_Frame=Constant_Data_Frame.iloc[:,[subset[i][0],subset[i][1]]].values
            clf = KNN()
            clf.fit(Tenative_Data_Frame)
            cor.append([subset[i][0],subset[i][1],sum(clf.labels_)])
            i+=1
        q=0
        for col in Constant_Data_Frame.columns:
            print(q,"=",col) 
            q+=1
        #Sorting
        return Def_Outliers(Constant_Data_Frame,Like_Kurtosis(sorted(cor, key=lambda x: abs(x[2]),reverse=False),int(len(Constant_Data_Frame.columns))))
    return Compute_All_Outlier(Constant_Data_Frame)
    
# =============================================================================
# Draw ScatterPlot Function
# =============================================================================
def ScatterPlot(Constant_Data_Frame,Name):
    # =============================================================================
    # Ordering Axes
    # =============================================================================
    def Like_Kurtosis(Sorted_Cor,Colums_Len):
        List=list(Sorted_Cor[0][1])
        i=1
        while Colums_Len>int(len(List)):
            if Sorted_Cor[i][1][0]==List[0]:
                if not Sorted_Cor[i][1][1] in List:
                    List.insert(0,Sorted_Cor[i][1][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][1][1]==List[0]:
                if not Sorted_Cor[i][1][0] in List:   
                    List.insert(0,Sorted_Cor[i][1][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][1][0]==List[-1]:
                if not Sorted_Cor[i][1][1] in List:
                    List.append(Sorted_Cor[i][1][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            elif Sorted_Cor[i][1][1]==List[-1]:
                if not Sorted_Cor[i][1][0] in List:  
                    List.append(Sorted_Cor[i][1][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            i+=1
        return List
    # =============================================================================
    # Ordering data according to Pearson correlations
    # =============================================================================
    def combine(Tentative_Data_Frame,Index_List):
        subset = list(itertools.combinations(Index_List, 2))
        i=0
        Will_Sort=[]
        while i<len(subset):
            Will_Sort.append([pearsonr(Tentative_Data_Frame[subset[i][0]],Tentative_Data_Frame[subset[i][1]]),subset[i]])
            i+=1
        Will_Sort=sorted(Will_Sort, key=lambda x: abs(x[0][0]),reverse=True)
        return Like_Kurtosis(sorted(Will_Sort, key=lambda x: abs(x[0][0]),reverse=True),int(len(Index_List)))
    # =============================================================================
    # Ordering whole data      
    # =============================================================================
    def sort(Result,Data_Frame):
        Result_First=list(combine(Data_Frame,list(np.transpose(np.transpose(list(itertools.filterfalse(lambda x: x[0],Result)))[1]))))
        Result_Second=list(np.transpose(list(np.transpose(list(itertools.filterfalse(lambda x: not x[0],Result))))[1:]))
        Result_Second=list([i for i,j in sorted(Result_Second, key=itemgetter(1),reverse=True)])
        return Result_First+Result_Second
    # =============================================================================
    # Defining whether the series is high or low cardinal
    # =============================================================================
    def High_Or_Low(Constant_Data_Frame):
        Constant_Data_Frame= np.transpose(Constant_Data_Frame.values)
        i=0
        result=[]
        while i<len(Constant_Data_Frame):
            j=0
            count=[]
            while j<len(Constant_Data_Frame[0]):
                if not Constant_Data_Frame[i][j] in count:
                    count.append(Constant_Data_Frame[i][j])
                j+=1
            result.append([len(count)<(len(Constant_Data_Frame[i]))**0.5,i,len(count)])
            i+=1
        return sort(result,Constant_Data_Frame)
    # Printing figures for ordered data
    Tentative_Data_Frame= Constant_Data_Frame.iloc[:, High_Or_Low(Constant_Data_Frame)]
    fig = ff.create_scatterplotmatrix(Tentative_Data_Frame, height=int(len(Tentative_Data_Frame.columns))*150, width=int(len(Tentative_Data_Frame.columns))*150)
    py.plot(fig,filename = '{}'.format(Name))
    imgkit.from_file('{}.html'.format(Name), '{}.jpg'.format(Name))
    return
def ParallelCoordinat(Constant_Data_Frame,Outlier_List,Name):
    # =============================================================================
    # Ordering data according to Pearson correlations
    # =============================================================================
    Tentative_Data_Frame=Constant_Data_Frame
    #Draw To Parallel Coordinat 
    cols = list(Tentative_Data_Frame.columns.values)
    x = [i for i, _ in enumerate(cols)]
    colours ='#00ff00'
    rcolours ='#ff0000'
    # Setting up parallel coordinates[i for i in range(len(lst))]
    fig, axes = plt.subplots(1, len(x)-1, sharey=False, figsize=(int(len(cols))*2,int(len(cols))))
    
    # calculating min max and range of the second coordinate
    min_max_range = {}
    for col in cols:
        min_max_range[col] = [Tentative_Data_Frame[col].min(), Tentative_Data_Frame[col].max(), np.ptp(Tentative_Data_Frame[col])]
        Tentative_Data_Frame[col] = np.true_divide(Tentative_Data_Frame[col] - Tentative_Data_Frame[col].min(), np.ptp(Tentative_Data_Frame[col]))
    
    # Assigning colours
    for i, ax in enumerate(axes):
        for idx in Tentative_Data_Frame.index:
            if Outlier_List[i][idx]==1:
                ax.plot(x, Tentative_Data_Frame.loc[idx, cols], rcolours)
            else:
                ax.plot(x, Tentative_Data_Frame.loc[idx, cols], colours)
        ax.set_xlim([x[i], x[i+1]])
    
    # =============================================================================
    # Defining tickers for parallel coordinates
    # =============================================================================
    
    def set_ticks_for_axis(dim, ax, ticks):
        min_val, max_val, val_range = min_max_range[cols[dim]]
        step = val_range / float(ticks-1)
        tick_labels = [round(min_val + step * i, 2) for i in range(ticks)]
        norm_min = Tentative_Data_Frame[cols[dim]].min()
        norm_range = np.ptp(Tentative_Data_Frame[cols[dim]])
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
    plt.show()
    fig.savefig('{}.png'.format(Name))
    return
#Work For All Data
for i in range(1,8):
    if i==5:
        continue
    Constant_Data_Frame=pd.read_csv('DataSet {}.csv'.format(i))
    Dimension_Count=len(Constant_Data_Frame.values[0])
    Outlier_List=Count_Outlier(Constant_Data_Frame)
    print(Outlier_List[1])
    #Determine to ScatterPlot or Parallel Coordinate
    if Dimension_Count<3:
        ScatterPlot(Constant_Data_Frame,"Data {}".format(i))
    elif Outlier_List[1]<thold:
        ParallelCoordinat(Constant_Data_Frame,Outlier_List[0],"Data {}".format(i))
    else:
       ScatterPlot(Constant_Data_Frame,"Data {}".format(i))