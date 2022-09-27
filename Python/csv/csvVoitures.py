import csv
from os.path import *

fichierCsv="./voiture.csv"
if isfile(fichierCsv)==True:
    
    file=open(fichierCsv, "a",newline='',encoding="utf-8")
    writer = csv.DictWriter(file,fieldnames=['PUISSSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'],delimiter=';')    
else:
    file=open(fichierCsv, "w",newline='',encoding="utf-8")
    writer = csv.DictWriter(file,fieldnames=['PUISSSANCE FISCALE', 'COULEUR', 'CARBURANT', 'MODELE', 'MARQUE'],delimiter=';')
    writer.writeheader()
reponse="oui"
while reponse=="oui":
    marque=input("Marque  du véhicule : ")
    puissance=input("Puissance  du véhicule : ")
    couleur=input("Couleur  du véhicule : ")
    carburant=input("Carburant  du véhicule : ")
    modele=input("Modèle  du véhicule : ")

    writer.writerow({'COULEUR':couleur, 'CARBURANT':carburant, 'MODELE':modele, 'MARQUE':marque,'PUISSSANCE FISCALE':puissance})
    reponse=input("Coulez-vous saisir une autre voiture ? oui/non")
file.close()

      
