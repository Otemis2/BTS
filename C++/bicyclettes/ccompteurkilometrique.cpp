/*
#-----------------------------------------------------------------------
# Nom Fichier: ccompteurkilometrique.cpp
# Classe : CCompteurkilometrique
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "ccompteurkilometrique.h"

/*
# --------------------------------------
# Nom Procedure : CCompteurKilometrique()
# Classe: CCompteurKilometrique
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CCompteurKilometrique::CCompteurKilometrique()
{
}

/*
# --------------------------------------
# Nom Procedure : ~CCompteurKilometrique()
# Classe: CCompteurKilometrique
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CCompteurKilometrique::~CCompteurKilometrique()
{
}

/*
# --------------------------------------
# Nom Procedure : getKMTotal()
# Classe: CCompteurKilometrique
# Sujet : renvois la variable kmTotal
# Entree : aucune
# Sortie : kmTotal : floatant
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
float CCompteurKilometrique::getKMTotal()
{
    return kmTotal;
}

/*
# --------------------------------------
# Nom Procedure : setKMTotal( kmCompeteur)
# Classe: CCompteurKilometrique
# Sujet : copie le kmCompeteur dans kmTotal
# Entree : kmCompeteur : floatant
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CCompteurKilometrique::setKMTotal( float kmCompeteur)
{
    kmTotal = kmCompeteur;
}
