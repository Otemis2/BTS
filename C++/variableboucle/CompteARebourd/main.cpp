/*
#---------------------------------------
#Programme : CompteARebourd
#Sujet : Cree un algorithme qui decompte un temps donnée
#Auteur :HUCK
#Date de création :2/11/20
#Version :
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
Début

VAR: minute , decompte : short;

afficher "veulliez saisir les minutes et les secondes du compte a rebourd";
afficher "veulliez saisir les minutes ";
saisir minute;
afficher "veulliez saisir les secondes du compte a rebourd";
saisir decompte;



    Tant que (decompte != 0)

        afficher minute "min", decompte , "s";
        decompte = decompte + (minute * 60);

        minute = div (decompte / 60)
        decompte = mod (decompte / 60)

        afficher minute " min ", decompte , "s";
        decompte = decompte --

    Fin Tant que

Fin

#Tests

*/
int main ()
{
short minute , decompte;

cout << "veulliez saisir les minutes et les secondes du compte a rebourd"<<endl;
cout << "veulliez saisir les minutes "<<endl;
cin >> minute<<endl;
cout << "veulliez saisir les secondes du compte a rebourd"<<endl;
cin >> decompte<<endl;

cout << minute "min", decompte , "s";
decompte = decompte + (minute * 60);

    while (decompte != 0)
    {

        minute = div (decompte / 60);
        decompte = mod (decompte / 60);

        cout << minute " min ", decompte , "s";
        decompte = decompte --;
    }
return 0;
}
