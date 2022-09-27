/*
#-----------------------------------------------------------------------
# Nom Fichier: croue.cpp
# Classe : CRoue
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "croue.h"

/*
# --------------------------------------
# Nom Procedure : CRoue()
# Classe: CRoue
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CRoue::CRoue()
{
}

/*
# --------------------------------------
# Nom Procedure : ~CRoue()
# Classe: CRoue
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
CRoue::~CRoue()
{
}

/*
# --------------------------------------
# Nom Procedure : getDiametre()
# Classe: CRoue
# Sujet : renvois la variable diametre
# Entree : aucune
# Sortie : diametre : entier court non signé
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
unsigned short CRoue::getDiametre()
{
    return diametre;
}

/*
# --------------------------------------
# Nom Procedure : setDiametre( diametreRoue )
# Classe: CRoue
# Sujet : copie le diametreRoue dans diametre
# Entree : diametreRoue : entier court non signé
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 07/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CRoue::setDiametre( unsigned short diametreRoue )
{
    diametre = diametreRoue;
}
