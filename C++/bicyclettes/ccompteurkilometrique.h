/*
# -----------------------------------------------------------------------
# Nom Fichier : ccompteurKilometrique.h
# Classe : CCompteurKilometrique
# Sujet : gestion du programme bicyclette
# Auteur : HUCK
# Cr�ation : 07/10/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
#ifndef CCOMPTEURKILOMETRIQUE_H
#define CCOMPTEURKILOMETRIQUE_H

class CCompteurKilometrique
{
private:
    float kmTotal;
public:
    CCompteurKilometrique();
    ~CCompteurKilometrique();
    float getKMTotal();
    void setKMTotal( float kmCompeteur);
};

#endif // CCOMPTEURKILOMETRIQUE_H
