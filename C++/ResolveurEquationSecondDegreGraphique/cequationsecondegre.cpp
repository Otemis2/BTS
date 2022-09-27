/*# -----------------------------------------------------------------------
# Nom Fichier: CEquationSecondDegre.cpp
# Sujet : Definition de la classe CEQuationSecondDegre.
# Version : 0.1
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# --------------------------------------------------------------------------*/
#include "cequationsecondegre.h"
#include <math.h>
#include <iostream>
using namespace std;
/*# -----------------------------------------------------------------------
# Nom Fonction Membre :CEquationSecondDegre
# Classe : CEquationSecondDegre
# Sujet :constructeur de la classe
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
CEquationSeconDegre::CEquationSeconDegre()
{
    a = 0;
    b = 0;
    c = 0;
    x1 = 0;
    delta = 0;
    x2 = 0;
}
/*# -----------------------------------------------------------------------
# Nom Fonction Membre :CEquationSecondDegre
# Classe : CEquationSecondDegre
# Sujet :constructeur surcharge de la classe
# Version : 0.1
# Entree : a1: short
#          b1: short
#          c1: short
# Sortie : aucune
# Retour : aucun
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
CEquationSeconDegre::CEquationSeconDegre(short a1, short b1, short c1)
{
    a = a1;
    b = b1;
    c = c1;
    x1 = 0;
    x2 = 0;
    delta = 0;
}
/*# -----------------------------------------------------------------------
# Nom Fonction Membre :~CEquationSecondDegre
# Classe : CEquationSecondDegre
# Sujet :destructeur de la classe
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
CEquationSeconDegre::~CEquationSeconDegre()
{

}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :calculerDiscriminant
# Classe : CEquationSecondDegre
# Sujet :constructeur surcharge de la classe
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : short; valeur du discriminant
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
short CEquationSeconDegre::calculerDiscriminant()
{
    delta = b*b-4*a*c;
    return delta;
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :racineDouble
# Classe : CEquationSecondDegre
# Sujet :calcule x1 si delta = 0
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : bool; false si erreur
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
bool CEquationSeconDegre::racineDouble()
{

    if(( a != 0)&&( delta == 0))
    {
        x1 = float(- b/(2*a));
        x2 = x1;
        return true;
    }
    else
    {
        return false;
    }
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :racineReel
# Classe : CEquationSecondDegre
# Sujet :calcule les racines x1 et x2 reel
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : bool; false si erreur
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
bool CEquationSeconDegre::racineReel()
{
    if(( a != 0)&&( delta > 0))
    {
        x1 = - (float)(b)/float(2*a)
                - sqrt(delta)/(float)(2*a);
        cout << x1<<endl;
        x2 = - (float)(b)/float(2*a)
                + sqrt(delta)/(float)(2*a);
        return true;
    }
    else
    {
        return false;
    }

}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :getA
# Classe : CEquationSecondDegre
# Sujet :accesseur de l'attribut a
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : short; valeur de l'attribut a
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/

short CEquationSeconDegre::getA()
{
    return a;
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :getB
# Classe : CEquationSecondDegre
# Sujet :accesseur de l'attribut b
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : short; valeur de l'attribut b
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/

short CEquationSeconDegre::getB()
{
    return b;
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :getC
# Classe : CEquationSecondDegre
# Sujet :accesseur de l'attribut c
# Version : 0.1
# Entree : aucune
# Sortie : aucune
# Retour : short; valeur de l'attribut c
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/

short CEquationSeconDegre::getC()
{
    return c;
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :setA
# Classe : CEquationSecondDegre
# Sujet :mutateur de l'attribut a
# Version : 0.1
# Entree : a1 short ; valeur à écrire dans l'attribut
# Sortie : aucune
# Retour : aucune;
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/

void CEquationSeconDegre::setA(short a1)
{
    a = a1;
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :setB
# Classe : CEquationSecondDegre
# Sujet :mutateur de l'attribut b
# Version : 0.1
# Entree : b1 short ; valeur à écrire dans l'attribut
# Sortie : aucune
# Retour : aucune;
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
void CEquationSeconDegre::setB(short b1)
{
    b = b1;
}
/*
# -----------------------------------------------------------------------
# Nom Fonction Membre :setC
# Classe : CEquationSecondDegre
# Sujet :mutateur de l'attribut c
# Version : 0.1
# Entree : c1 short ; valeur à écrire dans l'attribut
# Sortie : aucune
# Retour : aucune;
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# -----------------------------------------------------------------------*/
 void CEquationSeconDegre::setC(short c1)
 {
     c = c1;
 }
 /*
 # -----------------------------------------------------------------------
 # Nom Fonction Membre :getX1
 # Classe : CEquationSecondDegre
 # Sujet :accesseur de l'attribut x1
 # Version : 0.1
 # Entree : aucune
 # Sortie : aucune
 # Retour : float; valeur de l'attribut x1
 # Auteur : Chameroy Estelle
 # Création : 26/11/2018
 # Mise à jour :
 # -----------------------------------------------------------------------*/

 float CEquationSeconDegre::getX1()
 {
     return x1;
 }
 /*
 # -----------------------------------------------------------------------
 # Nom Fonction Membre :getX2
 # Classe : CEquationSecondDegre
 # Sujet :accesseur de l'attribut x2
 # Version : 0.1
 # Entree : aucune
 # Sortie : aucune
 # Retour : float; valeur de l'attribut x2
 # Auteur : Chameroy Estelle
 # Création : 26/11/2018
 # Mise à jour :
 # -----------------------------------------------------------------------*/
 float CEquationSeconDegre::getX2()
 {
     return x2;
 }

