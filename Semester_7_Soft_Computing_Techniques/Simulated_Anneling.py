from numpy import asarray
from numpy.random import randn
from numpy.random import rand
from numpy.random import seed
from numpy import arange
from matplotlib import pyplot as plt
import math
# def Temp(iteration):
#     return 20*(0.9**iteration)


# def simulated_Anneling(Array):
#     index=np.random.randint(1,99)
#     i=0
#     opt=5
#     while Temp(i)>0.001:
#         print(index,Array[index])
#         if index<4 or index>95:
#             index=int(len(Array))//2
            
#         if Array[opt]<Array[index]:
#             opt=index
            
#         j=np.random.randint(-4,4)
#         if Array[index]<Array[index+1]:
#             index+=1
#         elif Array[index]<Array[index-1]:
#             index-=1
#         elif math.exp(-1*abs(Array[index+j]-Array[index+j])/Temp(i))>np.random.rand():
#             index+=j
#         i+=1
#     return opt


# A=np.random.randn(100)*100+1
# plt.plot(A)
# print(A[simulated_Anneling(A)])
def objective(x):
	return x[0]**2.0

# simulated annealing algorithm
def simulated_annealing(bounds, n_iterations, step_size, temp):
    X=[]
    Y=[]
    best = bounds[:, 0] + rand(len(bounds)) * (bounds[:, 1] - bounds[:, 0])
    best_eval = objective(best)
    curr, curr_eval = best, best_eval
	
    for i in range(n_iterations):
        candidate = curr + randn(len(bounds)) * step_size
        candidate_eval = objective(candidate)
        if candidate_eval < best_eval:
            best, best_eval = candidate, candidate_eval
            X.append(best)
            Y.append(best_eval)
            print('>%d f(%s) = %.5f' % (i, best, best_eval))
		
        diff = candidate_eval - curr_eval
        t = temp / float(i + 1)
        metropolis = math.exp(-diff / t)
        #print("candidate {} {},\nCur {} {} ,\nt met {} {}".format(candidate, candidate_eval,curr, curr_eval,t,metropolis))
        if diff < 0 or rand() < metropolis:
            curr, curr_eval = candidate, candidate_eval
        #input()
    return [X,Y,best, best_eval]



#seed(5)
X,Y,best, score = simulated_annealing(asarray([[-5.0, 5.0]]), 100,1,10)
print('Done!')
print('f(%s) = %f' % (best, score))
fig, ax = plt.subplots()
inputs = arange(-10.0, 10.0, 0.1)
ax.plot(inputs,  [objective([x]) for x in inputs])
plt.plot(X, Y, color='green', linestyle='dashed', linewidth = 3,
         marker='o', markerfacecolor='red', markersize=12)

plt.show()
