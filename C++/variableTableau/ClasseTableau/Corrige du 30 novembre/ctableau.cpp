#include "ctableau.h"
#include <cstdlib>
#include <ctime>

using namespace std;

/*# --------------------------------------
# Nom Fonction Membre : CTableau
# Classe : CTableau
# Sujet : constructeur de la classe
# Version : 0.1
# EntrÃ©e : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# CrÃ©ation : 04/11/20
# Mise Ã  jour :
# ----------------------------------------*/
CTableau::CTableau()
{
    nbCases=0;
    table=NULL;
}

/*# --------------------------------------
# Nom Fonction Membre : CTableau
# Classe : CTableau
# Sujet : constructeur de la classe Ã  partir d'un nombre de cases et d'un tableau donnÃ©
# Version : 0.1
# EntrÃ©e : nbC : entier, tab : tableau d'entiers
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# CrÃ©ation : 04/11/20
# Mise Ã  jour :
# ----------------------------------------*/
CTableau::CTableau(short nbC,short tableau[])
{
    nbCases=nbC;
    table=new short[nbCases];
    for (short i=0;i<nbCases;i++)
    {
        table[i]=tableau[i];
    }
}

/*# --------------------------------------
# Nom Fonction Membre : CTableau
# Classe : CTableau
# Sujet : constructeur de la classe gÃ©nÃ©ration d'un tableau Ã  nbC cases contenant des entiers
          alÃ©atoires compris entre 1 et n
# Version : 0.1
# EntrÃ©e : nbC : entier, n : entier
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# CrÃ©ation : 04/11/20
# Mise Ã  jour :
# ----------------------------------------*/
CTableau::CTableau(short nbC,short n)
{
    nbCases=nbC;
    table=new short[nbCases];
    srand(time(0));
    for (short i=0;i<nbCases;i++)
    {
        table[i]=rand()%n+1;

    }
}

/*# --------------------------------------
# Nom Fonction Membre : CTableau
# Classe : CTableau
# Sujet : destructeur de la classe
# Version : 0.1
# EntrÃ©e : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# CrÃ©ation : 04/11/20
# Mise Ã  jour :
# ----------------------------------------*/
CTableau::~CTableau()
{

}

/*# --------------------------------------
# Nom Fonction Membre : getTable
# Classe : CTableau
# Sujet : accesseur à  l'attribut tab
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : tableau d'entiers
# Auteur : Mme Rapebach
# CrÃ©ation : 04/11/20
# Mise Ã  jour :
# ----------------------------------------*/
short* CTableau::getTable()
{
    return table;
}

/*# --------------------------------------
# Nom Fonction Membre : getNbCases
# Classe : CTableau
# Sujet : accesseur Ã  l'attribut nbCases
# Version : 0.1
# EntrÃ©e : aucune
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# CrÃ©ation : 04/11/20
# Mise Ã  jour :
# ----------------------------------------*/
short CTableau::getNbCases()
{
    return nbCases;
}

/*# --------------------------------------
# Nom Fonction Membre : calculerSomme
# Classe : CTableau
# Sujet : calculer la somme des éléments du tableau
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à  jour : 1
# ----------------------------------------
Fonction calculerSomme() : entier
    VAR : somme : entier
          i : entier
    Début
        somme<-0
        Pour (i<-0 jusqu'à nbCases-1 avec un pas de 1) faire
            somme<-somme+table[i]
        Fin Pour
        Retourner somme
    Fin
*/
short CTableau::calculerSomme()
{
    short somme=0;
    for (short i=0;i<nbCases;i++)
    {
        somme=somme+table[i];
    }
    return somme;
}

/*# --------------------------------------
# Nom Fonction Membre : calculerMoyenne
# Classe : CTableau
# Sujet : calculer la moyenne des éléments du tableau
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : flottant
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à jour :
# ----------------------------------------
Fonction calculerMoyenne() : flottant
    VAR : somme : entier
    Début
        somme<-calculerSomme()
        retourner flottant(somme)/nbCases
    Fin
 */
