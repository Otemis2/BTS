from tkinter import *#"Du module tkinter importer tout"
from tkinter import filedialog
import csv

#Fonction
def ouvrir():
    zoneTexte.delete("0.0","end")#Pour effacer tout le contenu de la zone de texte
    ligne=1
    global chemin
    chemin=filedialog.askopenfilename(filetypes = [("All", "*"),("Fichier Python","*.py;*.pyw")])
    #print(chemin)
    fichierSource=open(chemin,'r',encoding="utf-8")
    with open(chemin, newline='') as csvfile:
        lecteur = csv.reader(csvfile, delimiter=' ', quotechar='|')
        for row in lecteur:
            print(', '.join(row))
    return None


def enregistrer():
    with open(chemin,'w',encoding="utf-8") as fichierSource:
        txt = zoneTexte.get("0.0","end")#0 = ligne .0 = colone 
        fichierSource.write(txt)
    return None

#Programme principal
fenetre=Tk() #Instanciation de la classe Tk() : root est un objet (fenetre)
zoneTexte=Text(fenetre,width=100,height=30) #taille en caractères
zoneTexte.grid(row=0,column=0)

#Construction du Menu et des sous-menus

menu=Menu(fenetre)
sm1=Menu(fenetre)
menu.add_cascade(label="Fichier" ,menu=sm1)
sm1.add_command(label="Ouvrir" ,command=ouvrir)
sm1.add_command(label="enregistrer" ,command=enregistrer)
sm1.add_command(label="quitter" ,command=fenetre.destroy)

fenetre.config(menu=menu,width=100)
fenetre.title("Edition de texte")
fenetre.mainloop()#Demarer le gestionnaire d'événement
