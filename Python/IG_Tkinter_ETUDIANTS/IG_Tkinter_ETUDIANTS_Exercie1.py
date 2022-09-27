from tkinter import*

#variable initialiser

# Fonction
def calculerSurface() :#défini la fonction calculerSurface
    rayon=lE_1.get()#récupére le contenu du lineEdit est le met dans la variable rayon
    if rayon == "": #si la valeur de rayon est nul alors
        rayon = 0 #rayon = 0
    rayon = int(rayon) #converti rayon en int 
    surface = round(((rayon * rayon)*3.141592),2) #calcule la surface arrondi a deux nombres apres la virgules
    label_2 = Label(fen,text = "",font = ("Times",10),fg="black")
    label_2.config(text="La surface du disque de rayon : "+str(rayon)+" est "+str(surface))
    label_2.pack() #place le label dans la fenetre
    lE_1.delete(0,"end") #efface le contenu du lineEdit

#Programe Princpal

fen = Tk() #initialise la fenetre
fen.geometry("250x100") #configure la taille de la fenetre 
fen.title("tk") #donne le titre de la fenetre
fen.resizable(width=False, height=False)

label_1 = Label(fen,text="Rayon : ",font = ("Times",10),fg="black")
label_1.pack() #place le label_1

lE_1=Entry(bg="white",fg="black",width=8)
lE_1.pack() #place le lineEdit_1

Bp_1=Button(text="Valider",command=calculerSurface)
Bp_1.pack() #place le Bouton_1


fen.mainloop()
