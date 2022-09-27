/*-----------------------------------------------------------------------
# Nom Fichier: CArticle.cpp
# Classe : CArticle
# Sujet : calculer le prix TTC
# Version : 0.1
# Auteur : HUCK
# Création : 30/11/2020
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------*/
#include "CArticle.h"

/*-----------------------------------------------------------------------
#NomFonctionMembre:CArticle
#Classe:CArticle
#Sujet:constructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:20/11/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

CArticle::CArticle()
{
    TVA = 0;
    PrixHT =0 ;
    PrixTTC = 0;


}
/*-----------------------------------------------------------------------
#NomFonctionMembre:~CArticle
#Classe:CArticle
#Sujet:destructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:20/11/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

CArticle::~CArticle()
{

}
/*-----------------------------------------------------------------------
#NomFonctionMembre:CArticle
#Classe:CArticle
#Sujet:constructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:20/11/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

void CArticle::setPrixHT(float PrixHT)
{
    PrixHT = PrixHT;
}

void CArticle::setTVA(float TVA)
{
    TVA = TVA;
};
/*-----------------------------------------------------------------------
#NomFonctionMembre:CArticle
#Classe:CArticle
#Sujet:accesceur de l'attribut PrixTTC
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour:float , valeur du PrixTTC
#Auteur:HUCK
#Création:20/11/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

float CArticle::getPrixTTC()
{
    return PrixTTC;
};

/*-----------------------------------------------------------------------
#NomFonctionMembre:CArticle
#Classe:CArticle
#Sujet:calculer le prixTTC
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:20/11/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

void CArticle::CalculerPrixTTC()
{
    PrixTTC = PrixHT * (1 + (TVA/100));
}
