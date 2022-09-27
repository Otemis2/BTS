/*
#---------------------------------------
#Programme : Moyenne2
#Sujet : On demande a l'utilisateur 3 note et on calcule la moyenne
#Auteur : HUCK
#Date de création : 09/11/2020
#Version :
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR: somme,moyenne,note

Debut
    somme<-0
    Pour (i<-1 jusqu'a  3 avec un pas de 1 faire)
        Afficher "Bonjour, veulliez saisir 3 note et je calculerai votre moyenne !",i
        Saisir note
        somme<-somme+note
    Fin Pour
    moyenne<-somme/3
        Si(moyenne => 10)
            Afficher "  Bravo, vous avez la moyenne, elle est de : ",moyenne
        Sinon
            Afficher "Vous n'avez pas la moyenne, il faut travailler encore, elle est de : ",moyenne
        FinSi
Fin

# Tests
note 1  note 2  note 3    moyenne  phrase
10      10      10          10     Bravo, vous avez la moyenne, elle est de :
 9      3       17          9.67   Vous n'avez pas la moyenne, il faut travailler encore, elle est de :
#Tests

*/

int main()
{

float moyenne,note;
float somme =0;

    somme<-0;
    cout << "Bonjour, veulliez saisir 3 note et je calculerai votre moyenne !"<<endl;
    for (short i = 1; i<= 3; i++)
    {
        cout << "veulliez saisir une note  !"<<endl<<i<<" :"<<endl;
        cin >> note;
        somme = somme+note;
    }
    moyenne = somme/3;
    if (moyenne >= 10)
        {
            cout << "Bravo, vous avez la moyenne, elle est de : "<<moyenne<<endl;
        }
        else
            {
            cout << "Vous n'avez pas la moyenne, il faut travailler encore, elle est de : "<<moyenne<<endl;
            }
}
