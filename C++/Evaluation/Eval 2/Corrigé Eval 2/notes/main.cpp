/*
  # ------------------------------------
  # Nom du programme : notes
  # Sujet : Demander au professeur combien il souhaite de notes, lui demander de les saisir,
  puis lui afficher la meilleure, la moins bonne et la moyenne
  # Auteur : Mme Rapebach
  # Date de création : 21/10/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : nbNotes : entier
      note : réel
      somme : réel
      maxi,mini : réels
      i : entier
Début
    Afficher "Combien de notes voulez-vous saisir ?"
    Saisir nbNotes
    maxi<-0
    mini<-20
    Pour (i<-1 jusqu'à nbNotes avec un pas de 1) faire
        Afficher "Saisir la note numero ",i
        Saisir note
        somme<-somme+note
        Si (note>maxi) alors
            maxi<-note
        Fin Si
        Si (note<mini) alors
            mini<-note
        Fin Si
   Fin Pour
   Afficher "La moyenne est de ",somme/nbNotes,", la meilleure note est ",maxi," et la moins bonne est ",mini
Fin

# Test
Proposé dans le sujet
*/
int main()
{
    short nbNotes;
    float note,somme;
    float mini=20;
    float maxi=0;
    cout<<"Combien de notes voulez vous saisir ?"<<endl;
    cin>>nbNotes;
    for (short i=1;i<=nbNotes;i++)
    {
        cout<<"Saisir la note numero "<<i<<endl;
        cin>>note;
        somme=somme+note;
        if (note>maxi)
        {
            maxi=note;
        }
        if (note<mini)
        {
            mini=note;
        }
    }
    cout<<"La moyenne est de "<<somme/nbNotes<<", la meilleure note est "<<maxi<<" et la moins bonne est "<<mini<<endl;
    return 0;
}

