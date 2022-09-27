/*
#-----------------------------------------------------------------------
# Nom Fichier: cskieur.cpp
# Classe : CSkieur
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Création : 16/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "cskieur.h"
#include <string.h>

/*
# --------------------------------------
# Nom Procedure : CCourseSki(nomCompettiteur,prenomCompetiteur,emailCompetiteur,numeroDossardCompetiteur)
# Classe: CSkieur
# Sujet : constructeur surchargé de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
CSkieur::CSkieur(char* nomCompettiteur, char* prenomCompetiteur, char* emailCompetiteur, unsigned short numeroDossardCompetiteur)
{
    nom = new char[256];
    strcpy(nom,nomCompettiteur);

    prenom = new char[256];
    strcpy(prenom,prenomCompetiteur);

    email = new char[256];
    strcpy(email,emailCompetiteur);

    numeroDossard = numeroDossardCompetiteur;

    temps = 0;
}

/*
# --------------------------------------
# Nom Procedure : CSkieur()
# Classe: CSkieur
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
CSkieur::CSkieur()
{
}

/*
# --------------------------------------
# Nom Procedure : ~CSkieur()
# Classe: CSkieur
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
CSkieur::~CSkieur()
{
}

/*
# --------------------------------------
# Nom Procedure : setNom( name )
# Classe: CSkieur
# Sujet : copie le nom du participant de name vers nom
# Entree : name : string
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CSkieur::setNom(char* name)
{
    nom = new char[256];
    strcpy(nom,name);
}

/*
# --------------------------------------
# Nom Procedure : setPrenom( vername )
# Classe: CSkieur
# Sujet : copie le prenom du participant de vername vers prenom
# Entree : vername : string
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CSkieur::setPrenom(char* vername)
{
    prenom = new char[256];
    strcpy(prenom,vername);
}

/*
# --------------------------------------
# Nom Procedure : setEmail( mail )
# Classe: CSkieur
# Sujet : copie l'email du participant de mail vers email
# Entree : vername : string
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CSkieur::setEmail(char* mail)
{
    email = new char[256];
    strcpy(email,mail);
}

/*
# --------------------------------------
# Nom Procedure : setNumeroDossard( dossard )
# Classe: CSkieur
# Sujet : copie le numero de dossard du participant de dossard vers numeroDossard
# Entree : dossard : entier court non signé
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CSkieur::setNumeroDossard(unsigned short dossard)
{
    numeroDossard = dossard;
}

/*
# --------------------------------------
# Nom Procedure : setTemps( time )
# Classe: CSkieur
# Sujet : copie le temps du participant de time vers temps
# Entree : time : entier court non signé
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CSkieur::setTemps(unsigned short time)
{
    temps = time;
}


/*
# --------------------------------------
# Nom Procedure : getEmail()
# Classe: CSkieur
# Sujet : renvois la variable email
# Entree : aucune
# Sortie : email : string
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
char* CSkieur::getEmail()
{
    return email;
}

/*
# --------------------------------------
# Nom Procedure : getNom()
# Classe: CSkieur
# Sujet : renvois la variable nom
# Entree : aucune
# Sortie : nom : string
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
char* CSkieur::getNom()
{
    return nom;
}

/*
# --------------------------------------
# Nom Procedure : getPrenom()
# Classe: CSkieur
# Sujet : renvois la variable prenom
# Entree : aucune
# Sortie : prenom : string
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
char* CSkieur::getPrenom()
{
    return prenom;
}

/*
# --------------------------------------
# Nom Procedure : getTemps()
# Classe: CSkieur
# Sujet : renvois la variable temps
# Entree : aucune
# Sortie : temps : entier court non signé
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
unsigned short CSkieur::getTemps()
{
    return temps;
}

/*
# --------------------------------------
# Nom Procedure : getNumeroDossard()
# Classe: CSkieur
# Sujet : renvois la variable numeroDossard
# Entree : aucune
# Sortie : numeroDossard : entier court non signé
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
unsigned short CSkieur::getNumeroDossard()
{
    return numeroDossard;
}

