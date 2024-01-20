# -*- coding: utf-8 -*-
"""
Created on Tue Nov  9 17:21:58 2021

@author: suca
"""
import numpy as np

def loss(Gens,Target):
    point=np.zeros(len(Gens))
    i=0
    maxi=0
    while i< len(Gens):
        
        j=0
        
        while j<len(Gens[i]):
            
            if Gens[i][j]==ord(Target[j]):
                point[i]+=1
            
            j+=1
            
        if point[maxi]<point[i]:
            maxi=i
            
        i+=1
    
    
    return point,maxi 
    
def compute_prob(point):
    sumi=sum(point)
    
    point/=sumi
    
    i=1
    
    while i<len(point):
        
        point[i]=point[i]+point[i-1]
        i+=1
        
    return point
    
def Rice(point,rice):
    i=0
    while i <len(point):
        if rice<point[i]:
            return i
        i+=1
    
    return 0

def crossover(A,B,Mutation):
    Line=np.random.randint(len(A))
    X=A[Line:].copy()
    A[Line:]=B[Line:]
    B[Line:]=X
    
    if np.random.random()<=Mutation:
        x=np.random.randint(len(A))
        y=np.random.randint(len(A))
        
        a1=np.random.randint(low=97,high=125)
        a2=np.random.randint(low=97,high=125)
        if a1==124:
            a1=32
        if a2==124:
            a2=32
        
        A[x],B[y]=a1,a2
    
    
    return A,B

def model(Target,Khoromoselenght=100,Mutation=0.4,generation=10000):
    lenght=len(Target)
    
    Gens=np.random.randint(28,size=(Khoromoselenght,lenght))
    i=0
    while i< len(Gens):
        Gens[i][Gens[i]==26]=-65
        i+=1
    Gens+=97
    for i in range(generation):
        
        
        loss_i,maxi=loss(Gens,Target)
        point=compute_prob(loss_i.copy())
        
        if loss_i[maxi]>=lenght//2:
            print("{}. Generation".format(i))
            print(''.join( x for x in list(map(lambda x: chr(x),Gens[maxi]))),loss_i[maxi])
            if loss_i[maxi]>=lenght:
                break
        New_Gens=[]
        #random_k=np.random.randint(50)
        for k in range(50):
            Parents=[]
            for j in range(2):
                rice=np.random.random()
                Parents.append(Rice(point,rice))
        
            A_i,B_i=crossover(Gens[Parents[0]],Gens[Parents[1]],Mutation)
            
            New_Gens.append(A_i)
            New_Gens.append(B_i)
        Gens=np.array(New_Gens)
        #if not random_k==0: 
        #    Gens[:random_k*2]=np.array(New_Gens)
    return Gens

    
Target = "berk tolay".lower()
Gens=model(Target=Target)












