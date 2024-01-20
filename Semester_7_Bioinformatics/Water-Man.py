import numpy as np
from termcolor import colored


def WM(string1,string2,payoff):
    # payoff[0] -> match
    # payoff[1] -> mismatch
    # payoff[2] -> gap_open
    # payoff[3] -> gap_extend ?
    
    m=int(len(string1))+1
    n=int(len(string2))+1
    if m>n:
        string1,string2,m,n=string2,string1,n,m
    
    matrices=np.zeros((m,n))
    mask=[[[0,0] for i in range(n)] for j in range(m)]
    i=1
    while i<m:
        matrices[i][0]=0
        mask[i][0]=[i-1,0]
        i+=1
        
    i=1
    while i<n:
        matrices[0][i]=0
        mask[0][i]=[0,i-1]
        i+=1
        
    i=1
    maximum=[0,0]    
    while i<m:
        j=1
        while j<n:
            
            if string1[i-1]==string2[j-1]:
                c=max(matrices[i-1][j-1]+payoff[0],0)
            else:
                c=max(matrices[i-1][j-1]+payoff[1],0)
                    
            h=max(matrices[i][j-1]+payoff[2],0)    
            l=max(matrices[i-1][j]+payoff[2],0)    
            
            if c>=h and c>=l:
               matrices[i][j]=c
               mask[i][j]=[i-1,j-1]
            elif h>=c and h>=l:
                matrices[i][j]=h
                mask[i][j]=[i,j-1]
            else:
                matrices[i][j]=l
                mask[i][j]=[i-1,j]
            
            if matrices[maximum[0]][maximum[1]]<=matrices[i][j]:
                maximum=[i,j]
            j+=1
        i+=1
        
    i,j=maximum
    step=[]
    result=[]
    while matrices[i][j]!=0:
        
        if mask[i][j][0]==i-1 and mask[i][j][1]==j-1:
            result.insert(0, [string1[i-1],string2[j-1]])
        elif mask[i][j][0]==i and j!=0:
            result.insert(0, [string1[i-1],'-'])
        elif mask[i][j][1]==j and i!=0:
            result.insert(0, ['-',string2[j-1]])
            
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


WM("acgttagggga","aaatagcata",[1,-1,-1])
    