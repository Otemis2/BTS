# -*- coding: cp1252 -*-
from tkinter import*

fen=Tk()

l=Label(text="ligne 0 colonne 0 ") 
l.grid(column=0,row=0)
s=Entry(width=5)
s.grid(column=0,row=1,sticky="W")
l2=Label(text="ligne 1 colonne 1 ") 
l2.grid(column=1,row=1)
b=Button(text="bouton 1 ") 
b.grid(column=0,row=2,columnspan=2)

fen.mainloop()

