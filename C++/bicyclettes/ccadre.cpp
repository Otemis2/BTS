/*
#-----------------------------------------------------------------------
# Nom Fichier: ccadre.cpp
# Classe : CCadre
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "ccadre.h"
#include <string.h>

/*
# --------------------------------------
# Nom Procedure : CCadre()
# Classe: CCadre
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CCadre::CCadre()
{
}

/*
# --------------------------------------
# Nom Procedure : ~CCadre()
# Classe: CCadre
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CCadre::~CCadre()
{
}

/*
# --------------------------------------
# Nom Procedure : setTaille ( tailleCadre )
# Classe: CCadre
# Sujet : copie la taille dans tailleCadre
# Entree : tailleCadre : entier court non signé
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CCadre::setTaille ( unsigned short tailleCadre )
{
    taille = tailleCadre;
}

/*
# --------------------------------------
# Nom Procedure : setCouleur ( couleurCadre )
# Classe: CCadre
# Sujet : copie le couleurCadre dans couleur
# Entree : couleurCadre : string
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CCadre::setCouleur ( char* couleurCadre )
{
    couleur = new char[256];
    strcpy( couleur,couleurCadre );
}

/*
# --------------------------------------
# Nom Procedure : getTaille()
# Classe: CCadre
# Sujet : renvois la variable taille
# Entree : aucune
# Sortie : taille : entier court
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
unsigned short CCadre::getTaille()
{
    return taille;
}

/*
# --------------------------------------
# Nom Procedure : getCouleur()
# Classe: CCadre
# Sujet : renvois la variable couleur
# Entree : aucune
# Sortie : couleur : string
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
char* CCadre::getCouleur()
{
    return couleur;
}
