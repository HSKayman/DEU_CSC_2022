# -*- coding: utf-8 -*-
"""
Created on Sun Jan 16 18:47:30 2022

@author: suca
"""

import numpy as np

def func(x,y):
    return x*x+y*y

def fitness(x,y):
    return 1/(1+func(x,y))

def ABC(colonySize,Dimension,bounds,iteration):
        limit=(colonySize*Dimension)//2
        sourceSize=colonySize//2
        
        source=np.random.uniform(bounds[0],bounds[1],size=(sourceSize,Dimension))
        
        
        sourceFitness=fitness(source[:,0], source[:,1])
        trialCounter=np.zeros(sourceSize)
        bestFitness=sourceFitness.max()
        bestBee=source[sourceFitness.argmax()]
        i=0
        while i<iteration:
           
            #first phase
            j=0
            while j<sourceSize:
                r=np.random.uniform(-1,1)
                k=np.random.randint(0,sourceSize)
                l=np.random.randint(0,Dimension)
                
                new=source[j]+r*(source[j][l]-source[k][l])
                
                if sourceFitness[j]<fitness(new[0],new[1]):
                    source[j]=new.copy()
                    sourceFitness[j]=fitness(new[0],new[1])
                    trialCounter[j]=0
                else:
                    trialCounter[j]+=1
                j+=1
            
            #pi    
            pi=sourceFitness.copy()
            pi=pi/np.sum(pi)
            j=1
            while j<sourceSize:
                pi[j]=pi[j]+pi[j-1]
                j+=1   
            #second phase
            j=0    
            while j<sourceSize:    
                l=0
                r=np.random.random()
                while r>=pi[l]:
                    l+=1
                    
                r=np.random.uniform(-1,1)
                k=np.random.randint(0,sourceSize)
                m=np.random.randint(0,Dimension)
                
                new=source[l]+r*(source[l][m]-source[k][m])
                
                if sourceFitness[l]<fitness(new[0],new[1]):
                    source[l]=new.copy()
                    sourceFitness[l]=fitness(new[0],new[1])
                    trialCounter[l]=0
                else:
                    trialCounter[l]+=1
                j+=1
            #third phase
            if bestFitness<sourceFitness.max():
                bestFitness=sourceFitness.max()
                bestBee=source[sourceFitness.argmax()]
            print("Best",bestBee," Fitness:",bestFitness)
            j=0
            while j<len(trialCounter):
               if trialCounter[j]>limit:
                   source[j]=np.random.uniform(bounds[0],bounds[1],(1,2))
                   sourceFitness[j]=fitness(source[j][0],source[j][1])
                   trialCounter[j]=0
               j+=1
               
            print(i,". Iteration",source[sourceFitness.argmax()],"Fitness:",sourceFitness.max(),"\n")
            i+=1
ABC(10,2,[-5,5],30)            
        













        
#ABC(6,2,[-5,5],100)        
        