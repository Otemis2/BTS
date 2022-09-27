/*
#---------------------------------------
#Programme : ResolEqua
#Sujet : On souhaite de déterminer le nombre de solutions réelles de l'équation ax² + bx +C = 0
#Auteur : Sylvain HUCK
#Date de création : 12/10/2020
#Version : 1
#---------------------------------------
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
VAR:   a , b , c , delta ,x1 , x2 : entier

Début
 Afficher "Veuillez saisir  le coefficient a, b, c"
 Afficher "Veuillez saisir le coefficient a"
 Saisir a
 Afficher "Veuillez saisir le coefficient b"
 Saisir b
 Afficher "Veuillez saisir le coefficient c"
 Saisir c
 //d'abord calculer le determiner Delta (determinant) :
  delta = b² - 4ac

    Si "delta > 0 " alors
        x1 = (-b + sqrt (delta)/(2*a)
        x2 = (-b - sqrt (delta)/(2*a)
        Afficher "Il y a deux solutions"
        Afficher "Le coefficient x1 vaut : ",x1
        Afficher "Le coefficient x2 vaut : ",x2
    Sinon
        Si "delta < 0" alors
            x1 = (-b)/(2*a)
            Afficher "Il y a une solution"
            Afficher "Le coefficient x1 vaut : ",x1
        Sinon
            Afficher "Il n'y a pas de solution"

        FinSi
    FinSi

Fin

#Tests
 a  b   c  solution x1             x2
 2 -6   2     1     3
-6  2   4     2   -0.79076       1.12409
 0  2   6     0
*/

int main()
{
    float   a , b , c , delta ,x1 , x2;

    cout << "Veuillez saisir  le coefficient a, b, c"<<endl;
     cout << "Veuillez saisir le coefficient a"<<endl;
    cin >> a;
    cout << "Veuillez saisir le coefficient b"<<endl;
    cin >> b;
    cout << "Veuillez saisir le coefficient c"<<endl;
    cin >> c;
    //d'abord calculer le determiner Delta (determinant) :
    delta = pow (a,2) - (4*a*c);

    if (delta > 0)
    {
        x1 = (-b + sqrt (delta))/(2*a);
        x2 = (-b - sqrt (delta))/(2*a);
        cout << "Il y a deux solutions"<<endl;
        cout << "Le coefficient x1 vaut : "<<x1<<endl;
        cout << "Le coefficient x2 vaut : "<<x2<<endl;
    }
    else
    {
        if (delta < 0)
        {
            x1 = (-b)/(2*a);
            cout << "Il y a une solution"<<endl;
            cout << "Le coefficient x1 vaut : "<<x1<<endl;
        }
        else
        {
            cout << "Il n'y a pas de solution"<<endl;
        }

    }

    return 0;
}

