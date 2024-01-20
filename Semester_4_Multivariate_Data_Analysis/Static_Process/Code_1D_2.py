import numpy as np
import pandas as pd
import pprint
import matplotlib.pyplot as plt
from scipy import stats
import scipy.stats as st

def detect_outlier(data_1):
    outliers=[]
    threshold=3
    mean_1 = np.mean(data_1)
    std_1 =np.std(data_1)
    
    
    for y in data_1:
        z_score= (y - mean_1)/std_1 
        if np.abs(z_score) > threshold:
            outliers.append(y)
    return outliers

# =============================================================================
# CONVERTING CSV TO DATAFRAME
# =============================================================================

data = pd.read_csv('data1.csv', error_bad_lines=False,warn_bad_lines=True)
a = list(data.columns.values)[0]
data_text = data[['{}'.format(a)]]
data_text['index'] = data_text.index
label = data_text
inputs = []
for i in range(len(label)):
    inputs.append(label[label['index'] == i].values[0][0])

# =============================================================================
# PRINTING THE DESCRIPTIVE STATISTICES IN A PYTHON DICTIONARY
# =============================================================================

dic = {"Sum of Values": sum(inputs),
       "Maximum Value": np.amax(inputs), 
       "Minimum Value": np.amin(inputs), 
       "Number of Observations": len(inputs), 
       "Mean": np.mean(inputs), 
       "Mode": stats.mode(inputs), 
       "Median": np.median(inputs),
       "Sample Standard Deviation": np.std(inputs, ddof=1),
       "Range": np.ptp(inputs),
       "Inter-quartile Range": np.percentile(inputs,75)-np.percentile(inputs,25),
       "25th Percentile": np.percentile(inputs,25),
       "50th Percentile": np.percentile(inputs,50), 
       "75th Percentile": np.percentile(inputs,75), 
       "Skewness": stats.skew(inputs),
       "Kurtosis": stats.kurtosis(inputs),
       "95% confidence interval": st.t.interval(0.95, len(inputs)-1, loc=np.mean(inputs), scale=st.sem(inputs)),
       "99% confidence interval": st.t.interval(0.99, len(inputs)-1, loc=np.mean(inputs), scale=st.sem(inputs)),
       "posibble outliers": detect_outlier(inputs)}

# =============================================================================
# CREATING THE FIGURES
# =============================================================================
#
# BOX PLOT

fig = plt.figure(figsize=(6,3))
b1 = fig.add_subplot(1,1,1)
b1.boxplot(inputs)
b1.set_title('Box Plot of {}\n'.format(a))
plt.show()

# HISTOGRAM AND CUMULATIVE HISTOGRAM FOR LABEL

fig = plt.figure(figsize=(6,3))
h1 = fig.add_subplot(1, 2, 1)
h1.hist(inputs)
h1.set_title('Historgram of {}\n'.format(a))
h2 = fig.add_subplot(1, 2, 2)
h2.hist(inputs, cumulative=True)
h2.set_title('Cum. Histogram of {}\n'.format(a))
plt.show()

print("\n\n DESCRIPTIVE STATISTICS FOR {}\n\n".format(a))
pprint.pprint(dic)