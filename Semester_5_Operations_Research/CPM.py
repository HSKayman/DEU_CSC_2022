# -*- coding: utf-8 -*-
"""
Created on Tue Jan 19 13:41:07 2021

@author: suca
"""
#Distance Matrices
Matrice_Distance=[[0 ,4 ,3 ,2 ,-1,-1,-1],#-1 demek sonsuz demek
                  [-1,-1,-1,-1, 3,2 ,-1],
                  [-1, 0,-1, 0,-1,-1,-1],
                  [-1,-1,-1,-1,-1,-1, 2],
                  [-1,-1,-1,-1,-1,-1, 4],
                  [-1,-1,-1,-1, 0,-1, 3],
                  [-1,-1,-1,-1,-1,-1,-1]]



#ET
ET=[-1 for i in range(len(Matrice_Distance))]
ET[0]=0
k=0
while k<len(Matrice_Distance):
    i=0
    while i<len(Matrice_Distance):
        j=0
        maxi=-1
        while j<len(Matrice_Distance):
            if(Matrice_Distance[j][i]==-1):
                j+=1
                continue;
            if(maxi<Matrice_Distance[j][i]+ET[j] and not ET[j]==-1):
                maxi=Matrice_Distance[j][i]+ET[j]
                ET[i]=ET[j]+Matrice_Distance[j][i] 
            j+=1
        i+=1        
    k+=1
print(ET)


##LT
LT=[-1 for i in range(len(Matrice_Distance))]
LT[-1]=ET[-1]
k=len(Matrice_Distance)-1
while k>-1:
    i=len(Matrice_Distance)-1
    while i>-1:
        j=len(Matrice_Distance)-1
        mini=9999999999999999
        while j>-1:
            if(Matrice_Distance[i][j]==-1):
                j-=1
                continue;
            if(mini>LT[j]-Matrice_Distance[i][j] and not LT[j]==-1):
                mini=LT[j]-Matrice_Distance[i][j]
                LT[i]=LT[j]-Matrice_Distance[i][j] 
            j-=1
        i-=1        
    k-=1
print(LT)


##Critical Path
print("Started Node")
i=0
while(i<len(Matrice_Distance)):
    if(not LT[i]==ET[i]):
        print("Critical Node : ",str(i))
    i+=1
print("Ended Node")    

