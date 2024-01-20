#DFS
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 23:22:53 2020

@author: suca
"""
def DFS(array,x):
    travel=[False for i in range(int(len(array)))]
    travel[x]=True
    stack=[]
    def DFSP(array,x):
        nonlocal travel
        if travel[x]==False:
            print(x)
        travel[x]=True
        nonlocal stack
        j=0
        flag=True
        
        while j<int(len(array)):
            if travel[j]==False and not array[x][j]==0:
                stack.append(j)
                DFSP(array,j)
                flag=False
            j+=1
        if flag==True:
            try:
                L=stack.pop()
                DFSP(array,L)
            except:
                if False in travel:
                    DFSP(array,travel.index(False))
        return True
    return DFSP(array,x)
    
array = [[0, 1, 1, 1, 0, 0],  
         [1, 0, 1, 0, 0, 0],  
         [1, 1, 0, 0, 0, 0],  
         [0, 1, 0, 0, 0, 1], 
         [0, 0, 0, 1, 0, 0],
         [0, 0, 0, 0, 0, 0]]
DFS(array,0)
    