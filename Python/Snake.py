from tkinter import*

#Fonctions et procédures

def deplacer(event):
    global x,y
    #print(event.keysym) Affiche sur le console ce qui est renvoyer
    if event.keysym == "Up":
        y=y-5
        can.coords(objet,x-10,y-10,x+10,y+10)
    elif event.keysym == "Down":
        y=y+5
        can.coords(objet,x-10,y-10,x+10,y+10)
    elif event.keysym == "Left":
        x=x-5
        can.coords(objet,x-10,y-10,x+10,y+10)
    elif event.keysym == "Right":
        x=x+5
        can.coords(objet,x-10,y-10,x+10,y+10)


        #can.coords(objet,x3,y3,x4,y4)
        #can.after(1,deplacer(event))

#Programe principal

fen=Tk()

can=Canvas(height=500,width=500,bd = 2 ,bg = "#08b41d")

can.pack()

x=250
y=250
objet = can.create_oval(x-10,y-10,x+10,y+10,fill="yellow",outline="red",width = 2)


can.bind("<Key>",deplacer)
can.focus_set()

#can.config(bd = 2 ,bg = "#08b41d")
fen.mainloop()
