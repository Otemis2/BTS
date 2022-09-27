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

#Programme principal
monEquation=CEquationSecondDegre()

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
        print("L'équation n'a pas de solution")

    
    


