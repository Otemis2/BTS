from math import*
from tkinter import*

#Définition de la classe CEquationSecondDegre
class CEquationSecondDegre:
    def __init__(self,a=0,b=0,c=0):
        self.a=a
        self.b=b
        self.c=c
        self.delta=0
        self.x1=0
        self.x2=0

    def getA(self):
        return self.a

    def getB(self):
        return self.b

    def getC(self):
        return self.c

    def getX1(self):
        return self.x1

    def getX2(self):
        return self.x2

    def setA(self,a):
        self.a=a

    def setB(self,b1):
        self.b=b1

    def setC(self,c1):
        self.c=c1

    def calculerDelta(self):
        self.delta=self.b**2-4*self.a*self.c
        return self.delta

    def calculerRacineReelle(self):
        self.x1=(-self.b-sqrt(self.delta))/(2*self.a)
        self.x2=(-self.b+sqrt(self.delta))/(2*self.a)

    def calculerRacineDouble(self):
        self.x1=-self.b/(2*self.a)
        self.x2=self.x1

monEquation=CEquationSecondDegre()
#Interface graphique

#Commande liée au bouton
def validation():
    global monEquation
    try:
        a=float(entreeA.get())
        b=float(entreeB.get())
        c=float(entreeC.get())
    except:
        labelInfo.config(text="Les coefficients sont mal saisis")
        labelDelta.config(text="Discriminant=")
        labX1.config(text=" ")
        labX2.config(text=" ")
    else:
        monEquation.setA(a)
        monEquation.setB(b)
        monEquation.setC(c)

        delta=monEquation.calculerDelta()
        labelDelta.config(text="Discriminant= "+str(delta))

        if delta > 0 :
            monEquation.calculerRacineReelle()
            labelInfo.config(text="L'équation a deux solutions : ")
            labX1.config(text=str(monEquation.getX1()))
            labX2.config(text=str(monEquation.getX2()))
        elif delta == 0 :
            monEquation.calculerRacineDouble()
            labelInfo.config(text="L'équation a une solutions : ")
            labX1.config(text=str(monEquation.getX1()))
            labX2.config(text=str(monEquation.getX2()))
        else :
            labelInfo.config(text="L'équation n'a pas de solution")
            labX1.config(text=" ")
            labX2.config(text=" ")

#Programme principal
fenetre = Tk()
fenetre.title("Résolution d'une équation du second dégrée")
police = ("Arial",25)

#Création du bandeau
bandeau = Frame(fenetre)

labelA = Label(bandeau,text = "a = ",font=police)
labelA.grid(row = 0,column =0)

entreeA = Entry(bandeau,width=7,font=police)
entreeA.grid(row = 0, column =1)

labelB = Label(bandeau,text = "b = ",font=police)
labelB.grid(row = 0,column =2)

entreeB = Entry(bandeau,width=7,font=police)
entreeB.grid(row = 0, column =3)

labelC = Label(bandeau,text = "c = ",font=police)
labelC.grid(row = 0,column =4)

entreeC = Entry(bandeau,width=7,font=police)
entreeC.grid(row = 0, column =5)

bandeau.pack()


labelInfo=Label (text="Entrez les coefficients",font=police)
labelInfo.pack()

#Création du label delta
labelDelta=Label (text="Discriminant = ",font=police)
labelDelta.pack()

#Création du bandeau solutions
solutions=Frame ()
lab1=Label (solutions, text="X1 = ",font=police)
lab1.grid(row=0,column=0)

labX1=Label (solutions, text="",font=police)
labX1.grid(row=0,column=1)

lab2=Label (solutions, text="X2 = ",font=police)
lab2.grid(row=0,column=2)

labX2=Label (solutions, text="",font=police)
labX2.grid(row=0,column=3)

solutions.pack()

#Création des deux bouttons
valider= Button(text="Valider",command=validation,font=police)
valider.pack()

quitter= Button(text="Quitter",command=fenetre.destroy,font=police)
quitter.pack()

fenetre.mainloop()

"""
a=float(input("Entrer la valeur de a : "))
monEquation.setA(a)

b=float(input("Entrer la valeur de b : "))
monEquation.setB(b)

c=float(input("Entrer la valeur de c : "))
monEquation.setC(c)
delta=monEquation.calculerDelta()
print (delta)

if delta > 0 :
    monEquation.calculerRacineReelle()
    print("L'équation a deux solutions : x1 = ",monEquation.getX1(),
          " et x2 = ",monEquation.getX2())
else :
    if delta == 0 :
        monEquation.calculerRacineDouble()
        print("L'équation a une solutions : x0 = ",monEquation.getX1())
    else :
        print("L'équation n'a pas de solution")"""

    
    


