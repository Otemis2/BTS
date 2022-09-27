from tkinter import *

#FONCTIONS
def plus():
    global nb
    nb=nb+1
    l.config(text=nb)
    print(nb)
    
#PROGRAMME PRINCIPAL

fen=Tk() 
nb=0
l=Label(text=nb)
l.pack()
b=Button(text="Incrémenter",command=plus) 
b.pack()

fen.mainloop() 

