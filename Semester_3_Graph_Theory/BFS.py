#BFS
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 23:51:05 2020

@author: suca
"""
def BFS(array,x):
    travel=[False for i in range(int(len(array)))]
    travel[x]=True
    que=[]
    while False in travel:
        j=0
        if travel[x]==False:
            travel[x]=True
        print(x)
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
                x=travel.index(False)
                continue
array = [[0, 1, 1, 1, 0, 0],  
         [1, 0, 1, 0, 0, 0],  
         [1, 1, 0, 0, 0, 0],  
         [0, 1, 0, 0, 0, 1], 
         [0, 0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0, 0]]
BFS(array,0)    
