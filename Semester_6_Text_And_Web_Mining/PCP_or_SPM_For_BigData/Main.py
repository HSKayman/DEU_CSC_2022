# =============================================================================
# import relevant libraries
# =============================================================================

from operator import itemgetter
import os
# Read the data
DATA="Electronic"

f= open("DataSets_Name.txt","w")
f.write("{}".format(DATA))
f.close()
os.system('mkdir {}'.format(DATA))
# =============================================================================
# Preprocessing the data
# =============================================================================

os.system('python Preprocessor.py')

#running the Metric codes
for i in [1,2,3]:
    os.system('python Metric_{}.py'.format(i))
print("\n\n\nMetric_1: KNN \nMetric_2: Pearson Correlation\nMetric_3: Euclidean Distance\n")
#run to final analysis code
with open('Result.txt','r') as f:
    Lines=f.readlines()
f.close()
os.system('del Result.txt')
Result=[]
for x in Lines:
    Result.append(list(map(float, x.split())))
f.close()
i=0
Result_2=[]
while i<len(Result):
    Result_2.append([Result[i][0],Result[i][2],1])
    Result_2.append([Result[i][1],Result[i][2],2])
    i+=1
Result_2=sorted(Result_2,key=itemgetter(0))

#PCP SP Method
# 0  1    2
for j, k,l in Result_2:
    if l==1:
        S="PCP"
    else:
        S="SP"
    print("Metric_{}-->Outlier%{} For {}".format(k,j*100,S))
j=0
if len(Result_2)==0:
    pass
else:    
    i=Result_2[0][0]
    if Result_2[j][2]==1:
        S="PCP"
    else:
        S="SP"
    print("Best figure for {} is {} with Metric_{}. Percentage of outliers is %{}".format(DATA,S,int(Result_2[j][1]),100*Result_2[j][0]))
        
os.system('del DataSets_Name.txt')
