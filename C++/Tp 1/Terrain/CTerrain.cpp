/*-----------------------------------------------------------------------
#Nom Fichier:CTerrain.cpp
#Classe:CTerrain
#Sujet:gestion d'un Terrain
#Version:0.1
#Auteur:HUCK
#Création:12/10/2020
#----------------------------------------------------------------------------------------------------------*/
#include "CTerrain.h"

/*-----------------------------------------------------------------------
#Nom Fonction Membre:CTerrain
#Classe:CTerrain
#Sujet:constructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/
CTerrain::CTerrain()
{
    longueur =0;
    largeur =0;
}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:~CTerrain
#Classe:CTerrain
#Sujet:destructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/
CTerrain::~CTerrain()
{

}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:calculerSuperficieEnM2
#Classe:CTerrain
#Sujet:calculer
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: long; superficie du cercle en M2
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/
/*algo
  variable :
    SuperficieEnM2 : long
Debut
    SuperficieEnM2 <- longueur*largeur
    retourne terrain
*/

long CTerrain::calculerSuperficieEnM2()
{
 long SuperficeEnM2;
 SuperficeEnM2 = longueur*largeur;
 return SuperficeEnM2;
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre:calculerSuperficieEnHectare
#Classe:CTerrain
#Sujet:calculer
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: float; superficie du cercle en Hectare
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/
/*algo
variable :
        SuperficieEnHectare : réel
Debut
        SuperficieEnHectare <- SurperficieEnM2/10000
        retourne terrain
*/

float CTerrain::calculerSuperficieEnHectare()
{
    long SuperficieEnM2;
    float SuperficeEnHectare;
    SuperficeEnHectare = (longueur*largeur)/10000.0;
    return SuperficeEnHectare;
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre:getLongueur
#Classe:CTerrain
#Sujet:accesceur de l'attribut longueur
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour: long; valeur de la longueur
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/

long CTerrain::getLongueur()
    {
      return longueur;
    }

/*-----------------------------------------------------------------------
#Nom Fonction Membre:getLargeur
#Classe:CTerrain
#Sujet:accesceur de l'attribut largeur
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: long; valeur de la largeur
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/

long CTerrain::getLargeur()
    {
      return largeur;
    }

/*-----------------------------------------------------------------------
#Nom Fonction Membre:setLongueur
#Classe:CTerrain
#Sujet: mutateur de l'attribut longueur
#Version:0.1
#Entrees (in): long L ;Longueur du terrain
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: aucune
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/

void CTerrain::setLongueur(long L)
{
    longueur = L;
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre:setLargeur
#Classe:CTerrain
#Sujet: mutateur de l'attribut largeur
#Version:0.1
#Entrees (in): long l ;largeur du terrain
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: aucune
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------*/

void CTerrain::setLargeur(long l)
{
    largeur = l;
}
