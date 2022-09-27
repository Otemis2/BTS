/*
#---------------------------------------
#Programme : SommeInconnu
#Sujet : Calculez la somme de deux nombres choisi entre 0 et 1000
#Auteur :HUCK
#Date de création :09/11/2020
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
    Début
    Var : nb1 , nb2 , essais : short
    essais <- -1;
    nb1 = rand() %1000 + 1;
    nb2 = rand() %1000 + 1;

    afficher "Bienvenue , veuillez entrez une valeur et essayer de trouver le bon resultat";
        Tant que (essais != nb1+nb2)

                afficher "Combien vaut ",nb1,"+",nb2,";
                saisir essais;

                si (essais < nb1+nb2)

                    afficher "Le nombre est plus eleve !";


                Sinon
                    Si (essais > nb1+nb2)

                        afficher "Le nombre est plus bas !";


                    Sinon


                            afficher "Bien jouer vous avez trouver la bonne somme ! ";
                            afficher "Le nombre etait  " nb1+nb2 ;

                    FinSi
                FinSi
        Fin Tant que
    Fin
    Test :
    essais  result
    1180      Ce n'est pas la bonne reponse !
    1182      Ce n'est pas la bonne reponse !
    1181     Bien jouer vous avez trouver le bon resultat!
 // compte pas les boucles
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    short nb1,nb2, essais;
    nb1 = rand() %1000 + 1;
    nb2 = rand() %1000 + 1;
    essais = -1;

//cout<<nb1+nb2<<endl;

    cout << "Bienvenue , veuillez entrez une valeur et essayer de trouver le bon resultat" << endl;
    while (essais != nb1+nb2)
            {
                cout << "Combien vaut "<<nb1<<"+"<<nb2<<" ?"<<endl;
                cin >> essais;

                if (essais < nb1+nb2)
                {

                    cout << "Ce n'est pas la bonne reponse !" << endl;

                }
                else
                    if (essais > nb1+nb2)
                    {

                        cout << "Ce n'est pas la bonne reponse !" << endl;

                    }
                    else
                    {

                        cout << "Bien jouer vous avez trouver le bonne resultat ! " << endl;
                        cout << "Le nombre etait  "<< nb1+nb2 << endl;

                     }
            }
    return 0;
}

