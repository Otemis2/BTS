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
      i : entier
Début
    Afficher "Saisir un nombre"
    Saisir maxi
    position<-1
    Pour (i<-2 jusqu'à 20 avec un pas de 1) faire
        Afficher "Saisir une valeur"
        Saisir nb
        Si (nb>maxi) alors
            maxi <- nb
            position<-i
        Fin Si
    Fin pour
    Afficher "La plus grande valeur est ",maxi
    Afficher "Elle a été saisie à la position ",position
Fin

VAR : nb,maxi: entiers courts
      i : entier
      position : entier
Début2
    maxi<- -32768
    position <-1
    Pour (i<-1 jusqu'à 20 avec un pas de 1) faire
        Afficher "Saisir une valeur"
        Saisir nb
        Si (nb>maxi) alors
            maxi <- nb
            position<-i
        Fin Si
    Fin pour
    Afficher "La plus grande valeur est ",maxi
    Afficher "Elle a été saisie à la position ",position
Fin2
# Tests
On entre 20 valeurs consécutifs en plaçant la plus grande valeur
- en première position
- en dernière position
- n'importe où entre la 2ème et la 19ème position
*/
int main()
{
    //Codage du premier algorithme
    short maxi,nb;
    unsigned short position=1;
    cout<<"Saisir une valeur"<<endl;
    cin>>maxi;
    for(short i=2;i<=20;i++)
    {
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

