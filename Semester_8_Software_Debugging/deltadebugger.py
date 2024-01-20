import re
def remove_html_markup(s):
    tag = False
    quote = False
    out = ""
    for c in s:
        if c == '<' and not quote:    # start of markup
            tag = True
        elif c == '>' and not quote:  # end of markup
            tag = False
        elif c =='"' or c=="'" and tag:
            quote = not quote
        elif not tag:
            out = out + c
 
    assert '<' not in out and '>' not in out
    #assert out.find('<') == -1
    return out
test_count= 0


def test(s):
    global test_count
    test_count = test_count +1;
    print (test_count, s, len(s))
    if re.search("<SELECT[^>]*>", s) != None:
        print("FAIL")
        return "FAIL"
    else:
        print("PASS")
        return "PASS"
def ddmin(s):
    #assert test(s) == "FAIL"
    n = 2     # Initial granularity
    while len(s) >= 2:
        start = 0
        subset_length = int(len(s) / n)
        some_complement_is_failing = False
        while start < len(s):
            complement = s[:start] + s[start + subset_length:]
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
# UNCOMMENT TO TEST
#html_input = '<SELECT>foo</SELECT>'
#html_input = '<SELECT><OPTION VALUE="simplify"><OPTION VALUE ="beatify")></SELECT>'
html_input ='ABCDEFG'
print (ddmin(html_input))