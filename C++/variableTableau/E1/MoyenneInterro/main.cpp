/*
#---------------------------------------
#Programme : MoyenneInterro
#Sujet : Calculer la moyenne d'une classe a une interro puis donne la plus basse et la meilleurs
#Auteur :HUCK
#Date de création : 16/11/2020
# Version :
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR :
      nbeleve,note : court
      i : entiers
      tabNote [nbeleve] ,somme,moyenne : réels

    afficher "Combien avez vous d'eleves ?";
    Saisir nbeleve;


    Pour ( i <- 0 jusqu'à nbEleve -1 avec un pas de 1)faire
        afficher "Saisir la note ",i++
        Saisir tabNote[i];
        somme <- somme+note
    FinPour

    somme =0;
    maxi = 0;
    mini =20;
    Pour ( i <- 0 jusqu'à nbEleve -1 avec un pas de 1)faire
        afficher "La note de l'élève ",i+1," est ",tabNote [i];
        Si tabNote[i]>maxi alors
            maxi <- tabNote[i]
        FinSi
        Si tabNote [i]< mini alors
            mini <- tabeNote[i]
        FinSi
    FinPour

    moyenne <- somme/nbeleve

    Afficher "La moyenne de cette interro est de : ",moyenne;
    Afficher "La moins bonne note est : ",mini;
    Afficher "La meilleur note est : ",maxi;

# Tests
note 1  note 2  note 3  note 4  note 5  note 6  note 7 note 8  note 9   note 10     moyenne
12        5      3       9,5      14      18,5    7     18,5    9         11,5        10.8

*/
int main()
{
    float moyenne,maxi,mini;
    short nbeleve;
    float somme=0;

    cout << "Combien avez vous d'eleves ?"<<endl;
    cin>> nbeleve;

    float tabNote [nbeleve];

    for (short i=0;i<=( nbeleve-1 ) ;i++)
    {
        cout<<"Saisir la note "<<i+1<<endl;
        cin>> tabNote [i];
        somme=somme+tabNote [i];
    }
    cout<<endl;

    maxi = 0;
    mini =20;

    for (short i=0;i<=( nbeleve-1 ) ;i++)
    {
        cout << "la note d'eleve "<<i+1<<" est : "<<tabNote [i]<<endl;

        if ( tabNote[i]>maxi)
        {
           maxi = tabNote[i];
        }
        if (tabNote [i]< mini)
        {
               mini = tabNote[i];
        }
    }
    cout<<endl;

    moyenne=somme/nbeleve;

    cout<<"La moyenne de cette interro est de : "<<moyenne<<endl<<endl;
    cout<<"La moins bonne note est : "<<mini<<endl;
    cout<<"La meilleur note est : "<<maxi<<endl;
}

