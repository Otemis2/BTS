#include "CCesar.h"
#include <string.h>

/*# --------------------------------------
# Nom Proc�dure Membre :CCesar
# Classe : CCesar
# Sujet : constructeur de la classe
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
CCesar::CCesar()
{
    messageClair=NULL;
    messageCode=NULL;
    cle=NULL;
}




/*# --------------------------------------
# Nom Proc�dure Membre :~CCesar
# Classe : CCesar
# Sujet : destructeur de la classe
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
CCesar::~CCesar()
{

}




/*# --------------------------------------
# Nom Proc�dure Membre : nettoyerChaine
# Classe : CCesar
# Sujet : ne garder que les caract�res alphab�tiques et le point virgule
# Version :
# Entr�e : aucune
# Sortie : aucune
# Entr�e/sortie : chaine : chaine de caracteres
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 04/01/2021
# Mise � jour :
# ----------------------------------------
Proc�dure nettoyerChaine(inout chaine : chaine de caract�res)
    VAR : i : entier
          k : entier
          copieChaine : chaine de caracteres
    D�but
        copieChaine<-chaine
        k<-0
        Pour (i<-0 jusqu'� longueur(copieChaine)-1 avec un pas de 1) faire
            Si ((copieChaine[i]>='a' ET copieChaine[i]<='z')
                    OU (copieChaine[i]>='A' ET copieChaine[i]<='Z')
                    OU (copieChaine[i]=';'))alors
                chaine[k]<-copieChaine[i]
                k<-k+1
            Fin Si
        Fin Pour
        chaine[k]<-'\0'
    Fin

*/
void CCesar::nettoyerChaine(char* chaine)
{
    short k=0;
    char* copieChaine=new char[256];
    strcpy(copieChaine,chaine);
    for (short i=0;i<=strlen(copieChaine)-1;i++)
    {
        if((copieChaine[i]>='a' && copieChaine[i]<='z')||(copieChaine[i]>='A' && copieChaine[i]<='Z')||(copieChaine[i]==';'))
        {
            chaine[k]=copieChaine[i];
            k++;
        }
    }
    chaine[k]='\0';
}




/*# --------------------------------------
# Nom Proc�dure Membre : mettreMajuscules
# Classe CCesar
# Sujet : convertir tous les caract�res alphab�tiques d'une cha�ne en majuscules
# Version :
# Entr�e : aucune
# Sortie : aucune
# Entr�e/sortie : chaine : chaine de caracteres
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 28/12/2020
# Mise � jour :
# ----------------------------------------
Proc�dure mettreMajuscules(inout chaine : chaine de caract�res)
    VAR : i : entier
    D�but
        Pour (i<-0 jusqu'� longueur(chaine)-1 avec un pas de 1) faire
            Si (chaine[i]>='a' ET chaine[i]<='z') alors
                chaine[i]=chaine[i]+'A'-'a'
            Fin Si
        Fin Pour
    Fin

*/
void CCesar::mettreMajuscules(char* chaine)
{
    for (short i=0;i<=strlen(chaine)-1;i++)
    {
        if (chaine[i]>='a' && chaine[i]<='z')
        {
            chaine[i]=chaine[i]+'A'-'a';
        }
    }
}




/*# --------------------------------------
# Nom Fonction Membre : coderCaractere
# Classe : CCesar
# Sujet : coder un caract�re en Cesar
# Version :
# Entr�e : car : caract�re, clef : caract�re
# Sortie : aucune
# Entr�e/sortie : caract�re
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 04/01/2021
# Mise � jour :
# ----------------------------------------
Fonction coderCaractere(in : car,clef : caract�res): caractere
    VAR
    carCode : charactere
    D�but
       carCode <- car + clef - 'A';
       Si (carCode > 'Z')alors
           carCode <- carCode-26
       Fin Si
       retourne carCode
    Fin
*/
char CCesar::coderCaractere(char car,char clef)
{
   char carCode;
   carCode = car + clef - 'A';
   if (carCode>'Z')
   {
       carCode = carCode-26;
   }
   return carCode;
}




/*# --------------------------------------
# Nom Fonction Membre : decoderCaractere
# Classe : CCesar
# Sujet : decoder un caract�re en Cesar
# Version :
# Entr�e : car : caract�re, clef : caract�re
# Sortie : aucune
# Entr�e/sortie : caract�re
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 04/01/2021
# Mise � jour :
# ----------------------------------------
Fonction decoderCaractere(in : car,clef : caract�res): caractere
    VAR
    carClair : charactere
    D�but
       carCode <- car - clef + 'A';
       Si (carClair < 'A')alors
           carClair <- carClair+26
       Fin Si
       Si (carClair > 'Z')alors
           carClair <- carClair-26
       Fin Si
       retourne carClair
    Fin
*/
char CCesar::decoderCaractere(char car,char clef)
{
   char carClair;
   carClair = car - clef + 'A';
   if (carClair<'A')
   {
       carClair = carClair+26;
   }
   if (carClair>'Z')
   {
       carClair = carClair-26;
   }
   return carClair;
}




