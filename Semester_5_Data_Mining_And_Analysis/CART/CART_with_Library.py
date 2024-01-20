import pandas as pd

#Reading data
train=pd.read_csv('trainSet.csv')
test=pd.read_csv('testSet.csv')
train_x=train.drop(columns=['class']).values
train_y=train['class'].values

test_x=test.drop(columns=['class']).values
test_y=test['class'].values

#Label Encoding
le=[]
for i in range(train_x[0].size):
    if type(train_x[1,i])==type('s'):
        a={i[1]:i[0] for i in enumerate(list(set(train_x[:,i])))}
        #print(a)
        for j in range(len(train_x[:,i])):
            train_x[j,i]=a[train_x[j,i]]
                    
        for j in range(len(test_x[:,i])):
            test_x[j,i]=a[test_x[j,i]]
        
    le.append(a)
    
#Creating Tree
from sklearn import tree
clf = tree.DecisionTreeClassifier(max_depth=3)
clf = clf.fit(train_x, train_y)

prediction=clf.predict(test_x)


#Computing Accuary
matrices=[0,0,0,0]#
i=0
while i<len(prediction):
    if prediction[i]=='good' and test_y[i]=='good':
        matrices[0]+=1#tp
    elif prediction[i]=='good' and test_y[i]=='bad':
        matrices[1]+=1#fp
    elif prediction[i]=='bad' and test_y[i]=='good':
        matrices[2]+=1#tp
    elif prediction[i]=='bad' and test_y[i]=='bad':
        matrices[3]+=1#tn
        
    i+=1
print('Accuary={}'.format((matrices[0]+matrices[3])/len(test_y)))


#Drawing Tree
import graphviz 
dot_data = tree.export_graphviz(clf,) 
graph = graphviz.Source(dot_data)
graph.render("clf.png",view=True)   