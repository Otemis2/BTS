/*
#---------------------------------------
#Programme : somme
#Sujet : faire le moyenne de deux réels
#Auteur : Mme Rapebach
#Date de création : 07/09/20
#---------------------------------------
*/


#include <iostream>

using namespace std;
/*
VAR: nb1,nb2,somme: réels
   moy : réel

Début
Afficher "Saisir un premier nombre"
Saisir nb1
Afficher "Saisir un second nombre"
Saisir nb2
somme <-nb1+nb2
moy <-
Afficher "La moyenne vaut",moy
Fin
#Tests
nb1 nb2     affichage

*/

int main()
{
   float nb1,nb2; // On déclare les variables.
   float moy;

    cout << "Saisir un premier nombre"  << endl;
    cin >> nb1;
    cout << "Saisir un second nombre" << endl;
    cin >> nb2;
    moy=nb1+nb2;
    cout<<"La somme vaut "<<moy<<endl;
    return 0;
}

