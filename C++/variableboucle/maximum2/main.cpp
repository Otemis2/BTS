/*
  # ------------------------------------
  # Nom du programme : maximum
  # Sujet : Déterminer la plus grande valeur parmi 20
  # Auteur : Mme Rapebach
  # Date de création : 05/10/20
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : nb,maxi: entiers courts
      position : entier non signé
      i : entier non signé
Début
    Afficher "Saisir un nombre"
    Saisir nb
    maxi<-nb
    position<-1
    i<-1
    Tant que (nb<>0) faire
        i<-i+1
        Afficher "Saisir une valeur"
        Saisir nb
        Si (nb>maxi) alors
            maxi <- nb
            position<-i
        Fin Si
    Fin Tant que
    Afficher "La plus grande valeur est ",maxi
    Afficher "Elle a été saisie �  la position ",position
Fin


# Tests
On entre des valeurs en plaçant la plus grande valeur
- en premiere position
- en derniere position
- n'importe ou entre la 2eme et la 19 eme position
On verifie qu'une fois qu'on saisit un 0 le programme s'arrete.
*/

int main()
{
    short maxi,nb;
    unsigned short position=1;
    unsigned short i=1;
    cout<<"Saisir une valeur"<<endl;
    cin>>nb;
    maxi=nb;
    while(nb!=0)
    {
        i++;
        cout<<"Saisir un nombre"<<endl;
        cin>>nb;
        if (nb>maxi)
        {
            maxi=nb;
            position=i;
        }
    }
    cout <<"La plus grande valeur saisie est "<<maxi << endl;
    cout<<"Elle a ete saisie a la position "<<position<<endl;
    return 0;
}
