/*
#---------------------------------------
#Programme : Tarifs
#Sujet : Calculer un tarifs
#Auteur : Mme Rapebach
#Date de création : 14/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: adulte, enfant, prix : réels

Début
Afficher "Bonjour, veuiller saisir le nombre d'adulte et le nombre d'enfant, s'il vous plait";
Afficher "Veuiller saisir le nombre d'adulte";
Saisir adulte;
Afficher "Veuiller saisir le nombre d'enfant";
Saisir enfant;
adulte <- adulte * 37;
enfant <- enfant * 28;
prix <- adulte + enfant
Afficher "le prix est de ",prix,"euro"
Fin
#Tests
prix      adulte    enfant
 671        3         20
 121        1         3
*/
int main()
{
float adulte;
float enfant;
float prix;

cout << "Bonjour, veuiller saisir le nombre d'adulte et le nombre d'enfant, s'il vous plait"<<endl;
cout << "Veuiller saisir le nombre d'adulte"<<endl;
cin >> adulte;
cout << "Veuiller saisir le nombre d'enfant"<<endl;
cin >> enfant;
adulte = adulte * 37;
enfant = enfant * 28;
prix = adulte + enfant;
cout << "le prix est de "<<prix<<" euro"<<endl;

    return 0;
}

