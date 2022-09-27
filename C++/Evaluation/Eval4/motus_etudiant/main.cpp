#include <iostream>
#include "string.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    char mots[6][7];
    strcpy(mots[0],"CHEVAL");
    strcpy(mots[1],"OISEAU");
    strcpy(mots[2],"MAJEUR");
    strcpy(mots[3],"DESERT");
    strcpy(mots[4],"RATEAU");
    strcpy(mots[5],"ORANGE");
    // Initialiser le tableau mots avec les mots cheval, oiseau, majeur, desert, rateau, orange


    short nbCoups=0;
    char motSecret;
    srand(time(NULL));

    short i = rand() %6;

    strcpy (motSecret, mots[i]);
    // Initialiser motSecret avec un mot pris au hasard dans le tableau mots


    char motPropose;
    char motAffiche[7]="******";
    do
    {
        cout<<"Propose un mot de 6 lettres en minuscule "<<endl;
        cin>>motPropose;
        //VÃ©rifier que le mot propose contient bien 6 lettres
        if (strlen(motPropose) != 6)
        {
            cout<<"Le mot propose n'a pas 6 lettres"<<endl;
        }
        else
        {
            if (motPropose >='a' && motPropose <='z')
            {
                motPropose = motPropose +'A'-'a';
            }

            bool present = false;

            for (short i = 0; i <= 7; i++)
            {

                if (motSecret == motPropose)
                {

                    motSecret = motPropose;

                    present = true;

                }

            }
            // Remplacer les lettres de motAffiche par la lettre de motSecret convertie en majuscule
            // lorsqu'elle correspond exactement Ã  l'endroit oÃ¹ elle doit se trouver dans motSecret

        }
        cout<<motAffiche<<endl;
        nbCoups = nbCoups+1;
    } while (motPropose != motSecret); // Ecrire la condition d'arrÃªt de la boucle.

    //nbCoups doit augmenter de 1 Ã  chaque passage dans la boucle.
    cout<<"Bravo vous avez trouve en "<<nbCoups<<" coups."<<endl;


    return 0;
}
