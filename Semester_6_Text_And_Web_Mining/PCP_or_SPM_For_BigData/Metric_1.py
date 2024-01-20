# =============================================================================
# importing relevant libraries
# =============================================================================
from pyod.models.knn import KNN
import pandas as pd
import numpy as np
import itertools
import os

#called Metric_1 function KNN
def Metric_1(Constant_Data_Frame,Xindex):
    
    # =============================================================================
    # Marking outliers PCP
    # =============================================================================
    def Def_Outliers(index):
        i=0
        result=[]
        while i<int(len(index))-1:
            Tenative_Data_Frame=Constant_Data_Frame.iloc[:,[index[i],index[i+1]]].values
            clf = KNN()
            clf.fit(Tenative_Data_Frame)
            result.append(clf.labels_)
            i+=1
        sumi=0
        for i in result:
            for j in i:
                sumi+=j               
        return [index,result,sumi/(int(len(Constant_Data_Frame))*int(len(index)))]
    # =============================================================================
    # Marking outliers SP
    # =============================================================================
    def Def_Outliers_2(index):
        i=0
        result=[]
        while i<int(len(index))-1:
            Tenative_Data_Frame=Constant_Data_Frame.iloc[:,[index[i],index[i+1]]].values
            clf = KNN()
            clf.fit(Tenative_Data_Frame)
            result.append(clf.labels_)
            i+=1
        sumi=0
        for i in result:
            for j in i:
                sumi+=j  
        return [index,sumi/(int(len(Constant_Data_Frame))*int(len(index)))]
    
    # =============================================================================
    # Ordering Axes PCP
    # =============================================================================
    def Like_Kurtosis(Sorted_Cor,Colums_Len):
        List=Sorted_Cor[0][:2]
        i=1
        while Colums_Len>int(len(List)):
            if Sorted_Cor[i][0]==List[0]:
                if not Sorted_Cor[i][1] in List:
                    List.insert(0,Sorted_Cor[i][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][1]==List[0]:
                if not Sorted_Cor[i][0] in List:   
                    List.insert(0,Sorted_Cor[i][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][0]==List[-1]:
                if not Sorted_Cor[i][1] in List:
                    List.append(Sorted_Cor[i][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            elif Sorted_Cor[i][1]==List[-1]:
                if not Sorted_Cor[i][0] in List:  
                    List.append(Sorted_Cor[i][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            i+=1
        return List
    
    # =============================================================================
    # Ordering Axes SP
    # =============================================================================
    def Like_Kurtosis_2(Sorted_Cor,Colums_Len):
        if len(Sorted_Cor)==0:
            return []
        List=list(Sorted_Cor[0][1])
        i=1
        while Colums_Len>int(len(List)):
            if Sorted_Cor[i][1][0]==List[0]:
                if not Sorted_Cor[i][1][1] in List:
                    List.insert(0,Sorted_Cor[i][1][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][1][1]==List[0]:
                if not Sorted_Cor[i][1][0] in List:   
                    List.insert(0,Sorted_Cor[i][1][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            if Sorted_Cor[i][1][0]==List[-1]:
                if not Sorted_Cor[i][1][1] in List:
                    List.append(Sorted_Cor[i][1][1])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            elif Sorted_Cor[i][1][1]==List[-1]:
                if not Sorted_Cor[i][1][0] in List:  
                    List.append(Sorted_Cor[i][1][0])
                    Sorted_Cor.pop(i)
                    i=0
                    continue
            i+=1
        return List
    
    # =============================================================================
    # Ordering data according to Compute_All_Outlier_PCP
    # =============================================================================
    def Compute_All_Outlier():
        subset = list(itertools.combinations([i for i in range(len(Constant_Data_Frame.columns.values))], 2))
        i=0
        Num=[]
        while(i<len(subset)):
            Tenative_Data_Frame=Constant_Data_Frame.iloc[:,[subset[i][0],subset[i][1]]].values
            clf = KNN()
            clf.fit(Tenative_Data_Frame)
            Num.append([subset[i][0],subset[i][1],sum(clf.labels_)])
            i+=1
        
        #Sorting
        return Def_Outliers(Like_Kurtosis(sorted(Num, key=lambda x: abs(x[2]),reverse=False),int(len(Constant_Data_Frame.columns)))) 
    
    # =============================================================================
    # Ordering data according to Compute_All_Outlier_SP
    # =============================================================================
    def Compute_All_Outlier_2(Tenative_Data_Frame,Index_List):
        subset = list(itertools.combinations(Index_List, 2))
        i=0
        cor=[]
        while(i<len(subset)):
            Tenative_Data_Frame_II=np.transpose(Tenative_Data_Frame[[subset[i][0],subset[i][1]]])
            clf = KNN()
            clf.fit(Tenative_Data_Frame_II)
            cor.append([sum(clf.labels_),subset[i]])
            i+=1
        
        #Sorting
        return Like_Kurtosis_2(sorted(cor, key=lambda x: abs(x[0]),reverse=False),int(len(Index_List)))
 
    # =============================================================================
    # Ordering whole data      
    # =============================================================================
    def sort(Result,Data_Frame):
        Result_Second=list(np.transpose(list(np.transpose(list(itertools.filterfalse(lambda x: not x[0],Result))))[1:]))
        Result_Second=list([i for i,j in sorted(Result_Second, key=lambda x: x[1],reverse=True)])
        Result_First=list(Compute_All_Outlier_2(Data_Frame,list(np.transpose(np.transpose(list(itertools.filterfalse(lambda x: x[0],Result)))[1]))))
        return Def_Outliers_2(Result_First+Result_Second)
    
    # =============================================================================
    # Defining whether the series is high or low cardinal
    # =============================================================================
    def High_Or_Low():
        Tenative_Data_Frame= np.transpose(Constant_Data_Frame.values)
        i=0
        result=[]
        while i<len(Tenative_Data_Frame):
            j=0
            count=[]
            while j<len(Tenative_Data_Frame[0]):
                if not Tenative_Data_Frame[i][j] in count:
                    count.append(Tenative_Data_Frame[i][j])
                j+=1
            result.append([len(count)<(len(Tenative_Data_Frame[i]))**0.5,i,len(count)])
            i+=1
        return sort(result,Tenative_Data_Frame)

    Result_SP=High_Or_Low()
    Result_PCP=Compute_All_Outlier()
    print("Ordering with Metric_1 is completed")  
    #run to drawer
    f= open("Data.txt","w+")
    f.write("{}\n".format(Xindex))
    for i in Result_PCP[0]:
        f.write("{} ".format(i))
    f.write("\n")
    for i in Result_SP[0]:
        f.write("{} ".format(i))
    f.write("\n1 ")
    f.close()
    df =pd.DataFrame(Result_PCP[1])
    df.to_csv('Color_Map.csv', index=False)
    os.system('python Figure_Plotter.py')
    os.system('del Data.txt')
    os.system('del Color_Map.csv')
    return [Result_PCP[2],Result_SP[1]]

#Read to index of Datasets 
with open('DataSets_Name.txt') as f:
    #only first line
    x =str(f.readlines()[0])
Constant_Data_Frame=pd.read_csv('{}/{}_pp_norm.csv'.format(x,x))  
Result=Metric_1(Constant_Data_Frame,x)

#for analysis write to in file
f=open("Result.txt","a")
f.write("{} {} {}\n".format(Result[0],Result[1],1))
f.close()
    
    
