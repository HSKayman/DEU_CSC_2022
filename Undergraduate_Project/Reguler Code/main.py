import argparse
import os

ap=argparse.ArgumentParser()
ap.add_argument("--coin",help="Kendin Bul")
ap.add_argument("--times",help="Kendin Bul")
coin=ap.parse_args().coin
times=ap.parse_args().times


os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/Scrapt_Coin_Price/download-kline.py" -s {} -i {} -startDate 2022-02-15 '.format(coin,times))
os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/Conventer.py" --coin {} --times {}'.format(coin,times))



#
