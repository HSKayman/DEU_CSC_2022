#!/usr/bin/env python
# coding: utf-8

# In[1]:

# =============================================================================
# Importing Requirment Library
# =============================================================================
from sklearn.metrics import precision_recall_fscore_support
from keras.layers import Dense, Flatten
from keras.models import Sequential
import matplotlib.pyplot as plt
from keras.layers import Dense
from tensorflow import keras
import pandas as pd
import numpy as np
import os,cv2


# In[2]:

# =============================================================================
# Reading Photos
# =============================================================================
Xtrain=[]
Ytrain=[]
Xtest=[]
Ytest=[]
for i in os.listdir("./mnist-train/"):
    for j in os.listdir("./mnist-train/"+i+"/"):
        Xtrain.append(cv2.imread("./mnist-train/"+i+"/"+j,0))
        Ytrain.append([1 if number==i else 0 for number in os.listdir("./mnist-train/")])

for i in os.listdir("./mnist-test/"):
    for j in os.listdir("./mnist-test/"+i+"/"):
        Xtest.append(cv2.imread("./mnist-test/"+i+"/"+j,0))
        Ytest.append([1 if number==i else 0 for number in os.listdir("./mnist-test/")])
                    


# In[3]:

# =============================================================================
# GrayScale Normalization
# =============================================================================
Xtrain=np.array(Xtrain)
Xtrain[Xtrain>0]=1
Ytrain=np.array(Ytrain)
Xtest=np.array(Xtest)
Xtest[Xtest>0]=1
Ytest=np.array(Ytest)


# In[4]:

# =============================================================================
# Definiong Number Of Node which in NN
# =============================================================================
exceptedAccuary=0.99
NumberOfTrainRow=2000
numberOfRequirementNode=int((1-exceptedAccuary)*NumberOfTrainRow)
numberOfRequirementNode


# In[5]:

# =============================================================================
# Seting Model
# =============================================================================
model = Sequential()
model.add(Flatten(input_shape=Xtrain.shape[1:]))
model.add(Dense(50, activation='relu'))
model.add(Dense(25, activation='relu'))
model.add(Dense(10, activation='softmax'))


# In[6]:

# =============================================================================
# Fiting Model via lr=0.009, categorical_crossentropy and 30 epochs
# =============================================================================
model.compile(loss='categorical_crossentropy', optimizer=keras.optimizers.Adam(learning_rate=0.009), metrics=[
'accuracy',
keras.metrics.Recall(),
keras.metrics.Precision()])
history=model.fit(Xtrain, Ytrain, epochs=30, verbose=1)


# In[7]:

# =============================================================================
# Ploting Result
# =============================================================================
plt.plot(history.history['accuracy'])
plt.plot(history.history['loss'])
plt.title('model accuracy')
plt.ylabel('accuracy')
plt.xlabel('epoch')
plt.legend(['accuaracy', 'loss'], loc='upper right')
plt.show()


# In[8]:


(Ytrain.shape,Xtrain.shape)


# In[9]:

# =============================================================================
# Predicting Yhat Train
# =============================================================================
YtrainHat=model.predict(Xtrain)
metricsTrain=model.evaluate(Xtrain, Ytrain)


# In[10]:
# =============================================================================
# Predicting Yhat Test
# =============================================================================

YtestHat=model.predict(Xtest)
metricsTest=model.evaluate(Xtest, Ytest)


# In[11]:

# =============================================================================
# Train Metric Process
# =============================================================================
YtrainM=np.argmax(Ytrain, axis=1)
YtrainHatM=np.argmax(YtrainHat, axis=1)
metricsTrain=precision_recall_fscore_support(YtrainM, YtrainHatM, average=None)
TrainM_dict={'Number':[i for i in os.listdir("./mnist-test/")],
                                    'Precision':[float(str(i)[:5]) for i in metricsTrain[0]],
                                     'Recall':[float(str(i)[:5]) for i in metricsTrain[1]],
                                     'FScore':[float(str(i)[:5]) for i in metricsTrain[2]]}


# In[12]:

# =============================================================================
# Printing Train Metrics
# =============================================================================
df=pd.DataFrame.from_dict(TrainM_dict).set_index('Number')
df=df.transpose()
df['Mean']=df.mean(axis=1)
df


# In[13]:

# =============================================================================
# Test Metric Process
# =============================================================================
YtestM=np.argmax(Ytest, axis=1)
YtestHatM=np.argmax(YtestHat, axis=1)
metricsTest=precision_recall_fscore_support(YtestM, YtestHatM, average=None)
TestM_dict={'Number':[i for i in os.listdir("./mnist-test/")],
                                    'Precision':[float(str(i)[:5]) for i in metricsTest[0]],
                                     'Recall':[float(str(i)[:5]) for i in metricsTest[1]],
                                     'FScore':[float(str(i)[:5]) for i in metricsTest[2]]}


# In[14]:

# =============================================================================
# Printing Test Metrics
# =============================================================================
df=pd.DataFrame.from_dict(TestM_dict).set_index('Number')
df=df.transpose()
df['Mean']=df.mean(axis=1)
df


# In[15]:

# =============================================================================
# Plotting Model
# =============================================================================
keras.utils.plot_model(model, to_file="model.png", show_shapes=True)


# In[ ]:




