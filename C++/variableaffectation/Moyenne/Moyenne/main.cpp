/*
#---------------------------------------
#Programme : moyenne
#Sujet : faire la moyenne de deux nombres
#Auteur : Mme Rapebach
#Date de cr�ation : 14/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: nb1,nb2: r�els
     moyenne : r�el

D�but
Afficher "Saisir un premier nombre"
Saisir nb1
Afficher "Saisir un second nombre"
Saisir nb2
somme <-nb1+nb2/2
Afficher "La moyenne vaut",moyenne
Fin
#Tests
nb1 nb2     affichage
1   3       2.5
1.2 3.5     2.95
*/

int main()
{
   float nb1,nb2; // On d�clare les variables.
   float moyenne;

    cout << "Saisir un premier nombre"  << endl;
    cin >> nb1;
    cout << "Saisir un second nombre" << endl;
    cin >> nb2;
    moyenne=nb1+nb2/2;
    cout<<"La moyenne vaut "<<moyenne<<endl;

    return 0;

}
