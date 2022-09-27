from tkinter import*
from random import*
from csv import*

#Procédures
def valider():
    global pseudo
    pseudo=pseudoSaisie.get()
    if len(pseudo)!=0: #Si aucun pseudo n'est saisi il ne se passe rien
        #Sinon on détruit la fenêtre pseudonyme et on active le bouton commencer.
        pseudonyme.destroy()
        boutonCommencer.config(state=NORMAL)
        
def commencer():
    global xn,yn,nourriture,x,y,snake,objets,delai,perdu,score
    #On initialise toutes les variables
    can.delete(ALL) #Effacement de tout ce qui est dans le canvas (si on recommence)
    can.config(bg="#f0f0f0") #On remet le fond en gris clair
    can.focus_set() #On met le focus sur le canvas pour que les événements soient détectés

    #On remet 0 dans l'affichage du label score
    labelScore.config(text="Score : 0")
    #On désactive le bouton commencer
    boutonCommencer.config(state=DISABLED)
    
    #Réinitialisation des variables de jeu.
    snake=[]
    objets=[]
    delai=500
    perdu=False
    score=0
    deplacement="Left"

    #création du serpent
    x=250 #On le place au centre
    y=250
    objet=can.create_oval(x-10,y-10,x+10,y+10,fill="green")
    snake.append([x,y]) #On ajouter les coordonnées à la liste
    objets.append(objet) #On ajouter l'item à la liste

    #création de la première nourriture (placement au hasard dans la fenêtre)
    xn=randrange(10,500,20)
    yn=randrange(10,500,20)
    nourriture=can.create_image(xn,yn,image=photo)

    #On appelle la procédure déplacer pour que le jeu commence
    deplacer()

 
def afficherScore():
    global fen_score
    #On détruit la fenêtre pour la recréer.
    fen_score.destroy()
    fen_score=Frame(fen)
    try:
        Label(fen_score,text="Affichage des scores").grid(row=0,column=0,columnspan=2)
        Label(fen_score,text="Pseudo").grid(row=1,column=0)
        Label(fen_score,text="Score").grid(row=1,column=1)
        i=2
        with open('scores.csv',newline='') as csvfile:
            reader=DictReader(csvfile)
            #Pour chaque joueur on affiche le pseudo et le score
            for joueur in reader:
                if i<12: #Pour n'afficher que 10 joueurs au maximum
                    Label(fen_score,text=joueur["pseudo"]).grid(row=i,column=0)
                    Label(fen_score,text=joueur["score"]).grid(row=i,column=1)
                i+=1
            
    except:
        lab=Label(fen_score,text="Aucun score enregistré")
        lab.pack()

    fen_score.grid(row=0,column=1,rowspan=3,sticky="N")
        
def sauvegarder(score):
    global pseudo
    try:
        listeScores=[]
        #On récupère la liste des scores enregistrés
        with open('scores.csv',newline='') as csvfile:
            reader=DictReader(csvfile)
            for row in reader:
                listeScores.append(row)
        #On cherche où insérer le nouveau score pour qu'ils soient classés
        #Par ordre décroissant.
        i=0
        while score<float(listeScores[i]["score"]) and i<len(listeScores)-1:
            i=i+1
            
    except:
        listeScores=[]
        i=0

    listeScores.insert(i,{'pseudo':pseudo,'score':str(score)})

    #On remplace fichier csv précédent par ce nouveau fichier.
    with open('scores.csv','w',newline='') as csvfile:
        champs=['pseudo','score']
        writer=DictWriter(csvfile,fieldnames=champs)
        writer.writeheader()
        for row in listeScores:
            writer.writerow(row)

    afficherScore()   

def effacerScores():
    #print("Effacer")
    #On ouvre le fichier en écriture, on écrit une ligne vide et on le referme.
    csvfile=open('scores.csv','w')
    csvfile.write("")
    csvfile.close()

    afficherScore()
        
def contact(snake,element): #snake est la liste des coordonnées des
    #élements du serpent et element contient les coordonnées d'un element
    cont=False
    for i in range(len(snake)):
        if snake[i][0]==element[0] and snake[i][1]==element[1]:
            cont=True
    return cont

def modifierDirection(event):
    global deplacement
    if event.keysym=="Up":
        deplacement="Up"
    elif event.keysym=="Right":
        deplacement="Right"
    elif event.keysym=="Down":
        deplacement="Down"
    elif event.keysym=="Left":
        deplacement="Left"

