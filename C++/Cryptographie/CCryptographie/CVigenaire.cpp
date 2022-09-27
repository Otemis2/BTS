#include "CVigenaire.h"
#include <string.h>

/*# --------------------------------------
# Nom Procédure Membre :CVigenaire
# Classe : CVigenaire
# Sujet : constructeur de la classe
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
CVigenaire::CVigenaire()
{
    messageClair=NULL;
    messageCode=NULL;
    cle=NULL;
}

/*# --------------------------------------
# Nom Procédure Membre :~CVigenaire
# Classe : CVigenaire
# Sujet : destructeur de la classe
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
CVigenaire::~CVigenaire()
{

}

/*# --------------------------------------
# Nom Procédure Membre : mettreMajuscules
# Classe CVigenaire
# Sujet : convertir tous les caractères alphabétiques d'une chaîne en majuscules
# Version :
# Entrée : aucune
# Sortie : aucune
# Entrée/sortie : chaine : chaine de caracteres
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 28/12/2020
# Mise à jour :
# ----------------------------------------
Procédure mettreMajuscules(inout chaine : chaine de caractères)
    VAR : i : entier
    Début
        Pour (i<-0 jusqu'à longueur(chaine)-1 avec un pas de 1) faire
            Si (chaine[i]>='a' ET chaine[i]<='z') alors
                chaine[i]=chaine[i]+'A'-'a'
            Fin Si
        Fin Pour
    Fin

*/
void CVigenaire::mettreMajuscules(char* chaine)
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
# Nom Procédure Membre : nettoyerChaine
# Classe : CVigenaire
# Sujet : ne garder que les caractères alphabétiques et le point virgule
# Version :
# Entrée : aucune
# Sortie : aucune
# Entrée/sortie : chaine : chaine de caracteres
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 04/01/2021
# Mise à jour :
# ----------------------------------------
Procédure nettoyerChaine(inout chaine : chaine de caractères)
    VAR : i : entier
          k : entier
          copieChaine : chaine de caracteres
    Début
        copieChaine<-chaine
        k<-0
        Pour (i<-0 jusqu'à longueur(copieChaine)-1 avec un pas de 1) faire
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

void CVigenaire::nettoyerChaine(char* chaine)
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
# Nom Fonction Membre : coderCaractere
# Classe : CVigenaire
# Sujet : coder un caractère en Cesar
# Version :
# Entrée : car : caractère, clef : caractère
# Sortie : aucune
# Entrée/sortie : caractère
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 04/01/2021
# Mise à jour :
# ----------------------------------------
Fonction coderCaractere(in : car,clef : caractères): caractere
    VAR
    carCode : charactere
    Début

   carCode <- car + clef - 'A';
   Si (carCode > 'Z')alors

       carCode <- carCode-26

   Fin Si
   retourne carCode;

    Fin
*/
char CVigenaire::coderCaractere(char car,char clef)
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
# Nom Fonction Membre : getMessageClair
# Classe : CVigenaire
# Sujet : Retourner l'attribut messageClair
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
char* CVigenaire::getMessageClair()
{
    return messageClair;
}

/*# --------------------------------------
# Nom Fonction Membre : getMessageCode
# Classe : CVigenaire
# Sujet : Retourner l'attribut messageCode
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
char* CVigenaire::getMessageCode()
{
    return messageCode;
}

/*# --------------------------------------
# Nom Fonction Membre : getCle
# Classe : CVigenaire
# Sujet : Retourner l'attribut cle
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
char* CVigenaire::getCle()
{
    return cle;
}

/*# --------------------------------------
# Nom Procédure Membre : setMessageClair
# Classe : CVigenaire
# Sujet : Modifier la valeur de messageClair
# Version : 0.1
# Entrée : message : chaine de caractères
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
void CVigenaire::setMessageClair(char* message)
{
    messageClair=new char[256];
    nettoyerChaine(message);
    mettreMajuscules(message);
    strcpy(messageClair,message);
}

/*# --------------------------------------
# Nom Procédure Membre : setMessageCode
# Classe : CVigenaire
# Sujet : Modifier la valeur de messageCode
# Version : 0.1
# Entrée : message : chaine de caractères
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
void CVigenaire::setMessageCode(char* message)
{
    messageCode=new char[256];
    nettoyerChaine(message);
    mettreMajuscules(message);
    strcpy(messageCode,message);
}

/*# --------------------------------------
# Nom Procédure Membre : setCle
# Classe : CVigenaire
# Sujet : Modifier la valeur de cle
# Version : 0.1
# Entrée : clef : chaine de caractères
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------*/
void CVigenaire::setCle(char* clef)
{
    cle=new char[256];
    nettoyerChaine(clef);
    mettreMajuscules(clef);
    strcpy(cle,clef);
}

/*# --------------------------------------
# Nom Fonction Membre : getCleValide
# Classe : CVigenaire
# Sujet : Déterminer si la clé saisie est valide
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : booléen
# Auteur : Mme Rapebach
# Création : 18/01/2020
# Mise à jour :
# ----------------------------------------
Fonction getCleValide():booléen
    VAR : cleValide : booléen
    Début
    Si (longueur (cle) = 1) alors
        cleValide <- vrai
    Sinon
        cleValide <- faux
    FinSi
    Retourne cleValide
    Fin
*/
bool CVigenaire::getCleValide()
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
# Nom Procédure Membre : coderMessage
# Classe : CVigenere
# Sujet : coder un message à partir de la clé et du message clair
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : aucune
# Auteur : HUCK
# Création : 07/02/2021
# Mise à jour :
# ----------------------------------------
Procédure coderMessage()
    VAR : i, j : entier
    Début
        j<-0
        messageCode<-new char[strlen(messageClair)+1]
        strcpy(messageCode, messageClair)
        Pour(i allant de 0 à strlen(messageClair)-1 avec un pas de 1)faire
            Si(j=strlen(cle))alors j<-0
            Si((messageCode[i]>='A')&&(messageCode[i]<='Z'))alors
                messageCode[i]<-((messageCode[i]+cle[j]-2*'A')%26+'A')
                j++
            Fin Si
        Fin Pour
        messageCode[strlen(messageClair)]<-'\0'
    Fin
*/
void CVigenaire::coderMessage()
{
    unsigned short j=0;
    messageCode = new char [strlen(messageClair)+1];
    strcpy(messageCode, messageClair);
    for (short i=0 ; i <=strlen(messageClair)-1; i++)
    {
        if(j== strlen(cle)) j=0;
        if((messageCode[i]>='A')&&(messageCode[i]<='Z'))
        {
            messageCode[i]=((messageCode[i]+cle[j]-2*'A')%26+'A');
            j++;
        }
    }
    messageCode[strlen(messageClair)]='\0';

}

/*# --------------------------------------
# Nom Procédure Membre : decoderMessage
# Classe : CVigenere
# Sujet : decoder un message à partir de la clé et du message clair
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : aucune
# Auteur : HUCK
# Création : 07/02/2021
# Mise à jour :
# ----------------------------------------
Procédure decoderMessage()
    VAR : i, j : entier
    Début
        j<-0
        messageClair<-new char[strlen(messageCode)+1]
        strcpy(messageClair, messageCode)
        Pour(i allant de 0 à strlen(messageCode)-1 avec un pas de 1)faire
            Si(j=strlen(cle))alors j<-0
            Si((messageClair[i]>='A')&&(messageClair[i]<='Z'))alors
                messageClair[i]<-((messageClair[i]-cle[j]+2*'A')%26+'A')
                j++
            Fin Si
        Fin Pour
        messageClair[strlen(messageCode)]<-'\0'
    Fin
*/
void CVigenaire::decoderMessage()
{
    unsigned short j=0;
    messageClair = new char [strlen(messageCode)+1];
    strcpy(messageClair, messageCode);
    for (short i=0 ; i <=strlen(messageCode)-1; i++)
    {
        if(j== strlen(cle)) j=0;
        if((messageClair[i]>='A')&&(messageClair[i]<='Z'))
        {
            messageClair[i]=((messageClair[i]-cle[j]+2*'A')%26+'A');
            j++;
        }
    }
    messageClair[strlen(messageCode)]='\0';
}


