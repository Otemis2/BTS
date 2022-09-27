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
VAR: rayon,circonf,surface : réels
const : PI=3.14 : réel

Début
PI <- 3.14
Afficher "Veuiller saisir le rayon";
Saisir rayon;
circonf <- 2 * PI * rayon;
surface <- (rayon * rayon) * PI;
Afficher "La circonference est de ",circonf,"et la surface est de ",surface
Fin

#Tests
rayon      circonference    surface
 3            18.84          28.26
 10            62.8           314
*/
int main()
{
float rayon;
float circonf;
float surface;
const float PI = 3.14;

cout << "Veuiller saisir le rayon"<<endl;
cin >> rayon;
circonf = 2 * PI * rayon;
surface = (rayon * rayon) * PI;
cout << "La circonference est de "<< circonf<<" et la surface est de "<< surface<<endl;
    return 0;
}