def deplacer():
    global x,y,deplacement,perdu,snake,objets,nourriture,xn,yn,delai,score
    
    if deplacement=="Up":
        if y>20:
            y=y-20
        else:
            perdu=True        
            
    elif deplacement=="Left":
        if x>20:
            x=x-20
        else:
            perdu=True

    elif deplacement=="Down":
        if y<480:
            y=y+20
        else:
            perdu=True

    elif deplacement=="Right":
        if x<480:
            x=x+20
        else:
            perdu=True

    #On regarde s'il la nouvelle tête de serpent entre en contact avec un élément du serpent.
    if not perdu:
        if contact(snake,[x,y]):
            perdu=True

    if not perdu:
        #Si on ne touche pas le serpent
        if not contact(snake,[xn,yn]):
            can.delete(objets[0])
            del snake[0] #On supprime la queue
            del objets[0]
        else:
            xn=randrange(10,500,20)
            yn=randrange(10,500,20)
            #On vérifie que la nouvelle nourriture ne se place pas sur un élément du
            #serpent. Si c'est le cas on détermine de nouvelles coordonnées.
            while contact(snake,[xn,yn]):
                xn=randrange(10,500,20)
                yn=randrange(10,500,20)
            #On déplace la nourriture
            can.coords(nourriture,xn,yn)
            # Si le délai est supérieur à 100 on le diminue de 20.
            # On met une limite pour que ce ne soit pas trop rapide.
            if delai>100:
                delai-=20
            score+=1 #On ajoute 1 au score et on met à jour le Label
            labelScore.config(text="Score : "+str(score))

        #On ajoute les coordonnées la nouvelle tête, on crée l'item
        #correspond.
        snake.append([x,y])
        tete=can.create_oval(x-10,y-10,x+10,y+10,fill="green")
        # Si la liste d'objets n'est pas vide, on met le dernier élément
        #en vert pâle
        if len(objets)!=0:
            can.itemconfigure(objets[len(objets)-1],fill="palegreen")
        #On ajoute la tête à la liste d'objets.
        objets.append(tete)

        #Après delai ms on rappelle la fonction déplacer
        can.after(delai,deplacer)
    #Si on a perdu
    else:
        #Le fond du canvas devient bleu
        can.config(bg="blue")
        #Le message perdu s'affiche
        can.create_text(250,250,text="PERDU",fill="red",font=("Arial",30))
        #On sauvegarde le score
        sauvegarder(score)
        #le bouton commencer se réactive (et devient recommencer)
        boutonCommencer.config(state=NORMAL,text="Recommencer")

#Programme principal
#Initilisation des variables

perdu=False #Passera à vrai quand on aura perdu
deplacement="Left"
nourriture="" #Item correspondant à la nourriture
snake=[] #Contient les coordonnées des éléments du serpent
objets=[] #Contient les références aux items éléments du serpent
delai=500 #Délai en ms, entre deux déplacements
score=0 
pseudo=""

#Position de la nourriture
xn=0 
yn=0
#Position du serpent
x=0
y=0

#Coordonnées de la nourriture

fen=Tk()

#création du label de score au dessus
labelScore=Label(text="Score : 0")
labelScore.grid(row=0,column=0)

can=Canvas(height=500,width=500)
can.grid(row=1,column=0)

#Importation de l'image de la nourriture
photo=PhotoImage(file="PetitePomme.png")

#Sous fenêtre qui prendra la place du canevas au départ
#Elle disparaîtra dès que l'utilisateur aura entré un pseudo
pseudonyme=Frame(fen)

Label(pseudonyme,text="Entrer un pseudo").pack()

pseudoSaisie=Entry(pseudonyme,width=25)
pseudoSaisie.pack()

Button(pseudonyme,text="Valider",command=valider).pack()

pseudonyme.grid(row=1,column=0)

#Bouton commencer désactivé tant qu'un pseudo n'a pas été saisi.
boutonCommencer=Button(text="Commencer",state=DISABLED,command=commencer)
boutonCommencer.grid(row=2,column=0)

boutonQuitter=Button(text="Quitter",command=fen.destroy)
boutonQuitter.grid(row=3,column=0)

fen_score=Frame(fen) #On la crée sans la placer pour la définir en variable globale
afficherScore()

boutonEffacer=Button(text="Effacer les scores",command=effacerScores)
boutonEffacer.grid(row=3,column=1)

#Création de la récéption de l'événement clavier.
can.bind("<Key>",modifierDirection)

fen.mainloop()
