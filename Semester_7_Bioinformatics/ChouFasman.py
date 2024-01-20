# -*- coding: utf-8 -*-
"""
Created on Sun Jan 23 23:09:09 2022

@author: suca
"""



def Find(letter):
    a=[
    ['A', 142,   83,   66,   0.06,   0.076,  0.035,  0.058],
    ['R',  98,   93,   95,   0.070,  0.106,  0.099,  0.085],
    ['N', 101,   54,  146,   0.147,  0.110,  0.179,  0.081],
    ['D',  67,   89,  156,   0.161,  0.083,  0.191,  0.091],
    ['C',  70,  119,  119,   0.149,  0.050,  0.117,  0.128],
    ['E', 151,   37,   74,   0.056,  0.060,  0.077,  0.064],
    ['Q', 111,  110,   98,   0.074,  0.098,  0.037,  0.098],
    ['G',  57,   75,  156,   0.102,  0.085,  0.190,  0.152],
    ['H', 100,   87,   95,   0.140,  0.047,  0.093,  0.054],
    ['I', 108,  160,   47,   0.043,  0.034,  0.013,  0.056],
    ['L', 121,  130,   59,   0.061,  0.025,  0.036,  0.070],
    ['K', 114,   74,  101,   0.055,  0.115,  0.072,  0.095],
    ['M', 145,  105,   60,   0.068,  0.082,  0.014,  0.055],
    ['F', 113,  138,   60,   0.059,  0.041,  0.065,  0.065],
    ['P',  57,   55,  152,   0.102,  0.301,  0.034,  0.068],
    ['S',  77,   75,  143,   0.120,  0.139,  0.125,  0.106],
    ['T',  83,  119,   96,   0.086,  0.108,  0.065,  0.079],
    ['W', 108,  137,   96,   0.077,  0.013,  0.064,  0.167],
    ['Y',  69,  147,  114,   0.082,  0.065,  0.114,  0.125],
    ['V', 106,  170,   50,   0.062,  0.048,  0.028,  0.053]]
    
    for i in a:
        if i[0]==letter:
            return i
    return None

def alpha(letters):
    def find_alpha():
        nonlocal letters
        j=0
        while j<len(letters)-6:
            count=4
            for i in letters[j:j+6]:
                if Find(i)[1]>=100:
                    count-=1
            if count<1:
                return [j,j+6] 
            j+=1
        return [-1,-1]
    def find_right(end):
        nonlocal letters
        j=end-3    
        while j<len(letters)-3:
            sumi=0
            for i in letters[j:j+4]:
                sumi+=Find(i)[1]
            if sumi/4<100:
                return j+4-1
            j+=1
        return len(letters)
    
    def find_left(start):
        nonlocal letters
        j=start+3    
        while j>3:
            sumi=0
            for i in letters[j-4:j]:
                sumi+=Find(i)[1]
            if sumi/4<100:
                return j-4+1
            j-=1
        return 0
        
    
    index=find_alpha()
    index[1]=find_right(index[1])
    index[0]=find_left(index[0])
    i=0
    alpha=[0 for i in range(len(letters))]
    sumi=0
    sumi_b=0
    while i<len(alpha):
        if i>index[0]-1 and i<index[1]:
            alpha[i]=1
            sumi+=Find(letters[i])[1]
            sumi_b+=Find(letters[i])[2]
        else:
            alpha[i]=0
        i+=1
    return [alpha,sumi>sumi_b,sumi/sum(alpha)]


def beta(letters):
    def find_beta():
        nonlocal letters
        j=0
        while j<len(letters)-4:
            count=3
            for i in letters[j:j+5]:
                if Find(i)[2]>=100:
                    count-=1
            if count<1:
                return [j,j+5]
            j+=1
        return [-1,-1]
    
    def find_right(end):
        nonlocal letters
        j=end-3    
        while j<len(letters)-3:
            sumi=0
            for i in letters[j:j+4]:
                sumi+=Find(i)[2]
            if sumi/4<100:
                return j+4-1
            j+=1
        return len(letters)
    def find_left(start):
        nonlocal letters
        j=start+3    
        while j>3:
            sumi=0
            for i in letters[j-4:j]:
                sumi+=Find(i)[2]
            if sumi/4<100:
                return j-4+1
            j+=1
        return 0
        
    
    index=find_beta()
    index[1]=find_right(index[1])
    index[0]=find_left(index[0])
    i=0
    beta=[0 for i in range(len(letters))]
    sumi=0
    sumi_a=0
    while i<len(beta):
        if i>index[0]-1 and i<index[1]:
            beta[i]=1
            sumi+=Find(letters[i])[2]
            sumi_a+=Find(letters[i])[1]
        else:
            beta[i]=0
        i+=1    
    return [beta,sumi>sumi_a,sumi/sum(beta)]

def turn(letters,alpha_v,beta_v):  
    j=0
    while j<len(letters)-4:
        product=1
        count=4;
        sumi=0
        for i in letters[j:j+4]:
            product*=Find(i)[count]
            sumi+=Find(i)[3]
            count+=1
        if product>0.000075 and sumi/4>100 and sumi>alpha_v and sumi>beta_v:
            return j,j+4
        j+=1
    return -1,-1
            
def ChauFasman(letters):
    a_alpha=alpha(letters)
    a_beta=beta(letters)
    a_turn=turn(letters,a_alpha[2],a_beta[2])
    
    i=0
    sumi_a=0
    sumi_b=0
    while i<len(letters):
        if a_alpha[0][i]==1 and a_beta[0][i]==1:
            sumi_a+=Find(letters[i])[1]
            sumi_b+=Find(letters[i])[2]
        i+=1
    back=a_alpha.copy()    
    if sumi_b>sumi_a:
        i=0
        while i<len(letters):
            if a_alpha[0][i]==1 and a_beta[0][i]==1:
                a_alpha[0][i]=0
            i+=1
        
    i=0
    snc=[0 for i in range(len(letters))]
    while i<len(letters):
        if a_turn[0]-1<i and a_turn[1]>i:
            snc[i]="d"
        elif a_alpha[0][i]==1:
            snc[i]="a"
            if a_alpha[1]:
                snc[i]+="_s"
            else:
                snc[i]+="_y"
        elif a_beta[0][i]==1:
            snc[i]="b"
            if a_beta[1]:
                snc[i]+="_y"
            else:
                snc[i]+="_s"
        i+=1
        
    return snc,back[0],a_beta[0]


print(ChauFasman("TSPTTWVYAELMRSTG"))

    