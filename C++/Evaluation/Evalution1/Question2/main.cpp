/*
#---------------------------------------
#Programme : Tarifs
#Sujet : Calculer un tarifs
#Auteur : HUCK Sylvain
#Date de création : 28/09/20
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: nbadult,nbenfant,tarif : réels

Début
Afficher "Veuliez saisir le nombre d'adulte et le nombre d'enfants, s'il vous plait";
Afficher "Veuliez saisir le nombre d'adulte";
Saisir nbadult;
Afficher "Veuiller saisir le nombre d'enfants";
Saisir nbenfant;
tarif<- (nbadult * 24) + (nbenfant * 18)
Afficher "Veuliez payer ",tarif," euro"
Fin
#Tests
tarif     nbadult    nbenfant
 432        3          20
  78        1          3
*/
int main()
{
float nbadult ,nbenfant,tarif;

cout << "Veuliez saisir le nombre d'adulte et le nombre d'enfants, s'il vous plait"<<endl;
cout << "Veuiller saisir le nombre d'adulte"<<endl;
cin >> nbadult;
cout << "Veuiller saisir le nombre d'enfants"<<endl;
cin >> nbenfant;
tarif = (nbadult * 24) + (nbenfant * 18);
cout << "Veuliez payer "<<tarif<<" euro"<<endl;
    return 0;
}

