#include <iostream>
#include "CCraps.h"
using namespace std;

int main()
{
    // diagramme de sequence du cas d'utilisation
    // jouer une partie de craps
    CCraps jeuDuCraps;
    unsigned short somme1, somme2;
    //1er lancer de des
    somme = jeuDuCraps.lancerDes();
    if ((somme == 7))|| (somme ==11))
       {
        cout << "Victoire"<<endl;
       }
        else
       {
        cout << "Perdu";
        }
    if ((somme == 2))|| (somme == 3))
       {
        cout << "Victoire"<<endl;
       }
        else
       {
        cout << "Perdu";
        }



    {
        cout <<"Perdu"<<endl;
    }
    else
    {
        do
        {
            somme1 = jeuDuCraps.lancerDes();
            if (somme1 == 7)
        }
    }

    return 0;
}

