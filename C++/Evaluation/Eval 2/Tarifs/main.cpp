/*
#---------------------------------------
#Programme : Tarifs
#Sujet : Determiner le tarif tarifs
#Auteur : HUCK
#Date de création : 14/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: age : short

Début
Afficher "Bonjour, qu elle age avez vous , s'il vous plait";
Saisir age;
    Si (age < 8)
       Afficher "Votre entre est gratuite, bonne visite !"
    Sinon
         Si (age <= 26)
            Afficher "Votre entre coutera 5 euro, bonne visite !"
            Sinon
                Si (age <= 65)
                    Afficher "Votre entre coutera 13 euro, bonne visite !"
                        Sinon
                            Afficher "Votre entre coutera 7 euro, bonne visite !"
                FinSi
         FinSi
    FinSi
Fin

#Tests
Age Prix
7    Gratuit
10   5
55   13
78   7
*/
int main()
{
short age ;

cout << "Bonjour, qu elle age avez vous , s'il vous plait"<<endl;
cin >>age;

if (age <= 7)
    {
        cout << "Votre entre est gratuite, bonne visite !"<<endl;
    }
    else
        {
        if (age <= 25)
            {
            cout << "Votre entre coutera 5 euro, bonne visite !"<<endl;
            }
            else
                {
                    if (age <= 65)
                        {
                            cout << "Votre entre coutera 13 euro, bonne visite !"<<endl;
                        }
                        else
                            {
                                cout << "Votre entre coutera 7 euro, bonne visite !"<<endl;
                           }
                }
        }
    return 0;
}
