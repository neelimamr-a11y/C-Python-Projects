from tkinter import *
window=Tk(className="my App")
window.geometry("370x400")
window.configure(bg="black")
    
display=Entry(window,font=("Arial",20),justify="right")
display.grid(row=0,column=0,columnspan=4)
def press(value):
    display.insert(END,value)
def clear():
    display.delete(0,END)
def delete():
    x= display.get()
    display.delete(0, END)
    display.insert(0,x[:-1])
def equal():
    exp = display.get()
    if "+" in exp:
        a, b = exp.split("+")
        result = int(a) + int(b)
    elif "-" in exp:
        a, b = exp.split("-")
        result = int(a) - int(b)
    elif "*" in exp:
        a, b = exp.split("*")
        result = int(a) * int(b)
    elif "/" in exp:
        a, b = exp.split("/")
        result = int(a) / int(b)
    display.delete(0, END)
    display.insert(0, result)


Button(window,text="C",height=3,width=16,command=clear).grid(row=1,column=0,columnspan=2)
Button(window,text="DEL",height=3,width=16,command=delete).grid(row=1,column=2,columnspan=2)

Button(window,text="/",height=3,width=8,command=lambda:press("/")).grid(row=2,column=0)
Button(window,text="*",height=3,width=8,command=lambda:press("*")).grid(row=2,column=1)
Button(window,text="7",height=3,width=8,command=lambda:press("7")).grid(row=2,column=2)
Button(window,text="8",height=3,width=8,command=lambda:press("8")).grid(row=2,column=3)

Button(window,text="9",height=3,width=8,command=lambda:press("9")).grid(row=3,column=0)
Button(window,text="-",height=3,width=8,command=lambda:press("-")).grid(row=3,column=1)
Button(window,text="4",height=3,width=8,command=lambda:press("4")).grid(row=3,column=2)
Button(window,text="5",height=3,width=8,command=lambda:press("5")).grid(row=3,column=3)

Button(window,text="6",height=3,width=8,command=lambda:press("6")).grid(row=4,column=0)
Button(window,text="+",height=3,width=8,command=lambda:press("+")).grid(row=4,column=1)
Button(window,text="1",height=3,width=8,command=lambda:press("1")).grid(row=4,column=2)
Button(window,text="2",height=3,width=8,command=lambda:press("2")).grid(row=4,column=3)

Button(window,text="3",height=3,width=8,command=lambda:press("3")).grid(row=5,column=0)
Button(window,text=".",height=3,width=8,command=lambda:press(".")).grid(row=5,column=1)
Button(window,text="0",height=3,width=8,command=lambda:press("0")).grid(row=5,column=2)
Button(window,text="%",height=3,width=8,command=lambda:press("%")).grid(row=5,column=3)

Button(window,text="=",height=3,width=16,command=equal).grid(row=6,column=0,columnspan=2)
window.mainloop()