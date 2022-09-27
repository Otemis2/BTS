/*
  # ------------------------------------
  # Nom du programme : age
  # Sujet : Calculer l'âge d'une personne à partir de sa date de naissance
  # Auteur : Mme Rapebach
  # Date de création : 02/10/2020
  # Version :
  #-------------------------------------
  */

#include <iostream>
#include <ctime> // Bibliothèque permettant de récuperer la date du jour.

using namespace std;

/*
VAR : jour,mois,annee : entiers
      jourA,moisA,anneeA : entiers
      age : entier
Début
    jourA<-jour systeme
    moisA<-mois systeme
    anneeA<annee systeme
    Afficher "Entre ton jour de naissance"
    Saisir jour
    Afficher "Entre ton mois de naissance (entier entre 1 et 12)
    Saisir mois
    Afficher "Entre ton annee de naissance"
    Saisir annee
    age<-anneeA-annee
    Si ((mois>moisA) OU ((mois=moisA) ET (jour>jourA))) alors
        age<-age-1
    Fin Si
    Afficher "Tu as ",age," ans.")
Fin

# Tests
jour    mois    annee       age
12      3       2000        20
3       10      2005        15
5       10      2002        18
30      10      2001        18
7       12      2000        19

*/
int main()
{
    time_t now=time(0);
    struct tm *date=localtime(&now);

    short jourA,moisA,anneeA;
    short jour,mois,annee;
    short age;

    jourA=date->tm_mday; // Donne le jour du mois
    moisA=date->tm_mon+1; // tm_mon donne le mois depuis janvier (donc entre 0 et 11)
    anneeA=date->tm_year+1900; // tm_donne le nombre d'année depuis 1900
    cout<<"Entre ton jour de naissance."<<endl;
    cin>>jour;
    cout<<"Entre ton mois de naissance (entier entre 1 et 12)."<<endl;
    cin>>mois;
    cout<<"Entre ton annee de naissance."<<endl;
    cin>>annee;
    age=anneeA-annee;
    if ((mois>moisA)||((mois==moisA)&&(jour>jourA)))
    {
        age=age-1;
    }
    cout<<"Tu as "<<age<<" ans."<<endl;
    return 0;
}
