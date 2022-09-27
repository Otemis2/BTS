from tkinter import*
from tkinter.filedialog import*

class CCesar:
    def __init__(self):
        self.messageClair=None
        self.messageCode=None
        self.cle=None

    def mettreMajuscules(self,chaine):
        chaineMaj=""
        for i in range(len(chaine)):
            if chaine[i]>="a" and chaine[i]<="z":
                chaineMaj=chaineMaj+chr(ord(chaine[i])+ord("A")-ord("a"))
            elif chaine[i]=="à" or chaine[i]=="â" or chaine[i]=="ä":
                chaineMaj=chaineMaj+"A"
            elif chaine[i]=="é" or chaine[i]=="è" or chaine=="ê" or chaine[i]=="ë":
                chaineMaj=chaineMaj+"E"
            elif chaine[i]=="ï" or chaine[i]=="î":
                chaineMaj=chaineMaj+"I"
            elif chaine[i]=="ô" or chaine[i]=="ö":
                chaineMaj=chaineMaj+"O"
            elif chaine[i]=="û" or chaine[i]=="ü" or chaine[i]=="ù":
                chaineMaj=chaineMaj+"U"
            elif chaine[i]=="ç" :
                chaineMaj=chaineMaj+"C"
            else:
                chaineMaj=chaineMaj+chaine[i]
        return chaineMaj

    def nettoyerChaine(self,chaine):
        chaine=self.mettreMajuscules(chaine)
        chaineNettoyee=""
        for i in range(len(chaine)):
            if chaine[i]>="A" and chaine[i]<="Z":
                chaineNettoyee=chaineNettoyee+chaine[i]
        return chaineNettoyee

    def coderCaractere(self,car,cle):
        numCarCode=ord(car)+ord(cle)-ord('A')
        if numCarCode>ord("Z"):
            numCarCode=numCarCode-26
        return chr(numCarCode)

    def decoderCaractere(self,car,cle):
        numCarClair=ord(car)-(ord(cle)-ord('A'))
        if numCarClair<ord('A'):
            numCarClair=numCarClair+26
        return chr(numCarClair)

    def getMessageClair(self):
        return self.messageClair

    def getMessageCode(self):
        return self.messageCode

    def getCle(self):
        return self.cle

    def setMessageClair(self,message):
        self.messageClair=self.nettoyerChaine(message)

    def setMessageCode(self,message):
        self.messageCode=self.nettoyerChaine(message)

    def setCle(self,cle):
        self.cle=self.mettreMajuscules(cle)

    def getCleValide(self):
        if len(self.cle)==1:
            return True
        else:
            return False

    def coderMessage(self):
        self.messageCode=""
        for i in range(len(self.messageClair)):
            self.messageCode+=self.coderCaractere(self.messageClair[i],self.cle)

    def decoderMessage(self):
        self.messageClair=""
        for i in range(len(self.messageCode)):
            self.messageClair+=self.decoderCaractere(self.messageCode[i],self.cle)


class CVigenere:
    def __init__(self):
        self.messageClair=None
        self.messageCode=None
        self.cle=None

    def mettreMajuscules(self,chaine):
        chaineMaj=""
        for i in range(len(chaine)):
            if chaine[i]>="a" and chaine[i]<="z":
                chaineMaj=chaineMaj+chr(ord(chaine[i])+ord("A")-ord("a"))
            elif chaine[i]=="à" or chaine[i]=="â" or chaine[i]=="ä":
                chaineMaj=chaineMaj+"A"
            elif chaine[i]=="é" or chaine[i]=="è" or chaine=="ê" or chaine[i]=="ë":
                chaineMaj=chaineMaj+"E"
            elif chaine[i]=="ï" or chaine[i]=="î":
                chaineMaj=chaineMaj+"I"
            elif chaine[i]=="ô" or chaine[i]=="ö":
                chaineMaj=chaineMaj+"O"
            elif chaine[i]=="û" or chaine[i]=="ü" or chaine[i]=="ù":
                chaineMaj=chaineMaj+"U"
            elif chaine[i]=="ç" :
                chaineMaj=chaineMaj+"C"
            else:
                chaineMaj=chaineMaj+chaine[i]
        return chaineMaj

    def nettoyerChaine(self,chaine):
        chaine=self.mettreMajuscules(chaine)
        chaineNettoyee=""
        for i in range(len(chaine)):
            if chaine[i]>="A" and chaine[i]<="Z":
                chaineNettoyee=chaineNettoyee+chaine[i]
        return chaineNettoyee

    def coderCaractere(self,car,cle):
        numCarCode=ord(car)+ord(cle)-ord('A')
        if numCarCode>ord("Z"):
            numCarCode=numCarCode-26
        return chr(numCarCode)

    def decoderCaractere(self,car,cle):
        numCarClair=ord(car)-(ord(cle)-ord('A'))
        if numCarClair<ord('A'):
            numCarClair=numCarClair+26
        return chr(numCarClair)

    def getMessageClair(self):
        return self.messageClair

    def getMessageCode(self):
        return self.messageCode

    def getCle(self):
        return self.cle

    def setMessageClair(self,message):
        self.messageClair=self.nettoyerChaine(message)

    def setMessageCode(self,message):
        self.messageCode=self.nettoyerChaine(message)

    def setCle(self,cle):
        self.cle=self.mettreMajuscules(cle)

    def getCleValide(self):
        if len(self.cle)>=1:
            return True
        else:
            return False

    def coderMessage(self):
        self.messageCode=""
        for i in range(len(self.messageClair)):
            self.messageCode+=self.coderCaractere(self.messageClair[i],self.cle[i%len(self.cle)])

    def decoderMessage(self):
        self.messageClair=""
        for i in range(len(self.messageCode)):
            self.messageClair+=self.decoderCaractere(self.messageCode[i],self.cle[i%len(self.cle)])       

