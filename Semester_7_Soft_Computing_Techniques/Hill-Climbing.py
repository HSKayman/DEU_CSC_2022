# hill climbing search of a one-dimensional objective function
from numpy import asarray
from numpy.random import randn
from numpy.random import rand
from numpy.random import seed
from numpy import arange
from matplotlib import pyplot as plt

def objective(x):
	return x[0]**2.0

def hillclimbing( bounds, n_iterations, step_size):
    X=[]
    Y=[]
    solution = bounds[:, 0] + rand(len(bounds)) * (bounds[:, 1] - bounds[:, 0])
    solution_eval = objective(solution)  
    for i in range(n_iterations):
        candidate = solution + randn(len(bounds)) * step_size
        candidte_eval = objective(candidate)
        if candidte_eval <= solution_eval:
            solution, solution_eval = candidate, candidte_eval
            print('>%d f(%s) = %.5f' % (i, solution, solution_eval))
            X.append(solution)
            Y.append(solution_eval)
    return [X,Y,solution, solution_eval]




seed(5)

X,Y,best, score = hillclimbing(asarray([[-5.0, 5.0]]), 1000,0.1)
print('Done!')
print('f(%s) = %f' % (best, score))
fig, ax = plt.subplots()
inputs = arange(-5.0, 5.0, 0.1)
ax.plot(inputs,  [objective([x]) for x in inputs])
plt.plot(X, Y, color='green', linestyle='dashed', linewidth = 3,
         marker='o', markerfacecolor='red', markersize=12)

plt.show()
