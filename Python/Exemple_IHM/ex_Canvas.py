# -*- coding: cp1252 -*-
from tkinter import*

Fenetre=Tk()    
Fenetre.title("Mon programme en Tkinter")

zone_dessin = Canvas(Fenetre,width=500,height=500,bg='yellow',bd=8,relief="ridge")
zone_dessin.pack() 
 
zone_dessin.create_line(0,0,499,499,fill='red',width=4) 
zone_dessin.create_line(0,499,499,0,fill='red',width=4) 
zone_dessin.create_rectangle(150,150,350,350) 
zone_dessin.create_oval(150,150,350,350,fill='blue',width=4) 
 
bouton_sortir= Button(Fenetre,text="Sortir",command=Fenetre.destroy)
bouton_sortir.pack()
  
Fenetre.mainloop() 

