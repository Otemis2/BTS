/*-----------------------------------------------------------------------
#Nom Fichier:CEquation.cpp
#Classe:CEquation
#Sujet:gestion d'un Terrain
#Version:0.1
#Auteur:HUCK
#Création:13/10/2020
#----------------------------------------------------------------------------------------------------------*/
#include "Equation.h"
#include <cmath>
/*-----------------------------------------------------------------------
#Nom Fonction Membre:CEquation
#Classe:CEquation
#Sujet:constructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:13/10/2020
#-----------------------------------------------------------------------*/
CEquation::CEquation()
{
    a =0;
    b =0;
    c =0;
}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:~CEquation
#Classe:CEquation
#Sujet:destructeur de classe
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucune
#Auteur:HUCK
#Création:13/10/2020
#-----------------------------------------------------------------------*/
CEquation::~CEquation()
{

}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:calculerDelta
#Classe:CEquation
#Sujet:calculer
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: short; Delta
#Auteur:HUCK
#Création:13/10/2020
#-----------------------------------------------------------------------*/
/*algo
  variable :
    Delta : short
Debut
    Delta <- b²-4ac
    retourne Equation
*/

short CEquation::calculerDelta()
{
 short Delta;
 Delta = (b*b)-(4*a*c);
 return Delta;
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre:calculerRacineDouble
#Classe:CEquation
#Sujet:calculer
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: float; x1
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/
/*algo
variable :
        x1 : float
Debut
        x1 <- (-b)/(2*a)
        retourne x1
*/

float CEquation::calculerRacineDouble()
{

    float x1;
    x1 = ((-b)/(2*a));
    return x1;
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre:calculerRacineReels
#Classe:CEquation
#Sujet:calculer
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: float : x1 ,x2
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/
/*algo
variable :
        x1,x2 : float
Debut
        x1 <- (-b)/(2*a)
        x2 <- (-b)/(2*a)
        retourne x1,x2
*/

float CEquation::calculerRacineReels()
{

    float x1,x2;
    x1 = ((-b + sqrt (delta))/(2*a));
    x2 = ((-b - (sqrt (delta)))/(2*a));
    return x1,x2;
}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:getX1
#Classe:CEquation
#Sujet:accesceur de l'attribut x1
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: float; valeur de x1
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

float CEquation::getX1()
    {
      return x1;
    }
/*-----------------------------------------------------------------------
#Nom Fonction Membre:getX2
#Classe:CEquation
#Sujet:accesceur de l'attribut x2
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: float; valeur de x2
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

float CEquation::getX2()
    {
      return x2;
    }

/*-----------------------------------------------------------------------
#Nom Fonction Membre:getA
#Classe:CEquation
#Sujet:accesceur de l'attribut A
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: short; valeur de a
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

short CEquation::getA()
    {
      return a;
    }
/*-----------------------------------------------------------------------
#Nom Fonction Membre:getB
#Classe:CEquation
#Sujet:accesceur de l'attribut B
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: short; valeur de b
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

short CEquation::getB()
    {
      return b;
    }
/*-----------------------------------------------------------------------
#Nom Fonction Membre:getC
#Classe:CEquation
#Sujet:accesceur de l'attribut C
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: short; valeur de c
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

short CEquation::getC()
    {
      return c;
    }
/*-----------------------------------------------------------------------
#Nom Fonction Membre:setC
#Sujet: mutateur de l'attribut C
#Version:0.1
#Entrees (in): short C ;
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: aucune
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

void CEquation::setC(short c1)
{
    c = c1;
}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:setB
#Sujet: mutateur de l'attribut B
#Version:0.1
#Entrees (in): short B ;
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: aucune
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

void CEquation::setB(short b1)
{
    b = b1;
}
/*-----------------------------------------------------------------------
#Nom Fonction Membre:setA
#Sujet: mutateur de l'attribut A
#Version:0.1
#Entrees (in): short A ;
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour: aucune
#Auteur:HUCK
#Création:19/10/2020
#-----------------------------------------------------------------------*/

void CEquation::setA(short a1)
{
    a = a1;
}

