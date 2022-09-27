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
print("\nListe triée : ",listeComplete,"\n")

with open('fruits5.csv', 'w', newline='',encoding="utf-8") as fichierCsv:
    ecrivain = csv.writer(fichierCsv, delimiter=' ')
    i=0
    k=0
    listefruits=[]
    l="ligne"
    nb=0#iniatialise la variable qui compte le nombre de linge écrite
    fruit=""
    tailleTab = len(listeComplete)
    for i in range(tailleTab):
       k=i+1
       fruit=listeComplete[i]#récupere le fruit contenu dans listeComplete[i] et le copie dans la variable  "fruit"
       while len(fruit) != 12:#Tant que la longueur du mot dans la variable fruit est pas égal a 12 alors
           fruit=fruit+'*'#fruit = mot contenu dans fruit avec * a coter
       listefruits.append(fruit)#ajoute le fruit dans la liste
       if i == tailleTab-1:#Permet d'enregistrer le dernier mot
           nb+=1#incrémentation
           ligne = (l,nb,' : ',listefruits)
           ecrivain.writerow(ligne)#écrit la variable "ligne" dans le fichier csv 
       else:
           if listeComplete[i][0]!=listeComplete[k][0]:
               nb+=1
               ligne = (l,nb,' : ',listefruits)
               ecrivain.writerow(ligne)
               listefruits=[]#efface la liste en réinitialisent 
