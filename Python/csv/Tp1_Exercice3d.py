import csv

fichier = open('fruits.csv','r',encoding="utf-8")
lecteur = csv.reader(fichier, delimiter=';')
listeComplete=[]
for ligne in lecteur:
    print(ligne)
    listeComplete=listeComplete+ligne
fichier.close()
print("\nListe non triée : ",listeComplete,"\n")
listeComplete.sort() #La méthode sort trie le liste
print("\nListe triée : ",listeComplete,"\n")

with open('fruits3.csv', 'w', newline='') as fichierCsv:
    ecrivain = csv.writer(fichierCsv, delimiter=';')
    compteur=0
    liste5fruits=[]
    for fruit in listeComplete:
        compteur+=1
        while len(fruit) != 12:
            fruit=fruit+'*'
        liste5fruits.append(fruit)
        if compteur==5:
            compteur=0
            ecrivain.writerow(liste5fruits)
            liste5fruits=[]
    if liste5fruits!=[]:
        ecrivain.writerow(liste5fruits)
