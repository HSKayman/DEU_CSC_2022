# -*- coding: utf-8 -*-
"""
Created on Thu Nov 21 21:37:31 2021

@author: suca
"""

# =============================================================================
# Requierment Library
# =============================================================================
import graphviz #only visulation , https://graphviz.org/download/  , https://pypi.org/project/graphviz/
import math #only log for parameter

# =============================================================================
# Tree
# =============================================================================
class Node:
    def __init__(self):
        self.rule = None
        self.column = None
        self.right = None
        self.left = None
        
    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.column,self.rule)
        if self.right:
            self.right.PrintTree()

# =============================================================================
# Cart
# =============================================================================
class CART:
    def __init__(self,filename,target,limitofmeasure=10,maxdepth=0):
        self.candidate_rules=None
        self.postrules=None
        self.target=target
        self.depth=maxdepth
        self.maxdepth=maxdepth
        self.filename=filename
        self.tree=Node()
        self.drawer=graphviz.Graph(format='png')
        self.limitofmeasure=limitofmeasure
        self.classi=None

# =============================================================================
# Read any file to dictionary with splitting ',' and deleting '\n' and if row is int, it'll change data type to float
# =============================================================================
    def fileread(self,filename):
        trainfile = open(filename, "r")
        train = trainfile.readlines()
        trainfile.close()

        dataFrame={}
        columns=[]

        for column in train[0].rstrip("\n").split(','):
            dataFrame[column]=[]
            columns.append(column)

        i=1
        while i < len(train):
            variables=train[i].rstrip("\n").split(',')
            j=0
            while j < len(variables):
                try:
                    dataFrame[columns[j]].append(float(variables[j]))
                except:
                    dataFrame[columns[j]].append(variables[j])
                j+=1
            i+=1

        return dataFrame

# =============================================================================
# if type of this column is countinues type, it'll change to classification type using gini
# =============================================================================
    def float2class(self,dataFrame):
        newRules=[]
        for i in dataFrame.keys():
            if type(dataFrame[i][0])==type(1.00):
                rule,dataFrame[i]=self.gini(dataFrame[i],dataFrame[self.target])
                newRules.append([rule,i])

        return newRules,dataFrame

# =============================================================================
# testset columns need to change as trainset columns type from sourced gini
# =============================================================================
    def dopostprocess(self,dataFrame):
        i=0
        while i<len(self.postrules):
            j=0
            while j<len(dataFrame[self.postrules[i][1]]):
                if dataFrame[self.postrules[i][1]][j]<=self.postrules[i][0]:
                    dataFrame[self.postrules[i][1]][j]="<={}".format(self.postrules[i][0])
                else:
                    dataFrame[self.postrules[i][1]][j]=">{}".format(self.postrules[i][0])
                j+=1
            i+=1
        
        return dataFrame
    
# =============================================================================
# gini
# =============================================================================
    def gini(self,column,target):
        merged=[]

        targets=list(set(target))  
        values=list(set(sorted(column)))
        rules=[]

        values.insert(0,values[0]-10)
        values.insert(-1,values[-1]+10)

        i=0
        while i<len(column):
            merged.append([column[i],target[i]])
            i+=1
        i=0
        while i<len(values)-1:

            leftup = sum(1 for x in merged if x[1]==targets[0] and x[0]<=(values[i]+values[i+1])/2)
            rightup = sum(1 for x in merged if x[1]==targets[0] and x[0]>(values[i]+values[i+1])/2)
            leftdown = sum(1 for x in merged if x[1]==targets[1] and x[0]<=(values[i]+values[i+1])/2)
            rightdown = sum(1 for x in merged if x[1]==targets[1] and x[0]>(values[i]+values[i+1])/2)

            gini=0
            if (leftup+leftdown!=0):
                gini+=((leftup+leftdown)/(leftup+leftdown+rightup+rightdown))*(1-(leftup/(leftup+leftdown))**2-(leftdown/(leftup+leftdown))**2)
            if (rightup+rightdown!=0):
                gini+=((rightup+rightdown)/(leftup+leftdown+rightup+rightdown))*(1-(rightup/(rightup+rightdown))**2-(rightdown/(rightup+rightdown))**2)

            rules.append([gini,(values[i]+values[i+1])/2])
            i+=1


        rule=min(rules,key=lambda x : x[0])

        i=0
        while i<len(column):
            if column[i]<=rule[1]:
                column[i]="<={}".format(rule[1])
            else:
                column[i]=">{}".format(rule[1])
            i+=1

        return rule[1],column

