import itertools
import pprint
for digit in [3]:
    gi=list(itertools.product('01',repeat=digit))
    k=0
    c=0
    i=[]
    while(c<2**(digit-1)):
        c+=1
        i.append(gi[k])
        if(k>=0):
            k+=1
        else:
            k-=1
        k*=-1
    if(digit<=1):
        k=-1
        c=0
    else:
        k*=-1
        k-=1
        c=0
    while(c<2**(digit-1)):
        c+=1
        i.append(gi[k])
        k*=-1
        if(k>=0):
            k-=1
        else:
            k-=2
    leng=len(i[0])-1
    pprint.pprint(i)
    count=0
    while(leng>=0):
        same=i[0][leng]
        for j in i:
            if not j[leng]==same:
                count+=1
                same=j[leng]
        leng-=1
    print("n=",digit,";",count,"tane degisim var.")