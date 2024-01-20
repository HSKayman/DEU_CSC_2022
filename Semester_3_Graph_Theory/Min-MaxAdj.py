#Min-MaxAdj
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan  6 17:35:18 2020

@author: suca
"""
def MinMax(array):
    mini=len(array)
    maxi=0
    for i in array:
        c=0
        for j in i:
            if not j==0:
                c+=1
        if mini>c:
            mini=c
        if maxi<c:
            maxi=c
    return mini,maxi
    
array=[[0,7,4,0,2,0,0],
		[7,0,3,2,0,6],
		[4,3,0,8,1,0],
		[0,2,8,0,10,3],
		[2,0,1,10,0,0],
		[0,6,0,3,0,0]]


mini,maxi=MinMax(array)
print(mini,maxi)