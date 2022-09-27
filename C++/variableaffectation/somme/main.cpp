/*
#---------------------------------------
#Programme : somme
#Sujet : faire le somme de deux réels
#Auteur : Mme Rapebach
#Date de création : 07/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: nb1,nb2: réels
   somme : réel

Début
Afficher "Saisir un premier nombre"
Saisir nb1
Afficher "Saisir un second nombre"
Saisir nb2
somme <-nb1+nb2
Afficher "La somme vaut",somme
Fin
#Tests
nb1 nb2     affichage
1   3       4
1.2 3.5     4.7
*/

int main()
{
   float nb1,nb2; // On déclare les variables.
   float somme;

    cout << "Saisir un premier nombre"  << endl;
    cin >> nb1;
    cout << "Saisir un second nombre" << endl;
    cin >> nb2;
    somme=nb1+nb2;
    cout<<"La somme vaut "<<somme<<endl;

    return 0;

}

