def points(mot):
    scrabble={"A":1,"B":3,"C":3,"D":2,"E":1,"F":4,
              "G":2,"H":4,"I":1,"J":8,"K":10,"L":1,"M":2,"N":1,"O":1,"P":3,"Q":8,
              "R":1,"S":1,"T":1,"U":1,"V":4,"W":10,"X":10,"Y":10,"Z":10}
    nbPoints=0
    #On va parcourir le mot à l'aide d'une boucle
    for i in range(0,len(mot)):
    # ou for i in range(len(mot))
        nbPoints=nbPoints+scrabble[mot[i]]
    #On va ajouter à nbPoints le nombre de points de la lettre correspondant
    return nbPoints

#2éme méthode de parcours de lettres de mot
def points2(mot):
    scrabble={"A":1,"B":3,"C":3,"D":2,"E":1,"F":4,
              "G":2,"H":4,"I":1,"J":8,"K":10,"L":1,"M":2,"N":1,"O":1,"P":3,"Q":8,
              "R":1,"S":1,"T":1,"U":1,"V":4,"W":10,"X":10,"Y":10,"Z":10}
    nbPoints=0
    for lettre in mot:
        nbPoints=nbPoints+scrabble[lettre]
    return nbPoints



print("VACANCES vaut ",points("VACANCES"),"points")
print("VACANCES vaut ",points2("VACANCES"),"points")
