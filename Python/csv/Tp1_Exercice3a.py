import csv
# ouverture et lecture des lignes d'un fichier csv
with open("adherents3.csv", newline='',encoding="utf-8") as f:
    #adherents3.csv est un fichier au format csv enregistré avce le bloc notes,
    #les termes sont séparés par des espaces
    contenu = csv.reader(f, delimiter='')#par défaut le délimiter est ','
    for row in contenu:#pour chaque ligne de contenu
        print(row)
