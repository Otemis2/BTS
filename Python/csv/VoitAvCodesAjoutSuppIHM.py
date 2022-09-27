import tkinter
from os.path import *
from tkinter.messagebox import showerror
import csv

try:
    import Tkinter as tk
except:
    import tkinter as tk

#variable initialiser
fichier = "./voituresAvecCodes.csv"

# Fonction
def comErreur() :
    rep = showerror ("message erreur","Code invalide !")
    
def affichage():
    listeBox.delete(0,listeBox.size())
    if isfile(fichier)==True: #Vérification de l'existence du fichier
        file=open(fichier,"r",newline='',encoding="utf-8") #Ouverture du fichier en lecture seule
        reader = csv.DictReader(file,delimiter=';') #Utilisation de la classe DictReader
        for row in reader: #Lecture de chaque ligne une par une
            code = row['CODE']
            puiFis = row['PUISSANCE FISCALE']
            color = row['COULEUR']
            carbu = row['CARBURANT']
            model = row['MODELE']
            marque = row ['MARQUE']
            while len(code) != 4 :
                code = code+" "
            while len(puiFis) != 17 :
                puiFis = puiFis+" "
            while len(color) != 10 :
                color = color+" "
            while len(carbu) != 10 :
                carbu = carbu+" "
            while len(model) != 15 :
                model = model+" "
            while len(marque) != 10 :
                marque = marque+" "
            listeBox.insert("end",code+" "+puiFis+" "+color+" "+carbu+" "+model+" "+marque)
        file.close() #Fermeture du fichier
    
def afficherFenAjout():
    fenAjout.grid(row=10,column = 0)
    bPSupprimer['state'] = tk.DISABLED
    bPAjouter['state'] = tk.DISABLED
    
def afficherFenSupprimer():
    fenSupprimer.grid(row=10,column = 1)
    bPSupprimer['state'] = tk.DISABLED
    bPAjouter['state'] = tk.DISABLED
    
def ajouterVoiture(): #Création de la fonction ajouterVoiture()
    puissance=lEPuiFis.get()
    couleur=lEcouleur.get()
    Carburant=carburant.get()
    modele=lEmodel.get()
    """i=lBMarque.curselection()
    if i == ():
        i =0
    marque=lBMarque.get(i)"""

    marque=Marque.get()
    
    code=0 #Initialisation de la variable code
    if isfile(fichier)==True: #Vérification de l'existence du fichier
        file=open(fichier,"r",newline='',encoding="utf-8") #Ouverture du fichier en lecture seule
        reader = csv.DictReader(file,delimiter=';') #Utilisation de la classe DictReader
        for row in reader: #Lecture de chaque ligne une par une
            code=int(row["CODE"]) #La variable code prend la valeur du code de la ligne jusqu'à la fin du fichier
        file.close() #Fermeture du fichier
        file=open(fichier,"a",newline='',encoding="utf-8") #Ouverture du fichier en ajout
        writer = csv.DictWriter(file, fieldnames=['CODE', 'PUISSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'], delimiter=';')#Utilisation de DictWriter
        code=code+1 #Incrementation de la variable code
        writer.writerow({'CODE': code,'PUISSANCE FISCALE': puissance, 'COULEUR': couleur, 'CARBURANT': Carburant, 'MODELE': modele, 'MARQUE': marque}) #Ecriture des differentes données dans le fichier
    else:
        file=open(fichier,"w",newline='',encoding="utf-8") #Ouverture du fichier en ecriture seule
        writer = csv.DictWriter(file, fieldnames=['CODE', 'PUISSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'], delimiter=';')#Utilisation de DictWriter
        writer.writeheader() #Ecriture de l'entete dans le fichier
        code=code+1 #Incrementation de la variable code
        writer.writerow({'CODE': code,'PUISSANCE FISCALE': puissance, 'COULEUR': couleur, 'CARBURANT': Carburant, 'MODELE': modele, 'MARQUE': marque}) #Ecriture des differentes données dans le fichier
    file.close()#Ferme le fichier
    affichage()

def supprimerVoiture(): #Création de la fonction supprimerVoiture()
    codeSupprime = lECodeSupprime.get()
    codePresent=False

    file=open(fichier,"r",newline='',encoding="utf-8")#Permet de récupérer le nom du fichier , son emplacement, son encodage
    reader = csv.DictReader(file,delimiter=';') #Ouvre le fichier et fixe le delimiter
    listeLigne=[] #Creation de la liste vide listeLigne
    for row in reader:
        listeLigne.append(row) #Ajoute dans la variable listeLigne la ligne lu
    file.close()#Ferme le fichier
    ligneASupprime=0#Initialisation de la variable avec la valeur 0
    for ligne in range(len(listeLigne)): #On parcour la liste
        if codeSupprime==listeLigne[ligne]['CODE']:#Vérification pour determiner si on ets sur la bonne ligne
            ligneASupprime=ligne #On garde la ligne a supprime dans la variable ligneASupprime
            codePresent=True
    if codePresent == False:
        comErreur()   
    if codeSupprime==listeLigne[ligneASupprime]['CODE']:
        del listeLigne[ligneASupprime] #On supprime la ligne avec le code correspondant
        file=open(fichier,"w",newline='',encoding="utf-8")
        writer = csv.DictWriter(file, fieldnames=['CODE', 'PUISSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'], delimiter=';')
        writer.writeheader()#Ecrit l'entête
        for i in range(len(listeLigne)):
            if listeLigne[i]['CODE']==codeSupprime:#Vérification pour determiner si on ets sur la bonne ligne
                i = i+1
            else:
                writer.writerow(listeLigne[i]) #On réécrit chaque ligne dans le fichier
        file.close()#ferme le fichier
    affichage()

