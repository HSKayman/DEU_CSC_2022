# -*- coding: utf-8 -*-
"""
Created on Thu Dec  3 23:04:20 2020

@author: HasanSucaKayman
"""
import numpy as np
def NWM(table,MaxOrMin=None): #Max True, Min False
    numberOfRow,numberOfColoumn=table.shape
    if np.sum(table.T[numberOfColoumn-1])==np.sum(table[numberOfRow-1]):
        i=0
        j=0
        result=np.zeros((numberOfRow-1,numberOfColoumn-1))
        while(numberOfColoumn-1>j and numberOfRow-1>i):
            if table[numberOfRow-1,j]<table[i,numberOfColoumn-1]:
                result[i,j]=table[numberOfRow-1,j]
                table[numberOfRow-1,j]-=result[i,j]
                table[i,numberOfColoumn-1]-=result[i,j]
                j+=1
            else:
                result[i,j]=table[i,numberOfColoumn-1]
                table[numberOfRow-1,j]-=result[i,j]
                table[i,numberOfColoumn-1]-=result[i,j]
                i+=1
        table=np.delete(table, np.s_[-1:], axis=1)[:-1,:]
        print("Z={}".format(np.sum(result*table)))
    else:
        print("demand and supply are not equal")
        return None
    return result

    
    
table=np.array(([2,3,5,6,5],
               [2,1,3,5,10],
               [3,8,4,6,15],
               [12,8,4,6,0]))        
MaxOrMin=False
print(NWM(table,True))
