/*
#-----------------------------------------------------------------------
# Nom Fichier: CPoste.cpp
# Classe : CPoste
# Sujet : gestion du logiciel d'affranchissement d'un colis
# Version : 0.1
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "cposte.h"
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : CPoste
# Classe : CPoste
# Sujet : Constructeur de la classe CPoste
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
CPoste::CPoste()
{
    tableauPoids[0] = 20;
    tableauPoids[1] = 50;
    tableauPoids[2] = 100;
    tableauPoids[3] = 250;
    tableauPoids[4] = 500;
    tableauPoids[5] = 1000;
    tableauPoids[6] = 2000;
    tableauPoids[7] = 3000;

    tableauPrix[0][0] = 1.42;
    tableauPrix[1][0] = 2.39;
    tableauPrix[2][0] = 2.39;
    tableauPrix[3][0] = 4.33;
    tableauPrix[4][0] = 6.27;
    tableauPrix[5][0] = 8.21;
    tableauPrix[6][0] = 8.21;
    tableauPrix[7][0] = 8.21;

    tableauPrix[0][1]= 0.97;
    tableauPrix[1][1]= 1.94;
    tableauPrix[2][1]= 1.94;
    tableauPrix[3][1]= 3.88;
    tableauPrix[4][1]= 5.82;
    tableauPrix[5][1]= 7.76;
    tableauPrix[6][1]= 7.76;
    tableauPrix[7][1]= 7.76;


    tableauPrix[0][2]= 4.30;
    tableauPrix[1][2]= 4.85;
    tableauPrix[2][2]= 5.50;
    tableauPrix[3][2]= 6.70;
    tableauPrix[4][2]= 7.85;
    tableauPrix[5][2]= 9.00;
    tableauPrix[6][2]= 10.70;
    tableauPrix[7][2]= 11.93;


    tableauPrix[0][3]= 1.16;
    tableauPrix[1][3]= 2.32;
    tableauPrix[2][3]= 2.32;
    tableauPrix[3][3]= 4.64;
    tableauPrix[4][3]= 6.96;
    tableauPrix[5][3]= 9.28;
    tableauPrix[6][3]= 9.28;
    tableauPrix[7][3]= 9.28;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : ~CPoste
# Classe : CPoste
# Sujet : Destructeur de la classe CPoste
# Version : 0.1
# Entrees (in) :
# Sorties (out) :
# Entrees/Sorties (inout) : Aucune
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
CPoste::~CPoste()
{

}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getPoidsColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) :
# Sorties (out) :  poidsColis
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
short CPoste::getPoidsColis()
{
    return poidsColis;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getPrixColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) :
# Sorties (out) :  PrixColis
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
float CPoste::getPrixColis()
{
    return prixColis;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getTarifColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) :
# Sorties (out) :  tarifColis
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
short CPoste::getTarifColis()
{
    return tarifColis;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getNbColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) :
# Sorties (out) :  nbColis
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
short CPoste::getNbColis()
{
    return nbColis;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getPrixTotal
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) :
# Sorties (out) :  prixTotal
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/

float CPoste::getPrixTotal()
{
   return prixTotal;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setPoidsColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) : poids
# Sorties (out) :
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
short CPoste::setPoidsColis(short poids)
{
    poidsColis = poids;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setTarifColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) : tarif
# Sorties (out) :
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
short CPoste::setTarifColis(short tarif)
{
    tarifColis = tarif;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setPrixColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) : prix
# Sorties (out) :
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
float CPoste::setPrixColis(short prix)
{
    prixColis = prix;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setNbColis
# Classe : CPoste
# Sujet :
# Version : 0.1
# Entrees (in) : nb
# Sorties (out) :
# Entrees/Sorties (inout) :
# Retour :
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
short CPoste::setNbColis(short nb)
{
    nbColis = nb;
}
/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : affranchirColis
# Classe : CPoste
# Sujet : permet determiner le prix de chaque colis et d'adittionner chaque colis pour avoir le prix total
# Version : 0.1
# Entrees (in) :
# Sorties (out) : prixTotal
# Entrees/Sorties (inout) : Aucune
# Retour : vrai ou faux
# Auteur : HUCK
# Cr?ation : 10/02/2021
# Mise ? jour :
# -----------------------------------------------------------------------
*/
bool CPoste::affranchirColis()
{
    if((tarifColis>=0 && tarifColis<=3)&&(poidsColis >=0 && poidsColis <=3000))
    {
        unsigned short i=0;
        while (tableauPoids[i] < poidsColis)
        {
                i++;
        }
        prixColis = tableauPrix[i][tarifColis];
        prixTotal = prixTotal + prixColis;

        return true;
    }
    else
    {
        return false;
    }

}
