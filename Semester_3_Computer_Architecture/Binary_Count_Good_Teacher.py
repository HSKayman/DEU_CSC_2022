import itertools
import pprint
for digit in range(2,20):
    gi=list(itertools.product('01',repeat=digit))
    c=0
    i=[]
    while(c<2**(digit-1)):
        i.append(gi[c])
        c+=1
    c=-1
    while(abs(c)<=2**(digit-1)):
        i.append(gi[c])
        c-=1
    leng=len(i[0])-1
    count=0
    while(leng>=0):
        same=i[0][leng]
        for j in i:
            if not j[leng]==same:
                count+=1
                same=j[leng]
        leng-=1
    print("n=",digit,";",count,"tane degisim var ve formulu","=","2^(",digit+1,")-",2*digit,"-1")