# -*- coding: utf-8 -*-
"""
Created on Fri Dec 31 15:59:10 2021
Spyder (Python 3.8)
@author: suca
"""
#!pip install tk
# =============================================================================
# Import Libraries
# =============================================================================
import matplotlib.pyplot as plt #just visulation
import random
import tkinter #just form for basic dialog to ask value of k

class Kmeans:
    def __init__(self):
        self.k=None
        self.filename=None
        self.cluster=None
        self.data=[]
        self.normalizedData=[]
        self.isScaling=None
        self.WCS=[]
        self.BCS=0
        self.TSS=0
        self.dunnIndex=0
        self.group=[]
        self.mini=[]
        self.maxi=[]
        self.columns=[]
   
# =============================================================================
# Euclidian Distance Calculator        
# =============================================================================
    def euclidian_distance(self,x,y):
        i=0
        result=0
        while i<len(x):
            result+=(x[i]-y[i])*(x[i]-y[i])
            i+=1
        return result**0.5
    
# =============================================================================
# File Reader Function    
# =============================================================================
    def fileread(self):
            trainfile = open(self.filename, "r")
            train = trainfile.readlines()
            trainfile.close()
        
            for column in train[0].rstrip("\n").split(','):
                self.columns.append(column)
            
            i=1
            while i < len(train):
                self.data.append([float(j) for j in train[i].rstrip("\n").split(',')])
                i+=1
                
# =============================================================================
# Normalizing min-max scale and reverse                
# =============================================================================
    def scaling(self,mode=0):
        if mode==0:
            self.mini=[i for i in self.data[0]]
            self.maxi=[i for i in self.data[0]]
            #average=[0 for i in objection[0]]
            i=1
            while i<len(self.data):
                j=0
                while j<len(self.data[i]):
                    #average[j]+=objection[i][j]
                    if self.mini[j]>self.data[i][j]:
                        self.mini[j]=self.data[i][j]
                    if  self.maxi[j]<self.data[i][j]:
                        self.maxi[j]=self.data[i][j]
                    j+=1
                i+=1
            self.normalizedData=[[0 for i in range(len(self.data[0]))] for j in range(len(self.data))]   
            i=0
            while i<len(self.data):
                j=0
                while j<len(self.data[i]):
                    self.normalizedData[i][j]=(self.data[i][j]-self.mini[j])/(self.maxi[j]-self.mini[j])
                    j+=1
                i+=1  
            
        else:
            i=0
            clusters=[[0 for x in range(len(self.data[0]))] for y in range(self.k)]
            while i<self.k:
                j=0
                while j<len(self.cluster[0]):
                    clusters[i][j]=self.cluster[i][j]*(self.maxi[j]-self.mini[j])+self.mini[j]
                    j+=1
                i+=1
            self.cluster=clusters
            
# =============================================================================
# Component Function of KMeans to be Dynamic Code           
# =============================================================================
    def allDistance(self):
       for i in self.normalizedData:
            distances=[]
            for j in self.cluster:
                distances.append(self.euclidian_distance(i,j))
            self.group.append(distances.index(min(distances)))
            self.WCS[self.group[-1]]+=min(distances)*min(distances)
            
    def resetParameter(self):
        self.group=[]
        self.WCS=[0 for i in range(self.k)]
    
# =============================================================================
# Changing From Old Cluster Coordinate to New One    
# =============================================================================
    def newCluster(self):
        i=0
        Result=[[0 for j in range(len(self.cluster[0]))] for i in range(self.k)]
        count=[0 for i in range(len(self.group))]
        while i<len(self.group):
            j=0
            while j<len(Result[self.group[i]]):
                Result[self.group[i]][j]+=self.normalizedData[i][j]
                j+=1
            count[self.group[i]]+=1
            i+=1
            
        i=0
        while i<len(Result):
            if count[i]!=0:
                Result[i]=[Result[i][k]/count[i] for k in range(len(Result[i]))]
            i+=1
        return Result

# =============================================================================
# Computing Perfomance Of Cluster Algorithm for TSS           
# =============================================================================
    def calculateTSS(self):
        average=[0 for i in self.normalizedData[0]]
        i=0
        while i<len(self.normalizedData):
            j=0
            while j<len(self.normalizedData[i]):
                average[j]+=self.normalizedData[i][j]
                j+=1
            i+=1
            
        i=0
        while i<len(average):
            average[i]=average[i]/len(self.normalizedData)
            i+=1
            
        for i in self.normalizedData:
            self.TSS+=self.euclidian_distance(i,average)**2

