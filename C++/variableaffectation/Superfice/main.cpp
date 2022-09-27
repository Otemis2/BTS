/*
#---------------------------------------
#Programme : Superfice
#Sujet : Calculer la superfice d'une suface
#Auteur : Mme Rapebach
#Date de création : 07/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: nb1: réels
     nb2 :réels
     metrec :
     hectare :

Début
Afficher "Saisir la longueur"
Saisir nb1
Afficher "Saisir la largeur"
Saisir nb2
metrec = nb1*nb2
Afficher "le perimetre est de ",metrec," metres²"
hectare = metrec * 10000
Afficher "le perimetre est de ",hectare," hectare"
Fin
#Tests
longueur largueur metre carré hectare
 10         5          50      0.005
 3.7       5.9        21.83   0.002183
*/
int main()
{
     float nb1;
     float nb2;
     float metrec;
     float hectare;


cout << "Saisir la longueur"<< endl;
cin >> nb1; // Préferable de mettre longueur et largueur en variable
cout << "Saisir la largeur"<< endl;
cin >> nb2;
metrec = nb1*nb2;
cout << "le perimetre est de "<<metrec<<" metres carres"<< endl;
hectare = metrec / 10000;
cout << "le perimetre est de "<<hectare<<" hectare"<< endl;
    return 0;
}

