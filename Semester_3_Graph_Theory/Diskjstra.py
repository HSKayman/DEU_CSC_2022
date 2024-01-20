#Diskjstra
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 01:09:43 2020

@author: suca
"""
import sys

def Diskjstra(array,xi):
    def minDistance(x,travel): 
        mini = sys.maxsize 
        i=0
        min_index=xi
        while i<int(len(x)): 
            if x[i] < mini and travel[i] == False: 
                mini = x[i] 
                min_index = i
            i+=1
        return min_index
    x=[sys.maxsize//2 for i in range(int(len(array)))]
    x[xi]=0
    travel=[False for i in range(int(len(array)))]
    while False in travel:
        j=0
        while j<int(len(array)):
            if array[xi][j] is not 0 or j is not sys.maxsize:
                if x[j]>array[xi][j]+x[xi]:
                    x[j]=array[xi][j]+x[xi]
            j+=1
        travel[xi]=True
        xi=minDistance(x,travel)
    return x
                
            
    
array= [[0, sys.maxsize//2, 8, 2, 6, 1],
        [sys.maxsize//2, 0, 6, 3, sys.maxsize//2, 9],
        [8, 6, 0, 6, 4, 6],
        [2, 3, 6, 0, 5, 6],
        [6, sys.maxsize//2, 4, 5, 0, 7],
        [1, 9, 6, 6, 7, 0]]
print(Diskjstra(array,1))