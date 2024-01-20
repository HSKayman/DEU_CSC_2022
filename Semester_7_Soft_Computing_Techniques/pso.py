# -*- coding: utf-8 -*-
"""
Created on Sun Jan 16 19:47:57 2022

@author: suca
"""

import numpy as np

def fitness(x,y):
    #return x*x+y*y
    return (x-3.14)**2 + (y-2.72)**2 + np.sin(3*x+1.41) + np.sin(4*y-1.73)

    
lr2=lr1=0.1
w=0.8
n_particles=20
iteration=50
#pso(c1,c2,w,20,50)
    
#def pso(lr1,lr2,w,n_particles,iteration):
X=np.random.rand(2,n_particles)*10-5
V=np.random.randn(2,n_particles)*0.1

prev_X=X
all_fitness=fitness(X[0], X[1])
best=prev_X[:, all_fitness.argmin()]
best_f = all_fitness.min()
i=0
while i<iteration:
    
    r1,r2=np.random.rand(2)
    V=w*V+lr1*r1*(prev_X-X)+lr2*r2*(best.reshape(-1,1)-X)
    X=X+V
    new_fitness=fitness(X[0], X[1])
    prev_X[:,(all_fitness >= new_fitness)]=X[:, (all_fitness>= new_fitness)]
    all_fitness=np.array([all_fitness,new_fitness]).min(axis=0)
    best=prev_X[:,all_fitness.argmin()]
    best_f=all_fitness.min()
    print(all_fitness.argmin(),". Kus :",best,best_f)
    i+=1





