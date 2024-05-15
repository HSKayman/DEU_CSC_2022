from numpy import array
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import os
import glob
import argparse


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
    return coin_MACD

def BBand(dataset, base='Close', period=20, multiplier=2):
    dataset = pd.DataFrame(dataset,columns=["Open","High","Low","Close"])
    coin_bb=dataset.copy()
    
    sma = coin_bb[base].rolling(window=period, min_periods=period - 1).mean()
    sd = coin_bb[base].rolling(window=period).std()

    coin_bb['BB_UPPER'] = sma + (multiplier * sd)
    coin_bb['BB_SMA'] = sma
    coin_bb['BB_LOWER'] = sma - (multiplier * sd)
    return coin_bb

def calc_rsi(dataset):
    dataset = pd.DataFrame(dataset,columns=["Open","High","Low","Close"])
    coin_rsi=dataset.copy()
    data=coin_rsi.copy()
    a=coin_rsi.columns[3]
    coin_rsi.drop(coin_rsi.columns.difference([a]), 1, inplace=True)
    coin_rsi=coin_rsi.reset_index(drop=True,inplace=False)
    coin_rsi["diff"]=coin_rsi.diff(1)

    coin_rsi['gain'] = coin_rsi['diff'].clip(lower=0).round(2)
    coin_rsi['loss'] = coin_rsi['diff'].clip(upper=0).abs().round(2)
    coin_rsi

    window_length=14
    # Get initial Averages
    coin_rsi['avg_gain'] = coin_rsi['gain'].rolling(window=window_length, min_periods=window_length).mean()[:window_length+1]
    coin_rsi['avg_loss'] = coin_rsi['loss'].rolling(window=window_length, min_periods=window_length).mean()[:window_length+1]
    # View Result

    # View first SMA value

    for i, row in enumerate(coin_rsi['avg_gain'].iloc[window_length+1:]):
        coin_rsi['avg_gain'].iloc[i + window_length + 1] =\
          (coin_rsi['avg_gain'].iloc[i + window_length] *
          (window_length - 1) +
          coin_rsi['gain'].iloc[i + window_length + 1])\
          / window_length
    # Average Losses
    for i, row in enumerate(coin_rsi['avg_loss'].iloc[window_length+1:]):
        coin_rsi['avg_loss'].iloc[i + window_length + 1] =\
          (coin_rsi['avg_loss'].iloc[i + window_length] *
          (window_length - 1) +
          coin_rsi['loss'].iloc[i + window_length + 1])\
          / window_length
    # View initial results

    coin_rsi['rs'] = coin_rsi['avg_gain'] / coin_rsi['avg_loss']
    coin_rsi['rsi'] = 100 - (100 / (1.0 + coin_rsi['rs']))

    # View Result

    return coin_rsi["rsi"]

ap=argparse.ArgumentParser()

ap.add_argument("--data",help="Kendin Bul")
ap.add_argument("--Ind",help="Kendin Bul")
ap.add_argument("--time",help="Kendin Bul")
args=ap.parse_args()

csv_data = args.data
time = args.time
ind = args.Ind

dataset = pd.read_csv('/home/shoujakymn/Desktop/Reguler Code/csv_data/{}_{}.csv'.format(csv_data,time))

if ind=='macd':
    dataset = macd(dataset)
    dataset =dataset[['MACD_12_26','MACDsignal_12_26','MACDdifference_12_26','Open','High','Low','Close']]
    dataset=dataset.dropna()
    dataset=dataset.reset_index(drop=True)
    dataset.to_csv('/home/shoujakymn/Desktop/Reguler Code/csv_data_macd/{}_{}_{}.csv'.format(csv_data,time,ind), index=False)
    print("done",csv_data,time,ind)
elif ind == 'bb':
    dataset = BBand(dataset)
    dataset =dataset[['BB_UPPER','BB_SMA','BB_LOWER','Open','High','Low','Close']]
    dataset=dataset.dropna()
    dataset=dataset.reset_index(drop=True)
    dataset.to_csv('/home/shoujakymn/Desktop/Reguler Code/csv_data_bb/{}_{}_{}.csv'.format(csv_data,time,ind), index=False)
elif ind=='rsi':
    dataset['rsi'] = calc_rsi(dataset)
    dataset =dataset[['rsi','Open','High','Low','Close']]
    dataset=dataset.dropna()
    dataset=dataset.reset_index(drop=True)
    dataset.to_csv('/home/shoujakymn/Desktop/Reguler Code/csv_data_rsi/{}_{}_{}.csv'.format(csv_data,time,ind), index=False)
    