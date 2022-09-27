/*-----------------------------------------------------------------------
#Nom:main.cpp
#Sujet:programme console de test unitaire du cercle
#Auteur:HUCK
#Création:06/10/2020
#Miseàjour:
#-----------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "ccercle.h"
using namespace std;

int main()
{

    ccercle monCercle;
    short rayon;
    float perimetre,surface;
    cout <<"Rayon ?"<<endl;
    cin >> rayon;
    monCercle.setRayon(rayon);
    perimetre = monCercle.calculerPerimetre();
    cout << "Le perimetre du cercle de rayon :"
         << monCercle.getRayon() <<"vaut : "<<perimetre<<endl;
    surface = monCercle.calculerSurface();
    cout <<"La surface du cercle de rayon : "
        << monCercle.getRayon() <<"vaut :"<<surface<<endl;
    return 0;
}

