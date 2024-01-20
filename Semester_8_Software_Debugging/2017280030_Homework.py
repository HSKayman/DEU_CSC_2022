#!/usr/bin/env python

import sys
import copy
from collections import defaultdict
#the buggy program
def remove_html_markup(s):
    tag   = False
    quote = False
    out   = ""

    for c in s:

        if c == '<' and not quote:
            tag = True
        elif c == '>' and not quote:
            tag = False
        elif c == '"' or c == "'" and tag:
            quote = not quote
        elif not tag:
            out = out + c

    return out

# The delta debugger   
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


the_line      = None # yürütülen kodun satır numarası
the_iteration = None # iterasyon sayısı (yürütülen kodun)
the_state     = None # programın durumu ve değişkenler
the_diff      = None
the_input     = None

#Bu fonksiyon, belirtilen satıra ve yinelemeye kadar 
#çalıştırlan fonksiyonu izlemeli ve ardından programın durumunu 
#the_state değişkenine kaydetmelidir.
#istenilen the_line / the_iteration konumunda durun ve frame.f_locals 
#öğesini the_state içinde saklayın.
#frame.f_locals dosyasının bir kopyasını oluşturmak için aşağıdaki ifadeyi kullanabilirsiniz:
# the_state = copy.deepcopy(frame.f_locals)
def trace_fetch_state(frame, event, arg):
    global the_line
    global the_iteration
    global the_state
    #Burayı uygulayın
# =============================================================================
#   My Code
# =============================================================================
    if frame.f_lineno==the_line:
        the_iteration-=1
        if the_iteration==0:
            the_state=copy.deepcopy(frame.f_locals)
            the_line=None  
            return the_line      
# =============================================================================
#   My Code
# =============================================================================
    return trace_fetch_state

#Bu fonksiyon, belirtilen satıra ve yinelemeye kadar çalıştırılan fonksiyonu izlemeli
# ve ardından frame.f_locals değerini the_diff içinde sağlanan değerlerle değiştirmelidir.
#Burada update() kullanmak çok önemlidir. 
#Öğeleri tek tek ayarlarsanız, bazı değişikliklerin kaybolması ihtimali vardır.
# Doğru çalıştığından emin olmak için lütfen aşağıdaki sözdizimini kullanın: 
#frame.f_locals.update(the_diff)
def trace_apply_diff(frame, event, arg):
    global the_line
    global the_diff
    global the_iteration
   #Burayı uygulayın
# =============================================================================
#    My Code
# =============================================================================
    if frame.f_lineno==the_line:
        the_iteration-=1
        if the_iteration==0:
            frame.f_locals.update(the_diff)
            the_line=None
            return the_line  # Don't get called again
# =============================================================================
#   My Code
# =============================================================================
    return trace_apply_diff

# LINE/ITERATION'daki durumu alın
def get_state(input, line, iteration):
    global the_line
    global the_iteration
    global the_state
    
    the_line      = line
    the_iteration = iteration
    
    sys.settrace(trace_fetch_state)
    y = remove_html_markup(input)
    sys.settrace(None)
    
    return the_state




# Test işlevi: Remove_html_output'u çağırın, THE_LINE/THE_ITERATION'da durun 
# ve farkları THE_LINE'da DIFFS'de uygulayın
def test(diffs):
    global the_diff
    global the_input
    global the_line
    global the_iteration

    line      = the_line
    iteration = the_iteration
    
    the_diff = diffs
    sys.settrace(trace_apply_diff)
    y = remove_html_markup(the_input)
    sys.settrace(None)

    the_line      = line
    the_iteration = iteration

    if y.find('<') == -1:
        return "PASS"
    else:
        return "FAIL"
        
html_fail = '"<b>foo</b>"'
html_pass = "'<b>foo</b>'"

locations = [(8, 1), (14, 1), (14, 2), (14, 3), (23, 1)]

def auto_cause_chain(locations):
    global html_fail, html_pass, the_input, the_line, the_iteration, the_diff
    print("The program was started with", repr(html_fail))
    
    for (line, iteration) in locations:


        state_pass = get_state(html_pass,line,iteration)
        state_fail = get_state(html_fail,line,iteration)
    
        # Başarılı ve başarısız koşular arasındaki farkları hesaplayın.
        #ekle işlemi için: diffs.append((var, state_fail[var]))
        diffs = []
        #Burayı uygulayın
# =============================================================================
#      My Code   
# =============================================================================
        for elements in state_fail:
            if (not elements in state_pass)or(not state_pass[elements]==state_fail[elements]):
                diffs.append((elements, state_fail[elements]))
# =============================================================================
#       My Code
# =============================================================================

        # Başarısızlığa neden olan farklılıklar setini en aza indirme
        the_input = html_pass
        the_line  = line
        the_iteration  = iteration
        cause = ddmin(diffs)
        
        # Çıktı 
        print ("Then, in Line " + repr(line) + " (iteration " + repr(iteration) + "),", end =" ")
        for (var, value) in cause:
            print (var, 'became', repr(value), end =" ")
        print()
            
    print ("Then the program failed.")

auto_cause_chain(locations)

# Çıktı şöyle görünmelidir:
"""
The program was started with '"<b>foo</b>"'
Then, in Line 8 (iteration 1), s became '"<b>foo</b>"'
Then, in Line 14 (iteration 1), c became '"'
Then, in Line 14 (iteration 2), quote became True
Then, in Line 14 (iteration 3), out became '<'
Then, in Line 23 (iteration 1), out became '<b>foo</b>'
Then the program failed.
"""