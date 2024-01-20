#assert 2+2 == 5
import math
import random
# def sqrt(x):
#     assert x>=0
#     y=math.sqrt(x)
#     assert y*y == x
#     return y

# for i in range(1,1000):
#     r=random.random()*10000
#     try:    
#         z=sqrt(r)
#     except:
#         print(r,r-math.sqrt(r)*math.sqrt(r))
#         break
# print ("Done!")
def sqrt(x,eps = 10E-7):
    assert x>=0
    y=math.sqrt(x)
    assert abs(y*y-x)<eps
    return y

for i in range(1,1000):
    r=random.random()*10000
    z=sqrt(r)

print ("Done!")