# =============================================================================
# candicate rule generator
# =============================================================================
    def candidate_generator(self,dataFrame):
        candidate=[]
        for i in dataFrame.keys():
            types=list(set(dataFrame[i]))
            if len(types)>2:
                for j in types:
                    candidate.append([i,j])
            if len(types)==2:
                candidate.append([i,types[0]])
        return candidate

# =============================================================================
# defining best split rule
# =============================================================================
    def score_calculator(self,dataFrame):
        size=len(dataFrame[self.target])
        targets=list(set(dataFrame[self.target]))

        if len(targets)==1:
            return [1,targets,0]
        score=[]
        
# =============================================================================
#         2*Pl*Pr(abs(Pl[true]-Pr[true])*abs(Pl[false]-Pr[false]))
# =============================================================================
        for i,j in self.candidate_rules: # using the same splitting for many uses and put '#' to 206.line  #self.candidate_generator({i:dataFrame[i] for i in dataFrame.keys() if i != self.target}):   
            left_records_p=sum(1 for x in dataFrame[i] if x==j)
            right_records_p=size-left_records_p

            if left_records_p==1 or left_records_p==0:
                break

            left_records_t=sum(1 for count,x in enumerate(dataFrame[i]) if x==j and dataFrame[self.target][count]==targets[0])/left_records_p
            right_records_t=sum(1 for count,x in enumerate(dataFrame[i]) if x!=j and dataFrame[self.target][count]==targets[0])/right_records_p

            left_records_p/=size
            right_records_p/=size
            score.append([2*left_records_p*right_records_p*(abs(left_records_t-right_records_t)+abs((1-left_records_t)-(1-right_records_t))),i,j])
# =============================================================================
#       right or left is empty
# =============================================================================
        if len(score)==0:
            return [2,0,0]

        choosen_rule=max(score,key=lambda x: x[0])

# =============================================================================
#        it is my knowledge from i got experiences for optimizing and it makes PRE-PRUNING **************************       
# =============================================================================
        if size*(choosen_rule[0])<self.limitofmeasure:
            return [2,0,0]
        
        self.candidate_rules.remove([choosen_rule[1],choosen_rule[2]])

        return choosen_rule

# =============================================================================
# recursive tree generator
# =============================================================================
    def Recursive_Tree_Builder(self,trainSet,word,node,deep):
