/*
  # ------------------------------------
  # Nom du programme : tarif_poste
  # Sujet : Calculer le prix d'une lettre en fonction de son poids
  # Auteur : Mme Rapebach
  # Date de création : 02/10/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : poids : entier
      tarif : flottant
Début
    Afficher "Entrer le poids du colis (en grammes)."
    Saisir poids
    Si (poids<=20) alors
        tarif<-0.97
    Sinon
        Si (poids<=100) alors
            tarif<-1.94
        Sinon
            Si (poids<=250) alors
                tarif<-3.88
            Sinon
                Si (poids<=500) alors
                    tarif<-5.82
                Sinon
                    tarif<-7.76
                Fin Si
            Fin Si
        Fin Si
    Fin Si
    Afficher "Le tarif est de ",tarif," euros."
Fin

# Tests
poids   tarif
12      0.97
85      1.94
198     3.88
335     5.82
1500    7.76
*/
int main()
{
    short poids;
    float tarif;
    cout<<"Entrer le poids du colis (en grammes)."<<endl;
    cin>>poids;
    if (poids<=20)
    {
        tarif=0.97;
    }
    else
    {
        if(poids<=100)
        {
            tarif=1.94;
        }
        else
        {
            if(poids<=250)
            {
                tarif=3.88;
            }
            else
            {
                if(poids<=500)
                {
                    tarif=5.82;
                }
                else
                {
                    tarif=7.76;
                }
            }
        }
    }
    cout<<"Le tarif est de "<<tarif<<" euros."<<endl;
    return 0;
}
