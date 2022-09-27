/*
#-----------------------------------------------------------------------
# Nom Fichier: ccourseSki.cpp
# Classe : CCourseSki
# Sujet : gestion du programme bicyclette
# Version : 0.1
# Auteur : HUCK
# Cr�ation : 16/10/2021
# Mise � jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "ccourseski.h"
#include <iostream>

using namespace std;
/*
# --------------------------------------
# Nom Procedure : CCourseSki()
# Classe: CCourseSki
# Sujet : constructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
CCourseSki::CCourseSki()
{
}

/*
# --------------------------------------
# Nom Procedure : ~CCourseSki()
# Classe: CCourseSki
# Sujet : destructeur de la classe
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
CCourseSki::~CCourseSki()
{
}

/*
# --------------------------------------
# Nom Procedure : setNbParticipant( nb )
# Classe: CCourseSki
# Sujet : copie le nombre de participant de nb vers nbParticipant
# Entree : nb : entier court non sign�
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CCourseSki::setNbParticipant(unsigned short nb)
{
    nbParticipant = nb;
}

/*
# --------------------------------------
# Nom Procedure : classer()
# Classe: CCourseSki
# Sujet : m�thode permettant de classer les participants en fonction de leur temps durant la course
# Entree : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CCourseSki::classer()
{
    cout<<"---CLASSEMENT EN COURT---"<<endl;
    //Tri � bulle avec les participant en fonction de leurs temps

    CSkieur * temp;
    //unsigned short permuter = 0;
    unsigned short i = nbParticipant;

    temp = new CSkieur();

    for(i; i<0;i = i-1)
    {
        cout<<"i de depart : "<<i<<endl;
        //permuter = 0;
        for(unsigned short j = 0; j <= i ; j++)
        {
            cout<<"---I1--- : "<<i<<endl<<endl;
            if(Skieur[j]->getTemps() > Skieur[j + 1]->getTemps())
            {
                cout<<"---I2--- : "<<i<<endl<<endl;
                //permuter = 1;

                temp->setNom(Skieur[j]->getNom());
                temp->setPrenom(Skieur[j]->getPrenom());
                temp->setNumeroDossard(Skieur[j]->getNumeroDossard());
                temp->setTemps(Skieur[j]->getTemps());
                temp->setEmail(Skieur[j]->getEmail());

                Skieur[j] = Skieur[j + 1];
                Skieur[j + 1] = temp;
            }
        }
        //i--;
        cout<<"---I3--- : "<<i<<endl<<endl;
    }
    //while((i > 0)&&(permuter == 1));

}

/*
# --------------------------------------
# Nom Procedure : getParticipant( nbInscription )
# Classe: CCourseSki
# Sujet : retourne le participant
# Entree : aucune
# Sortie : nbInscription : entier court non sign�
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
unsigned short CCourseSki::getNbParticipant()
{
    return nbParticipant;
}

/*
# --------------------------------------
# Nom Procedure : getParticipant()
# Classe: CCourseSki
# Sujet : retourne le nombre de participant
# Entree : aucune
# Sortie : aucun
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
CSkieur* CCourseSki::getParticipant(unsigned short numeroInscription)
{

    if (numeroInscription<nbParticipant)
    {
        return Skieur[numeroInscription];
    }
    else
    {
        return NULL;
    }
}

/*
# --------------------------------------
# Nom Procedure : setParticipant( nbInscription , competiteurCourant )
# Classe: CCourseSki
# Sujet : r�cupere le participant
# Entree : aucune
# Sortie : nbInscription : entier court non sign�
           competiteurCourant : CSkieur*
# Retour : aucun
# Auteur : HUCK
# Creation : 16/10/2021
# Mise a jour :
# ----------------------------------------
*/
void CCourseSki::setParticipant(unsigned short numeroInscription,CSkieur* competiteurCourant)
{
    if (numeroInscription<nbParticipant)
    {
        Skieur[numeroInscription] = competiteurCourant;
    }
}
