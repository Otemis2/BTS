from os.path import *
import csv
from sys import exit

#variable initialiser
fichier = "./voituresAvecCodes.csv"

#Definition des fonctions
def ajouterVoiture(): #Création de la fonction ajouterVoiture()

    code=0 #Initialisation de la variable code
    if isfile(fichier)==True: #Vérification de l'existence du fichier
        file=open(fichier,"r",newline='',encoding="utf-8") #Ouverture du fichier en lecture seule
        reader = csv.DictReader(file,delimiter=';') #Utilisation de la classe DictReader
        for row in reader: #Lecture de chaque ligne une par une
            code=int(row["CODE"]) #La variable code prend la valeur du code de la ligne jusqu'à la fin du fichier
        file.close() #Fermeture du fichier
        file=open(fichier,"a",newline='',encoding="utf-8") #Ouverture du fichier en ajout
        writer = csv.DictWriter(file, fieldnames=['CODE', 'PUISSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'], delimiter=';')#Utilisation de DictWriter
    else:
        file=open(fichier,"w",newline='',encoding="utf-8") #Ouverture du fichier en ecriture seule
        writer = csv.DictWriter(file, fieldnames=['CODE', 'PUISSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'], delimiter=';')#Utilisation de DictWriter
        writer.writeheader() #Ecriture de l'entete dans le fichier
    reponse="oui" #Initialisation de la variable reponse
    while reponse=="oui":
        puissance=input("Puissance fiscale du vehicule : ")#crée une variable qui demande a l'utilisateur la puissance fiascale et prend la valeur dans la variable
        couleur=input("Couleur du vehicule : ")
        carburant=input("Carburant du vehicule : ")
        modele=input("Modele du vehicule : ")
        marque=input("Marque du vehicule : ")
        reponse=input("Voulez-vous saisir une autre voiture ? ")
        code=code+1 #Incrementation de la variable code
        writer.writerow({'CODE': code,'PUISSANCE FISCALE': puissance, 'COULEUR': couleur, 'CARBURANT': carburant, 'MODELE': modele, 'MARQUE': marque}) #Ecriture des differentes données dans le fichier
    file.close()#Ferme le fichier
    return()

def supprimerVoiture(): #Création de la fonction ajouterVoiture()
    codeSupprime=input("Saisissez le code de la voiture à supprimer du fichier : ")
    while codeSupprime!="q":
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
            codeSupprime="q"
        else:
            codeSupprime=input("Code inexistant, saisissez un autre code ou q pour quitter : ")
    return()
#Programe Princpal

menu=input("Saisissez 'a' pour AJOUTER ou 's' pour SUPPRIMER une voiture du fichier : ")#variabel proposant de supprimé un d'ajouter une ligne et récupérant la réponse de l'utilisateur de
while menu!="a" or menu!="s"or menu!="q":
    if menu=="a":
        ajouterVoiture() #Utilisation de la fonction ajouterVoiture()
        menu=input("Saisissez 'a' pour AJOUTER ou 's' pour SUPPRIMER une voiture du fichier ou sinon 'q' pour quitter : ")#Permet redemandé à l'utilisateur si il veut faire autre chose (si on enleve celà sans rien mettre fais un boucle infini car la variable menu garde sa valeur)
        if menu == "q":
            exit()
    elif menu=="s":
        supprimerVoiture() #Utilisation de la fonction supprimerVoiture()
        menu=input("Saisissez 'a' pour AJOUTER ou 's' pour SUPPRIMER une voiture du fichier ou sinon 'q' pour quitter : ")#Permet redemandé à l'utilisateur si il veut faire autre chose (si on enleve celà sans rien mettre fais un boucle infini car la variable menu garde sa valeur)
        if menu == "q":
            exit()
    else:
        menu=input("Mauvaise saisie, saisissez 'a' pour AJOUTER ou 's' pour supprimer une voiture du fichier ou sinon 'q' pour quitter")#indique que le caractère entrée n'est pas valide et redemande un autre
        if menu == "q":
            exit()