/*# --------------------------------------
# Nom Proc�dure Membre : setMessageClair
# Classe : CCesar
# Sujet : Modifier la valeur de messageClair
# Version : 0.1
# Entr�e : message : chaine de caract�res
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
void CCesar::setMessageClair(char* message)
{
    messageClair=new char[256];
    nettoyerChaine(message);
    mettreMajuscules(message);
    strcpy(messageClair,message);
}




/*# --------------------------------------
# Nom Proc�dure Membre : setMessageCode
# Classe : CCesar
# Sujet : Modifier la valeur de messageCode
# Version : 0.1
# Entr�e : message : chaine de caract�res
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
void CCesar::setMessageCode(char* message)
{
    messageCode=new char[256];
    nettoyerChaine(message);
    mettreMajuscules(message);
    strcpy(messageCode,message);
}




/*# --------------------------------------
# Nom Proc�dure Membre : setCle
# Classe : CCesar
# Sujet : Modifier la valeur de cle
# Version : 0.1
# Entr�e : clef : chaine de caract�res
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
void CCesar::setCle(char* clef)
{
    cle=new char[256];
    nettoyerChaine(clef);
    mettreMajuscules(clef);
    strcpy(cle,clef);
}




/*# --------------------------------------
# Nom Fonction Membre : getMessageClair
# Classe : CCesar
# Sujet : Retourner l'attribut messageClair
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : chaine de caract�res
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
char* CCesar::getMessageClair()
{
    return messageClair;
}




/*# --------------------------------------
# Nom Fonction Membre : getMessageCode
# Classe : CCesar
# Sujet : Retourner l'attribut messageCode
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : chaine de caract�res
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
char* CCesar::getMessageCode()
{
    return messageCode;
}




/*# --------------------------------------
# Nom Fonction Membre : getCle
# Classe : CCesar
# Sujet : Retourner l'attribut cle
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : chaine de caract�res
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------*/
char* CCesar::getCle()
{
    return cle;
}




/*# --------------------------------------
# Nom Fonction Membre : getCleValide
# Classe : CCesar
# Sujet : D�terminer si la cl� saisie est valide
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : bool�en
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------
Fonction getCleValide():bool�en
    VAR : cleValide : bool�en
    D�but
    Si (longueur (cle) = 1) alors
        cleValide <- vrai
    Sinon
        cleValide <- faux
    FinSi
    Retourne cleValide
    Fin
*/
bool CCesar::getCleValide()
{
    bool cleValide;
    if (strlen(cle) == 1)
    {
        cleValide = true;
    }
    else
    {
        cleValide = false;
    }
    return cleValide;

}




/*# --------------------------------------
# Nom Proc�dure Membre : coderMessage
# Classe : CCesar
# Sujet : coder un message � partir de la cl� et du message clair
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------
Proc�dure coderMessage()
    VAR : i : entier court
    D�but
        messageCode<-new char[strlen(messageClair)+1]
        Pour(i allant de 0 � strlen(messageClair)-1 avec un pas de 1)faire
            messageCode<-coderCaractere(messageClair[i],cle[0])
        Fin Pour
        messageCode[strlen(messageClair)]<-"\0"
    Fin
*/
void CCesar::coderMessage()
{

    messageCode = new char [strlen(messageClair)+1];
    for (short i=0 ; i <=strlen(messageClair)-1; i++)
    {
        messageCode[i] = coderCaractere(messageClair[i],cle[0]);


    }
    messageCode[strlen(messageClair)]='\0';

}




/*# --------------------------------------
# Nom Proc�dure Membre : decoderMessage
# Classe : CCesar
# Sujet : coder un message � partir de la cl� et du message clair
# Version : 0.1
# Entr�e : aucune
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Cr�ation : 18/01/2020
# Mise � jour :
# ----------------------------------------
Proc�dure coderMessage()
    VAR : i : entier court
    D�but
        messageClair<-new char[strlen(messageCode)+1]
        Pour(i allant de 0 � strlen(messageCode)-1 avec un pas de 1)faire
            messageClair<-decoderCaractere(messageCode[i],cle[0])
        Fin Pour
        messageClair[strlen(messageCode)]<-"\0"
    Fin
*/
void CCesar::decoderMessage()
{
    messageClair = new char [strlen(messageCode)+1];
    for (short i=0 ; i <=strlen(messageCode)-1; i++)
    {
        messageClair[i] = decoderCaractere(messageCode[i],cle[0]);


    }
    messageClair[strlen(messageCode)]='\0';

}
