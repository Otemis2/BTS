from tkinter import*
import random

def deplacer(evnt):
    global yfruit,xfruit,rectangle,score,ymanger,xmanger
    ymanger=yfruit-evnt.y
    xmanger=xfruit-evnt.x
    if (ymanger<=15 and xmanger<=10 and ymanger>=-15 and xmanger>=-10):
        score=score+1
        print(score)
        if (score==10):
            can.create_text(250,250,text=("vous avez marquez 10 points !"),fill="red",font=("Arial",25))
        else :
            can.delete(rectangle)
            yfruit=random.randint(0,500) #genere aleatoirement un nombre entre 0 et 500 pour la coordonée y
            xfruit=random.randint(0,500) #genere aleatoirement un nombre entre 0 et 500 pour la coordonée x
            rectangle=can.create_rectangle(xfruit-10,yfruit-15,xfruit+10,yfruit+15,fill="red") #cree l'objet "point" qui sera l'objectif a mangé
            print(yfruit,xfruit)


##programe principal
fen=Tk()
#j'initialise mes variables
yfruit=0
xfruit=0
score=0
#debut
can=Canvas(height=500,width=500)
can.pack()
deplacement="Left"


yfruit=random.randint(0,500) #genere aleatoirement un nombre entre 0 et 500 pour la coordonée y
xfruit=random.randint(0,500) #genere aleatoirement un nombre entre 0 et 500 pour la coordonée x
rectangle=can.create_rectangle(xfruit-10,yfruit-15,xfruit+10,yfruit+15,fill="red") #cree l'objet "point" qui sera l'objectif a mangé
print(yfruit,xfruit)


can.bind('<Double-Button-1>',deplacer)
can.focus_set()
fen.mainloop()
