from numpy import array
import tensorflow as tf
from keras.models import Sequential
from keras.layers import LSTM
from keras.layers import Dense
from keras.layers import Flatten
from termcolor import colored
import numpy as np
import pandas as pd
import os
import glob
import argparse
import json
import requests
import os
import time

#TO-DO LIST
#------------
#dinamik coin           15coin and istenilen coinlerde
#dinamik indicators     to code tekli indicators
#to fix timestamp problem
#portfolio opt
#to integrate sentiment

def load_config():
    with open('config.json') as f:
        return json.load(f)
config = load_config()


def rsi(df, periods = 13, ema = True):
    close_delta = df['Close'].diff()

    up = close_delta.clip(lower=0)
    down = -1 * close_delta.clip(upper=0)
    
    if ema == True:
        ma_up = up.ewm(com = periods - 1, adjust=True, min_periods = periods).mean()
        ma_down = down.ewm(com = periods - 1, adjust=True, min_periods = periods).mean()
    else:
        ma_up = up.rolling(window = periods, adjust=False).mean()
        ma_down = down.rolling(window = periods, adjust=False).mean()
        
    rsi = ma_up / ma_down
    rsi = 100 - (100/(1 + rsi))
    return rsi.iloc[-1]

def macd(dataset, n_fast=12, n_slow=26):
    dataset = pd.DataFrame(dataset,columns=["Open","High","Low","Close"])
    coin_MACD=dataset.copy()

    EMAfast = pd.Series(coin_MACD['Close'].ewm(span=n_fast, min_periods=n_slow).mean())
    EMAslow = pd.Series(coin_MACD['Close'].ewm(span=n_slow, min_periods=n_slow).mean())
    MACD = pd.Series(EMAfast - EMAslow, name='MACD_' + str(n_fast) + '_' + str(n_slow))
    MACDsign = pd.Series(MACD.ewm(span=9, min_periods=9).mean(), name='MACDsignal_' + str(n_fast) + '_' + str(n_slow))
    MACDdiff = pd.Series(MACD - MACDsign, name='MACDdifference_' + str(n_fast) + '_' + str(n_slow))
    coin_MACD = coin_MACD.join(MACD)
    coin_MACD = coin_MACD.join(MACDsign)
    coin_MACD = coin_MACD.join(MACDdiff)
    return coin_MACD.iloc[-1]

def load_models(n_steps=3,n_features=6):# dinamik yaz
    models=[]
    for coin in config["Coins"]:
        TOKENUSDT = Sequential()
        TOKENUSDT.add(LSTM(units=50, input_shape=(n_steps, n_features), activation='relu'))
        TOKENUSDT.add(Dense(units=1))
        TOKENUSDT.compile(optimizer='adam', loss='mse', run_eagerly=True)
        path=glob.glob("/home/shoujakymn/Desktop/Reguler Code/checkpoints/{}_4h_macd*".format(coin))
        if len(path[1]) < len(path[0]):
            print(path[1][:-6])
            TOKENUSDT.load_weights(path[1][:-6])
        else:
            print(path[0][:-6])
            TOKENUSDT.load_weights(path[0][:-6])
        models.append(TOKENUSDT)
    return models

def lastvalue():
    current={}
    for coin in config["Coins"]:
        current[coin]= {"Open":[], 
            "High": [], 
            "Low": [], 
            "Close": [], 
            "MACD_12_26":[],
            "MACDsignal_12_26":[],
            "MACDdifference_12_26":[]
           }
    print("Waiting till prediction time comes!")
    while (int(time.time()) ) % 86400 > 14440:   
        time.sleep(10)
    while (int(time.time()) ) % 86400 < 13980:   
        time.sleep(10)
    for i in current.keys():
        os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/main.py" --coin {} --times {}'.format(i,"4h"))
        os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/Indicators.py" --data {} --time {} --Ind {} '.format(i,'4h','macd'))

    for coin in config["Coins"]:
        df=pd.read_csv('/home/shoujakymn/Desktop/Reguler Code/csv_data_macd/{}_{}_macd.csv'.format(coin,"4h"))
        current[coin]['Open']=list(df['Open'].values[-126:])
        current[coin]['High']=list(df['High'].values[-126:])
        current[coin]['Low']=list(df['Low'].values[-126:])
        current[coin]['Close']=list(df['Close'].values[-126:])
        current[coin]['MACD_12_26']=list(df['MACD_12_26'].values[-126:])
        current[coin]['MACDsignal_12_26']=list(df['MACDsignal_12_26'].values[-126:])
        current[coin]['MACDdifference_12_26']=list(df['MACDdifference_12_26'].values[-126:])
        
    return current

