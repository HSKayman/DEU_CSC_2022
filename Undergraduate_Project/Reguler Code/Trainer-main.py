import json
import os
def load_config():
    with open('config.json') as f:
        return json.load(f)


config = load_config()

#Download
for coin in config['Coins']:
    for timestamp in config['Timestamps']: 
        os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/main.py" --coin {} --times {}'.format(coin,timestamp))

#Indicators Process
for coin in config['Coins']:
    for timestamp in config['Timestamps']: 
        for ind in config['Indicators']:
            os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/Indicators.py" --data {} --time {} --Ind {} '.format(coin,timestamp,ind))
 
#Train Process
for coin in config['Coins']:
    for timestamp in config['Timestamps']: 
        for ind in config['Indicators']:
            os.system('python3 "/home/shoujakymn/Desktop/Reguler Code/Trainer.py" --data {} --time {} --Ind {} '.format(coin,timestamp,ind))
 

