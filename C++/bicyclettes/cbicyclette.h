/*
# -----------------------------------------------------------------------
# Nom Fichier : cbicyclette.h
# Classe : CBicyclette
# Sujet : gestion du programme bicyclette
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CBICYCLETTE_H
#define CBICYCLETTE_H

#include "ccadre.h"
#include "ccompteurkilometrique.h"
#include "cfrein.h"
#include "croue.h"

class CBicyclette
{
private:
    char* type;
    unsigned short numeroInventaire;

    CCadre cadre;
    CCompteurKilometrique * compteur;
    CFrein freins[2];
    CRoue roues[2];

public:
    CBicyclette();
    ~CBicyclette();
    char* getType();
    unsigned short getNumeroInventaire();
    void setType(char* typeVelo);
    void setNumeroInventaire(unsigned short numeroInventaireVelo);

};

#endif // CBICYCLETTE_H
