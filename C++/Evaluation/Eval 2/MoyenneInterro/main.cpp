/*
#---------------------------------------
#Programme : MoyenneInterro
#Sujet : Calculer la moyenne d'une classe a une interro puis donne la plsu basse et la meilleurs
#Auteur :HUCK
#Date de création : 09/11/2020
# Version :
#---------------------------------------
*/

#include <iostream>

using namespace std;
/*
VAR : somme,moyenne, i : flottants
      nbeleve,note : court

    afficher "Combien avez vous d'eleves ?";
    Saisir nbeleve;
    Pour ( i <- 1;i<=nbeleve;i++)
    {
        afficher "Saisir la note ",i
        Saisir note;*
        somme <- somme+note
    }
    moyenne <- somme/nbeleve
    Afficher <- "La moyenne de cette interro est de : ",moyenne;

# Tests
note 1  note 2  note 3  note 4  note 5  note 6  note 7 note 8  note 9   note 10     moyenne
12        5      3       9,5      14      18,5    7     18,5    9         11,5        10.8

*/
int main()
{
    float moyenne,nbeleve,note;
    float somme=0;

    cout << "Combien avez vous d'eleves ?"<<endl;
    cin>> nbeleve;
    for (float i=1;i<=nbeleve;i++)
    {
        cout<<"Saisir la note "<<i<<endl;
        cin>>note;
        somme=somme+note;
    }
    moyenne=somme/nbeleve;
    cout<<"La moyenne de cette interro est de : "<<moyenne<<endl;
}

