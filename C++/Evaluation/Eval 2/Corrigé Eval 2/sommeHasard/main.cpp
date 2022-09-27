/*
  # ------------------------------------
  # Nom du programme : sommeHasard
  # Sujet : demander à l'utilisateur de trouver le résultat d'une addition
  # Auteur : Mme Rapebach
  # Date de création : 21/10/2020
  # Version : 1
  #-------------------------------------
  */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
VAR : nb1,nb2 : entiers
    proposition : entier
    nbCoups: entier
Début
    nb1<-nombre aléatoire compris entre 1 et 1000
    nb2<-nombre aléatoire compris entre 1 et 1000
    proposition<-0
    nbCoups<-0
    Tant que (proposition <>nb1+nb2) faire
        nbCoups<-nbCoups+1
        Afficher "Combien vaut ",nb1,"+",nb2," ?"
        Saisir proposition
        Si (proposition<>nb1+nb2) alors
            Afficher "Ce n'est pas la bonne reponse ! ")
        Fin Si
    Fin Tant que
    Afficher "Vous avez trouve le bon resultat en ",nbCoups," coups."
Fin

# Tests
Proposer le bon résultat du premier coup, puis au deuxième coup, puis au troisième.
*/
int main()
{
    srand(time(0));
    short nb1,nb2;
    short proposition=0;
    short nbCoups=0;

    nb1=rand()%1000+1;
    nb2=rand()%1000+1;
    while (proposition!=nb1+nb2)
    {
        nbCoups++;
        cout<<"Combien vaut "<<nb1<<"+"<<nb2<<" ?"<<endl;
        cin>>proposition;
        if (proposition!=nb1+nb2)
        {
            cout<<"Ce n'est pas la bonne reponse ! "<<endl;
        }
    }

    cout << "Vous avez trouve le bon resultat en "<<nbCoups<<" coups." << endl;
    return 0;
}

