/*
# -----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du programme bicyclette
# Création : 07/10/2021
# Mise à jour :
# -----------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include "cbicyclette.h"
using namespace std;

int main()
{

    char* couleurCadre= new char[256];
    unsigned short tCadre;
    unsigned short troue ;
    char* typeFrein= new char[256];
    float kilometre;
    char* typeBicyclette= new char[256];
    unsigned short numInv;

    CBicyclette maBicyclette;
    CCadre monCadre;
    CCompteurKilometrique monCompteur;
    CFrein monFrein[2];
    CRoue roue[2];

    cout << "La bicyclette : " << endl;

    cout << "Saisir le type de bicyclette : " << endl;
    cin>>typeBicyclette;
    maBicyclette.setType(typeBicyclette);

    cout << "Quel cadre voulez-vous ?" << endl;

    cout << "Saisir la couleur : " << endl;
    cin>>couleurCadre;
    monCadre.setCouleur(couleurCadre);

    cout << "Saisir la taille du cadre : " << endl;
    cin>>tCadre;
    monCadre.setTaille(tCadre);

    cout << "Quels taille de roues voulez-vous ?" << endl;

    cout << "Saisir la taille de la roue avant : " << endl;
    cin>>troue;
    roue[0].setDiametre(troue);

    cout << "Saisir la taille de la roue arriere : " << endl;
    cin>>troue;
    roue[1].setDiametre(troue);

    cout << "les types de frein : " << endl;

    cout << "Saisir le type de frein pour la roue avant : " << endl;
    cin>>typeFrein;
    monFrein[0].setCaracterisque(typeFrein);

    cout << "Saisir le type de frein pour la roue arriere : " << endl;
    cin>>typeFrein;
    monFrein[1].setCaracterisque(typeFrein);

    cout << "Le compteur : " << endl;

    cout << "Saisir le kilometrage du compteur (en km): " << endl;
    cin>>kilometre;
    monCompteur.setKMTotal(kilometre);

    cout << "Saisir le numero d'inventaire : " << endl;
    cin>>numInv;
    maBicyclette.setNumeroInventaire(numInv);

    cout << "----Recapitulatif---- " << endl;

    cout << "Le type de bicyclette est  : " ;
    typeBicyclette = maBicyclette.getType();
    cout << typeBicyclette <<endl;

    cout << "La couleur du cadre est  : " ;
    couleurCadre = monCadre.getCouleur();
    cout << couleurCadre <<endl;

    cout << "La taille du cadre est  : " ;
    tCadre = monCadre.getTaille();
    cout << tCadre <<endl;

    cout << "La taille de la roue avant est  : " ;
    troue = roue[0].getDiametre();
    cout << troue <<endl;

    cout << "La taille de la roue arriere est  : " ;
    troue = roue[1].getDiametre();
    cout << troue <<endl;

    cout << "Le type de frein de la roue avant est  : " ;
    typeFrein = monFrein[0].getCaracteristique();
    cout << typeFrein <<endl;

    cout << "Le type de frein de la roue arriere est  : " ;
    typeFrein = monFrein[1].getCaracteristique();
    cout << typeFrein <<endl;

    cout << "Le kilometrage de la bicyclette est  : " ;
    kilometre = monCompteur.getKMTotal();
    cout << kilometre <<endl;

    cout << "Le numero de la becanne est  : " ;
    numInv = maBicyclette.getNumeroInventaire();
    cout << numInv <<endl;


    return 0;
}