# =============================================================================
#        it is my knowledge from i got experiences for optimizing and it makes PRE-PRUNING **************************       
# =============================================================================
        if deep==self.maxdepth:
            pos_neg=""
            maxi=0
            maxilabel=""
            for i in list(set(trainSet[self.target])):
                if maxi<trainSet[self.target].count(i):
                    maxi=trainSet[self.target].count(i)
                    maxilabel=i
                pos_neg+="{}->{}\n".format(i,trainSet[self.target].count(i))

            pos_neg+=maxilabel    


            self.drawer.node(word,pos_neg)#for graph
            node.column,node.rule='class',maxilabel
            if len(word)!=0:
                if word[-1]=='L':
                    self.drawer.edge(word[:-1], word,label='Yes')#for graph
                elif word[-1]=='R':
                    self.drawer.edge(word[:-1], word,label='No')#for graph

            return node

        rule=self.score_calculator(trainSet)

        if rule[0]==1:
            self.drawer.node(word+'S',"{}".format(rule[1]))#for graph
            self.drawer.edge(word, word+'S')#for graph
            node.column,node.rule='class',rule[1]

        elif rule[0]==2:
            pos_neg=""
            maxi=0
            maxilabel=""
            for i in list(set(trainSet[self.target])):
                if maxi<trainSet[self.target].count(i):
                    maxi=trainSet[self.target].count(i)
                    maxilabel=i
                pos_neg+="{}->{}\n".format(i,trainSet[self.target].count(i))

            pos_neg+=maxilabel    
            self.drawer.node(word,pos_neg)#for graph
            node.column,node.rule='class',maxilabel
            if len(word)!=0:
                if word[-1]=='L':
                    self.drawer.edge(word[:-1], word,label='Yes')#for graph
                elif word[-1]=='R':       
                    self.drawer.edge(word[:-1], word,label='No')#for graph

            return node
        else:

            size=len(trainSet[self.target])

            right_trainSet={}
            for column in trainSet.keys():
                right_trainSet[column]=[]

            i=0
            while i<len(trainSet[self.target]):

                if trainSet[rule[1]][i]== rule[2]:
                    for column in trainSet.keys():
                        right_trainSet[column].append(trainSet[column][i])
                        del trainSet[column][i]
                i+=1

            self.drawer.node(word,"{} == \"{}\" \n P={} \n records={}".format(rule[1],rule[2],rule[0],size))#for graph
            node.column,node.rule=rule[1],rule[2]
            if len(word)!=0:
                if word[-1]=='L':
                    self.drawer.edge(word[:-1], word,label='Yes')#for graph
                if word[-1]=='R':
                    self.drawer.edge(word[:-1], word,label='No')#for graph

            if len(trainSet[self.target])>len(right_trainSet[self.target]):
                node.left=Node()
                node.left=self.Recursive_Tree_Builder(trainSet,word+'L',node.left,deep+1)
                node.right=Node()
                node.right=self.Recursive_Tree_Builder(right_trainSet,word+'R',node.right,deep+1)
            else:
                node.right=Node()
                node.right=self.Recursive_Tree_Builder(right_trainSet,word+'R',node.right,deep+1)
                node.left=Node()
                node.left=self.Recursive_Tree_Builder(trainSet,word+'L',node.left,deep+1)

        return node

# =============================================================================
# Train Manager    
# =============================================================================
    def training_Manager(self,):
        #read file
        train=self.fileread(self.filename)
        #continues value to class
        self.postrules,train=self.float2class(train)
        #defining candicate leaf
        self.candidate_rules=self.candidate_generator({i:train[i] for i in train.keys() if i != self.target})

# =============================================================================
#        it is my knowledge from i got experiences for optimizing and it makes PRE-PRUNING **************************       
# =============================================================================        
        if self.maxdepth==0:
            self.maxdepth=math.log(len(self.candidate_rules),2)//1-1
        #creating tree
        self.tree=self.Recursive_Tree_Builder(train,'',Node(),0)

# =============================================================================
# Visualizator                                                                 **************************  
# =============================================================================
    def visulator(self,filename,show):
        self.drawer.render(filename,view=show)
        #self.tree.PrintTree()

# =============================================================================
#   it predicts row of test using trained tree         
# =============================================================================
    def decision(self,x,node):
        if node.column=='class':
            return node.rule
        if x[node.column]==node.rule:
            return self.decision(x,node.left)
        else:
            return self.decision(x,node.right)

# =============================================================================
#   it predicts rows        
# =============================================================================
    def prediction(self,dataFrame,l):
        predict=[]
        
        j=0
        while(j<l):
            x={i:dataFrame[i][j] for i in dataFrame.keys()}
            predict.append(self.decision(x,self.tree))
            j+=1
        return predict

# =============================================================================
#   computing confucision matrix             
# =============================================================================
    def confucision(self,predict,test_y):
        tp=0
        fn=0
        fp=0
        tn=0
        i=0
        while(i<len(predict)):
            if predict[i]==self.classi[0] and test_y[i]==self.classi[0]:
                tp+=1
            elif predict[i]==self.classi[1] and test_y[i]==self.classi[1]:
                tn+=1
            elif predict[i]==self.classi[1] and test_y[i]==self.classi[0]:
                fn+=1
            else:
                fp+=1
            i+=1   
        sumi=sum([tp,fn,fp,tn])
        
        return {'Accuary':(tn+tp)/sumi,'TPrate':tp/(tp+fn),'TNrate':tn/(tn+fp),'number of TP':tp,'number of TN':tn}
    
    
