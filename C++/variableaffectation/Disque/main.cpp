/*
#---------------------------------------
#Programme : Tarifs
#Sujet : Calculer un tarifs
#Auteur : Mme Rapebach
#Date de cr�ation : 14/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: rayon,circonf,surface : r�els
const : PI=3.14 : r�el

D�but
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

