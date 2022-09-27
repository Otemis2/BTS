#Définition de CCesar
class CCesar:
    def _init_(self):
        self.messageClair=None
        self.messageCoder=None
        self.cle=None

    def mettreMajuscules(self,chaine):
        chaineMaj=""
        for i in range(len(self,chaine)):
            if chaine[i]>='a' and chaine[i]<='z':
                chaineMaj=chaineMaj+chr(ord(chaine[i])+ord('A')-ord('a'))
            elif chaine[i]=="à" or chaine[i]=="â" or chaine[i]=="ä":
                chaineMaj=chaineMaj+"A"
            elif chaine[i]=="î" or chaine[i]=="ï":
                chaineMaj=chaineMaj+"I"
            elif chaine[i]=="ô" or chaine[i]=="ö":
                chaineMaj=chaineMaj+"O"
            elif chaine[i]=="û" or chaine[i]=="ü":
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
          if chaine[i]>='A' and chaine[i]<='Z':
              chaineNettoyee =  chaineNettoyee+chaine[i]
        return chaineNettoyee

monCesar=CCesar()

print (monCesar.nettoyerChaine("&&&&&12342567chaussette----è_ç_é_ezr("))
