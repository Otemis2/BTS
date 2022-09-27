/*-----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du jeu du mastermind
# Auteur : HUCK
# Création : 30/11/2020
# Mise à jour : 0
# -----------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "CArticle.h"

using namespace std;

int main()
{
    CArticle PrixArticle;

    float PrixHT;
    float TVA;

    cout<< "Prix de l'Article hors taxe"<<endl;
    cin >> PrixHT;

    PrixArticle.setPrixHT(PrixHT);

    cout<< "Taux de TVA de l'article"<<endl;
    cin>> TVA;

    PrixArticle.setTVA(TVA);

    PrixArticle.CalculerPrixTTC();

    cout<< "Le prix TTC est : "<<PrixArticle.getPrixTTC()<<endl;


}

