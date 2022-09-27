from tkinter import*

fen=Tk()
fen.title("Ma fenêtre")
fen.geometry("200x100")

obj1=Label(text="zone de texte",bg="blue",fg="yellow",bd=3)
obj1.pack()

obj2=Label(bitmap="question",bg="red",fg="grey",bd=11,relief=GROOVE)
obj2.pack()

fen.mainloop()
