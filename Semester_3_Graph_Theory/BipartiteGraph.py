#BipartiteGraph
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan  8 00:26:53 2020

@author: suca
"""
def BipartiteGraph(array):
    travel=[2 for i in range(int(len(array)))]
    i=0
    while i<int(len(array)):
        j=0
        while j<int(len(array)):
            if not array[i][j]==0 and not travel[j]==2:
                travel[i]=1-travel[j]
                break
            j+=1
        if travel[i]==2:
            travel[i]=1
        j=0                
        while j<int(len(array)):
            if not array[i][j]==0:
                if travel[i]==1:
                    if travel[j]==1:
                        return False
                    else:
                        travel[j]=2
                else:
                    if travel[j]==0:
                        return False
                    else:
                        travel[j]=1
            j+=1
        i+=1
        def inp(i):
            nonlocal travel
            return [i,travel[i]]
    return [inp(i) for i in range(int(len(travel)))]
array = [[0, 0, 0, 1, 1, 1],  
         [0, 0, 0, 1, 1, 1],  
         [0, 0, 0, 1, 1, 1],  
         [1, 1, 1, 0, 0, 0], 
         [1, 1, 1, 0, 0, 0],
         [1, 1, 1, 0, 0, 0]]
print(BipartiteGraph(array))