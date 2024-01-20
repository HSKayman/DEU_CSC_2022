#Havel-Hakimi
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan  6 17:45:24 2020

@author: suca
"""
def HavelHakimi(array):
    if max(array)>=len(array) or sum(array)%2==1:
        return False
    while True:
        array=sorted(array,reverse=True)
        j=array[0]
        array[0]=0
        while j>0:
            array[j]-=1
            j-=1
        if min(array)<0:
            return False
        if sum(array)==0:
            return True
positivearray=[5,5,7,6,4,2,4,5]
negativearray=[5,4,4,2,2,1]
print(HavelHakimi(negativearray))