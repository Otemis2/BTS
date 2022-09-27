/*
#-----------------------------------------------------------------------
# Nom Fichier: cfrein.cpp
# Classe : CFrein
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "cfrein.h"
#include <string.h>

/*
# --------------------------------------
# Nom Procedure : CFrein()
# Classe: CFrein
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CFrein::CFrein()
{
}

/*
# --------------------------------------
# Nom Procedure : ~CFrein()
# Classe: CFrein
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CFrein::~CFrein()
{
}

/*
# --------------------------------------
# Nom Procedure : getCaracteristique()
# Classe: CFrein
# Sujet : renvois la variable caracteristique
# Entree : aucune
# Sortie : caracteristique : string
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
char* CFrein::getCaracteristique()
{
    return caracteristique;
}

/*
# --------------------------------------
# Nom Procedure : setCaracterisque( caracteristiqueFrein )
# Classe: CFrein
# Sujet : copie le caracteristiqueFrein dans caracteristique
# Entree : caracteristiqueFrein : string
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CFrein::setCaracterisque( char* caracteristiqueFrein )
{
   caracteristique = new char[256];
   strcpy (caracteristique,caracteristiqueFrein);
}
