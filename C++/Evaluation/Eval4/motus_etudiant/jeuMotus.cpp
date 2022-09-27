/*
#-----------------------------------------------------------------------
# Nom : CJeuMotus.cpp
# Sujet : programme console de test unitaire du jeu du Motus
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "jeuMotus.h"

using namespace std;

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Constructeur
# Classe : CJeuMotus
# Sujet : constructeur de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
CJeuMotus::CJeuMotus()
{

    tentative = 0;
    strcpy(mot7lettres[0],"CHEVAL");
    strcpy(mot7lettres[1],"OISEAU");
    strcpy(mot7lettres[2],"MAJEUR");
    strcpy(mot7lettres[3],"DESERT");
    strcpy(mot7lettres[4],"RATEAU");
    strcpy(mot7lettres[5],"ORANGE");

}


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Destructeur
# Classe : CJeuMotus
# Sujet : Destructeur de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/

CJeuMotus::~CJeuMotus()
{}


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getTentative
# Classe : CJeuMotus
# Sujet : getTentative de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  tentative
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/

unsigned short CJeuMotus::getTentative()
{

    return tentative;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setTentative
# Classe : CJeuMotus
# Sujet : setTentative de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  tentative
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/

void CJeuMotus::setTentative(unsigned short tent)
{

    tentative = tent;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : motSecret
# Classe : CJeuMotus
# Sujet : motSecret de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/


char* CJeuMotus::motSecret()
{

    srand(time(NULL));

    short i = rand() %6;

    strcpy (secretWord, mot7lettres[i]);

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : motATrouver
# Classe : CJeuMotus
# Sujet : motATrouver de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  motATrouver
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/

char* CJeuMotus::motATrouver()
{

    strcpy(motATrouve,"*******");

    return motATrouve;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Proposer
# Classe : CJeuMotus
# Sujet : Proposer de la classe CJeuMotus
# Version : 0.1
# Entrees (in) : lettre
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------

#-----------------------------------------
# Nom : mettreMajuscules
# Sujet : convertir tous les caracteres alphab�tiques d'une chaine
#-----------------------------------------------
Proc�dure mettreMajuscules (inout chaine ; chaine de caract�res)
var : i : entier
D�but
    Pour (i<-0 jusqu'� longueur(chaine)-1 avec un  pas de 1) faire
        si (chaine[i]>='a' Et chaine[i]<='z')alors
            chaine[i]=chaine[i]+'A'-'a'
        Fin Si
    Fin Pour
Fin
*/

bool CJeuMotus::Proposer(char lettre)
{

        if (lettre >='a' && lettre <='z')
        {
            lettre = lettre +'A'-'a';
        }


    bool present = false;

    for (short i = 0; i <= 7; i++)
    {

        if (secretWord[i] == lettre)
        {

            motATrouve[i] = lettre;

            present = true;

        }

    }

    if (present == false)
    {
        cout << endl << "La lettre : " << lettre << " n'est pas presente dans le mot !"<<endl;
    }
    else
    {
        cout << "La lettre : " << lettre << " est presente dans le mot !"<<endl;
    }

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getMotSecret
# Classe : CJeuMotus
# Sujet : getMotSecret de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) : secretWord
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/

char* CJeuMotus::getMotSecret()
{

    return secretWord;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getMotATrouve
# Classe : CJeuMotus
# Sujet : getMotATrouve de la classe CJeuMotus
# Version : 0.1
# Entrees (in) :
# Sorties (out) : motATrouve
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Cr�ation : 24/01/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/

char* CJeuMotus::getMotATrouve()
{

    return motATrouve;

}
