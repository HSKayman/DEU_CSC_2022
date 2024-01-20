#MeanDegree
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan  6 19:47:32 2020

@author: suca
"""
def MeanDegre(array):
    c=0
    for i in array:
        for j in i:
            if j is not 0:
                c+=1
    return c/len(array)
array = [[0, 1, 1, 1, 0],  
         [1, 0, 1, 0, 0],  
         [1, 1, 0, 0, 0],  
         [0, 1, 0, 0, 1], 
         [0, 0, 0, 1, 0]]
print(MeanDegre(array))    