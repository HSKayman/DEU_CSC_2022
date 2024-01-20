patches = [ 1,2,3,4,5,6,7,8]

def test(s):
    #print(repr(s),len(s))
    if 3 in s and 6 in s:
        #print("FAIL")
        return "FAIL"
    else:
        #print("PASS")
        return "PASS"
    
#print(test(patches))
#print(test([]))
    
def ddmin(s,test):
    assert test(s) == "FAIL"
    n = 2     # Initial granularity
    while len(s) >= 2:
        start = 0
        subset_length = int(len(s) / n)
        some_complement_is_failing = False
        while start < len(s):
            complement = s[:start] + s[start + subset_length:]
            print(complement)
            if test(complement) == "FAIL":
                s = complement
                n = max(n - 1, 2)
                some_complement_is_failing = True
                break                
            start += subset_length
        if not some_complement_is_failing:
            if len(s) == n:
                break
            n = min(n * 2, len(s))
    return s

print(ddmin(patches,test))
