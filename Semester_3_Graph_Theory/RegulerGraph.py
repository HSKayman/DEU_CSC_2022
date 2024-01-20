#RegulerGraph
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan  6 19:08:01 2020

@author: suca
"""
def RegulerGraph(array):
    Flag=True
    for i in array:
        c=0
        for j in i:
            if not j==0:
                c+=1
        if Flag:
            x=c
            Flag=False
        else:
            if c is not x:
                return False
    return True
    
negativearray=[[0,7,4,0,2,0,0],
		[7,0,3,2,0,6],
		[4,3,0,8,1,0],
		[0,2,8,0,10,3],
		[2,0,1,10,0,0],
		[0,6,0,3,0,0]]
positivearray=[[0,7,4,0,2,0,0],
		[7,0,3,2,0,0],
		[4,3,0,8,0,0],
		[0,2,8,0,0,3],
		[2,0,1,10,0,0],
		[0,6,0,3,1,0]]
print(RegulerGraph(positivearray))
