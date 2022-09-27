#include "Mesfonctions.h"
#include "string.h"

/*
#-----------------------------------------
# Nom : mettreMajuscules
# Sujet : convertir tous les caracteres alphab�tiques d'une chaine
#-----------------------------------------------
Proc�dure mettreMajuscules (inout chaine ; chaine de caract�res)
var : i : entier
D�but
    Pour (i<-0 jusqu'� longueur(chaine)-1 avec un  pas de 1) faire
        si (chaine[i]>='a' Et chaine[i]<='z')alors
            chaine[i]=chaine[i]+'A'-'a'
        Fin Si
    Fin Pour
Fin
*/
void mettreMajuscules(char *chaine)
{
    for (short i=0 ; i <=strlen(chaine)-1; i++)
    {
        if (chaine[i]>='a' && chaine[i]<='z')
        {
            chaine[i]=chaine[i]+'A'-'a';
        }
    }
}

void mettreMinuscules(char *chaine)
{
    for (short i=0 ; i <=strlen(chaine)-1; i++)
    {
        if (chaine[i]>='A' && chaine[i]<='Z')
        {
            chaine[i]=chaine[i]+'a'-'A';
        }
    }
}

/*
#-----------------------------------------
# Nom : nettoyerChaine
# Sujet : nettoyer la chaine de caractere en gardant que les caractere et les ";"
#-----------------------------------------------
Proc�dure nettoyerChaine (inout chaine ; chaine de caract�res)
var : i : entier
    : k : entier
    : copieChaine : chaine de caracteres
D�but
    copieChaine<-chaine
    k<-0
    Pour (i<-0 jusqu'� longueur(copieChaine)-1 avec un  pas de 1) faire
        si (copieChaine[i]>='a' Et copieChaine[i]<='z')
            OU (copieChaine[i]>='A' Et copieChaine[i]<='Z')
            OU (copieChaine[i]>=';')alors

            Chaine[k]=copieChaine[i]
            k<-k+1
        Fin Si
    Fin Pour
    chaine[k]<-'\0'
Fin
*/
void nettoyerChaine(char *chaine)
{
 short k=0;
 char* copieChaine = new char[256];
 strcpy (copieChaine,chaine);
    for (short i=0 ; i <=strlen(copieChaine)-1; i++)
    {
        if ((copieChaine[i]>='a' && copieChaine[i]<='z')|| (copieChaine[i]>='A' && copieChaine[i]<='Z')|| (copieChaine[i]==';'))
        {
            chaine[k]=copieChaine[i];
            k=k+1;
        }
    }
 chaine[k]='\0';
}
/*
#-----------------------------------------
# Nom : determinerOccurenceA
# Sujet : nettoyer la chaine de caractere en gardant que les caractere et les ";"
#-----------------------------------------------
Fonction determinerOccurence(in element : entier) : entier
     VAR : occurence : entier
     i : entier
     app : bool

     D�but
        occurence <- -1
        app<- faux
        Pour (i <- 0 jusqu'� nbCases-1 avec un pas de 1)
            Si ((tab[i]=element) ET (occurence = -1)alors
                occurence<- i
           FinSi
           Retourner occurence
     Fin
 */
/*short determinerOccurenceA(char* chaine)
{
 char occurence ;//occurence est la variable du caractere choisi par l'utilisateur qui faudra regarde et compter dans le tableau de caractere
   for (short i = 0 ; i <=strlen(copieChaine)-1; i++)
    {

    }
}*/
/*
#-----------------------------------------
# Nom : etrePalindrome
# Sujet : determiner si une chaine est palindrome
#-----------------------------------------------
Methode 1 :

Fonction etrePalindrome(in chaine : chaine de characteres ) : booleen
     VAR : palindrome : boolen
           i : entier

     D�but
        palindrome<- vrai
        Pour (i <- 0 jusqu'� (strlen(chaine)/2-1)avec un pas de 1)

            Si (chaine[i]!= chaine[strlen(chaine)-1-i])alors

                palindrome <- faux

            FinSi

        FinPour

        Retourner palindrome

     Fin

Methode 2 :
Fonction etrePalindrome(in chaine : chaine de characteres ) : boole,

     VAR : chaineRetournee : chaine de caracteres qui a autant de caracteres que chaine
           i : entier

     D�but
        Pour (i <- 0 jusqu'� longueur(chaine)-1)avec un pas de 1)faire

        chaineRetournee[longueur(chaine)-1-i]=chaine

        FinPour

        Retourner palindrome

     Fin

     code :

bool etrePalindrome(char* chaine)
{
    char* chaineRetournee=new char[strlen(chaine)+1];
    for (short i = 0 ; i <=(strlen(chaine)-1);i++)
    {
          chaineRetournee[strlen(chaine)-1-i ]=chaine[i];
    }
    chaineRetournee[strlen(chaine)]='\0';// \0 est un caractere de fin de chaine A ne pas oubliez
    if (strcmp (chaineRetournee, chaine)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/
bool etrePalindrome(char* chaine)
{
     bool palindrome = true ;


        for (short i = 0 ; i <= (strlen(chaine)/2-1);i++)
        {
            if (chaine[i]!= chaine[strlen(chaine)-1-i])
            {
                palindrome = false;

            }

        }

        return palindrome;
}
/*
#-----------------------------------------
# Nom Fonction : proposer
# Sujet : determiner si la lettre proposee est dans le mot secret
et dans le cas echeant remplacer les �toiles par cette lettre
#Version :
#Entr�e : motSecret : chaine de caracteres, lettreProposee : caractere
#Sortie :
#Retour : bool�en
#Auteur :
#Cr�ation : 12/01/21
#-----------------------------------------------
Fonction proposer(in : motSecret : chaine de caracteres
                  inout : motTrouve : chaine de caracteres
                  in : lettreProposee : caractere) : boolen


VAR
i : entier
appartient : bool�en

D�but

appartient <- faux

        Pour (i <- 0 jusqu'� longueur(motSecret)-1 avec un pas de 1)
            Si (motSecret[i]=lettreProposee)alors
                motTrouve[i]=lettreProsee
                appartient <- vrai
           FinSi
        Fin Pour
           Retourner appartient
Fin

*/
bool proposer(char* motSecret, char* motTrouve,char lettreProposer)
{

bool appartient = false;

    for (short i = 0 ; i <= (strlen(motSecret));i++)
    {
        if (motSecret[i]==lettreProposer)
        {
            motTrouve[i]=lettreProposer;
            appartient = true;
        }

    }
return appartient;
}
