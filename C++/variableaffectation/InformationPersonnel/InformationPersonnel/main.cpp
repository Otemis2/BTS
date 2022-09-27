/*
#---------------------------------------
#Programme : Presentation
#Sujet : Demander à l'utilisateur sa taille et son age et les afficher
#Auteur : Mme Rapebach
#Date de création : 07/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: age: entier court
     taille : réels

Début
Afficher "Bonjour. Veuiller votre age et votre taille, s'il vous plait."
Saisir age ; taille
Afficher "Bonjour. Vous avez ",age,"  ans et vous mesurez ",taille,"  m"
Fin
#Tests
age    taille
14     1.96
15     1.00

*/

int main()
{
   unsigned short age; // On déclare les variables.
   float taille;

    cout << "Bonjour. Veuiller entrée votre age et votre taille, s'il vous plait."  << endl;
    cin >> age;
    cin >> taille;
    cout<<"Bonjour. Vous avez "<<age<<" ans et vous mesurez "<<taille<<" m"<<endl;

    return 0;

}
