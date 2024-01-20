import random

def fuzzer():
    string_length = int(random.random()*10)
    out =""
    for i in range(0,string_length):
        c = chr(int(random.random()*96+32))
        out = out + c
    return out

def msytery_test(s):
    try:
        s.index(".")
    except:
        return "PASS"
    else:
        return "FAIL"

def ddmin(s):
    assert msytery_test(s) == "FAIL"
    print(s)
    n = 2     # Initial granularity
    while len(s) >= 2:
        start = 0
        subset_length = int(len(s) / n)
        
        some_complement_is_failing = False
        while start < len(s):
            complement = s[:start] + s[start + subset_length:]
            print(s,subset_length,)
            if msytery_test(complement) == "FAIL":
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
    
print(ddmin(fuzzer()))

