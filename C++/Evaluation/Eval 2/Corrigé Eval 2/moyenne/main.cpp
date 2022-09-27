/*
  # ------------------------------------
  # Nom du programme : moyenne
  # Sujet : Dire à un étudiant si avec 3 notes il obtient la moyenne ou non
  # Auteur : Mme Rapebach
  # Date de création : 21/10/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>

using namespace std;

/*
VAR : note1,note2,note3 : réels

Début
    Afficher "Saisir la premiere note."
    Saisir note1
    Afficher "Saisir la deuxieme note."
    Saisir note2
    Afficher "Saisir la troisieme note."
    Saisir note3
    Si ((note1+note2+note3)/3<10) alors
        Afficher "Vous n'avez pas la moyenne, il faut travailler encore."
    Sinon
        Afficher "Bravo, vous avez la moyenne."
    Fin Si
Fin

# Tests
note1   note2   note3   Affichage
5.5     10      12.5    Vous n'avez pas la moyenne...
17.5    9       11      Bravo...
*/
int main()
{
    float note1,note2,note3;
    cout<<"Saisir la premiere note."<<endl;
    cin>>note1;
    cout<<"Saisir la deuxieme  note."<<endl;
    cin>>note2;
    cout<<"Saisir la troisieme  note."<<endl;
    cin>>note3;
    if ((note1+note2+note3)/3<10)
    {
        cout<<"Vous n'avez pas la moyenne, il faut travailler encore."<<endl;
    }
    else
    {
        cout<<"Bravo, vous avez la moyenne."<<endl;
    }
    return 0;
}

