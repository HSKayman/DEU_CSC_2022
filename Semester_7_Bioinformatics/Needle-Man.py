import numpy as np
from termcolor import colored


def NW(string1,string2,payoff):
    # payoff[0] -> match
    # payoff[1] -> mismatch
    # payoff[2] -> gap_open
    # payoff[3] -> gap_extend ?
    
    m=int(len(string1))+1
    n=int(len(string2))+1
    #if m>n:
    #    string1,string2,m,n=string2,string1,n,m
    
    matrices=np.zeros((m,n))
    mask=[[[0,0] for i in range(n)] for j in range(m)]
    i=1
    while i<m:
        matrices[i][0]=payoff[2]+matrices[i-1][0]
        mask[i][0]=[i-1,0]
        i+=1
        
    i=1
    while i<n:
        matrices[0][i]=payoff[2]+matrices[0][i-1]
        mask[0][i]=[0,i-1]
        i+=1
        
    i=1    
    while i<m:
        j=1
        while j<n:
            
            if string1[i-1]==string2[j-1]:
                c=matrices[i-1][j-1]+payoff[0]
            else:
                c=matrices[i-1][j-1]+payoff[1]
                    
            h=matrices[i][j-1]+payoff[2]    
            l=matrices[i-1][j]+payoff[2]    
            
            if c>=h and c>=l:
               matrices[i][j]=c
               mask[i][j]=[i-1,j-1]
            elif h>=c and h>=l:
                matrices[i][j]=h
                mask[i][j]=[i,j-1]
            else:
                matrices[i][j]=l
                mask[i][j]=[i-1,j]

            j+=1
        i+=1
        
    i=m-1
    j=n-1
    step=[]
    result=[]
    while True:
        
        if mask[i][j][0]==i-1 and mask[i][j][1]==j-1:
            result.insert(0, [string1[i-1],string2[j-1]])
        elif mask[i][j][0]==i and j!=0:
            result.insert(0, ['-',string2[j-1]])
        elif mask[i][j][1]==j and i!=0:
            result.insert(0, [string1[i-1],'-'])
        
            
        if (i==0 and j==0):
            step.append([0,0])
            break
            
        step.append([i,j])
        ix=mask[i][j][0]
        j=mask[i][j][1]
        i=ix
         
    i=0
    while i<m:
        j=0
        while j<n:
            if [i,j] in step:
                print(colored(matrices[i][j],'red'),end=' ')
            else: 
                print("{}".format(matrices[i][j]),end=' ')
            j+=1
        print()
        i+=1
    
    for i,j in result:
        print(i,end=' ')
    print()
    for i,j in result:
        print(j,end=' ')
    print() 
    return (matrices,step)


NW("aactatactatagct","tatagsstata",[1,0,-1])
    