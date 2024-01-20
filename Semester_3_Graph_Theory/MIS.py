#MIS
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan  6 20:01:11 2020

@author: suca
"""
def PaulUnger(array):
    x=[i for i in range(0,int(len(array)))]
    y=""
    def PaulUngerProc(array,x):
        nonlocal y
        i=0
        flag=True
        while i<len(x)-1:
            j=i+1
            while j<len(x):
                if array[x[i]][x[j]]==1:
                    flag=False
                    z=list(x)
                    z.remove(x[i])
                    PaulUngerProc(array,z)
                    z=list(x)
                    z.remove(x[j])
                    PaulUngerProc(array,z)
                j+=1
            i+=1
        if  flag and len(y)<len(x):
            y=list(x)
    PaulUngerProc(array,x)
    z=[i for i in x if not i in y]
    return len(z),z,len(y),y

array=[[0,1,0,1,1,0],
       [1,0,1,0,1,0],
       [0,1,0,0,0,0],
       [1,0,0,0,0,0],
       [1,1,0,0,0,1],
       [0,0,0,0,1,0]]
print(PaulUnger(array))