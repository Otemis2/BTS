#include <iostream>
#include "reservesargent.h"
#include "comptecourant.h"
#include "livretepargne.h"
#include "portemonnaie.h"

using namespace std;

int main()
{
    CompteCourant monCompte;
    PorteMonnaie monPorteMonnaie;
    LivretEpargne monLivret;
    //reservesArgent maReservesArgent;
    float sousCC;
    float sousPM;
    float sousLE;
    float soldeTotal;

    cout << "---Credit---" << endl<<endl;
    cout << "Saisiez la valeur(CC) : " << endl;
    cin>>sousCC;
    monCompte.crediter(sousCC);
    cout<< endl << "Saisiez la valeur(PM) : " << endl;
    cin>>sousPM;
    monPorteMonnaie.crediter(sousPM);
    cout<< endl << "Saisiez la valeur(LE) : " << endl;
    cin>>sousLE;
    monLivret.crediter(sousLE);

    cout << "---Debiter---" << endl<<endl;
    cout << "Saisiez la valeur(CC) : " << endl;
    cin>>sousCC;
    monCompte.debiter(sousCC);
    cout<< endl << "Saisiez la valeur(PM) : " << endl;
    cin>>sousPM;
    monPorteMonnaie.debiter(sousPM);
    cout<< endl << "Saisiez la valeur(LE) : " << endl;
    cin>>sousLE;
    monLivret.debiter(sousLE);

    cout << "---Consulter Solde---" << endl<<endl;
    sousCC = monCompte.getSolde();
    cout<<"la valeur(LE) est : " <<sousCC<< endl;

    sousPM = monPorteMonnaie.getSolde();
    cout<<"la valeur(PM) est : " <<sousPM<< endl;

    sousLE = monLivret.getSolde();
    cout<<"la valeur(LE) est : " <<sousLE<< endl;

    soldeTotal = sousCC+sousPM+sousLE;
    cout<<"le solde total : "<<soldeTotal<<endl;

    return 0;
}

