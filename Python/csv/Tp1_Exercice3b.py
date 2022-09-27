import csv
# ouverture et lecture des lignes d'un fichier csv
f = open("adherents4.csv", newline='',encoding="utf-8")
    #adherents3.csv est un fichier au format csv enregistré avce le bloc notes,
    #les termes sont séparés par des espaces
contenu = csv.reader(f, delimiter=';')#par défaut le délimiter est ','
for ligne in contenu:#pour chaque ligne de contenu
    print(ligne)
f.close()
