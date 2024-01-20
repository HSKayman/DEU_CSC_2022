# -*- coding: utf-8 -*-
"""
Created on Sat Jan 15 20:21:11 2022

@author: suca
"""
import random
from pprint import pprint as p

def ACO(population,dist,alpha,beta,ro,iteration):
    def initializer(n,cities):
        ant=[]
        for i in range(n):
            random.shuffle(cities)
            ant.append(cities.copy())
        return ant
    
    def Lk(ant,dist):
        result=[0 for i in ant]
        i=0
        while i<len(ant):
            j=1
            while j<len(ant[i]):
                result[i]+=dist[ant[i][j-1]][ant[i][j]]
                j+=1
            result[i]+=dist[ant[i][-1]][ant[i][0]]
            i+=1
        return result
    
    def tau(ant,fitnees,number_city):
        delta_tau=[[0 for i in range(number_city)] for j in range(number_city)]
        i=0
        while i <len(ant):
            j=1
            while j<number_city:
                delta_tau[ant[i][j-1]][ant[i][j]]=1/fitness[i]
                j+=1
            delta_tau[ant[i][-1]][ant[i][0]]=1/fitness[i]
            i+=1
        return delta_tau
    
    def new_pher(pher,delta_tau,ro):
        i=0
        while i<len(pher):
            j=0
            while j<len(pher[i]):
                pher[i][j]+=(1-ro)*pher[i][j]+delta_tau[i][j]
                j+=1
            i+=1
        return pher
    
    def cal_pij(alpha,beta,pher,n):
        pij=n.copy()
        i=0
   
        while i<len(n):
            j=0
            while j<len(n[i]):
                pij[i][j]=(n[i][j]**alpha)*(pher[i][j]**beta)
                j+=1
            j=0
            sumi=sum(pij[i])
            while j<len(n[i]):
                pij[i][j]=pij[i][j]/sumi
                j+=1
            j=1
            while j<len(n[i]):
                pij[i][j]=pij[i][j-1]+pij[i][j]
                j+=1
            i+=1
        return pij
    
    def new_ant(ant,n):
        
        def is_There(i,j,k):
            l=0
            while l<j:
                if ant[i][l]==k:
                    return True
                l+=1
            return False
        
        i=0
        while i<len(ant):
            r=random.random()
            j=0
            while r>n[0][j]:
                j+=1
            ant[i][0]=j
            i+=1
        
        i=0
        while i<len(ant):
            j=1
            while j<len(ant[i]):
                r=random.random()
                k=0
                while r>n[ant[i][j-1]][k]:
                    k+=1
                
                if is_There(i,j,k):
                    continue
                    
                ant[i][j]=k
                j+=1 
            i+=1
        return ant
                   
    number_city=len(dist[0])
    pher=[[1 for i in range(number_city)] for j in range(number_city)]
    n=[[1/i for i in j] for j in dist]
    
    ant=initializer(population, [i for i in range(number_city)])
    fitness=Lk(ant,dist)
    i=0
    while i<iteration:
        delta_tau=tau(ant,fitness,number_city)
        pher=new_pher(pher,delta_tau,ro)
        pij=cal_pij(alpha,beta,pher,n)
        ant=new_ant(ant,pij)
        fitness=Lk(ant,dist)
        print(fitness.index(min(fitness)),".Ant ","\nFitness: ",min(fitness),"\n",ant[fitness.index(min(fitness))])
        i+=1
        
        
    
                
#       0   1  2  3  4  5
dist=[[9999,32,41,27,13],#0
      [30,9999,34,39,58],#1
      [32,59,9999,14,24],#2
      [12,15,26,9999,24],#3
      [46,29,22,35,9999]]#5


#0-4-2-3-1-5
#22+14+32+13+33
alpha=1
beta=1
ro=0.05
ACO(99,dist,alpha,beta,ro,100)