float CTableau::calculerMoyenne()
{
    short somme=this->calculerSomme();
    return float(somme)/nbCases;
}

/*# --------------------------------------
# Nom Fonction Membre : determinerMaximum
# Classe : CTableau
# Sujet : Déterminer la plus grande valeur présente dans le tableau.
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à jour :
# ----------------------------------------
Fonction determinerMaximum() : entier
    VAR : maxi : entier
          i: entier
    Début
        maxi<-tab[0]
        Pour (i<-0 jusqu'à nbCases-1 avec un pas de 1) faire
            Si (tab[i]>maxi) alors
                maxi<-tab[i]
            Fin Si
        Fin Pour
        retourner maxi
    Fin
*/
short CTableau::determinerMaximum()
{
    short maxi=table[0];
    for (short i=1;i<nbCases;i++)
    {
        if (table[i]>maxi)
        {
            maxi=table[i];
        }
    }
    return maxi;
}

/*# --------------------------------------
# Nom Fonction Membre : determinerMinimum
# Classe : CTableau
# Sujet : Déterminer la plus petite valeur présente dans le tableau
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à jour :
# ----------------------------------------
Fonction determinerMinimum() : entier
VAR : mini : entier
      i: entier
Début
    mini<-tab[0]
    Pour (i<-0 jusqu'à nbCases-1 avec un pas de 1) faire
        Si (tab[i]<mini) alors
            mini<-tab[i]
        Fin Si
    Fin Pour
    retourner mini
Fin
*/
short CTableau::determinerMinimum()
{
    short mini=table[0];
    for (short i=1;i<nbCases;i++)
    {
        if (table[i]<mini)
        {
            mini=table[i];
        }
    }
    return mini;
}

/*# --------------------------------------
# Nom Fonction Membre : appartenir
# Classe : CTableau
# Sujet : Chercher si un element est présent dans le tableau
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : booléen
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à jour :
# ----------------------------------------
Fonction appartenir(in element : entier) : booléen
     VAR : appartient : booléen
           i : entier
     Début
        appartient<-faux
        Pour (i<-0 jusqu'à nbCases-1 avec un pas de 1) faire
            Si (tab[i]=element) alors
                appartient<-vrai
            Fin Si
        Fin Pour
        Retourner appartient
     Fin
 */
bool CTableau::appartenir(short element)
{
     bool appartient=false;
     for (short i=0;i<nbCases;i++)
     {
         if (table[i]==element)
         {
             appartient=true;
         }
     }
     return appartient;
}

/*# --------------------------------------
# Nom Fonction Membre : determinerOccurence
# Classe : CTableau
# Sujet : Chercher la premiere apparition d'un élément dans un
         Retourne-1 si l'élément n'est pas dans le tableau
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à jour :
# ----------------------------------------
Fonction determinerOccurence(in element : entier) : entier
     VAR : occurence : entier
     i : entier
     app : bool

     Début
        occurence <- -1
        app<- faux
        Pour (i <- 0 jusqu'à nbCases-1 avec un pas de 1)
            Si ((tab[i]=element) ET (occurence = -1)alors
                occurence<- i
           FinSi
           Retourner occurence
     Fin
 #Tests
 L'élément n'est qu'une fois dan le tableau
 L'élément apparait plusieurs fois dan le tableau
 L'élément n'apparait pas dans le tableau
 */
short CTableau::determinerOccurence(short element)
{
   float occurence = -1;
   for (short i = 0 ; i <nbCases ; i++)
    {
       if (occurence == -1)
       {
       if (table [i] == element)
       {
             occurence= true ;
       }
       }
    }
    return occurence;
}
/*# --------------------------------------
# Nom Fonction Membre : determinerOccurence
# Classe : CTableau
# Sujet : Chercher la premiere apparition d'un élément dans un
         Retourne-1 si l'élément n'est pas dans le tableau
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 04/11/20
# Mise à jour :
# ----------------------------------------
     determinerNbSup10()





short CTableau::determinerNbSup10()
{
    short nb=0;
    for (short i=0;i<nbCases;i++)
    {
        if (table[]);
    }
}
*/
/*# --------------------------------------
# Nom Fonction Membre : trieABulles
# Classe : CTableau
# Sujet : Trier les élément de table à l'aide du tri à bulles
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 07/11/20
# Mise à jour :
# ----------------------------------------
Procédure : trierABulles()
VAR : i,j : entier;
      temp : entier
Debut
    Pour (i<-? jusqu'à nbCases-2 avec un pas de un) faire
        Pour (j<-0 jusqu'à nbCases-2-i avec un pas de un) faire
            Si (table[j]>table[j+1])alors
                temp<-table[j]
                table[j]<table[j+1]
                table[j+1]<temp
            FinSi
        Fin Pour
   Fin pour
 */
