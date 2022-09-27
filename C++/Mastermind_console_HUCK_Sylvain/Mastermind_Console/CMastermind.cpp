/*
#-----------------------------------------------------------------------
# Nom Fichier: CMastermind.cpp
# Classe : CMastermind
# Sujet : gestion du jeu du mastermind
# Version : 0.1
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "CMastermind.h"
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Constructeur
# Classe : CMastermind
# Sujet : Constructeur de la classe CMastermind
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
CMastermind::CMastermind()
{

    nc=0;
    coup=0;
    srand(time(NULL));

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Destructeur
# Classe : CMastermind
# Sujet : Destructeur de la classe CMastermind
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
CMastermind::~CMastermind()
{

}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : initialiserJeu
# Classe : CMastermind
# Sujet : Permet d'iniatialiser le jeu du Mastermind en remplissent combinaison[i] par un nombre compris entre 0 et 8
# Version : 0.1
# Entrees (in) : nbCoul:entier court non sing� , nbCoup : non sign�
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------

initialiserJeu( nbCoul:entier court non sing� , nbCoup : non sign�)

VAR :
nc , nbCoul , coup , nbEssai , combinaison[4] : entier court non sign�
nbCoup : non sign�
i  :  entier court

Debut
    nc <- nbCoul
    coup <- nbCoup
    nbEssai <- 0
    i <- 0
    Pour (i jusqu'� 4 avec un pas de un)

        combinaison[i] <- nombreAl�atoire sur 8

    FinPour
Fin
*/
void CMastermind::initialiserJeu(unsigned short nbCoul, unsigned nbCoup)
{
    nc=nbCoul;
    coup=nbCoup;
    nbEssai=0;

    for (short i = 0; i<4;i++)
    {
        combinaison[i]= rand() %8;
    }

}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : analyser
# Classe : CMastermind
# Sujet : permettra de calculer le nombre de couleur bien et
mal plac�e � partir d�une proposition et la combinaison secr�te
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------

analyser()
Var :
nbBienPlacee , nbBonneCouleur , nbEssai , combinaison[4] , proposition[4] : entier court non sign�
i , t , j : entier court

Debut :

    nbBienPlacee <- 0
    nbBonneCouleur <- 0
    nbEssai <- nbEssai + 1
    i <- 0
    j <- 0

    Pour (j jusqu'� 4 avec un pas de un)
        Si (combinaison[j]= proposition[j])Alors

            nbBienPlacee <- nbBienPlacee + 1

        Sinon
            Pour (i jusqu'� 4 avec un pas de un)
                Si ((combinaison[i] = proposition[j])&(combinaison[i] <> proposition[i])&(combinaison[t] <> proposition[j]))
                    nbBonneCouleur <- nbBonneCouleur + 1
                    t=i
                FinSi
            FinPour
        FinSi
    FinPour
Fin
*/
void CMastermind::analyser()
{
    nbBienPlacee = 0;
    nbBonneCouleur = 0;
    nbEssai ++;
    short t;
    for (short j = 0; j < 4 ;j++)
    {
        if (combinaison[j]==proposition[j])
        {
            nbBienPlacee = nbBienPlacee + 1;
        }
        else
        {
            for (short i=0; i<4 ; i++)
            {
                if ((combinaison[i]== proposition[j])&&(combinaison[i]!= proposition[i])&&(combinaison[t]!= proposition[j]))
                {
                    nbBonneCouleur = nbBonneCouleur + 1;
                    t=i;
                }
             }
        }
    }
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getNc
# Classe : CMastermind
# Sujet : renvoie la valeur de nc au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : nc : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short CMastermind::getNc()
{
    return nc;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setNc
# Classe : CMastermind
# Sujet : recup�re la valeur de nc du main
# Version : 0.1
# Entrees (in) : nbCoul : entier non sign�
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
void CMastermind::setNc(unsigned short nbCoul)
{
    nc=nbCoul;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getCoup
# Classe : CMastermind
# Sujet : renvoie la valeur de coup au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : coup : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short CMastermind::getCoup()
{
    return coup;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setCoup
# Classe : CMastermind
# Sujet : recup�re la valeur de nbCoup du main
# Version : 0.1
# Entrees (in) : nbCoup : entier non sign�
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
void CMastermind::setCoup(unsigned short nbCoup)
{
    coup=nbCoup;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getNbEssai
# Classe : CMastermind
# Sujet : renvoie la valeur de nbEssai au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : nbEssai : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short CMastermind::getNbEssai()
{
    return nbEssai;
}


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getCombinaison
# Classe : CMastermind
# Sujet : renvoie la valeur de combinaison au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : combinaison : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short * CMastermind::getCombinaison()
{
    return combinaison;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getCombinaison
# Classe : CMastermind
# Sujet : renvoie la valeur de combinaison au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : combinaison : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short * CMastermind::getProposition()
{
    return proposition;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setProposition
# Classe : CMastermind
# Sujet : recup�re la valeur de tab[4] du main
# Version : 0.1
# Entrees (in) : tab[4] : entier non sign�
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
void CMastermind::setProposition(unsigned short tab[4])
{
    for(short i=0;i<4;i++)
    {
        proposition[i]=tab[i];
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getNbBienPlacee
# Classe : CMastermind
# Sujet : renvoie la valeur de nbBienPlacee au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : nbBienPlacee : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short CMastermind::getNbBienPlacee()
{
    return nbBienPlacee;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getNbBonneCouleur
# Classe : CMastermind
# Sujet : renvoie la valeur de nbBienPlacee au main
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : nbBonneCouleur : entier non sign�
# Entrees/Sorties (inout) : Aucune
# Retour : Aucun
# Auteur : HUCK
# Cr�ation : 29/04/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
unsigned short CMastermind::getNbBonneCouleur()
{
    return nbBonneCouleur;
}