# =============================================================================
# Computing Perfomance Of Cluster Algorithm for BCSS&dunnIndex           
# =============================================================================    
    def performance(self):
        self.calculateTSS()
        self.BCS=self.TSS-sum(self.WCS)
        
        distance=[]
        i=0
        while i<self.k:
            j=0
            while j<self.k:
                if i==j:
                    j+=1
                    continue
                distance.append(self.euclidian_distance(self.cluster[i],self.cluster[j]))
                        
                j+=1
            i+=1
        if len(distance)==0 or min(distance)==0:
            self.dunnIndex=0
        else:
            self.dunnIndex=max(self.WCS)/min(distance)

# =============================================================================
# Kmeans Algorithm Manager If want to change distance matrix, scaling , you can change code line inside this func.        
# =============================================================================
    def kmeansManager(self,k=3,filename="Final-data.txt",scale=True):
        if self.k is None or self.k==0:
            self.k=k
        self.filename=filename
        self.isScaling=scale
        self.fileread()
        self.scaling()
        if self.isScaling:
            self.cluster=[[random.random() for j in range(len(self.columns))] for i in range(self.k)]
        else:
            self.normalizedData=self.data.copy()
            self.cluster=[[random.uniform(self.mini[j],self.maxi[j]) for j in range(len(self.columns))] for i in range(self.k)]
            

        cluster_prev=[]
        self.resetParameter()
        while not cluster_prev==self.cluster:
            cluster_prev=self.cluster.copy()
            self.resetParameter()
            self.allDistance()
            self.cluster=self.newCluster()    
            
        self.performance()
        if self.isScaling:
            self.scaling(mode=1)
        self.result()
        
# =============================================================================
# Visulation for both of Scatter Matrices and Scatter plot        
# =============================================================================
    def scatter(self,d1,d2):
        if d1==-1 and d2==-1:
            fig = plt.figure()    
            fig, axes = plt.subplots(nrows=len(self.columns), ncols=len(self.columns),figsize=(len(self.columns)*5,len(self.columns)*5))
            i=0
            while i<len(self.columns):
                j=0
                axes[i][j].set_ylabel(self.columns[i])
                while j<len(self.columns):
                    axes[i][j].scatter([col[j] for col in self.data], [col[i] for col in self.data], c=[color/self.k for color in self.group],alpha=0.9)
                    axes[i][j].scatter([col[j] for col in self.cluster], [col[i] for col in self.cluster],marker="X",c="b")
                    
                    if i==len(self.columns)-1:
                        axes[i][j].set_xlabel(self.columns[j])

                    j+=1
                i+=1
            fig.savefig("Scatter-Matrices.pdf")  
            plt.show()
            
        else:
            plt.scatter([i[d1] for i in self.data], [i[d2] for i in self.data], c=[i/self.k for i in self.group],alpha=0.9)
            plt.scatter([i[d1] for i in self.cluster], [i[d2] for i in self.cluster],marker="X",c="b",alpha=0.9,s=[15 for i in range(self.k)])
            fname="{}-{}.pdf".format(self.columns[d1],self.columns[d2])
            plt.xlabel(self.columns[d1])
            plt.ylabel(self.columns[d2])
            plt.savefig(fname)
            plt.show()
            
# =============================================================================
# Printing Result Func            
# =============================================================================
    def result(self):
        
        f=open("sonuc.txt", "w")
        f.write("----------------------------------------\n")
        i=0
        while i<len(self.data):
            f.write("Observation {}:\t Cluster {}\n".format(i+1,self.group[i]))
            i+=1
        
        i=0
        while i<len(self.cluster):
            f.write("Cluster {}:\t Observation {}\n".format(i+1,self.group.count(i)))
            i+=1
        f.write("WCSS: {}\n".format(sum(self.WCS)))   
        f.write("BCSS: {}\n".format(self.BCS))  
        f.write("Dunn Index: {}\n".format(self.dunnIndex))  
        f.close()

        
# =============================================================================
# Creating Form and Main Lines
# =============================================================================
ROOT = tkinter.Tk()
ROOT.withdraw()

kmeans=Kmeans()
kmeans.k=abs(int(tkinter.simpledialog.askinteger(title="Number Of Cluster", prompt="Please enter k:")))

kmeans.kmeansManager()

col=[]
ans=tkinter.messagebox.askyesno("Question","Result file have just been written, Do you want to see Visulation?")
if ans:
    columns=""
    for index,i in enumerate(kmeans.columns):
        columns+="{}->{}\n".format(index,i)
    columns+="For All -1,-1 as a Scatter Matrices\n"
    columns+="Example: 0,3"
    col=[int(j) for j in tkinter.simpledialog.askstring(title="Numbers Of columns", prompt=columns).split(',')]
    kmeans.scatter(col[0],col[1])
