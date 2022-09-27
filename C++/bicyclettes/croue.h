/*
# -----------------------------------------------------------------------
# Nom Fichier : croue.h
# Classe : CRoue
# Sujet : gestion du programme bicyclette
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CROUE_H
#define CROUE_H

class CRoue
{
private:
    unsigned short diametre;
public:
    CRoue();
    ~CRoue();
    unsigned short getDiametre();
    void setDiametre( unsigned short diametreRoue );
};

#endif // CROUE_H
