
def remove_html_markup(s):
    tag = False
    quote = False
    out = ""

    for c in s:
        if c == '<' and not quote:    # start of markup
            tag = True
        elif c == '>' and not quote:  # end of markup
            tag = False
        elif (c =='"' or c=="'") and tag:
            quote = not quote
        elif not tag:
            out = out + c
            print(c)
    print(out)
    print('<' not in out,'>' not in out)
    assert '<' not in out and '>' not in out
    return out

# =============================================================================
# def removes_html_markup(s):
#     tag = False
#     quote = False
#     out = ""
#     for c in s:
#         assert tag or not quote #assuring tag = false && quote = true never happens
#         if c == '<' and not quote:
#             tag = True
#         elif c == '>' and not quote:
#             tag = False
#         elif (c == '"' or c == "'") and tag:
#             quote = not quote
#         elif not tag:
#             out = out + c
#     return out
# =============================================================================
#print(remove_html_markup("<a href='>'>Hata olabilir</a>"))
print(remove_html_markup('"<b>foo</b>"'))
#print(remove_html_markup('"<b>"foo"</b>"'))
#print(remove_html_markup('"<b>foo</b>"'))
#print(remove_html_markup("'<b>foo</b>'"))



#print(remove_html_markup("<b>Hello Anaconda</b>"))
#print(remove_html_markup("<a href='>'>Hata olabilir</a>"))
#print(remove_html_markup("<b>'Hata olabilir'</b>"))
#print(remove_html_markup("'<b>Hata olabilir</b>'"))