# Fenetre Principal
fen = tkinter.Tk()
fen.title("Garage Occassion")

fenAjout = tkinter.Frame(fen)
fenSupprimer = tkinter.Frame(fen)

titre = tkinter.Label( fen, text="Gestion de stock de véhicules",font=("Arial",18,"bold"))
titre.grid(row=0,column = 0,columnspan=3)

header = tkinter.Label( fen, text="CODE PUISSANCE FISCALE COULEUR    CARBURANT  MODELE          MARQUE   ",font=("courier",14))
header.grid(row=1,column = 0,columnspan=3)

listeBox = tkinter.Listbox(fen,font=("courier",14),bg="white",height="10",width="70")
listeBox.grid(row=2,column = 0,columnspan=3)

bPAjouter = tkinter.Button(fen, text ="Ajouter un véhicule", command = afficherFenAjout)
bPAjouter.grid(row=3,column = 0)

bPSupprimer = tkinter.Button(fen, text ="Supprimer un véhicule", command = afficherFenSupprimer)
bPSupprimer.grid(row=3,column = 1)

bPQuitter = tkinter.Button(fen, text ="Quitter", command = fen.destroy)
bPQuitter.grid(row=14,column = 2)
#Pour Supprimer un véhicule :

sousTitre = tkinter.Label( fenSupprimer, text="Supprimer un véhicule",font=("Arial",12,"bold"))
sousTitre.grid(row=0,column = 0,columnspan=4)

lCodeSupprime = tkinter.Label( fenSupprimer, text="Code : ",font=("Arial",10))
lCodeSupprime.grid(row=1,column = 0)

codeSupprime = tkinter.IntVar()
lECodeSupprime = tkinter.Entry(fenSupprimer, textvariable=codeSupprime )
lECodeSupprime.focus_set()
lECodeSupprime.grid(row=1,column = 1)

bPEnvoyer = tkinter.Button(fenSupprimer, text ="Envoyer", command = supprimerVoiture)
bPEnvoyer.grid(row=1,column = 2)

#Pour Ajouter un véhicule :

sousTitre = tkinter.Label( fenAjout, text="Ajouter un véhicule",font=("Arial",12,"bold"))
sousTitre.grid(row=0,column = 0,columnspan=4)

lMarque = tkinter.Label( fenAjout, text="Marque : ",font=("Arial",10))
lMarque.grid(row=1,column = 0)
"""
lBMarque = tkinter.Listbox(fenAjout,font=("courier",10),bg="white",height="1",width="10")
lBMarque.insert(0,"BMW")
lBMarque.insert(1,"Renault")
lBMarque.insert(2,"Citroën")
lBMarque.insert(3,"Peugeot")
lBMarque.grid(row=2,column = 0)"""

Marque = tkinter.StringVar()
contenu = ["BMW", "Renault", "Citroën", "Peugeot"]
Marque.set(contenu[1]) # par défaut
mDMarque = tkinter.OptionMenu(fenAjout, Marque, *contenu , command = "" )
mDMarque.grid(row=2,column = 0)

lmodel = tkinter.Label( fenAjout, text="Model : ",font=("Arial",10))
lmodel.grid(row=1,column = 1)

model = tkinter.StringVar()
model.set("Zoe")
lEmodel = tkinter.Entry(fenAjout, textvariable=model )
lEmodel.focus_set()
lEmodel.grid(row=2,column = 1)

lcouleur = tkinter.Label( fenAjout, text="Couleur : ",font=("Arial",10))
lcouleur.grid(row=1,column = 2)

couleur = tkinter.StringVar()
couleur.set("Blanc")
lEcouleur = tkinter.Entry(fenAjout, textvariable=couleur )
lEcouleur.focus_set()
lEcouleur.grid(row=2,column = 2)

lcarburant = tkinter.Label( fenAjout, text="Carburant : ",font=("Arial",10))
lcarburant.grid(row=3,column = 0)

carburant=tkinter.StringVar()
carburant.set("Essence") # par défaut

rBDiezel = tkinter.Radiobutton (fenAjout,text= "Diesel    ",value="Diezel",variable=carburant,font=("courier",10))
rBDiezel.grid(row=4,column = 0)

rBEssence = tkinter.Radiobutton (fenAjout,text= "Essence",value="Essence",variable=carburant,font=("courier",10))
rBEssence.grid(row=4,column = 1)

rBElectrique = tkinter.Radiobutton (fenAjout,text= "Electrique",variable=carburant,value="Electrique", font=("courier",10))
rBElectrique.grid(row=5,column = 0)

rBHybride = tkinter.Radiobutton (fenAjout,text= "Hybride",variable=carburant,value="Hybride", font=("courier",10))
rBHybride.grid(row=5,column = 1)

lPuiFis = tkinter.Label( fenAjout, text="Puissance Fiscale : ",font=("Arial",10))
lPuiFis .grid(row=6,column = 0)

PuiFis = tkinter.IntVar()
lEPuiFis = tkinter.Entry(fenAjout, textvariable=PuiFis )

lEPuiFis.focus_set()
lEPuiFis.grid(row=7,column = 0)

bPContinuer = tkinter.Button(fenAjout, text ="Continuer", command = ajouterVoiture)
bPContinuer.grid(row=8,column = 2)

affichage()

fen.mainloop()
