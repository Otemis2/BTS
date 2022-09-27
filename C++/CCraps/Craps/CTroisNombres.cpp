/*#----------------------------------------------------------
# Nom Fichier : CTroisNombres.cpp
# Sujet : Définition de la classe CTroisNombres
# Version : 0.1
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

#include <iostream>
#include "CTroisNombres.h"

/*#----------------------------------------------------------
# Nom Fonction Membre : CTroisNombres
# Classe : CTroisNombres
# Sujet : constructeur de la classe
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

CTroisNombres::CTroisNombres()
{
    nb1=0;
    nb2=0;
    nb3=0;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : CTroisNombres
# Classe : CTroisNombres
# Sujet : constructeur surchargé de la classe
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

CTroisNombres::CTroisNombres(int val1, int val2, int val3)
{
    nb1=val1;
    nb2=val2;
    nb3=val3;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : ~CTroisNombres
# Classe : CTroisNombres
# Sujet : destructeur de la classe
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

CTroisNombres::~CTroisNombres()
{
}

/*#----------------------------------------------------------
# Nom Fonction Membre : setNb1
# Classe : CTroisNombres
# Sujet : attribut val1 à nb1 (MUTATEUR1)
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

void CTroisNombres::setNb1(int val1)
{
    nb1=val1;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : setNb2
# Classe : CTroisNombres
# Sujet : attribut val2 à nb2 (MUTATEUR2)
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

void CTroisNombres::setNb2(int val2)
{
    nb2=val2;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : setNb3
# Classe : CTroisNombres
# Sujet : attribut val3 à nb3 (MUTATEUR3)
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

void CTroisNombres::setNb3(int val3)
{
    nb3=val3;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : getNb1
# Classe : CTroisNombres
# Sujet : récupère la valeur de val1 (ACCESSEUR1)
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

int CTroisNombres::getNb1()
{
    return nb1;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : getNb2
# Classe : CTroisNombres
# Sujet : récupère la valeur de val2 (ACCESSEUR2)
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

int CTroisNombres::getNb2()
{
    return nb2;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : getNb3
# Classe : CTroisNombres
# Sujet : récupère la valeur de val3 (ACCESSEUR3)
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

int CTroisNombres::getNb3()
{
    return nb3;
}

/*#----------------------------------------------------------
# Nom Fonction Membre : grand
# Classe : CTroisNombres
# Sujet : renvoi le plus grand nombre des 3
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

int CTroisNombres::grand()
{
    if ((nb1>nb2)&&(nb1>nb3))
    {
        return nb1;
    }
    else
    {
        if ((nb2>nb1)&&(nb2>nb1))
        {
            return nb2;
        }
        else
        {
            if ((nb3>nb1)&&(nb3>nb2))
            {
                return nb3;
            }
        }
    }
}

/*#----------------------------------------------------------
# Nom Fonction Membre : moyen
# Classe : CTroisNombres
# Sujet : renvoi le nombre moyen des 3
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

int CTroisNombres::moyen()
{
    if (((nb1>nb2)&&(nb1<nb3))||((nb1<nb2)&&(nb1>nb3)))
    {
        return nb1;
    }
    else
    {
        if (((nb2>nb1)&&(nb2<nb3))||((nb2<nb1)&&(nb2>nb3)))
        {
            return nb2;
        }
        else
        {
            if (((nb3>nb1)&&(nb3<nb2))||((nb3<nb1)&&(nb3>nb2)))
            {
                return nb3;
            }
        }
    }
}

/*#----------------------------------------------------------
# Nom Fonction Membre : petit
# Classe : CTroisNombres
# Sujet : renvoi le plus petit nombre des 3
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

int CTroisNombres::petit()
{
    if ((nb1<nb2)&&(nb1<nb3))
    {
        return nb1;
    }
    else
    {
        if ((nb2<nb1)&&(nb2<nb3))
        {
            return nb2;
        }
        else
        {
            if ((nb3<nb1)&&(nb3<nb2))
            {
                return nb3;
            }
        }
    }
}
