import numpy as np
import sys

def Find_Negative_Number(Z):
    Minimum=Z[0]
    IndexOfMinimum=-1
    for index,element in enumerate(Z):
        if(element<0 and element<=Minimum):
            Minimum=element
            IndexOfMinimum=index
    return IndexOfMinimum==-1,IndexOfMinimum
                
def Find_Smallest_Number(Z,A):
    i=1
    Minimum=sys.float_info.max
    IndexOfMinimum=-1
    while i<len(A):
        try:
            if Z[i]==0:
                i+=1
                continue
            if A[i]/Z[i]<=Minimum and A[i]/Z[i]>0:
                Minimum=A[i]/Z[i]
                IndexOfMinimum=i
        except:
            pass
        i+=1
    return IndexOfMinimum==-1,IndexOfMinimum

def Basic_Simplex_Algorithm(TargetFunction,Condition):
    NumberOfVariable=int(len(TargetFunction))
    NumberOfCondition=int(len(Condition))
    BasicVariable=[i for i in range(NumberOfVariable,NumberOfCondition+NumberOfVariable)]
    Tableu=np.zeros((NumberOfCondition+1,NumberOfCondition+NumberOfVariable+1))
    Tableu[0][0:NumberOfVariable]=list(map(lambda x: -1*x,TargetFunction))
    i=1
    j=NumberOfVariable
    while i<NumberOfCondition+1:
        Tableu[i][0:NumberOfVariable]=Condition[i-1][0:NumberOfVariable]
        Tableu[i][j]=1
        Tableu[i][-1]=Condition[i-1][-1]
        j+=1
        i+=1 
    while True:
        IsOptimal,IndexOfMinimumv=Find_Negative_Number(Tableu[0])
        if IsOptimal:
            BasicVariable=sorted(map(lambda x: x+1,list(filter(lambda x: x<NumberOfVariable,BasicVariable))))
            print("X: ",BasicVariable)
            print(Tableu[BasicVariable,-1])
            print("Max {}".format(Tableu[0][-1]))
            break
        IsOptimal, IndexOfMinimumh=Find_Smallest_Number(Tableu[:,IndexOfMinimumv],Tableu[:,-1])
        
        if IsOptimal:
            print("Infinite")
            break
        
        BasicVariable[IndexOfMinimumh-1]=IndexOfMinimumv
        Tableu[IndexOfMinimumh]=Tableu[IndexOfMinimumh]/Tableu[IndexOfMinimumh][IndexOfMinimumv]
        i=0
        while i< NumberOfCondition+1:
            if i==IndexOfMinimumh:
                i+=1
                continue
            Tableu[i]=Tableu[i]+((-1*Tableu[i][IndexOfMinimumv])*Tableu[IndexOfMinimumh])
            i+=1

c = [3, 5]
A = [[1, 0,4], [0, 2,12], [3, 2,18]]
Basic_Simplex_Algorithm(c,A)
