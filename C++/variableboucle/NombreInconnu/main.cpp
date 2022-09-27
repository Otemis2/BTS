/*
#---------------------------------------
#Programme : NombreInconnu
#Sujet : Determinez le nombre choisi entre 0 et 1000
#Auteur :HUCK
#Date de création :19/10/2020
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
    Début
    Var : nbgagnant , essais : short
    essais <- -1;
    nbgagnant = rand() %1000 + 1;

    afficher "Bienvenue , veuillez entrez une valeur et essayer de trouver le bon nombre";
        Tant que (essais != nbgagnant)

                afficher "Qu'elle est votre nombre ?";
                saisir essais;

                si (essais < nbgagnant)

                    afficher "Le nombre est plus eleve !";


                Sinon
                    Si (essais > nbgagnant)

                        afficher "Le nombre est plus bas !";


                    Sinon


                            afficher "Bien jouer vous avez trouver le bon nombre ! ";
                            afficher "Le nombre etait  " nbgagnant ;

                    FinSi
                FinSi
        Fin Tant que
    Fin
    Test :
    essais  result
    45      Le nombre est plus eleve !
    87      Le nombre est plus bas !
    78      Bien jouer vous avez trouver le bon nombre !
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
srand(time(NULL));

short essais,nbgagnant;
unsigned short nbCoup,nbPartie,nbPartieGagnez,nbPartiePerdu,exit;

nbgagnant = rand() %1000 + 1;
essais = -1;
exit = 0;
nbCoup = 0;
nbPartie = 0;
nbPartieGagnez = 0;
nbPartiePerdu = 0;
//cout<<nbgagnant<<endl;

cout << "Bienvenue , veuillez entrez une valeur et essayer de trouver le bon nombre" << endl;

while (exit != 2)
{
    if (exit = 1)
    {
        if (essais = nbgagnant)
        {
            nbPartie = nbPartiePerdu + nbPartieGagnez;
            cout << "Vous avez jouer : "<<nbPartie<<" partie et vous en avez gagnez : "<<nbPartieGagnez<<endl;

            cout << "Appuyer sur 1 pour Continuez sinon appuyer sur 2 pour quitter"<<endl<<endl;
            cin >> exit;
            nbCoup = 0;
            nbgagnant = rand() %1000 + 1;
            //cout<<nbgagnant<<endl;
        }
        while ((essais != nbgagnant))
        {
            if (nbCoup <= 10)
            {

                cout << "Qu'elle est votre nombre ? >> "<<endl;
                cin >> essais;
                nbCoup = nbCoup ++;

                if (essais < nbgagnant)
                {
                    cout << "Le nombre est plus eleve !" << endl;
                }
                else

                    if (essais > nbgagnant)
                    {
                        cout << "Le nombre est plus bas !" << endl;
                    }
                    else
                    {
                        cout << "Bien jouer vous avez trouver le bon nombre ! " << endl;
                        cout << "Le nombre etait  "<<nbgagnant<<" et en : "<<nbCoup<< " coup" << endl<<endl;

                        nbPartieGagnez = nbPartieGagnez ++;
                    }
            }
            else
            {
                cout<< "Perdu !"<<endl;
                nbPartiePerdu = nbPartiePerdu ++;

                if (nbCoup = 10)
                {

                    nbPartie = nbPartiePerdu + nbPartieGagnez;
                    cout << "Vous avez jouer : "<<nbPartie<<" partie et vous en avez gagnez : "<<nbPartieGagnez<<endl;

                    cout << "Appuyer sur 1 pour Continuez sinon appuyer sur 2 pour quitter"<<endl<<endl;
                    cin >> exit;
                    nbCoup = 0;
                    nbgagnant = rand() %1000 + 1;
                    //cout<<nbgagnant<<endl;
                }
            }
        }
    }
    else
    {
        return 0;
    }
}
}