# =============================================================================
# Launching Model
# =============================================================================
models=load_models()
current=lastvalue()

# =============================================================================
# Begin Artificial Parameters last 14 value
# =============================================================================


key="https://api.binance.com/api/v3/ticker/price?symbol="
dictionary={}
for coin in config["Coins"]:
    dictionary[coin+"_NowPrice"]=[]
    dictionary[coin+"_PredPrice"]=[]
    dictionary[coin+"_Rate_Inv"]=[]
    dictionary[coin+"_LorS"]=[]
    dictionary[coin+"_PorL"]=[]
    dictionary[coin+"_Currencies"]=[]
    dictionary[coin+"_Now+1Price"]=[]
    dictionary[coin+"Total_PorL"]=[]
    dictionary[coin+"Max_Possible"]=[]
    dictionary[coin+"Final_Currencies"]=[]
    dictionary[coin+"Confs"]=[]

import time 
unix=time.time()
pandas=pd.DataFrame(data=dictionary)
pandas.to_csv("result-{}.csv".format(unix),index=False)

currencies=[]
for coin in config["Coins"]:
    currencies.append(coin)

# =============================================================================
# Starting Parameter
# =============================================================================
confs=np.ones((len(currencies),4))
money=100
index=1
maxmoney=100  

while True:
    
    dictionary={}
    for coin in config["Coins"]:
        dictionary[coin+"_NowPrice"]=[]
        dictionary[coin+"_PredPrice"]=[]
        dictionary[coin+"_Rate_Inv"]=[]
        dictionary[coin+"_LorS"]=[]
        dictionary[coin+"_PorL"]=[]
        dictionary[coin+"_Currencies"]=[]
        dictionary[coin+"_Now+1Price"]=[]
        dictionary["Total_PorL"]=[]
        dictionary["Max_Possible"]=[]
        dictionary["Final_Currencies"]=[]
        dictionary["Confs"]=[]
        
    print("-----",index,". Stage ------:")
    print("Currency:",money)
    index+=1
 
    real_last_price=[current[currencies[j]]["Close"][-1] for j in range(len(currencies))]   
# =============================================================================
#     Prediction 
# =============================================================================
    print("\n Prediction")
    yhat=[]
    for j in range(len(currencies)):
        yhat_vals=pd.DataFrame(current[currencies[j]].values()).to_numpy()
        yhat_vals=yhat_vals[~np.isnan(yhat_vals).any(axis=1)]
        yhat_vals=np.vstack ([ yhat_vals[-3:],yhat_vals[:4]])
        yhat.append(models[j].predict(yhat_vals[:-1,-3:].transpose().reshape(1,3,6)))

    for c,i in enumerate(currencies):
        dictionary[i+"_NowPrice"].append(real_last_price[c])
        dictionary[i+"_PredPrice"].append(yhat[c])
        print(i,":",real_last_price[c],"->",yhat[c])
    print("------------------------") 
# =============================================================================
#     Profolio Opt.
# =============================================================================
    j=0
    sumi=0
    
    positive_accuary=[conf[0]/(conf[0]+conf[2]) for conf in confs]
    negative_accuary=[conf[3]/(conf[1]+conf[3]) for conf in confs]
    estimate_profit=[1+abs(yhat[j]-real_last_price[j])/real_last_price[j] for j in range(len(currencies))]
    while j<len(currencies):
        if yhat[j]<real_last_price[j]:  
            sumi+=negative_accuary[j]*estimate_profit[j]
        else:
            sumi+=positive_accuary[j]*estimate_profit[j]
        j+=1
# =============================================================================
#   Roulete    
# =============================================================================
    roulete=[]
    j=0
    flag_c=[]
    while j<len(currencies):
        if yhat[j]<real_last_price[j]:  
            roulete.append(money*negative_accuary[j]*estimate_profit[j]/sumi)
            print(currencies[j],".coin :%",negative_accuary[j]*estimate_profit[j]/sumi," short")
            dictionary[currencies[j]+"_Rate_Inv"].append(negative_accuary[j]*estimate_profit[j]/sumi)
            dictionary[currencies[j]+"_LorS"].append("short")
            flag_c.append(0)
        else:
            roulete.append(money*positive_accuary[j]*estimate_profit[j]/sumi)
            print(currencies[j],".coin :%",positive_accuary[j]*estimate_profit[j]/sumi," long")
            dictionary[currencies[j]+"_Rate_Inv"].append(positive_accuary[j]*estimate_profit[j]/sumi)
            dictionary[currencies[j]+"_LorS"].append("long")
            flag_c.append(1)

        j+=1

