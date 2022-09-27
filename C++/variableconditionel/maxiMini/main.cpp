/*
  # ------------------------------------
  # Nom du programme : maxi_1
  # Sujet : Déterminer la valeur la plus grande et la plus petite parmi 3 valeurs
  # Auteur : Mme Rapebach
  # Date de création : 27/09/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : nb1, nb2,nb3 : réels
      maxi, mini : réels
Début
    afficher "Saisir trois nombres réels"
    Saisir nb1
    Saisir nb2
    Saisir nb3
    maxi=nb1
    mini=nb1
    Si (nb2>maxi) alors
        maxi<-nb2
    Fin Si
    Si (nb3>maxi) alors
        maxi<-nb3
    Fin Si

    Si (nb2<mini) alors
        mini<-nb2
    Fin Si
    Si (nb3<mini) alors
        mini<-nb3
    Fin Si

    Afficher "La plus grand valeur est ",maxi," et la plus petite est ",mini

Fin

# Tests
nb1     nb2     nb3     maxi        mini
3.1     4.2     5.3     5.3         3.1
3.1     5.3     4.2     5.3         3.1
4.2     3.1     5.3     5.3         3.1
4.2     5.3     3.1     5.3         3.1
5.3     3.1     4.2     5.3         3.1
5.3     4.2     3.1     5.3         3.1
5.3     4.2     4.2     5.3         4.2
4.2     5.3     4.2     5.3         4.2
4.2     4.2     5.3     5.3         4.2
4.2     4.2     4.2     4.2         4.2

*/
int main()
{
    float nb1,nb2,nb3;
    float maxi,mini;

    cout<<"Saisir trois nombres reels"<<endl;
    cin>>nb1;
    cin>>nb2;
    cin>>nb3;
    maxi=nb1;
    mini=nb1;
    if (nb2>maxi)
    {
        maxi=nb2;
    }
    if (nb3>maxi)
    {
        maxi=nb3;
    }

    if (nb2<mini)
    {
        mini=nb2;
    }
    if (nb3<mini)
    {
        mini=nb3;
    }

    cout<<"La plus grand valeur est "<<maxi<<" et la plus petite est "<<mini<<endl;
    return 0;
}


