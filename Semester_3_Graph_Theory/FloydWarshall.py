#FloydWarshall
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 02:00:29 2020

@author: suca
"""
import sys
def FloydWarshall(array):
    k=0
    while k<int(len(array)):
        i=0
        while i<int(len(array)):
            j=0
            while j<int(len(array)):
                array[i][j]=min(array[i][j] ,array[i][k]+ array[k][j])
                j+=1
            i+=1
        k+=1
    return array

array= [[0, sys.maxsize//2, 8, 2, 6, 1],
        [sys.maxsize//2, 0, 6, 3, sys.maxsize//2, 9],
        [8, 6, 0, 6, 4, 6],
        [2, 3, 6, 0, 5, 6],
        [6, sys.maxsize//2, 4, 5, 0, 7],
        [1, 9, 6, 6, 7, 0]]
print(FloydWarshall(array))