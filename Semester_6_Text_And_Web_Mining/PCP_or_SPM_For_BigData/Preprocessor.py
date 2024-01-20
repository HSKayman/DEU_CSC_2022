# =============================================================================
# importing relevant libraries
# =============================================================================

import numpy as np 
import pandas as pd 
from sklearn.impute import SimpleImputer 
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import StandardScaler 

with open('DataSets_Name.txt') as f:
    
    x =str(f.readlines()[0])
f.close()

Data_Frame=pd.read_csv('Data/{}.csv'.format(x))
Tenative_Data_Frame=np.transpose(Data_Frame.values)
i=0
string_columns=[]
other_columns=[]

#categorize the types of classes
while i<len(Data_Frame.columns):
    if "<class 'str'>"==str(type(Tenative_Data_Frame[i][0])):
        string_columns.append(i)
    elif not False in pd.isna(Tenative_Data_Frame[i]):
        Data_Frame=Data_Frame.iloc[:,[y for y in range(int(len(Data_Frame.columns))) if not y==i]]
    else:
        other_columns.append(i)
    i+=1

#Fill in the null cells for non-string data
if int(len(other_columns))>0:
    imputer = SimpleImputer(missing_values=np.nan, strategy='mean')
    imputer = imputer.fit(Data_Frame.iloc[:,other_columns])
    Data_Frame.iloc[:,other_columns]=imputer.transform(Data_Frame.iloc[:,other_columns])

#Fill in the null cells for string data
if int(len(string_columns))>0:
    imputer = SimpleImputer(missing_values=np.nan, strategy="most_frequent")
    imputer = imputer.fit(Data_Frame.iloc[:,string_columns])
    Data_Frame.iloc[:,string_columns]=imputer.transform(Data_Frame.iloc[:,string_columns])
    labelencoder = LabelEncoder()

#encode strings as numerical values
i=0
while int(len(string_columns))>i:         
    Data_Frame.iloc[:,string_columns[i]] = labelencoder.fit_transform(Data_Frame.iloc[:,string_columns[i]])
    i+=1

#save the preprocessed data
Columns=Data_Frame.columns
df =pd.DataFrame(Data_Frame)
df.columns=Columns
df.to_csv('{}/{}_pp.csv'.format(x,x), index=False)

#save to csv
sc_X = StandardScaler()
Data_Frame= sc_X.fit_transform(Data_Frame)
df =pd.DataFrame(Data_Frame)
df.columns=Columns
df.to_csv('{}/{}_pp_norm.csv'.format(x,x), index=False)
print("PreProcessing is Finished")
