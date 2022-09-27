from os.path import *

fichier = "voitures.csv"

if isfile(fichier)==True:
    print("Le fichier voitures.csv existe")
else:
    print("Le fichier voitures.csv existe pas")
