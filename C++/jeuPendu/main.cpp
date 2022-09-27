#include <iostream>
#include <windows.h>
#include <string>
#include "JeuPendu.h"

using namespace std;

CJeuPendu pendu;

int main()
{

    // définition des variables

    char* motSecret = new char [256];
    string propLettre;

    char lettre;

    short tentatives;
    short countTentative = 0;


    cout << "Bienvenue sur le jeu du pendu " <<endl;


   propLettre.clear();

   pendu.setTentative(tentatives);

   pendu.motSecret();
   pendu.motATrouver();

   //cout << pendu.motSecret()<<endl;  Triche

            while (strcmp(pendu.getMotSecret(), pendu.getMotATrouve()))
            {


                cout << "Le mot a trouver est : " << pendu.getMotATrouve() << endl;
                cout << "Lettre deja propose : " << propLettre << endl;
                cout << "Nombre de tentative(s) : " << countTentative << "/" << "7" <<endl << endl;

                cout << "Veuillez proposer une lettre  "<<endl;
                cin >> lettre;

                for (short i = 0; i <= 7; i++)
                {

                    if (lettre == propLettre[i])
                    {

                        cout << "Vous avez deja  proposer cette lettre !"<<endl;

                    }

                }

                propLettre = propLettre + lettre;

                pendu.Proposer(lettre);

                countTentative++;

                if (countTentative >= 7 )
                {

                    cout << "Perdu !"<<endl;
                    return 0;
                }
            }
            cout << "Vous avez gagner !"<<endl;

}


