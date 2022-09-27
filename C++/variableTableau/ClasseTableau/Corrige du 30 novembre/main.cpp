#include <iostream>
#include "ctableau.h"
using namespace std;

/*# --------------------------------------
# Nom Proc�dure : afficher
# Sujet : afficher les �l�ments d'un tableau.
# Version : 0.1
# Entr�e : tableau : instance de la classe Tableau
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Cr�ation : 04/11/20
# Mise �  jour :
# ----------------------------------------
Proc�dure afficher(in tableau : instance de la classe Tableau)
    VAR : table : tableau d'entiers
          nbCases : entier
          i : entier
    D�but
        table<-attribut table de l'objet tableau
        nbCases<-attribut nbCases de l'objet tableau
        Pour (i<-0 jusqu'� nbCases-1 avec un pas de 1) faire
            Afficher "|",table[i]
        FinPour
        afficher "|"
    Fin

*/

void afficher(CTableau tableau)
{
    short *table=tableau.getTable();
    short nbCases=tableau.getNbCases();
    for (short i=0;i<nbCases;i++)
    {
        cout<<"|"<<table[i];
    }
    cout<<"|"<<endl;
}

int main()
{
    short element;
    short choix;
    //short tab[5]={5,1,4,3,2};
    //CTableau tableau(5,tab);
    CTableau tableau(10,20); // Création d'un tableau de 10 cases
    // comprenant des nombres entiers aléatoires compris entre 1 et 20.
    afficher(tableau);

    cout<<"Somme des elements du tableau "<<tableau.calculerSomme()<<endl;

    cout<<"Moyenne des elements du tableau "<<tableau.calculerMoyenne()<<endl;

    cout<<endl;

    cout<<"Valeur maximale "<<tableau.determinerMaximum()<<endl;
    cout<<"Valeur minimale "<<tableau.determinerMinimum()<<endl;

    cout<<endl;

    cout<<"Quel est l'element a chercher dans le tableau ?"<<endl;
    cin>>element;
    if (tableau.appartenir(element))
    {
        cout<<"L'element "<<element<<" est dans le tableau."<<endl;
    }
    else
    {
        cout<<"L'element "<<element<<" n'est pas dans le tableau."<<endl;
    }
    cout<<"L'element "<<element<<" apparait pour la premiere fois a la position "<<tableau.determinerOccurence(element)<<endl;
    /*cout<<"L'element "<<element<<" apparait "<<tableau.determinerNbApparitions(element)<<" fois dans le tableau "<<endl;
    cout<<"Dans le tableau, il y a "<<tableau.determinerNbSup10()<<" elements superieurs a 10."<<endl;
    */
    cout<<endl;

    cout<<"Choisir une methode de tri "<<endl;
    cout<<"1-Tri par selection"<<endl;
    cout<<"2-Tri par insertion"<<endl;
    cout<<"3-Tri a bulles"<<endl;
    cout<<"4-Mettre les pairs a gauche et les impairs a droite"<<endl;
    cin>>choix;
    switch (choix)
    {
    case 1:
        tableau.trierParSelection();
        break;
    case 2:
        tableau.trierParInsertion();
        break;
    case 3:
        tableau.trierABulles();
        break;
    /*case 4:
        tableau.classerPairsImpairs();
        break;*/
    default:
        cout<<"Choix invalide"<<endl;
    }
    cout<<"Affichage du tableau trie  ";
    afficher(tableau);
    return 0;
}
