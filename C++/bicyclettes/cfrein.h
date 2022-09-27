/*
# -----------------------------------------------------------------------
# Nom Fichier : cfrein.h
# Classe : CFrein
# Sujet : gestion du programme bicyclette
# Auteur : HUCK
# Cr�ation : 07/10/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
#ifndef CFREIN_H
#define CFREIN_H

class CFrein
{
private:
    char* caracteristique;
public:
    CFrein();
    ~CFrein();
    char* getCaracteristique();
    void setCaracterisque( char* caracteristiqueFrein);
};

#endif // CFREIN_H
