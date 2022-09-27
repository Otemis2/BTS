from tkinter import*

# Fonction
def affichage() :
    ch=obj2.get()
    obj1.config(text=ch)
    obj2.delete(0,len(ch))

# Programme principal
fen=Tk()

obj1=Label(text="Entrer un texte")
obj1.pack()

obj2=Entry(bg="grey",fg="blue",width=55)
obj2.pack()

obj3=Button(text="Valider",command=affichage)
obj3.pack()

fen.mainloop()
