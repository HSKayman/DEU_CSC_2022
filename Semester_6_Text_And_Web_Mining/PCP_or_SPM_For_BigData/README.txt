1. You can write "python3 Main.py" to run the code. The code starts with importing the relevant libraries. Then it first reads the data.
2.	Data set should be placed in Data workfile and its name has to be entered in line 8.
3.	Then the code preprocess the data by calling Preprocessor.py code.
    a. It categorizes the data accroding to the class types.
    b. It fills in the blank cells where non-string null cells are filled with mean of the data. Null string cells are filled with the one that has the highest frequency.
    c. it encodes the strings and assigns them numerical values.
    d. it saves the dataset as {Dataset Name}_pp.csv
    e. Finally, it normalizes the data and save it as {Dataset Name}_pp_norm.csv
4. It runs the metrics separately by calling corresponding pyhton files. All calculations and orderings are done within these subcodes.
	a. Metric 1: calculates the number of putliers with K-nearest neighbours algorithm.
	b. Metric 2: calculates the number of outliers with pearson correlation.
	c. Metric 3: calculates the number of outliers with Euclidean Norm.
5. Each code for the metrics calls the figure_plotter.py to be able to draw the figures.
6. It orders the results according to the percentage of outliers.
Finally, it prints out all the results that are sorted according to the percentage of outliers i.e. 

Metric_1: KNN 
Metric_2: Pearson Correlation
Metric_3:Euclidean Distance

Metric_1.0-->Outlier%6.533333333333332 For PCP
Metric_2.0-->Outlier%6.666666666666667 For PCP
Metric_2.0-->Outlier%7.733333333333333 For SP
Metric_3.0-->Outlier%7.733333333333333 For PCP
Metric_1.0-->Outlier%7.866666666666666 For SP
Metric_3.0-->Outlier%7.866666666666666 For SP
Best figure for asdas is PCP with Metric_1. Percentage of outliers is %6.533333333333332
 7. The final line points out the best choice.

 8. The results for each dataset is provided in the zip file; however, since the 3rd and 4th datasets are too big, I am sharing the results with subsamples.