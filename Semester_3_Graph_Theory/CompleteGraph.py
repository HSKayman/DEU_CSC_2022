#CompleteGraph
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Jan  8 00:03:35 2020

@author: suca
"""
def CompleteGraph(array,x):
    travel=[False for i in range(int(len(array)))]
    travel[x]=True
    que=[]
    while False in travel:
        j=0
        travel[x]=True
        while j<int(len(array)):
            if travel[j]==False and not array[x][j]==0:
                travel[j]=True
                que.append(j)
            j+=1
        try:
            L=que.pop(0)
            x=L
            continue
        except:
            if False in travel:
                return False
    return True
array = [[0, 1, 1, 1, 0, 0],  
         [1, 0, 1, 0, 0, 0],  
         [1, 1, 0, 0, 0, 0],  
         [0, 1, 0, 0, 0, 0], 
         [0, 0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0, 0]]
print(CompleteGraph(array,0)) 
