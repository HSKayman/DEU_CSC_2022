import sys
def remove_html_markup(s):
    tag = False
    quote = False
    out = ""

    for c in s:
        assert tag or not quote
        if c == '<' and not quote:    # start of markup
            tag = True
        elif c == '>' and not quote:  # end of markup
            tag = False
        elif (c =='"' or c=="'") and tag:
            quote = not quote
        elif not tag:
            out = out + c
 
    return out

stepping = True
breakpoints = {9:True,14:True}
watchpoints = {}

def debug(command,my_arg,my_locals):
    global stepping
    global breakpoints
    
    if command.find(' ')>0:
        arg = command.split(' ')[1]
    else:
        arg = None
    
    if command.startswith('s'): #step
        stepping = True
        return True
    elif command.startswith('c'): #continue
        stepping = False
        return True
    elif command.startswith('p'):    # print
        if arg==None:
            print(repr(my_locals))
        else:
            if arg in my_locals:
              print (arg+" = "+repr(my_locals[arg]))
            else:
                 print ('No such variable:', arg)
        return True;
    elif command.startswith('b'):   #breakpoint
        if arg==None:
            print("You must supply a line number")
        else:
            breakpoints[int(arg)]=True
        return True
    elif command.startswith('w'):   # watchpoint
        if arg==None:
            print ("You must supply a variable name")
        else:
            watchpoints[arg]=True
        return True
    elif command.startswith('q'):
        sys.exit(0)
    else:
        print("No such command",repr(command))
    
def input_command():
    command = input("(my-spyder)")
    return command

def traceit(frame, event, arg):
    #print(event,frame.f_lineno,frame.f_code.co_name,frame.f_locals)
    global stepping
    global breakpoints
    if event == "line":
        if stepping or frame.f_lineno in breakpoints:
            resume = False
            while not resume:    
                print(event,frame.f_lineno,frame.f_code.co_name,frame.f_locals)
                command = input_command()
                resume = debug(command,arg,frame.f_locals)
    return traceit

def remove_html_markup_traced(s):
    sys.settrace(traceit)
    ret = remove_html_markup(s)
    sys.settrace(None)
    return ret

ret = remove_html_markup_traced('xyz')
print(ret)
