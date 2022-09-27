import csv
from os.path import *

tailleDuCode = 0
fichierCsv="./voituresAvecCodes.csv"
if isfile(fichierCsv)==True: #Si le fichier existe Alors faire
    
    file=open(fichierCsv, "r",newline='',encoding="utf-8")#ouvre le fichier, avec qu'elle mode, ce qui signifie une nouvelle ligne et l'encodage
    reader = csv.DictReader(file,delimiter=';')#configure avec quel fonction utiliser le fichier et configure le delimiteur
    for row in reader:#lis chaque ligne du fichier csv contenu dans la variable reader
         tailleDuCode = tailleDuCode + 1 #augmente de 1 la valeur de tailleDuCode a chaque lecture de ligne
    file.close()#ferme le fichier
    
    file=open(fichierCsv, "a",newline='',encoding="utf-8")#ouvre le fichier en ajout, encoder en utf-8 et espace comme nouvelle ligne
    writer = csv.DictWriter(file,fieldnames=['CODE','PUISSSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'],delimiter=';')#configure avec quel fonction ouvrir, crée l'entete, et determine le delimiteur    
else:#Sinon
    file=open(fichierCsv, "w",newline='',encoding="utf-8")#ouvre le fichier en écriture si il n'existe pas le crée (but recherché)
    writer = csv.DictWriter(file,fieldnames=['CODE','PUISSSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'],delimiter=';')#configure avec quel fonction ouvrir, crée l'entete, et determine le delimiteur 
    writer.writeheader()#ecrit l'entete
reponse="oui"#initialise un variable qui a comme valeur oui
while reponse=="oui":#Tant que reponse est oui faire
    marque=input("Marque  du véhicule : ")#Demande a l'utilisateur une donnée , recupere sa reponse et la stock
    puissance=input("Puissance  du véhicule : ")#Demande a l'utilisateur une donnée , recupere sa reponse et la stock
    couleur=input("Couleur  du véhicule : ")#Demande a l'utilisateur une donnée , recupere sa reponse et la stock
    carburant=input("Carburant  du véhicule : ")#Demande a l'utilisateur une donnée , recupere sa reponse et la stock
    modele=input("Modèle  du véhicule : ")#Demande a l'utilisateur une donnée , recupere sa reponse et la stock
    tailleDuCode = tailleDuCode+1#augmente la valeur de 1 la valeur de tailleDuCode pour l'incrementer a chaque ligne
    writer.writerow({'CODE':tailleDuCode, 'COULEUR':couleur, 'CARBURANT':carburant, 'MODELE':modele, 'MARQUE':marque,'PUISSSANCE FISCALE':puissance})
    reponse=input("Voulez-vous saisir une autre voiture ? oui/non")#Demande a l'utilisateur si il veut continuer 
file.close()#ferme le fichier

      
