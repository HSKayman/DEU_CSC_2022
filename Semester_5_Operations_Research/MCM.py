# -*- coding: utf-8 -*-
"""
Created on Fri Dec  4 00:35:52 2020

@author: HasanSucaKayman
"""
import numpy as np
def MCM(Reeltable,MaxOrMin): #Max True, Min False
    table=np.copy(Reeltable)
    numberOfRow,numberOfColoumn=table.shape
    if np.sum(table.T[numberOfColoumn-1])==np.sum(table[numberOfRow-1]):
        result=np.zeros((numberOfRow-1,numberOfColoumn-1))
        if MaxOrMin:
             while( not (np.sum(table[numberOfRow-1])==0)):
                
                i=0
                maximum=table[0,0]
                maxs=[0,0]
                flag=True
                while(i<numberOfRow-1):
                    j=0;
                    while(j<numberOfColoumn-1):
                        if flag and not table[i,j]==-1:
                            flag=False
                            maximum=table[i,j]
                            maxs[0],maxs[1]=i,j
                        if maximum<table[i,j] and not table[i,j]==-1:
                            maximum=table[i,j]
                            maxs[0],maxs[1]=i,j
                        j+=1
                    i+=1
                i,j=maxs
                if table[numberOfRow-1,j]<table[i,numberOfColoumn-1]:
                    result[i,j]=table[numberOfRow-1,j]
                    table[numberOfRow-1,j]-=result[i,j]
                    table[i,numberOfColoumn-1]-=result[i,j]
                    table[i,j]=-1
                else:
                    result[i,j]=table[i,numberOfColoumn-1]
                    table[numberOfRow-1,j]-=result[i,j]
                    table[i,numberOfColoumn-1]-=result[i,j]
                    table[i,j]=-1
        else:
            while( not (np.sum(table[numberOfRow-1])==0)):
                
                i=0
                minimum=table[0,0]
                mins=[0,0]
                flag=True
                while(i<numberOfRow-1):
                    j=0;
                    while(j<numberOfColoumn-1):
                        if flag and not table[i,j]==-1:
                            flag=False
                            minimum=table[i,j]
                            mins[0],mins[1]=i,j
                        if minimum>table[i,j] and not table[i,j]==-1:
                            minimum=table[i,j]
                            mins[0],mins[1]=i,j
                        j+=1
                    i+=1
                i,j=mins
                if table[numberOfRow-1,j]<table[i,numberOfColoumn-1]:
                    result[i,j]=table[numberOfRow-1,j]
                    table[numberOfRow-1,j]-=result[i,j]
                    table[i,numberOfColoumn-1]-=result[i,j]
                    table[i,j]=-1
                else:
                    result[i,j]=table[i,numberOfColoumn-1]
                    table[numberOfRow-1,j]-=result[i,j]
                    table[i,numberOfColoumn-1]-=result[i,j]
                    table[i,j]=-1
        table=np.delete(Reeltable, np.s_[-1:], axis=1)[:-1,:]
        print("Z={}".format(np.sum(result*table)))
    else:
        print("demand and supply are not equal")
        return None
    return result
    
    
    
    
    
    
table=np.array(([2,3,5,6,5],
               [2,1,3,5,10],
               [3,8,4,6,15],
               [12,8,4,6,0]))        
print(MCM(table,True))