
import numpy as np
import pandas as pd
import os
import glob
import argparse

ap=argparse.ArgumentParser()
ap.add_argument("--mode",help="rsi bb ...")
ap.add_argument("--coin",help="Kendin Bul")
ap.add_argument("--times",help="Kendin Bul")
mode=ap.parse_args().mode
coin=ap.parse_args().coin
times=ap.parse_args().times


csv_files = glob.glob(os.path.join('//home/shoujakymn/Desktop/Reguler Code/Scrapt_Coin_Price/data/spot/monthly/klines/{}/{}'.format(coin,times), "*.zip"))
li=[]
for f in csv_files:
    df = pd.read_csv(f, header=None)
    li.append(df)

frame = pd.concat(li, ignore_index=True)
dataset_c=frame.copy()
dataset_c.columns
dataset_c.rename(columns={0:'Open time',1: 'Open',2: 'High',3: 'Low',4: 'Close',5: 'Volume',6: 'Close time	',7: 'Quote asset volume	',8: 'Number of trades	',9: 'Taker buy base asset volume',10: 'Taker buy quote asset volume',11: 'Ignore'}, inplace=True)
csvfiles = glob.glob(os.path.join('//home/shoujakymn/Desktop/Reguler Code/Scrapt_Coin_Price/data/spot/daily/klines/{}/{}'.format(coin,times), "*.zip"))
li=[]
for f in csvfiles:
    df = pd.read_csv(f, header=None)
    li.append(df)

frame = pd.concat(li, ignore_index=True)
dataset_d=frame.copy()
dataset_d.columns
dataset_d.rename(columns={0:'Open time',1: 'Open',2: 'High',3: 'Low',4: 'Close',5: 'Volume',6: 'Close time	',7: 'Quote asset volume	',8: 'Number of trades	',9: 'Taker buy base asset volume',10: 'Taker buy quote asset volume',11: 'Ignore'}, inplace=True)
dataset_p=pd.concat([dataset_c,dataset_d])
dataset_p["Open time"].sort_values()
dataset_p.astype(str)
dataset_p=dataset_p.drop_duplicates()
dataset_p=dataset_p.astype(float)
dataset_p=dataset_p.sort_values(by=['Open time'])
dataset_c=dataset_p
dataset_c['Open time'] = pd.to_datetime(dataset_c['Open time'], unit='ms')
dataset_c.index=dataset_c['Open time']
dataset_c=dataset_c[["Open","High","Low","Close"]]

#coin_rsi_o=calc_rsi(dataset_c,0)
#coin_rsi_h=calc_rsi(dataset_c,1)
#coin_rsi_l=calc_rsi(dataset_c,2)
dataset_t=dataset_c.copy()

# Commented out IPython magic to ensure Python compatibility.
# %cd /content/
dataset_t.to_csv('//home/shoujakymn/Desktop/Reguler Code/csv_data/{}_{}.csv'.format(coin,times), index=False)
