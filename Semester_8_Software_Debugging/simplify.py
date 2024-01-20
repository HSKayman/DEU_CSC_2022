
import re

def test(s):
   
    if re.search("<SELECT[^>]*>", s) != None :
        return "FAIL"
    else:
        return "PASS"

def simplify(s):
    assert test(s) == "FAIL"
    
    print(repr(s), len(s))
    
    split = int(len(s) / 2)
    s1 = s[:split]
    s2 = s[split:]
    
    if test(s1) == "FAIL":
        return simplify(s1)
    elif test(s2) == "FAIL":
        return simplify(s2)
    return s



#html_input = '<SELECT>foo</SELECT>'
html_input = '''<SELECT><OPTION VALUE="simplify"><OPTION VALUE ="beatify")></SELECT>'''
print(simplify(html_input))