# =============================================================================
#   Scrapting Value   for 4h      
# =============================================================================
    for f,i in enumerate (currencies):
        flag=True
        while flag:
            try:
                url=key+i  
                data=requests.get(url)
                data=data.json()
                flag=False
            except:
                print("Error!")
   
        yhat_vals=pd.DataFrame(current[currencies[f]].values()).to_numpy()
        yhat_vals=yhat_vals[~np.isnan(yhat_vals).any(axis=1)]
        yhat_vals=np.vstack ([ yhat_vals[-3:],yhat_vals[:4]])
        macd_vals= macd(pd.DataFrame(yhat_vals.transpose(),columns=["MACD_12_26","MACDsignal_12__26","MACDdifference_12_26","Open","High","Low","Close"]))
        
        current[i]["MACD_12_26"].append(macd_vals["MACD_12_26"])
        current[i]["MACDsignal_12_26"].append(macd_vals["MACDsignal_12_26"])
        current[i]["MACDdifference_12_26"].append(macd_vals["MACDdifference_12_26"])
        current[i]["Open"].append(float(data['price']))
        current[i]["High"].append(float(data['price']))
        current[i]["Low"].append(float(data['price']))
        current[i]["Close"].append(float(data['price']))
 

        
    
# =============================================================================
#   Live Stream    
# =============================================================================
    count=0
    flag_lose=[0 for i in currencies]
    flag_win=[0 for i in currencies]
    last_max_profit=[0 for i in currencies]
    last_max_loss=[0.0553 for i in currencies]
    print("Waiting till prediction time comes!")
    while (int(time.time()) - 3600) % 14400 >14280:   
        pass
    while (int(time.time()) - 3600) % 14400 <14280:
        
        count+=1

        for c,i in enumerate(currencies):
            
            try:
                url=key+i  
                data=requests.get(url)
                data=data.json()
                current[i]["Close"][-1]=float(data["price"])

                if abs(current[i]["Close"][-1]/real_last_price[c]-1) >last_max_profit[c] and (int(current[i]["Close"][-1]/real_last_price[c])==flag_c[c]) and flag_win[c]==0:
                    last_max_profit[c] += abs(current[i]["Close"][-1]/real_last_price[c]-1)
                    if last_max_profit[c] < 0.01:
                        last_max_loss[c] = 0.05
                    else:
                        last_max_loss[c] = 0.0553 / (((last_max_profit[c]*100) + 1)*2)

                elif abs(current[i]["Close"][-1]/real_last_price[c]-1) < last_max_profit[c] and  (int(current[i]["Close"][-1]/real_last_price[c])==flag_c[c]) and flag_win[c]==0:
                    if abs(current[i]["Close"][-1]/real_last_price[c]-1) <= last_max_profit[c] - last_max_loss[c]:
                        #flag_win[c]= last_max_profit[c] - last_max_loss[c]
                        ''' print(flag_win[c],'Your profit')
                        print(last_max_profit[c],'Your max profit')
                        print(last_max_loss[c],'Your stop loss')
                        print(current[i]['Close'][-1],'Your current price')
                        print(real_last_price[c][-1],'Your initial price')'''

                elif (int(current[i]["Close"][-1]/real_last_price[c])!=flag_c[c] and flag_win[c]==0):
                    if abs(current[i]["Close"][-1]/real_last_price[c]-1) >= 0.25 :
                        flag_win[c]= -0.25
                        '''print(flag_win[c],'Your profit')
                        print(last_max_profit[c],'Your max profit')
                        print(last_max_loss[c],'Your stop loss')
                        print(current[i]['Close'][-1],'Your current price')
                        print(real_last_price[c][-1],'Your initial price')'''
                
                #print(last_max_profit[c],"ust limit")
                #print(last_max_loss[c],"alt limit")
                #print(flag_win[c],"win")
                if current[i]["Low"][-1]>float(data['price']):
                    current[i]["Low"][-1]=float(data['price'])
                if current[i]["High"][-1]<float(data['price']):
                    current[i]["High"][-1]=float(data['price'])
            except Exception as e:
                '''
                print(last_max_profit[c],"ust limit")
                print(last_max_loss[c],"alt limit")
                '''
                print("Error!",e)
                continue
        
        for i in currencies:
            string='{:02d}:{:02d}:{:02d}'.format((count*5)//3600,(count*5)%3600//60,(count*5)%60),str(i),": ","Open:",str(current[i]["Open"][-1]),"Low:",str(current[i]["Low"][-1]),"High:",str(current[i]["High"][-1]),"Close:",str(current[i]["Close"][-1])
            print(f"\r{string}      ", end="")
            time.sleep(0.82)
    
        
    print("\n")
    
# =============================================================================
#   Calculating Close Value    
# =============================================================================
    for i in currencies:
        flag=True
        while flag:
            try:
                url=key+i  
                data=requests.get(url)
                data=data.json()
                current[i]["Close"][-1]=float(data['price'])
                flag=False
                
            except:
                print("Error!")

        #delete
        current[i]["Open"].pop(0)
        current[i]["High"].pop(0)
        current[i]["Low"].pop(0)
        current[i]["Close"].pop(0)
        current[i]["MACD_12_26"].pop(0)
        current[i]["MACDsignal_12_26"].pop(0)
        current[i]["MACDdifference_12_26"].pop(0)

# =============================================================================
#  Uptading Accuary Value    
# =============================================================================
    j=0
    maxi=0
    real_now_price=[current[currencies[j]]["Close"][-1] for j in range(len(currencies))]
    real_profit=([abs(real_last_price[i]-real_now_price[i])/real_last_price[i] for i in range(len(currencies))])
    while j<len(currencies):  
        if (1+real_profit[j])>maxi:
            maxi=1+real_profit[j]
        dictionary[currencies[j]+"_Currencies"].append(real_profit[j])    
        dictionary[currencies[j]+"_Now+1Price"].append(real_now_price[j]) 
        if flag_win[j]>0:
            roulete[j]=roulete[j]* (1+ flag_win[j])
            dictionary[currencies[j]+"_PorL"].append("profit")
            print(currencies[j],".take coin profit: {}".format(flag_win[j]),"->",real_now_price[j])
            if int((real_now_price[j]/real_last_price[j]))!=flag_c[j]:
                print("Take profit working")
                confs[j][3-3*flag_c[j]]+=abs(flag_win[j])*10
            elif real_profit[j]>abs(flag_win[j]):
                print("Take profit fakeout")
                confs[j][1+flag_c[j]]+=abs(flag_win[j])*15

        elif flag_win[j]<0:
            roulete[j]=roulete[j]* (1+ flag_win[j])
            dictionary[currencies[j]+"_PorL"].append("lose")
            print(currencies[j],".stop coin lose: {}".format(flag_win[j]),"->",real_now_price[j])
            if int((real_now_price[j]/real_last_price[j]))==flag_c[j]:
                print("Stop loss fakeout")
                confs[j][1+flag_c[j]]+=abs(flag_win[j])*15
            elif real_profit[j]>abs(flag_win[j]):
                print("Stop loss working")
                confs[j][1+flag_c[j]]+=abs(flag_win[j])*5

        elif yhat[j]<real_last_price[j] and real_now_price[j]<real_last_price[j]:
            dictionary[currencies[j]+"_PorL"].append("profit")
            roulete[j]=roulete[j]*(1+real_profit[j])
            print(currencies[j],".coin profit:",real_profit[j],"->",real_now_price[j])
            confs[j][0]+=real_profit[j]*10
        elif yhat[j]>real_last_price[j] and real_now_price[j]>real_last_price[j]:
            dictionary[currencies[j]+"_PorL"].append("profit")
            roulete[j]=roulete[j]*(1+real_profit[j])
            print(currencies[j],".coin profit:",real_profit[j],"->",real_now_price[j])
            confs[j][3]+=real_profit[j]*10
        elif yhat[j]>real_last_price[j] and real_now_price[j]<real_last_price[j]:
            dictionary[currencies[j]+"_PorL"].append("lose")
            roulete[j]=roulete[j]*(1-real_profit[j])
            print(currencies[j],".coin lose :",real_profit[j],"->",real_now_price[j])
            confs[j][1]+=real_profit[j]*10
        else:
            dictionary[currencies[j]+"_PorL"].append("lose")
            roulete[j]=roulete[j]*(1-real_profit[j])
            print(currencies[j],".coin lose :",real_profit[j],"->",real_now_price[j])
            confs[j][2]+=real_profit[j]*10
        j+=1
    maxmoney*=maxi
    if sum(roulete)>money:
        dictionary["Total_PorL"].append("profit")
        print("Total profit:%",sum(roulete)/money-1)#colored(sum(roulete)/money-1,"blue"))
    else:
        dictionary["Total_PorL"].append("lose")
        print("Total Lose:%",money/sum(roulete)-1)

    money=sum(roulete)
    money*=0.9999
    print("Final Currency:",money,"Possible Max Profit:",maxmoney,"\n\n")

    try:
        dictionary["Max_Possible"].append(maxmoney)
        dictionary["Final_Currencies"].append(money)
        dictionary["Confs"].append(confs)
        pandas=pd.DataFrame(data=dictionary)
        pandas.to_csv("result-{}.csv".format(unix),mode="a",index=False,header=False)
    except Exception as e :
        print(e)
    
