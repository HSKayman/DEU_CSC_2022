
from numpy import array
import tensorflow as tf
from tensorflow.keras.callbacks import CSVLogger
from tensorflow.keras.callbacks import ModelCheckpoint
from keras.models import Sequential
from keras.layers import LSTM
from keras.layers import Dense
from keras.layers import Flatten
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
import glob
import argparse



# split a multivariate sequence into samples
def split_sequences(sequences, n_steps):
    X, y = list(), list()

    for i in range(len(sequences)):
        # find the end of this pattern
        end_ix = i + n_steps
        # check if we are beyond the dataset
        if end_ix > len(sequences):
            break
        # gather input and output parts of the pattern
        seq_x, seq_y = sequences[i:end_ix, :-1], sequences[end_ix-1, -1]
        X.append(seq_x)
        y.append(seq_y)
    
    return array(X), array(y)

def form(yhat,y,f):
    conf=[[[],[]],#0
          [[],[]],#1
          [[],[]],#2
          [[],[]],#3
          [[],[]]] #4
    i=1
    while i<len(yhat):
        if yhat[i]<y[i-1] and y[i]<y[i-1]:
            conf[3][0].append(abs(yhat[i]-y[i]))
            conf[3][1].append(abs(y[i-1]-y[i])/y[i-1])
            conf[4][0].append(True)
            conf[4][1].append(1+abs(y[i-1]-y[i])/y[i-1])
        elif yhat[i]>y[i-1] and y[i]>y[i-1]:
            conf[0][0].append(abs(yhat[i]-y[i]))
            conf[0][1].append(abs(y[i-1]-y[i])/y[i-1])
            conf[4][0].append(True)
            conf[4][1].append(1+abs(y[i-1]-y[i])/y[i-1])
        elif yhat[i]>y[i-1] and y[i]<y[i-1]:
            conf[2][0].append(abs(yhat[i]-y[i]))
            conf[2][1].append(-1*abs(y[i-1]-y[i])/y[i-1])
            conf[4][0].append(False)
            conf[4][1].append(1-abs(y[i-1]-y[i])/y[i-1])
        else:
            conf[1][0].append(abs(yhat[i]-y[i]))
            conf[1][1].append(-1*abs(y[i-1]-y[i])/y[i-1])
            conf[4][0].append(False)
            conf[4][1].append(1-abs(y[i-1]-y[i])/y[i-1])
        i+=1
    
    f.write('Mean\n')
    try:
        f.write(str([[np.mean(i) for i in j] for j in conf])+'\n')
    except ValueError:  #raised if `y` is empty.
        pass
    f.write('Count'+'\n')
    try:
        f.write(str([len(i[0]) for i in conf])+'\n')
    except ValueError:  #raised if `y` is empty.
        pass
    try:
        f.write("acc: %{}".format((len(conf[0][0])+len(conf[3][0]))/(len(conf[0][0])+len(conf[3][0])+len(conf[1][0])+len(conf[2][0])))+'\n')
    except ValueError:  #raised if `y` is empty.
        pass
    f.write('Max'+'\n')
    try:
        f.write(str([[np.max(i) for i in j] for j in conf])+'\n')
    except ValueError:  #raised if `y` is empty.
        pass
    f.write('Min'+'\n')
    try:
        f.write(str([[np.min(i) for i in j] for j in conf])+'\n')
    except ValueError:  #raised if `y` is empty.
        pass
    money=100


    for i in range(len(conf[4][1])):
        #print(money)
        money=(money*conf[4][1][i])#+money*0.2
        money*=0.9999
    f.write('Money'+'\n')
    try:
        f.write(str(money)+'\n')
    except ValueError:  #raised if `y` is empty.
        pass

    return money

ap=argparse.ArgumentParser()

ap.add_argument("--data",help="Kendin Bul")
ap.add_argument("--Ind",help="Kendin Bul")
ap.add_argument("--time",help="Kendin Bul")
args=ap.parse_args()

csv_data = args.data
time = args.time
ind = args.Ind

n_steps =3
dataset=pd.read_csv('/home/shoujakymn/Desktop/Reguler Code/csv_data_{}/{}_{}_{}.csv'.format(ind,csv_data,time,ind))
# convert into input/output
pre_dataset=dataset.values.copy()
num=int(len(pre_dataset)*30/100)
pre_dataset.astype(float)
print(pre_dataset.shape)
X, y = split_sequences(pre_dataset[:,:], n_steps)
X_valid, y_valid = split_sequences(pre_dataset[-num:-int(num/2),:], n_steps)
X_test,y_test =split_sequences(pre_dataset[-int(num/2):,:], n_steps)

n_features=X.shape[2]
# define model
model = Sequential()
model.add(LSTM(units=50, input_shape=(n_steps, n_features), activation='relu'))
model.add(Dense(units=1))
model.compile(optimizer='adam', loss='mse', run_eagerly=True)
# choose a number of time steps
from datetime import datetime

today_time = str(datetime.now().strftime("%d/%m/%Y %H:%M:%S")).replace('/','')



checkpoint_filepath = "/home/shoujakymn/Desktop/Reguler Code/checkpoints/{}_{}_{}_{}".format(csv_data,time,ind,today_time)
model_checkpoint_callback = tf.keras.callbacks.ModelCheckpoint(
    filepath=checkpoint_filepath,
    save_weights_only=True,
    monitor='val_loss',
    mode='min',
    save_best_only=True)
history=model.fit(X, y,validation_data=(X_valid,y_valid), epochs=3000, callbacks=[model_checkpoint_callback])

f = open("/home/shoujakymn/Desktop/Reguler Code/checkpoints/{}_{}_{}_{}.log".format(csv_data,time,ind,today_time), "w")


yhat = model.predict(X)
f.write("Train\n")
form(yhat,y,f)


yhat_valid = model.predict(X_valid)
f.write("Valid\n")
form(yhat_valid,y_valid,f)

yhat_test = model.predict(X_test)
f.write("Test\n")
form(yhat_test,y_test,f)

f.close()
