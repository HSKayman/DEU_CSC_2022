# Complement Graph practice program.
# Graph theory exercise.
"""
Created on Mon Jan  6 19:37:15 2020

@author: suca
"""
def ComplementGraph(array):
    i=0;
    while i<len(array):
        j=0
        while j<len(array[0]):
            if i is not j:
                array[i][j]=1-array[i][j]
            j+=1
        i+=1
    return array
array = [[0, 1, 1, 1, 0],  
         [1, 0, 1, 0, 0],  
         [1, 1, 0, 0, 0],  
         [0, 1, 0, 0, 1], 
         [0, 0, 0, 1, 0]]
print(ComplementGraph(array)) 