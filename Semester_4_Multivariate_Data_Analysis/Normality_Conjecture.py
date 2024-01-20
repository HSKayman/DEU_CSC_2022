import seaborn as sns
import scipy.stats as st
import pylab
diamonds = sns.load_dataset('tips')
df=diamonds.copy().select_dtypes(["float64","int64"]).values.T
for x in df:
    st.probplot(x,dist="norm",plot=pylab)
    pylab.show()