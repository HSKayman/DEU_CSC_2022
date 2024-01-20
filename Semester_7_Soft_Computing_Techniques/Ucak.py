# -*- coding: utf-8 -*-
"""
Created on Sun Nov 21 17:04:31 2021

@author: suca
"""
import itertools
 
from pprint import pprint as pp

import numpy as np


def init():
    a=set()
    for i in itertools.permutations('11100',5):
        a.add(i)
    
    prob=[]
    for i in a:
       prob.append([int(j) for j in i])
    
    return prob

def fitness_func(x):
    return 15-x

def fitness(population,maxigun,mode="normal"):
    if mode=="normal":
        fit=[]
        for i in population:
            j=0
            count=0
            while j < int(len(i))-maxigun+1:
                for k in np.sum(i[j:j+maxigun],axis=0):
                    if k==3:
                        count+=1
                j+=1
            fit.append(fitness_func(count)) #################
        
        
        fit=np.array(fit)
        fit=fit/np.sum(fit)
        
        j=1
        while j<len(fit):
            fit[j]=fit[j]+fit[j-1]
            j+=1
        return fit 
    
    else:
        fit=[]
        for i in population:
            j=0
            count=0
            while j < int(len(i))-maxigun+1:
                for k in np.sum(i[j:j+maxigun],axis=0):
                    if k==3:
                        count+=1
                j+=1
            fit.append(fitness_func(count)) #################
        
        fitx=np.array(fit)
        return (population[np.where(fitx==max(fit))][0],max(fit))
        

def crossover(A,B,Mutation):
    
    randomi=np.random.randint(len(A))
    
    B[:randomi],A[:randomi] = A[:randomi],B[:randomi] 
    
    if(np.random.random()<Mutation):
        randomi=np.random.randint(len(A))
        B[randomi],A[randomi] = A[randomi],B[randomi]
    
    return A,B
    
    

def model(prob,day=7,population=1000,Mutation=0.5,generation=10,maxigun=3):#pop%2=0
    
    populations=[]
    
    for  i in range(population):
       chrom=[]
       for j in range(day):
           chrom.append(prob[np.random.randint(len(prob))])
       populations.append(chrom)   
    
    populations=np.array(populations)
    Best=[]
    for m in range(generation):
        
        New_Gens=[]
        
        fit=fitness(populations,maxigun)
        Result=fitness(populations,maxigun,"best")
        
        print('{}. Generation Best Planning Score -> {}'.format(m,Result[1]), end="\n",)
        pp(Result[0])
        
       # if Result[1] >= 14:#
       #     return Result
        for k in range(population//2):
                
            Parents=[]
            
            for j in range(2):
                rice=np.random.random()
                index=0
                
                while index<len(fit):
                    if fit[index]>=rice:
                        break
                    index+=1
                
                if index==len(fit):
                    index-=1
                
                Parents.append(populations[index])
               
            A_i,B_i=crossover(Parents[0],Parents[1],Mutation)
            
            New_Gens.append(A_i)
            New_Gens.append(B_i)
              
        populations=np.array(New_Gens)
                      
    return Result                       
    
model(init())
    



