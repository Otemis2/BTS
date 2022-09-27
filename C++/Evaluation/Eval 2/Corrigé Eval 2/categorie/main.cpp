/*
  # ------------------------------------
  # Nom du programme : categorie
  # Sujet : Donner le prix à payer en fonction de l'âge
  # Auteur : Mme Rapebach
  # Date de création : 21/10/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : age : entier
      tarif : réel
Début
    Afficher "Quel est votre age ?"
    Saisir age
    Si (age<8) alors
        tarif<-0
    Sinon
        Si (age<=25) alors
            tarif<-5
        Sinon
            Si (age<=65) alors
                tarif<-13
            Sinon
                tarif<-7
            Fin Si
        Fin Si
    Fin Si
    Afficher "Le tarif est de ",tarif," euros."
Fin

# Tests
age     tarif
5       0
15      5
31      13
70      7
*/
int main()
{
    short age;
    float tarif;
    cout << "Quel est votre age ?" << endl;
    cin>>age;
    if (age<8)
    {
        tarif=0;
    }
    else
    {
        if (age<=25)
        {
            tarif=5;
        }
        else
        {
            if (age<=65)
            {
                tarif=13;
            }
            else
            {
                tarif=7;
            }
        }
    }
    cout<<"Le tarif est de "<<tarif<<" euros."<<endl;
    return 0;
}
