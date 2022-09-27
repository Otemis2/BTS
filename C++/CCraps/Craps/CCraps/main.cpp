#include <iostream>
#include "CCraps.h"
using namespace std;

int main()
{
    // diagramme de sequence du cas d'utilisation
    // jouer une partie de craps
    CCraps jeuDuCraps;
    unsigned short somme1,somme;
    //1er lancer de des
    somme = jeuDuCraps.lancerDes();
    if ((somme == 7)|| (somme ==11))
       {
        cout << "Victoire"<<endl;
       }
        else
        {
            if ((somme == 2)|| (somme == 3)||(somme == 12))
            {
            cout << "Victoire"<<endl;
            cout << "Le nombre etais : "<<somme<<endl;
            }
            else
            {
                do
                  {
                   somme1 = jeuDuCraps.lancerDes();
                    if (somme1 == 7)
                    {
                        cout <<"Perdu"<<endl;
                    }
                    else
                        {
                            cout<<"Rejouer"<<endl;
                        }
                   }while ((somme != somme)&&(somme != 7));
          }
        }
}
