import csv
# ouverture et lecture des lignes d'un fichier csv
fichier = open('fruits.csv','r',encoding="utf-8")
lecteur = csv.reader(fichier, delimiter=';')
listeComplete=[]
for ligne in lecteur:
    print(ligne)
    listeComplete=listeComplete+ligne #on complète la liste coplète de fruits
fichier.close()
print("\nListe non triée : ",listeComplete,"\n")
listeComplete.sort() #La méthode sort trie le liste
#listeTriee=sorted(listeComplete, key=str.lower)
print("\nListe triée : ",listeComplete,"\n")

with open('fruits2.csv', 'w', newline='',encoding="utf-8") as fichierCsv:
    ecrivain = csv.writer(fichierCsv, delimiter=';')
    compteur=0
    liste5fruits=[]
    for fruit in listeComplete:
        compteur+=1
        liste5fruits.append(fruit)
        if compteur==5:
            compteur=0
            ecrivain.writerow(liste5fruits)
            liste5fruits=[]
    if liste5fruits!=[]: #pour écrire la dernière ligne si nbr fruit(s) < 5
        ecrivain.writerow(liste5fruits)
