#Kruskal
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan  8 01:01:35 2020

@author: suca
"""
def Kruskal(array):
    def takeSecond(elem):
        return elem[2]
    edge=[]
    for i,x in enumerate(array):
        for j,y in enumerate(x):
            if not y==0:
                edge.append([i,j,y])
    travel=[0 for i in array]
    edge.sort(key=takeSecond)
    i=0
    krusk=[]
    print(edge)
    dist=0
    while 0 in travel or not int(len(krusk))==int(len(array))-1:
        if not travel[edge[i][0]]+travel[edge[i][1]]==2:
           travel[edge[i][0]]=1
           travel[edge[i][1]]=1
           krusk.append(edge[i])
           dist+=edge[i][2]
        i+=1
        if i+1>int(len(edge)):
            break
    return [krusk,dist]
            
    
array= [[0, 0, 8, 2, 6, 1],
        [0, 0, 6, 3, 0, 9],
        [8, 6, 0, 6, 4, 6],
        [2, 3, 6, 0, 5, 6],
        [6, 0, 4, 5, 0, 7],
        [1, 9, 6, 6, 7, 0]]
print(Kruskal(array))





