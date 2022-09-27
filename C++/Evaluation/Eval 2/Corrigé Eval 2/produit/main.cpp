/*
  # ------------------------------------
  # Nom du programme : produit
  # Sujet : Calculer le produit des nombres de 1 à n, n étant saisi par l'utilisateur
  # Auteur : Mme Rapebach
  # Date de création : 21/10/2020
  # Version : 1
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : n : entier
      produit : entier
      i : entier
Début
    produit<-1
    Afficher "Entrer un nombre entier positif"
    Saisir n
    Pour (i<-2 jusqu'à n avec un pas de 1) faire
        produit=produit*i
    Fin Pour
    Afficher "Le produit des nombres de 1 a ",n," vaut ",produit
Fin

# Tests
n   produit
4   24
*/
int main()
{
    short n;
    short produit=1;
    cout<<"Saisir un nombre entier positif"<<endl;
    cin>>n;
    for (short i=2;i<=n;i++)
    {
        produit=produit*i;
    }
    cout<<"Le produit des nombres de 1 a "<<n<<" vaut "<<produit<<endl;
    return 0;
}


