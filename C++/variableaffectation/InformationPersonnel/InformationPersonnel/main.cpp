/*
#---------------------------------------
#Programme : Presentation
#Sujet : Demander � l'utilisateur sa taille et son age et les afficher
#Auteur : Mme Rapebach
#Date de cr�ation : 07/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: age: entier court
     taille : r�els

D�but
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
   unsigned short age; // On d�clare les variables.
   float taille;

    cout << "Bonjour. Veuiller entr�e votre age et votre taille, s'il vous plait."  << endl;
    cin >> age;
    cin >> taille;
    cout<<"Bonjour. Vous avez "<<age<<" ans et vous mesurez "<<taille<<" m"<<endl;

    return 0;

}
