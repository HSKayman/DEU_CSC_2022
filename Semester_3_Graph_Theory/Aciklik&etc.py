#Aciklik&vb
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  7 01:00:06 2020

@author: suca
"""
def Aciklik(array):
    aciklik=[max(i) for i in array]
    return max(aciklik),min(aciklik),aciklik
#uzaklik matrixi    
array= [[1, 0, 8, 2, 6, 1],
        [0, 4, 6, 3, 0, 9],
        [8, 6, 7, 6, 4, 6],
        [2, 3, 6, 5, 5, 6],
        [6, 0, 4, 5, 2, 7],
        [1, 9, 6, 6, 7, 7]]
print(Aciklik(array))