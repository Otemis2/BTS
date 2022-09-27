from tkinter import*

#variable initialiser

# Fonction
def Valider():
    framePrincipal.grid_forget()
    frameEnregistrement.pack(expand=True)

def Retour():
    frameEnregistrement.pack_forget()
    framePrincipal.grid()
    effacer()

def effacer() :
    lE_Nom.delete(0,"end") #efface le contenu du lineEdit
    lE_Tel.delete(0,"end") #efface le contenu du lineEdit

#Programe Princpal

fen = Tk() #initialise la fenetre
fen.geometry("240x80") #configure la taille de la fenetre 
fen.title("Formulaire") #donne le titre de la fenetre
fen.resizable(width=False, height=False)

framePrincipal= Frame(fen)
framePrincipal.grid()

l_Nom= Label(framePrincipal,text="Nom :")
l_Nom.grid(column=0, row=0)

lE_Nom= Entry(framePrincipal,width="20",bg="white")
lE_Nom.grid(column=1,row=0)

l_Tel= Label(framePrincipal,text="Tel :")
l_Tel.grid(column=0, row=1)

lE_Tel=Entry(framePrincipal,width="20",bg="white")
lE_Tel.grid(column=1,row=1)

frameEnregistrement= Frame(fen)
l_Enregistrement= Label(frameEnregistrement,text="Vos coordonnées ont été envoyées")
l_Enregistrement.pack(expand=True)
pB_Retour= Button(frameEnregistrement,text="Retour",width="10",command=Retour)
pB_Retour.pack()

frameBouton= Frame(framePrincipal)
frameBouton.grid(column=1,row=2,columnspan=2)

pB_Supprimer= Button(frameBouton,text="Effacer",width="10",command=effacer)
pB_Supprimer.grid(column=0,row=0)

pB_Valider= Button(frameBouton,text="Valider",width="10",command=Valider)
pB_Valider.grid(column=1,row=0)

fen.mainloop()

