#include <iostream>

using namespace std;

int main()
{
    short tabTemp(7); // Tableau contenant 7 valeurs
    short listeTemp[tabTemp]; // Variable qui encadre le tableau

    short moyenne;

    cout<<"Temp 1 : "<<endl;
    cin>>listeTemp[0]; // Affectation de la valeur au slot 0 (premier slot du tableau)

    cout<<"Temp 2 : "<<endl;
    cin>>listeTemp[1];

    cout<<"Temp 3 : "<<endl;
    cin>>listeTemp[2];

    cout<<"Temp 4 : "<<endl;
    cin>>listeTemp[3];

    cout<<"Temp 5 : "<<endl;
    cin>>listeTemp[4];

    cout<<"Temp 6 : "<<endl;
    cin>>listeTemp[5];

    cout<<"Temp 7 : "<<endl;
    cin>>listeTemp[6];

    moyenne = listeTemp[0+1+2+3+4+5+6] /7; // Calcul de la moyenne ?

    cout<<moyenne<<endl;
}
