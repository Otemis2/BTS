/*# ----------------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du jeu du mastermind
# Auteur : chameroy
# Cr?ation : 05/11/2015
# Mise ? jour : 12/09/2017
# --------------------------------------------------------------------------*/
#include <iostream>
#include "cmastermind.h"

using namespace std;

/*
#-----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du jeu du mastermind
# Auteur : HUCK
# Création : 29/04/2021
# Mise à jour :
# -----------------------------------------------------------------------------------------------------------
*/
int main()
{
    CMastermind maPartie;
    unsigned short *tab;
    unsigned short proposition[4];
    int i;
    unsigned short nbBon,nbMal;
    maPartie.initialiserJeu(8,12);
    tab = maPartie.getCombinaison();
    for(i=0; i<4;i++)
    {
       cout << tab[i]<<"\t";
    }
    cout <<endl;
    do
    {
        cout <<"Essai numero: "<<maPartie.getNbEssai()+1 <<endl;
        // saisi proposition joueur
        for(i=0;i<4;i++)
        {
           cout <<"Saisir couleur du pion numero " <<i<<" : ";
           cin >> proposition[i];
        }
        maPartie.setProposition(proposition);
        maPartie.analyser();
        nbBon = maPartie.getNbBienPlacee();
        nbMal = maPartie.getNbBonneCouleur();
        cout << "Bien place : "<< nbBon <<" Bonne Couleur : "<<nbMal <<endl;

    }while ((maPartie.getNbEssai() < maPartie.getCoup())&&(nbBon!=4));
    if (nbBon == 4)
       cout <<"Vous avez gagne"<<endl;
    else
       cout << "Perdu"<<endl;

    return 0;
}