def coderCesar():
    codage("Cesar",0)

def decoderCesar():
    codage("Cesar",1)

def coderVigenere():
    codage("Vigenere",0)

def decoderVigenere():
    codage("Vigenere",1)

def codage(nom,num):
    global info
    if nom=="Cesar":
        monCodage=CCesar()
    else:
        monCodage=CVigenere()
    message=texteInitial.get("0.0","end")
    #print(len(message))
    if len(message)==1 :
        info.set("Il faut saisir un message")
    else:
        if num==0:
            monCodage.setMessageClair(message)
        else:
            monCodage.setMessageCode(message)
        cle=clef.get()
        if len(cle)==0:
            info.set("Il faut saisir une clé")
        else:
            monCodage.setCle(cle)
            if not monCodage.getCleValide():
                info.set("Il faut saisir un clé valide")
            else:
                if num==0:
                    info.set("Message codé")
                    monCodage.coderMessage()
                    texteFinal.delete("0.0","end")
                    texteFinal.insert("0.0",monCodage.getMessageCode())
                else:
                    info.set("Message décodé")
                    monCodage.decoderMessage()
                    texteFinal.delete("0.0","end")
                    texteFinal.insert("0.0",monCodage.getMessageClair())

def ouvrir():
    try:
        filename = askopenfilename(title="Ouvrir votre document",filetypes=[('txt files','.txt'),('all files','.*')])
        fichier = open(filename, "r")
        content = fichier.read()
        fichier.close()
        texteInitial.delete("0.0","end")
        texteInitial.insert("0.0",content)
    except:
        pass

def effacer():
    global info
    texteInitial.delete("0.0","end")
    texteFinal.delete("0.0","end")
    clef.delete(0,len(clef.get()))
    info.set("Saisir un message")

def sauvegarder():
    try:
        fichier=asksaveasfile(mode='w',defaultextension=".txt")
        texteSauvegarde=str(texteFinal.get(0.0,END))
        fichier.write(texteSauvegarde)
        fichier.close()
    except:
        pass

#Programme principal
fen=Tk()
info=StringVar()
info.set("Saisir un message")

messages=Frame()
Label(messages,text="Ecrire le texte à coder ou à décoder").grid(row=0,column=0)
texteInitial=Text(messages,width=40,height=10)
texteInitial.grid(row=1,column=0)
Label(messages,text="Texte après codage ou décodage").grid(row=0,column=1)
texteFinal=Text(messages,width=40,height=10)
texteFinal.grid(row=1,column=1)
messages.pack()

Label(text="Saisir la clé de codage").pack()
clef=Entry(width=40)
clef.pack()

boutonsFichiers=Frame()
ouvrirFichier=Button(boutonsFichiers,text="Ouvrir un fichier",command=ouvrir)
ouvrirFichier.grid(row=0,column=0)

sauvegarderFichier=Button(boutonsFichiers,text="Sauvegarder un fichier",command=sauvegarder)
sauvegarderFichier.grid(row=0,column=1)
boutonsFichiers.pack()

boutons=Frame()
boutonCC=Button(boutons,text="Coder en César",command=coderCesar)
boutonCC.grid(row=0,column=0)

boutonDC=Button(boutons,text="Décoder en César",command=decoderCesar)
boutonDC.grid(row=1,column=0)

boutonCV=Button(boutons,text="Coder en Vigénère",command=coderVigenere)
boutonCV.grid(row=0,column=1)

boutonDV=Button(boutons,text="Décoder en Vigénère",command=decoderVigenere)
boutonDV.grid(row=1,column=1)
boutons.pack()

labelInfo=Label(textvariable=info)
labelInfo.pack()

basPage=Frame()
Button(basPage,text="Effacer tout",command=effacer).grid(row=0,column=0)
Button(basPage,text="Quitter",command=fen.destroy).grid(row=0,column=1)
basPage.pack()

fen.mainloop()
