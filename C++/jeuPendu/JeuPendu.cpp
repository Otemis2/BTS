/*
#-----------------------------------------------------------------------
# Nom : CJeuPendu.cpp
# Sujet : programme console de test unitaire du jeu du Pendu
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "JeuPendu.h"

using namespace std;

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Constructeur
# Classe : CJeuPendu
# Sujet : constructeur de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
CJeuPendu::CJeuPendu()
{

    tentative = 0;
    strcpy(mot7lettres[0],"CARREAU");
    strcpy(mot7lettres[1],"COULOIR");
    strcpy(mot7lettres[2],"DOSSIER");
    strcpy(mot7lettres[3],"FENETRE");
    strcpy(mot7lettres[4],"MATELAS");
    strcpy(mot7lettres[5],"PELUCHE");

}


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Destructeur
# Classe : CJeuPendu
# Sujet : Destructeur de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

CJeuPendu::~CJeuPendu()
{}


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getTentative
# Classe : CJeuPendu
# Sujet : getTentative de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  tentative
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

unsigned short CJeuPendu::getTentative()
{

    return tentative;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setTentative
# Classe : CJeuPendu
# Sujet : setTentative de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  tentative
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

void CJeuPendu::setTentative(unsigned short tent)
{

    tentative = tent;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : motSecret
# Classe : CJeuPendu
# Sujet : motSecret de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/


char* CJeuPendu::motSecret()
{

    srand(time(NULL));

    short i = rand() %6;

    strcpy (secretWord, mot7lettres[i]);

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : motATrouver
# Classe : CJeuPendu
# Sujet : motATrouver de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  motATrouver
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

char* CJeuPendu::motATrouver()
{

    strcpy(motATrouve,"*******");

    return motATrouve;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Proposer
# Classe : CJeuPendu
# Sujet : Proposer de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) : lettre
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------

#-----------------------------------------
# Nom : mettreMajuscules
# Sujet : convertir tous les caracteres alphabétiques d'une chaine
#-----------------------------------------------
Procédure mettreMajuscules (inout chaine ; chaine de caractères)
var : i : entier
Début
    Pour (i<-0 jusqu'à longueur(chaine)-1 avec un  pas de 1) faire
        si (chaine[i]>='a' Et chaine[i]<='z')alors
            chaine[i]=chaine[i]+'A'-'a'
        Fin Si
    Fin Pour
Fin
*/

bool CJeuPendu::Proposer(char lettre)
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
# Classe : CJeuPendu
# Sujet : getMotSecret de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) : secretWord
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

char* CJeuPendu::getMotSecret()
{

    return secretWord;

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getMotATrouve
# Classe : CJeuPendu
# Sujet : getMotATrouve de la classe CJEUPENDU
# Version : 0.1
# Entrees (in) :
# Sorties (out) : motATrouve
# Entrees/Sorties (inout) : Aucune
# Retour :  Aucune
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

char* CJeuPendu::getMotATrouve()
{

    return motATrouve;

}
