#include <iostream>
#include "cposte.h"

using namespace std;

int main()
{
    short poids;
    short tarif;
    short prix;
    short nb;
    CPoste affranchissement;

    cout<<"Saisir le nombre de colis : ";
    cin>>nb;
    affranchissement.setNbColis(nb);

    short j =1 ;
    for (short i = 0; i < nb;i++)
    {
        cout<<endl<<"-----Colis numero : "<<j<<endl<<endl;
        cout<<"Saisir le tarif : ";
        cin>>tarif;
        affranchissement.setTarifColis(tarif);

        cout<<endl<<"Saisir le poids du colis : ";
        cin>>poids;
        affranchissement.setPoidsColis(poids);

        affranchissement.affranchirColis();
        cout<<endl<<"---Recapilatif---"<<endl;
        cout<<"Le prix du colis : "<<affranchissement.getPrixColis()<<endl;
        cout<<"Le poid du colis : "<<affranchissement.getPoidsColis()<<endl;
        cout<<"Le tarif du colis : "<<affranchissement.getTarifColis()<<endl;
        cout<<"Le nombre de colis : "<<affranchissement.getNbColis()<<endl;

        j++;
    }

    cout<<endl<<endl<<"---PrixTotal---"<<endl;
    cout<<"Le prix total : "<<affranchissement.getPrixTotal()<<endl;

    return 0;
}

