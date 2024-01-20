import numpy as np
import pandas as pd
import pprint
import matplotlib.pyplot as plt
import statsmodels.api as sm
from scipy import stats
import scipy.stats as st

# =============================================================================
# CONVERTING CSV TO DATAFRAME
# =============================================================================

data=pd.read_csv('data2.csv', error_bad_lines=False)
a=list(data.columns.values)[0]
b=list(data.columns.values)[1]
data_text = data[['{}'.format(a)]]
data_text2 = data[['{}'.format(b)]]
data_text['index'] = data_text.index
data_text2['index'] = data_text2.index
label1 = data_text
label2 = data_text2
inputs = {"0" : [],
          "1" : []}
for i in range(len(label1)):
    inputs["0"].append(label1[label1['index'] == i].values[0][0])
    inputs["1"].append(label2[label2['index'] == i].values[0][0])

# =============================================================================
# PRINTING THE DESCRIPTIVE STATISTICES FOR LABEL 1 IN A PYTHON DICTIONARY
# =============================================================================

dic1 = {"Sum of All Values": sum(inputs["0"]),
       "Maximum Value":np.amax(inputs["0"]), 
       "Minimum Value": np.amin(inputs["0"]), 
       "Number of Observations": len(inputs["0"]), 
       "Mean":np.mean(inputs["0"]), 
       "Mode": stats.mode(inputs["0"]), 
       "Median": np.median(inputs["0"]),
       "Sample Standard Deviation" :np.std(inputs["0"], ddof=1),
       "Range": np.ptp(inputs["0"]),
       "Inter-quartile Range": np.percentile(inputs["0"],75)-np.percentile(inputs["0"],25),
       "25th Percentile": np.percentile(inputs["0"],25),
       "50th Percentile": np.percentile(inputs["0"],50), 
       "75th Percentile": np.percentile(inputs["0"],75), 
       "Skewness": stats.skew(inputs["0"]),
       "Kurtosis": stats.kurtosis(inputs["0"]),
       "95% Confidence Interval": st.t.interval(0.95, len(inputs["0"])-1, loc=np.mean(inputs["0"]), scale=st.sem(inputs["0"])),
       "99% confidence interval": st.t.interval(0.99, len(inputs["0"])-1, loc=np.mean(inputs["0"]), scale=st.sem(inputs["0"]))}

# =============================================================================
# PRINTING THE DESCRIPTIVE STATISTICES FOR LABEL 2 IN A PYTHON DICTIONARY
# =============================================================================

dic2 = {"Sumof All Values": sum(inputs["1"]),
       "Maximum Value":np.amax(inputs["1"]), 
       "Minimum Value": np.amin(inputs["1"]), 
       "Number of Observations": len(inputs["1"]), 
       "Mean":np.mean(inputs["1"]), 
       "Mode": stats.mode(inputs["1"]), 
       "Median": np.median(inputs["1"]),
       "Sample Standard Deviation" :np.std(inputs["1"], ddof=1),
       "Range": np.ptp(inputs["1"]),
       "Inter-quartile Range": np.percentile(inputs["1"],75)-np.percentile(inputs["1"],25),
       "25th Percentile": np.percentile(inputs["1"],25),
       "50th Percentile": np.percentile(inputs["1"],50), 
       "75th Percentile": np.percentile(inputs["1"],75), 
       "Skewness": stats.skew(inputs["1"]),
       "Kurtosis": stats.kurtosis(inputs["1"]),
       "95% Confidence Interval": st.t.interval(0.95, len(inputs["1"])-1, loc=np.mean(inputs["1"]), scale=st.sem(inputs["1"])),
       "99% confidence interval": st.t.interval(0.99, len(inputs["1"])-1, loc=np.mean(inputs["1"]), scale=st.sem(inputs["1"]))}

# =============================================================================
# CORRELATIOND AND COVARIANCE ANALYSIS
# =============================================================================

dic3 = {"Covariance": np.cov(inputs["0"], inputs["1"]),
        "Pearson Correlation": stats.pearsonr(inputs["0"], inputs["1"]),
        "spearman Correlation": stats.spearmanr(inputs["0"], inputs["1"]),
        "Regression Equation": stats.linregress(inputs["0"], inputs["1"])}

# =============================================================================
# CREATING THE IMAGES
# =============================================================================

# BOX PLOTs

fig = plt.figure(figsize=(12,6))
b1 = fig.add_subplot(1, 2, 1)
b1.boxplot(inputs["0"])
b1.set_title('Box Plot for {} data\n'.format(a[:]))
b2 = fig.add_subplot(1, 2, 2)
b2.set_title('Box Plot for {} data\n'.format(b[:]))
b2.boxplot(inputs["1"])
plt.show()

# HISTOGRAMS AND CUMULATIVE HISTOGRAM FOR LABEL 1

fig = plt.figure(figsize=(12, 6))
h1 = fig.add_subplot(1, 2, 1)
h1.hist(inputs["0"])
h1.set_title('Histogram of {}\n'.format(a[:]))
h2 = fig.add_subplot(1, 2, 2)
h2.hist(inputs["0"], cumulative=True)
h2.set_title('Cum. Histogram for {}\n'.format(a[:]))
plt.show()

# HISTOGRAMS AND CUMULATIVE HISTOGRAM FOR LABEL 2

fig = plt.figure(figsize=(12, 6))
h1 = fig.add_subplot(1, 2, 1)
h1.hist(inputs["1"])
h1.set_title('Histogram of {}\n'.format(b[:]))
h2 = fig.add_subplot(1, 2, 2)
h2.hist(inputs["1"], cumulative=True)
h2.set_title('Cum. Histogram for {}\n'.format(b[:]))
plt.show()
#
## SCATTER PLOT
#
#results = sm.OLS(inputs["0"],sm.add_constant(inputs["1"])).fit()
#print("\n\n",results.summary())
#plt.scatter(inputs["0"],inputs["1"])
#X_plot = np.linspace(min(dic1["Minimum Value"],dic["Minimum Value"]),max(dic1["Maximum Value"],dic["Maximum Value"]),dic["Number of Observations"])
#plt.plot(X_plot, X_plot*results.params[0] + results.params[1])
#plt.show()
##
#
print("\n\n DESCRIPTIVE STATISTICS FOR {} data\n\n".format(a[:]))
pprint.pprint(dic1)

print("\n\n DESCRIPTIVE STATISTICS FOR {} data\n\n".format(b[:]))
pprint.pprint(dic2)

print("\n\n Results of Covariance and Correaltion Analysis \n\n")
pprint.pprint(dic3)
#print("\n\n\n-----------------------------CMB OTP-----------------------------\n\n")
#pprint.pprint(dic2)