# =============================================================================
#   Estimation Manager    
# =============================================================================
    def testing_Manager(self,testingfile,resultvis=False):
        #reading test file
        test=self.fileread(testingfile)
        #spliting x test
        x_test={i:test[i] for i in test.keys() if i != self.target}
        #spliting y test
        y_test=test[self.target]
        #x test needs to preperocess which applied trainset
        p_test=self.dopostprocess(x_test)
        #predict
        predict=self.prediction(p_test,len(y_test))
        #calculating confucision matrix
        c=self.confucision(predict, y_test)
        
        if resultvis:
            self.resultvisulator(c)
       
        return c
# =============================================================================
# Printing Result of Test set     
# =============================================================================
    def resultvisulator(self,c):
        print("Result:",c)
        
# =============================================================================
# Parameter Optimizing using Bruteforce for only this model so it's static
# =============================================================================
# =============================================================================
# Parameter=[]
# for i in range(10):
#     for j in range(10):
#         p=[]
#         print('Stoprule={},MaxDepth={}'.format(i,j))
#         modelling=CART("trainSet.csv",'class',i,j)
#         p.append(i)
#         p.append(j)
#         modelling.training_Manager()
#         modelling.visulator('Tree Stoprule={},MaxDepth={}.png'.format(i,j),False)
#         modelling.classi=['good','bad']
#        
#         print('---->trainSet<----\n\n')
#         t=modelling.testing_Manager('trainSet.csv',True)
#         p.append(t['Accuary'])
#         p.append(t['number of TN'])
#         ##################################################
#         print('---->testSet<----\n\n\n')
#         t=modelling.testing_Manager('testSet.csv',True)
#         p.append(t['Accuary'])
#         p.append(t['number of TN'])
#         Parameter.append(p)
# 
# import matplotlib.pyplot as plt
# fig, ax = plt.subplots()
# 
# ax.plot([i[0]*10+i[1] for i in Parameter], [i[2] for i in Parameter], linewidth=2.0,color='green')
# ax.plot([i[0]*10+i[1] for i in Parameter], [i[4] for i in Parameter], linewidth=2.0,color='red')
# 
# =============================================================================

# =============================================================================
# Even if accuary is low, it is better because of TNrate 
# {'Accuary': 0.644, 
# 'TPrate': 0.8920454545454546, 
# 'TNrate': 0.05405405405405406, 
# 'number of TP': 157, 
# 'number of TN': 4}
# splitted dataset size * measure of goodnes > 30 and maxdepth of Tree = 4
# =============================================================================
modelling=CART("trainSet.csv",'class',30,4)
modelling.training_Manager()
modelling.visulator('Tree',True)
modelling.classi=['good','bad']
print('---->trainSet<----\n\n')
modelling.testing_Manager('trainSet.csv',True)
print('---->testSet<----\n\n\n')
modelling.testing_Manager('testSet.csv',True)

# =============================================================================
# accuary is higher than prev but almost TNrate=0 because classes of trainingset isn't balanced each other
# {'Accuary': 0.704,
#  'TPrate': 0.9943181818181818, 
#  'TNrate': 0.013513513513513514, 
#  'number of TP': 175, 
#  'number of TN': 1}
# splitted dataset size * measure of goodnes < 10 and maxdepth of Tree = 5
# =============================================================================
# modelling=CART("trainSet.csv",'class',10,5)
# modelling.training_Manager()
# modelling.visulator('Tree 2',True)
# modelling.classi=['good','bad']
# print('---->trainSet<----\n\n')
# modelling.testing_Manager('trainSet.csv',True)
# print('---->testSet<----\n\n\n')
# modelling.testing_Manager('testSet.csv',True)