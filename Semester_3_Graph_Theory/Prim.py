#Prims
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jan  9 01:31:06 2020

@author: suca
"""
import sys
def Prims(array):
    def minimum(key, travel): 
        mini = sys.maxsize 
        nonlocal array
        min_index=None
        for i in range(int(len(array))): 
            if key[i] < mini and travel[i]== False: 
                mini = key[i] 
                min_index = i 
        return min_index 
    key=[sys.maxsize]*int(len(array)) 
    parent=[None]*int(len(array))
    key[0]=0 
    travel=[False]*int(len(array)) 
    parent[0]=-1 
    for cout in range(int(len(array))): 
        i = minimum(key, travel) 
        travel[i] = True
        for j in range(int(len(array))): 
            if not array[i][j] == 0 and travel[j] == False and key[j] >array[i][j]: 
                    key[j] = array[i][j] 
                    parent[j] =i 
    return [[parent[i],i,array[i][parent[i]]] for i in range(1,int(len(array)))]
array= [[0, 0, 8, 2, 6, 1],
        [0, 0, 6, 3, 0, 9],
        [8, 6, 0, 6, 4, 6],
        [2, 3, 6, 0, 5, 6],
        [6, 0, 4, 5, 0, 7],
        [1, 9, 6, 6, 7, 0]]
print(Prims(array))