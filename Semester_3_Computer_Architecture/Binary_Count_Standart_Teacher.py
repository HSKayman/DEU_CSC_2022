import itertools
eq=3
for digit in range(1,20):
    i=list(itertools.product('01',repeat=digit))
    leng=len(i[0])-1
    count=0
    while(leng>=0):
        same=i[0][leng]
        for j in i:
            if not j[leng]==same:
                count+=1
                same=j[leng]
        leng-=1
    print("n=",digit,";",count,"tane degisim var ve formulu","=","2^(",(digit),"+1)-",eq)
    eq=eq+1
    