/*-----------------------------------------------------------------------
#NomFichier:ccercle.cpp
#Classe:ccercle
#Sujet:gestion d'un cercle
#Version:0.1
#Auteur:chameroy
#Création:06/10/2020
#Mise à jour:
#----------------------------------------------------------------------------------------------------------*/
#include "ccercle.h"

/*-----------------------------------------------------------------------
#NomFonctionMembre:ccercle
#Classe:ccercle
#Sujet:constructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
# Eentrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:06/10/2020
#Miseàjour:
#-----------------------------------------------------------------------*/
ccercle::ccercle()
{
    rayon =0;
    x =0;
    y =0;
}
    /*-----------------------------------------------------------------------
    #NomFonctionMembre:~ccercle
    #Classe:ccercle
    #Sujet:destructeur de classe
    #Version:0.1
    #Entrees (in): Aucune
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour:Type; Aucune
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/
    ccercle::~ccercle()
    {

    }
    /*-----------------------------------------------------------------------
    #NomFonctionMembre:calculerPerimetre
    #Classe:ccercle
    #Sujet:calculer le perimetre du cercle de rayon::rayon
    #Version:0.1
    #Entrees (in): Aucune
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour: float; perimetre du cercle
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/
/*algo
  constante
  PI: réel = 3.14
  variable :
    perimetre : réel; perimetre du cercle
Debut
    perimetre <- 2*PI*rayon
    retourne perimetre
Fin
*/

    float ccercle::calculerPerimetre()
    {
        float perimetre;
        const float PI = 3.14;
        perimetre = 2 * PI *rayon;
        return perimetre;
    }

    /*-----------------------------------------------------------------------
    #NomFonctionMembre:calculerSurface
    #Classe:ccercle
    #Sujet:calculer la surface du cercle de rayon::rayon
    #Version:0.1
    #Entrees (in): Aucune
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour: float; surface du cercle
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/
/*algo
  constante
  PI: réel = 3.14
  variable :
    surface : réel; surface du cercle
Debut
    surface <- PI*rayon*rayon
    retourne surface
Fin
*/

    float ccercle::calculerSurface()
    {
        float surface;
        const float PI = 3.14;
        surface = PI * rayon * rayon;
        return surface;
    }

    /*-----------------------------------------------------------------------
    #Nom Fonction Membre:getRayon
    #Classe:ccercle
    #Sujet:accesceur de l'attribut rayon
    #Version:0.1
    #Entrees (in): Aucune
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour: short; valeur du rayon
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/

    short ccercle::getRayon()
        {
        return rayon;
        }

    /*-----------------------------------------------------------------------
    #Nom Fonction Membre:getX
    #Classe:ccercle
    #Sujet:accesceur de l'attribut X
    #Version:0.1
    #Entrees (in): Aucune
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour: short; valeur de la coordonnee X du rayon
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/

    short ccercle::getX()
        {
        return x;
        }
    /*-----------------------------------------------------------------------
    #Nom Fonction Membre:getY
    #Classe:ccercle
    #Sujet:accesceur de l'attribut Y
    #Version:0.1
    #Entrees (in): Aucune
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour: short; valeur de la coordonnee Y du rayon
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/

    short ccercle::getY()
        {
        return y;
        }

    /*-----------------------------------------------------------------------
    #Nom Fonction Membre:setRayon
    #Classe:ccercle
    #Sujet: mutateur de l'attribut rayon
    #Version:0.1
    #Entrees (in): short r ;rayon du cercle
    #Sorties (out): Aucune
    # Eentrees/Sorties (inout): Aucune
    #Retour: aucune
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/

    void ccercle::setRayon(short r)
    {
        rayon = r;
    }

    /*-----------------------------------------------------------------------
    #Nom Fonction Membre:setX
    #Classe:ccercle
    #Sujet: mutateur de l'attribut x
    #Version:0.1
    #Entrees (in): short coordX ;coordonnee x du cercle
    #Sorties (out): Aucune
    #Entrees/Sorties (inout): Aucune
    #Retour: aucune
    #Auteur:HUCK
    #Création:06/10/2020
    #Miseàjour:
    #-----------------------------------------------------------------------*/

    void ccercle::setX(short coordX)
    {
        x = coordX;
    }

    /*-----------------------------------------------------------------------
    #Nom Fonction Membre:setY
    #Classe:ccercle
    #Sujet: mutateur de l'attribut Y
    #Version:0.1
    #Entrees (in): short coordY ;coordonnee Y du cercle
    #Sorties (out): Aucune
    #Entrees/Sorties (inout): Aucune
    #Retour: aucune
    #Auteur:HUCK
    #Création:06/10/2020
    #Mise à jour:
    #-----------------------------------------------------------------------*/

    void ccercle::setY(short coordY)
    {
        y = coordY;
    }
