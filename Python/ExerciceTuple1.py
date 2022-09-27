def temps_secondes(temps):

    heures=temps[0]
    minutes=temps[1]
    secondes=temps[2]
    totalSeconde=(heures*60+minutes)*60+secondes
    return totalSeconde

def temps_h_min_s(secondes):

    minutes=secondes//60
    secondes=secondes%60
    
    heures=minutes//60
    minutes=minutes%60
    
    return heures,minutes,secondes

heures=int(input("Entrer le nombre d'heures : "))
minutes=int(input("Entrer le nombre de minutes : "))
secondes=int(input("Entrer le nombre de secondes : "))

temps=(heures,minutes,secondes)
print(temps_secondes(temps))

secondes=int(input("Entrer le nombre de secondes : "))

temps=(secondes)
print(temps_h_min_s(temps))

