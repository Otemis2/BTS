/*-----------------------------------------------------------------------
# Nom Fichier : CArticle.h
# Classe : CArticle
# Sujet : calculer le prix de l'article
# Auteur : HUCK
# Création : 30/11/2020
# Mise à jour :
# -----------------------------------------------------------------------*/
#ifndef CARTICLE_H
#define CARTICLE_H

class CArticle
{
private :

    float prixHT;
    float tauxTVA;
    float prixTTC;

public :
    CArticle();
    ~CArticle();
    void CalculerPrixTTC();
    float getPrixTTC();
    float getPrixHT();
    float getTauxTVA();
    void setPrixHT(float prixHorsTaxe);
    void setTauxTVA(float tva);
};
#endif // CARTICLE_H

