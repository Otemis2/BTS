/*
#---------------------------------------
#Programme : Reduction
#Sujet : Calculer la reduction d'un prix
#Auteur : Mme Rapebach
#Date de création : 14/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: prix : réels
     P100 : réels
     promo : réels

Début
Afficher "Saisir le prix sans reduction";
    p100 = p100/100;
    promo = prix*p100;
    promo = prix-promo; prix * (1-reduc/100)
Saisir prix;
Afficher "Saisir le taux de reduction";
Saisir p100;
p100 <- p100/100
promo <- prix*p100;
Afficher "le perimetre est de ",promo;
Fin
#Tests
prix      p100    promo
 5         5        4.75
*/
int main()
{
  float prix;
  float p100;
  float promo;
    cout << "Saisir le prix sans reduction"<<endl;
    cin >> prix;
    cout << "Saisir le taux de reduction"<<endl;
    cin >> p100;
    promo = prix * (1-p100/100)
    cout << "Le prix reduit est de "<<promo<<endl;
    return 0;
}
