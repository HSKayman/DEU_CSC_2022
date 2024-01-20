#https://nerdland.net/the-lottery-problem/
#https://yalansavar.org/2016/03/31/bu-tesaduf-olamaz/
'''
hitmn=6 # bir kolonda kac sayi olmasi gerektigi
to=1   # lotonun alt siniri
uto=14  #lotonun ust siniri
strike=4 # kac tane turmasi gerektigi
import itertools
a=list(itertools.combinations(range(to,uto),hitmn))
i=0
b=[]
while i<len(a):
    z=itertools.combinations(a[i],strike)
    for x in z:
        if x in b:
            pass
        else:
            b.append(x)
    i+=1
'''
from pprint import pprint as p
import itertools
"""

a=list(itertools.combinations(range(10),4))
p(a)
print(len(a))
b=list(itertools.combinations(range(6),4))
p(b)
print(len(a)/len(b))

sumi=0
r=10
t=6
m=4
k=m
while not k==t:    
    print(sumi)
    sumi+=int(len(list(itertools.combinations(range(t),k))))*int(len(list(itertools.combinations(range(r-t),t-k))))
    k+=1
print(sumi)
"""
a=list(itertools.combinations(range(10),4))
p(a)