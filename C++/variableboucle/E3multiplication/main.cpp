/*
#---------------------------------------
#Programme : multiplication
#Sujet : On veut avoir la table de multication de 2
#Auteur : HUCK
#Date de création : 12/10/2020
# Version : 0
#---------------------------------------
*/
#include <iostream>

using namespace std;
/*
VAR:resultat ,x : réel

Début
x<-0
tant que (x!=x)faire
resultat = x*2
x<- x+1
Fin

#Tests

*/
int main()
{
    short result , nbMult , nbx , mult;
    cout << "veullez saisir la table de multiplication que vous desirez"<<endl;
    cin >> mult;
    cout << "veullez saisir le multiplicateur que vous desirez"<<endl;
    cin >> nbMult;
    nbx = 0 ;

    while ( nbx -1 != nbMult)
    {
        result = mult * nbx ;
        cout << mult << " * " << nbx << " = " << result << endl;
        nbx = nbx + 1;
    }

    return 0;
}

