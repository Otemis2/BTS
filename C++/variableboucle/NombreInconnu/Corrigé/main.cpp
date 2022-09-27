/*
  # ------------------------------------
  # Nom du programme : exercice6_ameliore
  # Sujet : Jeu qui consiste à trouver un nombre entier compris entre 1 et 1000
  # Auteur : Mme Rapebach
  # Date de création : 20/11/2020
  # Version : 1
  #-------------------------------------
  */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
VAR : nbSecret,nbPropose : entiers
      nbPartiesGagnees,nbPartiesJouees,nbCoups : entiers
      rejouer : booléen
      choix : entier
Début
    rejouer<-Vrai
    nbPartiesJouees<-0
    nbPartiesGagnees<-0
    Tant que (rejouer) faire
        nbPartiesJouees<-nbPartiesJouees+1
        nbSecret<-nombre entier aleatoire compris entre 1 et 1000
        nbPropose<-0
        nbCoups<-0
        Tant que ((nbPropose<>nbSecret et nbCoups<10)) faire
            nbCoups<-nbCoups+1
            Afficher "Proposez un nombre compris entre 1 et 1000"
            Saisir nbPropose
            Si (nbPropose<nbSecret) alors
                Afficher "Le nombre propose est trop petit."
            Sinon
                Si (nbPropose>nbSecret) alors
                    Afficher "Le nombre propose est trop grand?"
                Fin Si
            Fin Si
        Fin Tant que
        Si (nbPropose<>nbSecret) alors
            Afficher "Vous avez perdu ! Le nombre a trouver etait ",nbSecret
        Sinon
            Afficher "Bravo vous avez gagne en ",nbCoups," essais."
            nbPartiesGagnees<-nbPartieGagnees+1
        Fin Si
        Afficher "Vous avez joue ",nbPartiesJouees," parties et vous en avez gagne ",nbPartiesGagnees
        Afficher "Taper 1 pour recommencer une partie"
        Saisir choix
        Si (choix!=1) alors
            rejouer<-faux
        Fin Si
   Fin Tant que
Fin

# Tests
Afficher le nombre a trouver pour les tests.
. Trouver le nombre en moins de 10 coups : verifier que le nombre de coups est correct
. Trouver le nombre en exactement 10 coups
. Ne pas trouver le nombre en moins de 10 coups
Vérifier à chaque fois que le nombre de parties jouees et le nombre de parties gagnees sont corrects
*/
int main()
{
    short nbSecret,nbPropose;
    short nbPartiesGagnees=0,nbPartiesJouees=0;
    short nbCoups;
    bool rejouer=true;
    short choix;
    srand(time(0));

    while (rejouer)
    {
        nbPartiesJouees++;
        nbSecret=rand()%1000+1;
        nbPropose=0;
        nbCoups=0;
        cout<<nbSecret<<endl;
        while ((nbPropose!=nbSecret)&&(nbCoups<10))
        {
            nbCoups++;
            cout<<"Proposez un nombre compris entre 1 et 1000"<<endl;
            cin>>nbPropose;
            if (nbPropose<nbSecret)
            {
                cout<<"Le nombre propose est trop petit."<<endl;
            }
            else
            {
                if (nbPropose>nbSecret)
                {
                    cout<<"Le nombre propose est trop grand."<<endl;
                }
            }
        }
        if (nbPropose!=nbSecret)
        {
            cout<<"Vous avez perdu ! Le nombre a trouver etait "<<nbSecret<<endl<<endl;
        }
        else
        {
            cout<<"Bravo vous avez gagne en "<<nbCoups<<" essais."<<endl<<endl;
        }
        cout<<"Vous avez joue "<<nbPartiesJouees<< " parties et vous en avez gagne "<<nbPartiesGagnees<<endl<<endl;
        cout<<"Tapez 1 pour recommencer une partie."<<endl;
        cin>>choix;
        if (choix!=1)
        {
            rejouer=false;
        }
        cout<<endl;
    }


    return 0;
}