void CTableau :: trierABulles()
{
short i,j ;
short temp ;

    for (i=0; i <= nbCases-2; i++)
    {
        for (j=0; i <= nbCases-2-i; j++)
        {
              if (table[j]>table[j+1])
            {
                temp = table[j];
                table[j]=table[j+1];
                table[j+1]=temp;
            }
        }
   }
 }
/*# --------------------------------------
# Nom Fonction Membre : trieParSelection
# Classe : CTableau
# Sujet : Trier les élément de table à l'aide du tri par selection
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 07/11/20
# Mise à jour :
# ----------------------------------------
Procédure : trierParSelection()
VAR : j : entier
      temp : entier
      caseMaxi : entier
Debut
Pour (i<-nbCases-1 jusqu'à 0 avec un pas de -1)
    temp<-table[0]
    caseMaxi <- 0
    Pour (j<-1 jusqu'à i avec un pas de un) faire
            Si (table[j]>temp)alors
                temp<-table[j]
                caseMaxi<-j
            FinSi
   Fin pour
   table[caseMaxi]<-table[i]
   table[i]<-temp
 Fin pour
  */
void CTableau :: trierParSelection()
{
for (short i = nbCases-1 ;i >= 0 ; i--)
{
     short temp;
     short caseMaxi;

         temp = table[0];
         caseMaxi = 0;
         for (short j = 1; j <= i ;j++)
         {
             if (table[j]>temp)
             {
                 temp = table[j];
                 caseMaxi = j;
             }
         }
        table[caseMaxi]=table[i];
        table[i]=temp;
     }

}
/*# --------------------------------------
# Nom Fonction Membre : trieParInsertion
# Classe : CTableau
# Sujet : Trier les élément de table à l'aide du tri par insertion
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 07/11/20
# Mise à jour :
# ----------------------------------------
Procédure : trierParInsertion()
VAR : i,j : entier
      temp : entier
Debut
Pour (i<-1 jusqu'à nbCases-1 avec un pas de 1) faire
    j<-i
    Tant que ((j>=1) ET (table[j]<table[j-1]) faire
        temp<-table[j]
        table[j]<-table[j-1]
        table[j-1]<-temp
        j<-j-1
    Fin Tant que
 Fin pour
  */
void CTableau :: trierParInsertion()
{
short i,j ;
short temp ;

for (i= 1; i <= nbCases-1 ; i++)
  {
    j = i;
    while ((j>=1) && (table[j]<table[j-1]))
    {
        temp = table[j];
        table[j]= table[j-1];
        table[j-1]= temp;
        j = j-1;
    }
 }
}
/*# --------------------------------------
# Nom Fonction Membre : trieParInsertion
# Classe : CTableau
# Sujet : Trier les élément de table à l'aide du tri par insertion
# Version : 0.1
# Entrée : element : entier
# Sortie : aucune
# Retour : aucune
# Auteur : Mme Rapebach
# Création : 07/11/20
# Mise à jour :
# ----------------------------------------
Procédure : trierParInsertion()
VAR : i,j : entier
      temp : entier
Debut
Pour (i<-1 jusqu'à nbCases-1 avec un pas de 1) faire
    j<-i
    Tant que ((j>=1) ET (table[j]<table[j-1]) faire
        temp<-table[j]
        table[j]<-table[j-1]
        table[j-1]<-temp
        j<-j-1
    Fin Tant que
 Fin pour
  */
