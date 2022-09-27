/*
# -----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du programme gestion d'une course de ski
# Cr√©ation : 16/10/2021
# Mise √  jour :
# -----------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include "ccourseski.h"

using namespace std;

int main()
{
    CSkieur* leSkieur;
    CCourseSki maCourse;

    char* nomCompettiteur = new char[20];
    char* prenomCompetiteur = new char[20];
    char* emailCompetiteur = new char[100];
    unsigned short nb;
    float temps;

    //CSkieur monSkieur(nomCompettiteur,prenomCompetiteur,emailCompetiteur,numeroDossardCompetiteur);

    cout<<"saisir le nombre de participant : ";
    cin>>nb;
    maCourse.setNbParticipant(nb);

    for (unsigned short numeroDossardCompetiteur = 1;numeroDossardCompetiteur <= nb; numeroDossardCompetiteur++ )
    {
        cout<<"Participant num : "<<numeroDossardCompetiteur<<endl;
        cout<<"saisir le nom : ";
        cin>>nomCompettiteur;
        cout<<"saisir le prenom : ";
        cin>>prenomCompetiteur;
        cout<<"Saisir l'email : ";
        cin>>emailCompetiteur;

        leSkieur = new CSkieur (nomCompettiteur,prenomCompetiteur,emailCompetiteur,numeroDossardCompetiteur);
        maCourse.setParticipant(numeroDossardCompetiteur-1,leSkieur);
    }

    cout<<"Recap : "<<endl<<endl;
    //afficher les compÈtiteurs
    for(unsigned short dossard=1; dossard<=nb;dossard++)
    {
        cout<<"Numero de dossard : "<<maCourse.getParticipant(dossard-1)->getNumeroDossard()<<endl;
        cout<<"Nom du competiteur : "<<maCourse.getParticipant(dossard-1)->getNom()<<endl;
        cout<<"Prenom du competiteur : "<<maCourse.getParticipant(dossard-1)->getPrenom()<<endl;
        cout<<"Email du competiteur : "<<maCourse.getParticipant(dossard-1)->getEmail()<<endl;
        cout<<"Temps : "<<maCourse.getParticipant(dossard-1)->getTemps()<<endl<<endl;
    }

    cout<<"Fin du recap"<<endl<<endl;

    //gerer la course
    for (short dossard = 1;dossard <= nb; dossard++ )
    {
        cout<<"NumÈro de dossard : "<<maCourse.getParticipant(dossard-1)->getNumeroDossard()<<endl;
        cout<<"Nom du competiteur : "<<maCourse.getParticipant(dossard-1)->getNom()<<endl;
        cout<<"Prenom du competiteur : "<<maCourse.getParticipant(dossard-1)->getPrenom()<<endl;
        cout<<"Email du competiteur : "<<maCourse.getParticipant(dossard-1)->getEmail()<<endl;
        cout<<"Temps : ";
        cin>>temps;
        maCourse.getParticipant(dossard-1)->setTemps(temps);
        cout<<endl<<endl;
    }
    //classer les competiteur
    maCourse.classer();

    cout<<"Publication : "<<endl<<endl;

    //publier les rÈsultats
    for (unsigned short dossard = 1;dossard <= nb; dossard++ )
    {
        cout<<"NumÈro de dossard : "<<maCourse.getParticipant(dossard-1)->getNumeroDossard()<<endl;
        cout<<"Nom du competiteur : "<<maCourse.getParticipant(dossard-1)->getNom()<<endl;
        cout<<"Prenom du competiteur : "<<maCourse.getParticipant(dossard-1)->getPrenom()<<endl;
        cout<<"Email du competiteur : "<<maCourse.getParticipant(dossard-1)->getEmail()<<endl;
        cout<<"Temps : "<<maCourse.getParticipant(dossard-1)->getTemps()<<endl<<endl;
    }
    return 0;
}

