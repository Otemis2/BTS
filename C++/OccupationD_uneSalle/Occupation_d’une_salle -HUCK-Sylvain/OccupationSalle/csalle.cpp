/*
# -----------------------------------------------------------------------
# Nom Fichier : CSalle.cpp
# Classe : CSalle
# Sujet : gestion de l'occupation d'une salle
# Version : 0.1
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

#include "csalle.h"
#include <string.h>
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : Constructeur
# Classe : CSalle
# Sujet : Constructeur du programme de gestion d'une salle
# Version : 0.1
# Entrees (in) : nomvariable:type ; Rôle/Description ou Aucune
# Sorties (out) : nomvariable:type ; Rôle/Description ou Aucune
# Eentrees/Sorties (inout) : Aucune
# Retour : Type ; Rôle/Description ou Aucune
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
CSalle::CSalle()
{


    strcpy(tabJours[0],"lundi");
    strcpy(tabJours[1],"mardi");
    strcpy(tabJours[2],"mercredi");
    strcpy(tabJours[3],"jeudi");
    strcpy(tabJours[4],"vendredi");


    strcpy(tabCreneau[0],"08h-09h");
    strcpy(tabCreneau[1],"09h-10h");
    strcpy(tabCreneau[2],"10h-11h");
    strcpy(tabCreneau[3],"11h-12h");
    strcpy(tabCreneau[4],"12h-13h");
    strcpy(tabCreneau[5],"13h-14h");
    strcpy(tabCreneau[6],"14h-15h");
    strcpy(tabCreneau[7],"15h-16h");
    strcpy(tabCreneau[8],"16h-17h");
    strcpy(tabCreneau[9],"17h-18h");
    strcpy(tabCreneau[10],"18h-19h");

    for(short i=0; i < 11;  i++ )
    {
        for(short k=0; k < 5; k++ )
        {
            tabOccupation[i][k] = false;
        }
    }
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : Destructeur
# Classe : CSalle
# Sujet : Destructeur du programme de gestion d'une salle
# Version : 0.1
# Entrees (in) : nomvariable:type ; Rôle/Description ou Aucune
# Sorties (out) : nomvariable:type ; Rôle/Description ou Aucune
# Eentrees/Sorties (inout) : Aucune
# Retour : Type ; Rôle/Description ou Aucune
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
CSalle::~CSalle()
{
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : getJours
# Classe : CSalle
# Sujet : récupere le jour du programme
# Version : 0.1
# Entrees (in) : jour
# Sorties (out) :
# Eentrees/Sorties (inout) : Aucune
# Retour : tabJours[jour]
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
char* CSalle::getJours(short jour)
{
    return tabJours[jour];
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : getCreneaux
# Classe : CSalle
# Sujet : récupere le creneau du programme
# Version : 0.1
# Entrees (in) : creneau
# Sorties (out) :
# Eentrees/Sorties (inout) : Aucune
# Retour : tabCreneau[creneau]
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
char* CSalle::getCreneaux(short creneau)
{
  return tabCreneau[creneau];
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : getOccupations
# Classe : CSalle
# Sujet : récupere l'occupation de la salle
# Version : 0.1
# Entrees (in) : creneau , jour
# Sorties (out) :
# Eentrees/Sorties (inout) : Aucune
# Retour : tabOccupation[creneau][jour]
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CSalle::getOccupations(short creneau, short jour)
{
    return tabOccupation[creneau][jour];
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : getProba
# Classe : CSalle
# Sujet : calcule et récupere taux d'occupation de la salle
# Version : 0.1
# Entrees (in) : nbOccuper , nbCreneauMax
# Sorties (out) :
# Eentrees/Sorties (inout) : Aucune
# Retour : proba
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
double CSalle::getProba (float nbOccuper, float nbCreneauMax)
{
    proba = (nbOccuper/nbCreneauMax)*100;
    return proba;
}

/*
# -----------------------------------------------------------------------
# Nom Fonction Membre : setOccupation
# Classe : CSalle
# Sujet : modifie l'occupation de la salle
# Version : 0.1
# Entrees (in) : creneau : court , jour : court , occupation : bool
# Sorties (out) :
# Eentrees/Sorties (inout) : Aucune
# Retour :
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CSalle::setOccupation(short creneau, short jour, bool occupation)
{
    tabOccupation[creneau][jour] = occupation;
}
