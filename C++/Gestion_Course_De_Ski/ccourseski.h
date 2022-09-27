/*
# -----------------------------------------------------------------------
# Nom Fichier : ccourseSki.h
# Classe : CCourseSki
# Sujet : gestion du programme gestion d'une course de ski
# Auteur : HUCK
# Création : 16/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CCOURSESKI_H
#define CCOURSESKI_H
#include "cskieur.h"

class CCourseSki
{
private:
    unsigned short nbParticipant;
    CSkieur* Skieur[50];
public:
    CCourseSki();
    ~CCourseSki();
    unsigned short getNbParticipant();
    void setNbParticipant(unsigned short nb);
    void classer();

    CSkieur* getParticipant(unsigned short numeroInscription);
    void setParticipant(unsigned short numeroInscription,CSkieur* competiteurCourant);

};

#endif // CCOURSESKI_H
