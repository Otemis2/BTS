/*
  # ------------------------------------
  # Nom du programme : temperature
  # Sujet : Calculer la température moyenne sur 7 jours
  # Auteur : Mme Rapebach
  # Date de création : 30/10/2020
  # Version : 1
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : temp,somme,moyenne : flottants
      i : entier
Début
    somme<-0
    Pour (i<-1 jusqu'à 7 avec un pas de 1 faire)
        Afficher "Saisir la température du jour ",i
        Saisir temp
        somme<-somme+temp
    Fin Pour
    moyenne<-temp/7
    Afficher "La temperature moyenne sur 7 jours vaut ",moyenne
Fin

# Tests
temp 1  temp 2  temp 3  temp 4  temp 5  temp 6  temp 7  moyenne
12.5    13      11.5    12      13      10.5    9.5     11.71

*/
int main()
{
    float moyenne,temp;
    float somme=0;
    for (short i=1;i<=7;i++)
    {
        cout<<"Saisir la temperature du jour "<<i<<endl;
        cin>>temp;
        somme=somme+temp;
    }
    moyenne=somme/7;
    cout<<"La temperature moyenne sur 7 jours vaut "<<moyenne<<endl;
}
