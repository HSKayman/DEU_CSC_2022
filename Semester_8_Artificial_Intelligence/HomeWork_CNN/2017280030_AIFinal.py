#!/usr/bin/env python
# coding: utf-8

# # Import Library

# In[28]:


from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from keras.utils.np_utils import to_categorical
import itertools
from keras.utils.np_utils import to_categorical 
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPool2D
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ReduceLROnPlateau
from sklearn.metrics import accuracy_score
import numpy as np 
import pandas as pd 
import seaborn as sns
import matplotlib.pyplot as plt
import os


# In[2]:


print(os.listdir("./"))


# # Read Train

# In[3]:


traindf = pd.read_csv("./fashion-mnist_train.csv")
print(traindf.shape)
traindf.head()


# # Read Test

# In[4]:


testdf= pd.read_csv("./fashion-mnist_test.csv")
print(testdf.shape)
testdf.head()


# In[5]:


class_names = ['T_shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat', 
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']


# # Split for test and train to X,Y

# In[6]:


Y_train = traindf["label"]
X_train = traindf.drop(labels = ["label"],axis = 1)
Y_test = testdf["label"]
X_test = testdf.drop(labels = ["label"],axis = 1)


# In[7]:


Y_train.value_counts()


# In[8]:


Y_test.value_counts()


# # Check Random Row

# In[9]:


img = X_train.iloc[0].values
img = img.reshape((28,28))
plt.imshow(img,cmap='gray')
plt.title(class_names[Y_train.iloc[0]])
plt.axis("off")
plt.show()


# # Normalization

# In[10]:


X_train = X_train / 255.0
X_test = X_test / 255.0


# # Reshape process to model

# In[11]:


X_train = X_train.values.reshape(-1,28,28,1)
X_test = X_test.values.reshape(-1,28,28,1)


# # Encode Categorical Y    X[0]=1--->X[0]=[0,1,0,0,0,0,0,0,0,0]

# In[12]:


Y_train = to_categorical(Y_train, num_classes = 10)
Y_test = to_categorical(Y_test, num_classes = 10)


# # Split from train set to validate set

# In[13]:


X_train, X_val, Y_train, Y_val = train_test_split(X_train, Y_train, test_size = 0.1, random_state=2)


# # Creating model

# In[14]:


model = Sequential()
model.add(Conv2D(filters = 8, kernel_size = (5,5),padding = 'Same', 
                 activation ='relu', input_shape = (28,28,1)))

model.add(MaxPool2D(pool_size=(2,2)))
model.add(Dropout(0.25))
#
model.add(Conv2D(filters = 16, kernel_size = (3,3),padding = 'Same', 
                 activation ='relu'))

model.add(MaxPool2D(pool_size=(2,2), strides=(2,2)))
model.add(Dropout(0.25))

# fully connected
model.add(Flatten())
model.add(Dense(256, activation = "relu"))
model.add(Dropout(0.5))
model.add(Dense(10, activation = "softmax"))


# In[15]:


model.compile(optimizer = "Adam" , loss = "categorical_crossentropy", metrics=["accuracy"])


# In[16]:


epochs = 75 
batch_size = 250


# In[17]:


datagen = ImageDataGenerator(
        featurewise_center=False, 
        samplewise_center=False,  
        featurewise_std_normalization=False,  
        samplewise_std_normalization=False,  
        zca_whitening=False,  
        rotation_range=5,  
        zoom_range = 0.1, 
        width_shift_range=0.1,  
        height_shift_range=0.1,  
        horizontal_flip=False,  
        vertical_flip=False) 

datagen.fit(X_train)


# # Fit Model

# In[18]:


history = model.fit(datagen.flow(X_train,Y_train, batch_size=batch_size), epochs = epochs, validation_data = (X_val,Y_val), steps_per_epoch=X_train.shape[0] // batch_size)


# # Check History loss for overfitting

# In[19]:


plt.plot(history.history['val_loss'], color='b', label="validation loss")
plt.title("Test Loss")
plt.xlabel("Number of Epochs")
plt.ylabel("Loss")
plt.legend()
plt.show()


# # Train Results

# In[58]:


Y_pred = model.predict(X_train)
Y_pred_classes = np.argmax(Y_pred,axis = 1) 
Y_true = np.argmax(Y_train,axis = 1) 
confusion_mtx = confusion_matrix(Y_true, Y_pred_classes) 

f,ax = plt.subplots(figsize=(8, 8))
sns.heatmap(confusion_mtx, annot=True, linewidths=0.01,cmap="Greens",linecolor="gray", fmt= '.1f',ax=ax)
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Train Confusion Matrix")
plt.show()


# In[59]:


accuracy_score(Y_true, Y_pred_classes)


# In[60]:


np.max(confusion_mtx,axis=0)/np.sum(confusion_mtx,axis=0)


# # Validation Results

# In[61]:


Y_pred = model.predict(X_val)
Y_pred_classes = np.argmax(Y_pred,axis = 1) 
Y_true = np.argmax(Y_val,axis = 1) 
confusion_mtx = confusion_matrix(Y_true, Y_pred_classes) 

f,ax = plt.subplots(figsize=(8, 8))
sns.heatmap(confusion_mtx, annot=True, linewidths=0.01,cmap="Greens",linecolor="gray", fmt= '.1f',ax=ax)
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Train Confusion Matrix")
plt.show()


# In[62]:


accuracy_score(Y_true, Y_pred_classes)


# In[63]:


np.max(confusion_mtx,axis=0)/np.sum(confusion_mtx,axis=0)


# # Test Result

# In[64]:


Y_pred = model.predict(X_test)
Y_pred_classes = np.argmax(Y_pred,axis = 1) 
Y_true = np.argmax(Y_test,axis = 1) 
confusion_mtx = confusion_matrix(Y_true, Y_pred_classes) 

f,ax = plt.subplots(figsize=(8, 8))
sns.heatmap(confusion_mtx, annot=True, linewidths=0.01,cmap="Greens",linecolor="gray", fmt= '.1f',ax=ax)
plt.xlabel("Predicted Label")
plt.ylabel("True Label")
plt.title("Test Confusion Matrix")
plt.show()


# In[65]:


accuracy_score(Y_true, Y_pred_classes)


# In[66]:


np.max(confusion_mtx,axis=0)/np.sum(confusion_mtx,axis=0)


# In[ ]:




