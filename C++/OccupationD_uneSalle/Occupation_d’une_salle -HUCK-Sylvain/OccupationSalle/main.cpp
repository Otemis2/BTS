#include <iostream>
#include <string.h>
#include "csalle.h"

/*
# -----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire de gestion d'une salle
# Auteur : Huck
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------------------------------------------
*/

using namespace std;

int main()
{
    CSalle maSalle;
    short creneau = 0;
    bool occupation =0;
    short total = 0;
    short jour = 0;
    short choix;
    short nbOccuper = 0;
    short occupationGlo = 0;
    short nbCreneauMax  = 11;
    short i = 1;
    bool continuer=true;

    while (continuer)
    {
        choix=-1;

        cout<<"Faites un choix "<<endl;
        cout<<"1-Afficher tous les creneaux"<<endl;
        cout<<"2-Reserver un creneau d'une heure"<<endl;
        cout<<"3-Reserver un creneau de plusieurs heures"<<endl;
        cout<<"4-Liberer un creneau"<<endl;
        cout<<"5-Afficher les taux d'occupation"<<endl;
        cout<<"0-Quitter"<<endl;
        cin>>choix;


        switch (choix)
        {
        case 1:
            cout<<"\t ";
            for (short i=0;i<5;i++)
            {
                cout<<" "<<maSalle.getJours(i)<<"   ";//affiche en colone les jours
            }
            cout<<endl;
            for (short creneau=0;creneau<11;creneau++)
            {
                cout<<maSalle.getCreneaux(creneau)<<" : ";// affiche en ligne les créneaux
                for (short jour=0;jour<5;jour++)
                {
                    maSalle.getOccupations(creneau,jour);// Affiche l'occupation de la salle avec 0 et 1
                    if (maSalle.getOccupations(creneau,jour)== 0)//transforme le 0 en libre et sinon le reste en occupe
                    {
                        cout <<"Libre     ";
                    }
                    else
                    {
                        cout <<"Occupe    ";
                    }
                }
                cout<<endl;
            }
            break;
        case 2:
            cout<<"1 : lundi"<<endl;
            cout<<"2 : mardi"<<endl;
            cout<<"3 : mercredi"<<endl;
            cout<<"4 : jeudi"<<endl;
            cout<<"5 : vendredi"<<endl;
            cout<<"choisir un jour de la semaine"<<endl;
            cin>>jour;
            jour = jour - 1;

            for (short creneau=0;creneau<11;creneau++)
            {
                total = total + maSalle.getOccupations(creneau,jour);// Met dans une variable le nombre de creneau occuper
            }
            if(total == 11)
            {
                cout<<"Il n'y a plus de creneau disponible"<<endl;//si total est égal a 11 alors afficher message sinon
            }
            else
            {
               //affiche la liste de creneau
               short i = 1;
               cout<<maSalle.getJours(jour)<<endl;
               for(short creneau = 0; creneau < 11; creneau++)
               {
                   maSalle.getOccupations(creneau,jour);
                   cout<<i<<" : "<<maSalle.getCreneaux(creneau);
                   if (maSalle.getOccupations(creneau,jour)== 0)
                   {
                       cout <<" Libre"<<endl;
                   }
                   else
                   {
                       cout <<" Occupe"<<endl;
                   }
                   i++;
               }
               cout<<"Choisir un creneau"<<endl;
               cin>>creneau;
               creneau = creneau -1;
               //verifie si l'occupation de la salle est disponible
               if(maSalle.getOccupations(creneau,jour)== 1)
               {
                   cout<<"Le creneau choisi n'est pas disponible"<<endl;
               }
               else
               {
                   cout<<"salle reservee"<<endl;
                   occupation = 1;
                   maSalle.setOccupation(creneau, jour, occupation);//change l'occupation
               }
            }
            break;
        case 3:
            //Permet de reserver plusieurs creneaux
            short nbHeure;
            total = 0;

            cout<<"1 : lundi"<<endl;
            cout<<"2 : mardi"<<endl;
            cout<<"3 : mercredi"<<endl;
            cout<<"4 : jeudi"<<endl;
            cout<<"5 : vendredi"<<endl;
            cout<<"choisir un jour de la semaine"<<endl;
            cin>>jour;
            jour = jour -1;

            for (short creneau=0;creneau<11;creneau++)
            {
                total = total + maSalle.getOccupations(creneau,jour);
            }
            if(total == 11)
            {
                cout<<"Il n'y a plus de creneau disponible"<<endl;
            }
            else
            {
               short i = 1;
               short totalCreneau = 0;
               cout<<maSalle.getJours(jour)<<endl;
               for(short creneau = 0; creneau < 11; creneau++)
               {
                   maSalle.getOccupations(creneau,jour);
                   cout<<i<<" : "<<maSalle.getCreneaux(creneau);
                   if (maSalle.getOccupations(creneau,jour)== 0)
                   {
                       cout <<" Libre"<<endl;
                   }
                   else
                   {
                       cout <<" Occupe"<<endl;
                   }
                   i++;
               }
               cout<<"Choisir un debut de seance"<<endl;
               cin>>creneau;
               creneau = creneau -1;
               cout<<"Choisir un nombre d'heures"<<endl;
               cin>>nbHeure;

               short nbCreneau = (creneau + nbHeure);

               if(nbCreneau > 11)
               {
                   totalCreneau++;
               }
               else
               {
                   while(creneau < nbCreneau)
                   {
                     totalCreneau =  totalCreneau + maSalle.getOccupations(creneau,jour);
                     creneau++;
                   }
               }
               if(totalCreneau >= 1)
               {
                   cout<<"Il est impossible de faire cette reservation"<<endl;
               }
               else
               {
                   occupation = 1;
                   creneau = nbCreneau - nbHeure;
                   while (creneau < nbCreneau)
                   {
                        maSalle.setOccupation(creneau, jour, occupation);
                        creneau++;
                   }
                   cout<<"salle reservee"<<endl;
                }
            }
            break;
        case 4:
            //Liberer un creneau
            short jour;
            i = 1;

            cout<<"1 : lundi"<<endl;
            cout<<"2 : mardi"<<endl;
            cout<<"3 : mercredi"<<endl;
            cout<<"4 : jeudi"<<endl;
            cout<<"5 : vendredi"<<endl;
            cout<<"choisir un jour de la semaine"<<endl;
            cin>>jour;
            jour = jour - 1;

            cout<<maSalle.getJours(jour)<<endl;
            for(short creneau = 0; creneau < 11; creneau++)
            {
                maSalle.getOccupations(creneau,jour);
                cout<<i<<" : "<<maSalle.getCreneaux(creneau);
                if (maSalle.getOccupations(creneau,jour)== 0)
                {
                    cout <<" Libre"<<endl;
                }
                else
                {
                    cout <<" Occupe"<<endl;
                }
                i++;
             }
             cout<<"Choisir un creneau"<<endl;
             cin>>creneau;
             creneau = creneau -1;
             if(maSalle.getOccupations(creneau,jour)== 0)
             {
                   cout<<"Le creneau choisi est deja disponible"<<endl;//PAS Obligatoire (pas dit dans énoncé)
             }
             else
             {
                   cout<<"salle liberee"<<endl;
                   occupation = 0;
                   maSalle.setOccupation(creneau, jour, occupation);
             }

            break;
        case 5:
            //Calcule la le taux d'occupation
            cout<<"Taux d'occupations par jour"<<endl;
            creneau = 0;
            jour = 0;

            while (jour < 5)
            {
                while(creneau < nbCreneauMax)
                {
                  nbOccuper =  nbOccuper + maSalle.getOccupations(creneau,jour);
                  creneau++ ;
                }
                occupationGlo = occupationGlo + nbOccuper;
                cout<<maSalle.getJours(jour)<<" : "<<maSalle.getProba(nbOccuper, nbCreneauMax)<<" pourcent."<<endl;
                nbOccuper = 0;
                creneau = 0;
                jour++;
            }

            nbCreneauMax  = 55;
            cout<<"Taux d'occupations globale "<<maSalle.getProba(occupationGlo, nbCreneauMax)<<" pourcent."<<endl;

            break;
        case 0:
            continuer=false;
            break;
        default:
            break;
       }

        cout<<endl;
    }

    return 0;
}
