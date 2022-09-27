/*
#-----------------------------------------------------------------------
# Nom Fichier: cbicyclette.cpp
# Classe : CBicyclette
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "cbicyclette.h"
#include <string.h>

/*
# --------------------------------------
# Nom Procedure : CBicyclette
# Classe: CBicyclette
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CBicyclette::CBicyclette()
{
    compteur =  new CCompteurKilometrique();
}

/*
# --------------------------------------
# Nom Procedure : ~CBicyclette
# Classe: CBicyclette
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CBicyclette::~CBicyclette()
{
}

/*
# --------------------------------------
# Nom Procedure : getType()
# Classe: CBicyclette
# Sujet : renvois la variable type
# Entree : aucune
# Sortie : type : string
# Retour : aucun
# Auteur :
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
char* CBicyclette::getType()
{
    return type;
}

/*
# --------------------------------------
# Nom Procedure : getNumeroInventaire()
# Classe: CBicyclette
# Sujet : renvois la variable numeroInventaire
# Entree : aucune
# Sortie : numeroInventaire : unsigned short
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
unsigned short CBicyclette::getNumeroInventaire()
{
    return numeroInventaire;
}

/*
# --------------------------------------
# Nom Procedure : setType(typeVelo)
# Classe: CBicyclette
# Sujet : copie le typeVelo dans type
# Entree : typeVelo : string
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CBicyclette:: setType(char* typeVelo)
{
    type = new char[256];
    strcpy(type,typeVelo);
}

/*
# --------------------------------------
# Nom Procedure : setNumeroInventaire(numeroInventaireVelo)
# Classe: CBicyclette
# Sujet : copie le numeroInventaireVelo dans numeroInventaire
# Entree : numeroInventaireVelo : entier court non signé
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CBicyclette::setNumeroInventaire(unsigned short numeroInventaireVelo)
{
    numeroInventaire = numeroInventaireVelo;
}
