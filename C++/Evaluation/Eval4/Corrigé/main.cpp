#include <iostream>
#include "string.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    short choix;
    cout<<"Choisir l'exercice : "<<endl;
    cin>>choix;
    switch (choix)
    {
    case 1:
    {
        char mots[6][7];
        strcpy(mots[0],"cheval");
        strcpy(mots[1],"oiseau");
        strcpy(mots[2],"majeur");
        strcpy(mots[3],"desert");
        strcpy(mots[4],"rateau");
        strcpy(mots[5],"orange");

        short nbCoups=0;
        char motSecret[7];
        srand(time(0));
        strcpy(motSecret,mots[rand()%6]);
        //cout<<motATrouver<<endl;
        char* motPropose=new char[256];
        char motAffiche[7]="******";
        do
        {
            nbCoups+=1;

            cout<<"Propose un mot de 6 lettres en minuscule "<<endl;
            cin>>motPropose;
            if (strlen(motPropose)!=6)
            {
                cout<<"Le mot propose n'a pas 6 lettres"<<endl;
            }
            else
            {
                for (short i=0;i<6;i++)
                {
                    if (motPropose[i]==motSecret[i])
                    {
                        motAffiche[i]=motPropose[i]+'A'-'a';
                    }
                }
            }
            cout<<motAffiche<<endl;
        } while (strcmp(motSecret,motPropose)!=0);

        cout<<"Bravo vous avez trouve en "<<nbCoups<<" coups."<<endl;
        break;
    }

    case 2:
    {
        char mdp[8]="Bonjour";
        char question[9]="Chouette";
        char *proposition=new char [256];
        char *reponse=new char[256];
        short tentative=0;

        do
        {
            tentative++;
            cout<<"Entrez votre mot de passe "<<endl;
            cin>>proposition;

        }while (strcmp(proposition,mdp)!=0 && tentative<3);

        if (strcmp(proposition,mdp)!=0)
        {
            cout<<"Repondez a la question suivante : quel type d'animal est Hedwige dans Harry Potter ?"<<endl;
            cin>>reponse;
            if (strcmp(reponse,question)==0)
            {
                cout<<"Vous etes bien identifie"<<endl;
            }
            else
            {
                cout<<"L'acces est refuse"<<endl;
            }
        }
        else
        {
            cout<<"Vous etes bien identifie"<<endl;
        }

        break;
    }
    case 3 :
    {
        char terminaisons[6][4]={"ai","as","a","ons","ez","ont"};
        char pronoms[6][5]={"Je","Tu","Il","Nous","Vous","Ils"};
        char *verbe=new char[256];
        cout<<"Saisir un verbe du premier groupe"<<endl;
        cin>>verbe;
        for (short i=0;i<6;i++)
        {
            cout<<pronoms[i]<<" "<<verbe<<terminaisons[i]<<endl;
        }
        break;
    }
    }

    return 0;
}

