/*
#---------------------------------------
#Programme : Nom du programme
#Sujet :
#Auteur :
#Date de cr�ation :
# Version :
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR:
CONST :

D�but

Fin

#Tests

*/
int main()
{
    short date,mois,annee;
    cout << "Veuliez saisir votre date de naissance" <<endl;
    cout << "Veuliez saisir votre le jour" <<endl;
    cin >> date;
    cout << "Veuliez saisir votre le mois" <<endl;
    cin >> mois;
    cout << "Veuliez saisir votre annee" <<endl;
    cin >> annee;
    annee = 2020 - annee;
    cout << "votre age est "<< annee<<" ans"<<endl;

    return 0;
}

