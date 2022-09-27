/*
  # ------------------------------------
  # Nom du programme : temperature_moyenne
  # Sujet : stocker les températures sur 7 jours et calculer la moyenne
  # Auteur : Mme Rapebach
  # Date de création : 22/10/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : tabTemp[7] : tableau de réels.
      moyenne, somme : réels
      i : entier

Début
    somme=0
    Pour (i<-0 jusqu'à 6 avec un pas de 1) faire
        Afficher ("Saisir la temperature du jour ",i+1
        Saisir tabTemp[i]
        somme=somme+tabTemp[i]
    Fin Pour
    moyenne=somme/7
    Afficher ("La température moyenne est de ",moyenne)
    Afficher ("Affichage de la variable tabTemp ",tabTemp)
Fin

# Tests
tabTemp                 moyenne
[12,13,15,11,16,9,10]   environ 12.3
*/
int main()
{
    float tabTemp[7];
    float moyenne;
    float somme=0;
    for (short i=0;i<7;i++)
    {
        cout<<"Saisir la temperature du jour "<<i+1<<endl;
        cin>>tabTemp[i];
        somme=somme+tabTemp[i];
    }
    moyenne=somme/7;
    cout<<"La temperature moyenne est de "<<moyenne<<endl;
    cout<<"Affichage de la variable tabTemp "<<tabTemp<<endl;

    return 0;
}


