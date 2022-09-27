/*-----------------------------------------------------------------------
#Nom:main.cpp
#Sujet:programme console de test unitaire du terrain
#Auteur:HUCK
#Création:12/10/2020
#-----------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "CTerrain.h"

using namespace std;

int main()
{
    CTerrain monTerrain;
    long Longueur, largeur ,SuperficieEnM2;
    float superficieEnHectare;

    cout <<"Longueur ?";
    cin >> Longueur;

    cout <<"Largeur ?";
    cin >> largeur;

    monTerrain.setLongueur(Longueur);
    monTerrain.setLargeur(largeur);
    SuperficieEnM2 = monTerrain.calculerSuperficieEnM2();
    cout << "La superficie en metre carre vaut :"<< SuperficieEnM2<<endl;

    superficieEnHectare = monTerrain.calculerSuperficieEnHectare();
    cout << "La superficie en Hectare vaut : "<< superficieEnHectare<<endl;

    return 0;
}

