/*
#-----------------------------------------------------------------------
# Nom Fichier: CVerif_CB.cpp
# Classe : CVerif_CB
# Sujet : gestion de l'application Carte Bancaire
# Version : 0.1
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "cverif_cb.h"
#include <QDate>
#include <QTime>

CVerif_CB::CVerif_CB()
{

}

CVerif_CB::~CVerif_CB()
{

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : VerifierNumeroCb
# Classe : CVerif_CB
# Sujet : permettra de verifier si le numero de la carte bancaire saisi est valide
# Version : 0.1
# Entrees (in) : numerocb:chaine caractere non signé ; Contenir le numero de la carte bancaire
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Type ; Aucune
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CVerif_CB::VerifierNumeroCb(unsigned char* numerocb)
{

    int somme=0;
    int reste=0;
    int index=0;
    int N1=0;
 // Verification du numéro CB

//DEBUT:
        for(index=1;index<16;)
        {
            N1=numerocb[index];
            somme=somme+N1;
            index=index + 2;
        }

        for(index=0;index<16;)
        {
            N1=numerocb[index];
            N1=N1*2;
            if(N1>9)
            {N1=N1-9;}
            somme=somme+N1;
            index=index + 2;
        }
        reste=somme%10;
        if(reste==0)
        {
            numeroCB_OK = true;
            return true;
        }
        else
        {
            numeroCB_OK = false;
            return false;
        }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : VerifierDateCb
# Classe : CVerif_CB
# Sujet : permettra de verifier si le mois et l'année de la carte bancaire saisi est valide
# Version : 0.1
# Entrees (in) : moisCB :caractere non signé ; Contenir le mois de la carte bancaire
                 anneeCB :entier ; Contenir l'année de la carte bancaire
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Type ; Aucune
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CVerif_CB::VerifierDateCb(unsigned char moisCB,int anneeCB)
{
    int moiscourrant;
    int anneecourante;
    //mois courrant
    moiscourrant=QDate::currentDate().month();
    //date courrant
    anneecourante=QDate::currentDate().year();

    int mois = (int)moisCB;
    if (anneeCB<anneecourante)
    {
        dateCB_OK = false;
        return false;
    }
    else
    {
        if (anneeCB==anneecourante)
        {
            if (mois<moiscourrant)
            {
                dateCB_OK = false;
                return false;
            }
            else
            {
                if (mois==moiscourrant)
                {
                    dateCB_OK = true;
                    return true;
                }
                else
                {
                    if (mois>moiscourrant)
                    {
                        dateCB_OK = true;
                        return true;
                    }
                    dateCB_OK = false;
                    return false;
                }
                dateCB_OK = false;
                return false;

            }
        }
        dateCB_OK = true;
        return true;
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : setNumeroCB
# Classe : CVerif_CB
# Sujet : permettra de récuper le numero de la carte bancaire et de la mettre dans la varible privée numeroCB
# Version : 0.1
# Entrees (in) : numerocb :chaine de caractere non signé ; Contenir le numero de la carte bancaire
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Type ; Aucune
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void CVerif_CB::setNumeroCB(unsigned char* numerocb)
{
    for(int index = 0; index < 16; index++)
    {
        numeroCB[index]=numerocb[index];
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getNumeroCB_OK
# Classe : CVerif_CB
# Sujet : permettra de renvoyer si le numero de la carte est valide
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Type ; Aucune
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CVerif_CB::getNumeroCB_OK()
{
    return numeroCB_OK;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getCodeCB_OK
# Classe : CVerif_CB
# Sujet : permettra de renvoyer si la date de la carte est valide
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Type ; Aucune
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CVerif_CB::getCodeCB_OK()
{
    return dateCB_OK;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : getcarteValide()
# Classe : CVerif_CB
# Sujet : permettra de verifier si la date et le numero de la carte est valide est de renvoyer la confirmation
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Type ; Aucune
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool CVerif_CB::getcarteValide()
{
    if ((dateCB_OK == true)&&(numeroCB_OK==true))
    {
        carteValide = true;
        return carteValide;
    }
    else
    {
        carteValide = false;
        return carteValide;
    }
}
