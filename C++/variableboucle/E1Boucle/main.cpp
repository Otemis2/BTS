/*
#---------------------------------------
#Programme : E1Boucle
#Sujet : Determiner la valeur la plus grande entre 20 valeurs
#Auteur : HUCK Sylvain
#Date de création : 05/10/2020
# Version : 0
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: nbGrand,nbDonne : entier
     i : entier

Début

    Pour (i <- 1 jusqu'à 20 avec un pas de 1)
        Afficher "Veuliez saisir un chiffre entre 1 et 20"
        Saisir nbDonne
        nbGrand <- 0
        si (nbDonne >= nbGrand)
            nbGrand = nbDonne
        finsi
   FinPour
   afficher "la plus grande valeurs est ",nbGrand
Fin

#Tests

*/
int main()
{
    unsigned short nbGrand,nbDonne;
    unsigned short i;
    for (short i = 1; i <= 20; i++)
    {
        cout << "Veuliez saisir un chiffre entre 1 et 20"<<endl;
        cin nbDonne;
        nbGrand = 0;
        if (nbDonne >= nbGrand)
    {
      nbGrand = nbDonne;
    }
    }
    cout << "La plus grande valeur est "<<nbGrand<<endl;
    return 0;
}

