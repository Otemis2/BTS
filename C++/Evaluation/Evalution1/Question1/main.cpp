/*
#---------------------------------------
#Programme : Moyenne
#Sujet : Calculer la moyenne de 3 valeurs
#Auteur : HUCK Sylvain
#Date de création : 28/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR:nb1,nb2,nb3,moy : réels

Début
Afficher « Veuliez saisir 3 valeurs »
Afficher « Veuliez saisir la premières valeurs »
Saisir nb1
Afficher « Veuliez saisir la seconde valeurs »
Saisir nb2
Afficher « Veuliez saisir la dernières valeurs »
Saisir nb3
moy<- nb1+nb2+nb 3/3
Afficher « La moyenne est de », moy
Fin

#Tests
nb1     nb2     nb3         moy
9       18      5           10.66
-12     3       5,6         -1.13
*/

int main()
{

    float nb1,nb2,nb3,moy;

    cout<<  "Veuliez saisir 3 valeurs"  <<endl;
    cout<<  "Veuliez saisir la premieres valeurs" <<endl;
    cin >> nb1;
    cout << "Veuliez saisir la seconde valeurs"  <<endl;
    cin >> nb2;
    cout << "Veuliez saisir la dernières valeurs"<<endl;
    cin >> nb3;
    moy = (nb1+nb2+nb3)/3;
    cout<< "La moyenne est de " << moy <<endl;

    return 0;
}

