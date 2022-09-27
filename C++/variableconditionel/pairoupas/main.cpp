/*
#---------------------------------------
#Programme : pairoupas
#Sujet : déterminer si un nombre entier saisi par l’utilisateur est pair ou impair
#Auteur : Sylvain HUCK
#Date de création : 21/09/2020
# Version : 1
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR:   nb1 : entier



Début
    Afficher "Saisir deux nombres entiers"
    Saisir nb1
    Si (nb1 mod 2 = 0) alors
        afficher "le nombre est pair"
    sinon
        afficher "le nombre impair"
    FinSi
Fin

#Tests
     4   : pair
     1  : impair
*/
int main()
{
    unsigned short nb1;

    cout<<"Saisir deux nombres entiers"<<endl;
    cin>>nb1;
    if (nb1 % 2 == 0)
    {
        cout<< "le nombre est pair"<<endl;
    }
    else
    {
        cout<< "le nombre est impair"<<endl;
    }

    return 0;
}
