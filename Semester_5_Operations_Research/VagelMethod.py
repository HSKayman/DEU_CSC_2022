# -*- coding: utf-8 -*-
"""
Created on Fri Dec  4 00:38:22 2020

@author: HasanSucaKayman
"""

import numpy as np
def FindMinOrMax(array,MaxOrMin):#Max True, Min False
    count=0
    for i in array:
        if i==-1:
            count+=1
    if(count>array.shape[0]-1):
        return -1
    if(count>array.shape[0]-2):
        return 0
    else:
        new_arr = np.sort(np.delete(array, np.where(array == -1)))
        
        if MaxOrMin:
            return new_arr[-1]-new_arr[-2]
        else:
            return new_arr[1]-new_arr[0]
def FindIndex(array,MaxOrMin):#Max True, Min False
    index=0
    opt=0
    for i,j in enumerate(array):
        if not j==-1:
            index=i
            opt=j
            
    if MaxOrMin:
        for i,j in enumerate(array):
            if opt<j and not j==-1:
                opt=j
                index=i
    else:
        for i,j in enumerate(array):
            if opt>j and not j==-1:
                opt=j
                index=i
    return index
    
        
def Vogel(Reeltable,MaxOrMin): #Max True, Min False
    table=np.copy(Reeltable)
    numberOfRow,numberOfColoumn=table.shape
    if np.sum(table.T[numberOfColoumn-1])==np.sum(table[numberOfRow-1]):
        result=np.zeros((numberOfRow-1,numberOfColoumn-1))
        while( not (np.sum(table[numberOfRow-1])==0)):
           
           i=0
           riskList=[]
           while(i<numberOfRow-1):
               riskList.append(FindMinOrMax(table[i,:-1],MaxOrMin))
               i+=1
           i=0
           while(i<numberOfColoumn-1):
               riskList.append(FindMinOrMax(table[:-1,i], MaxOrMin))
               i+=1
           
           index=0
           maxi=riskList[0]
           for i,j in enumerate(riskList):
               if maxi<j:
                   maxi=j
                   index=i
           if(index>numberOfRow-2):
              index-=numberOfRow-1
              i,j=FindIndex(table[:-1,index],MaxOrMin),index
              if table[numberOfRow-1,j]<table[i,numberOfColoumn-1]:
                   result[i,j]=table[numberOfRow-1,j]
                   table[numberOfRow-1,j]-=result[i,j]
                   table[i,numberOfColoumn-1]-=result[i,j]
                   table[:-1,j]=-1
              else:
                   result[i,j]=table[i,numberOfColoumn-1]
                   table[numberOfRow-1,j]-=result[i,j]
                   table[i,numberOfColoumn-1]-=result[i,j]
                   table[i,:-1]=-1
           else:
               i,j=index,FindIndex(table[index,:-1],MaxOrMin)
               #print(i,j)
               #break
               if table[numberOfRow-1,j]<table[i,numberOfColoumn-1]:
                   result[i,j]=table[numberOfRow-1,j]
                   table[numberOfRow-1,j]-=result[i,j]
                   table[i,numberOfColoumn-1]-=result[i,j]
                   table[:-1,j]=-1
               else:
                   result[i,j]=table[i,numberOfColoumn-1]
                   table[numberOfRow-1,j]-=result[i,j]
                   table[i,numberOfColoumn-1]-=result[i,j]
                   table[i,:-1]=-1
        table=np.delete(Reeltable, np.s_[-1:], axis=1)[:-1,:]
        print("Z={}".format(np.sum(result*table)))
    else:
        print("demand and supply are not equal")
        return None
    return result
    
    
    
table=np.array(([13,10,22,29,18,0,5],
               [14,13,16,21,999999,0,6],
               [3,0,999999,11,6,0,7],
               [18,9,19,23,11,0,4],
               [30,24,34,36,28,0,3]
               ,[3,5,4,5,6,2,0]))        
print(Vogel(table,False))
