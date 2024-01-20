import seaborn as sns
import statistics as st
diamonds = sns.load_dataset('diamonds')
df=diamonds.copy().select_dtypes(["float64","int64"])

#print(df.corr())


def correlation(dataFrame):
    for i in df.isnull().sum():
        if(int(i)!=0):
            return -1
    lenght=int(len(dataFrame.columns))
    dataFrame=dataFrame.values.T
    result=[[1 for j in range(lenght)] for i in range(lenght)]
    avg=[st.mean(dataFrame[i]) for i in range(lenght)]
    i=0
    while(i<lenght):
        j=i+1
        while(j<lenght):
            result[i][j]=sum(list(map(lambda x,y:abs((x-avg[i])*(y-avg[j])),dataFrame[i],dataFrame[j])))
            result[i][j]/=abs(sum(list(map(lambda x:(x-avg[i])**2,dataFrame[i])))*sum(list(map(lambda x:(x-avg[j])**2,dataFrame[j]))))**(0.5)
            result[j][i]=result[i][j]
            j+=1
        i+=1
    return result


result=correlation(df)
print(result)
            