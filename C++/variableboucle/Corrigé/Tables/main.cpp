/*
  # ------------------------------------
  # Nom du programme : Tables
  # Sujet : Afficher les tables de multiplications
  # Auteur : Mme Rapebach
  # Date de création : 30/10/2020
  # Version : 1
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : choix : entier
      i : entier
      j: entier
      nb : entier
Début
    Afficher "Faites votre choix : "
    Afficher "1-Afficher la table du 2"
    Afficher "2-Afficher la table d'un nombre au choix"
    Afficher "3-Afficher toutes les tables de 1 à 10"
    Saisir choix
    Cas (choix) parmi
        Cas 1
            Pour (i<-0 jusqu'à 10 avec un pas de 1) faire
                Afficher i,"*2=",i*2
            Fin Pour
        Cas 2
            Afficher "Choisissez le nombre dont vous voulez afficher la table"
            Saisir nb
            Pour (i<-0 jusqu'à 10 avec un pas de 1) faire
                Afficher i,"*",nb,"=",i*nb
            Fin Pour
        Cas 3
            Pour (j<-1 jusqu'à 10 avec un pas de 1) faire
                Afficher "Table du ",j
                Pour (i<-0 jusqu'à 10 avec un pas de 1) faire
                    Afficher i,"*",j,"=",i*j
                Fin Pour
                Afficher ""
            Fin Pour
        Défaut
            Afficher "Choix incorrect"
   Fin Cas

Fin

# Tests
Essayer chacun des cas et vérifier que l'affichage est correct
*/
int main()
{
    short choix;
    short nb;
    cout<<"Faites votre choix : "<<endl;
    cout<<"1-Afficher la table du 2."<<endl;
    cout<<"2-Afficher la table d'un nombre au choix."<<endl;
    cout<<"3-Afficher toutes les tables de 1 à 10."<<endl;
    cin>>choix;
    switch (choix)
    {
    case 1:
    {
        for (short i=0;i<=10;i++)
        {
            cout<<i<<"*2="<<i*2<<endl;
        }
        break;
    }
    case 2:
    {
        cout<<"Choisissez le nombre dont vous voulez afficher la table"<<endl;
        cin>>nb;
        for (short i=0;i<=10;i++)
        {
            cout<<i<<"*"<<nb<<"="<<i*nb<<endl;
        }
        break;
    }
    case 3:
    {
        for (short j=1;j<=10;j++)
        {
            cout<<"Table du "<<j<<endl;
            for (short i=0;i<=10;i++)
            {
                cout<<i<<"*"<<j<<"="<<i*j<<endl;
            }
            cout<<endl;
        }
        break;
    }
    default:
    {
        cout<<"Choix incorrect"<<endl;
        break;
    }

    }
}

