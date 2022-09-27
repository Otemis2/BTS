from tkinter import *#"Du module tkinter importer tout"
#Programme principal
fenetre=Tk() #Instanciation de la classe Tk() : root est un objet (fenetre)

zoneTexte=Text(fenetre,width=100,height=30) #taille en caractères
zoneTexte.grid(row=0,column=0)

#Construction du Menu et des sous-menus

menu=Menu(fenetre)
sm1=Menu(fenetre)
menu.add_cascade(label="Fichier" ,menu=sm1)
sm1.add_command(label="Ouvrir" ,command=None)
sm1.add_command(label="enregistrer" ,command=None)
sm1.add_command(label="quitter" ,command=fenetre.destroy)

fenetre.config(menu=menu,whidth=150)
fenetre.title("edition de texte")
fenetre.mainloop()
