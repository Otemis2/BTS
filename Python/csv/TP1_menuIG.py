# -*- coding: utf-8 -*-
import  tkinter #import du module tkinter


#Définition des fonctions

def  affiche  ()  :
	print  ("fonction  affiche")

def  calcul  ()  :
	print  ("fonction  calcul  ",  3  *  4)

def  ajoute_bouton  ()  :
        global nb #variable globale (accessible en lecture/écriture depuis toute partie du programme)
                #pour garder en mémoire le nbr de bouton(s) déjà créé(s).
        nb  += 1
        b  =  tkinter.Button  (text  =  "bouton  "  +  str  (nb))
        b.pack  ()
        
#Déclaration de la variable nb
nb =  0

#PROGRAMME PRINCIPAL
fenetre  =  tkinter.Tk() #instanciation de la classe Tk (du module tkinter)
zoneSaisie  =  tkinter.Text(width  =  50,  height  =  10) #zone de saisie sur 10 lignes et 50 colonnes
zoneSaisie.pack  () #mise en place de la zone de saisie dans la fenêtre

#Construction du Menu et sous-menus
m    =  tkinter.Menu()
sm1  =  tkinter.Menu()
sm2  =  tkinter.Menu()
m.add_cascade(label  =  "sous-menu  1",  menu  =  sm1) #add_cascade: méthode permettant l'ajout dans le menu m du sous-menu sm1
m.add_cascade(label  =  "sous-menu  2",  menu  =  sm2)
sm1.add_command(label  =  "affiche", command  =  affiche) #
sm1.add_command(label  =  "calcul", command  =  calcul)
sm2.add_command(label  =  "ajoute_bouton",  command  =  ajoute_bouton)
sm2.add_command(label  =  "fin", command  =  fenetre.destroy)
fenetre.config(menu  =  m,  width  =  200)
fenetre.title("essai  de  menu")
fenetre.mainloop  ()#démarrage du réceptionnaire d'événements associé à la fenêtre
