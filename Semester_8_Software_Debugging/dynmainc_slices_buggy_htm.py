import sys

def remove_html_markup(s):
    tag   = False
    quote = False
    out   = ""

    for c in s:
        if c == '<' and not quote:
            tag = True
        elif c == '>' and not quote:
            tag = False
        elif c == '"':
            quote = not quote
        elif not tag:
            out = out + c

    return out

def traceit(frame, event, arg):
    if event == "line":
        filename = frame.f_code.co_filename
        lineno = frame.f_lineno
        print(open(filename).readlines()[lineno-1])

    return traceit

def test():
    sys.settrace(traceit)
    remove_html_markup('"<')
    sys.settrace(None)

test()

