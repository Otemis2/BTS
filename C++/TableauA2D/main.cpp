#include <iostream>
#include "cconcession.h"

using namespace std;

int main()
{
    CConcession maConcession;
    bool continuer=true;
    bool continuerSousMenu=true;
    short choix;
    short choixAffichage;
    short choixModification;
    short choixStatistiques;
    char* nom=new char[26];
    short quantite;
    float prix;
    while (continuer)
    {
        continuerSousMenu=true;
        choixAffichage=-1;
        choixModification=-1;
        choixStatistiques=-1;
        cout<<"Faites un choix "<<endl;
        cout<<"1-Afficher des donnees"<<endl;
        cout<<"2-Modifier des donnees"<<endl;
        cout<<"3-Afficher des statistiques"<<endl;
        cout<<"0-Quitter"<<endl;
        cin>>choix;

        while (continuerSousMenu)
        {
            switch(choix)
            {
            case 1:
                cout<<"1-Afficher la liste des vendeurs"<<endl;
                cout<<"2-Afficher la liste des modeles"<<endl;
                cout<<"3-Afficher la liste des prix"<<endl;
                cout<<"4-Afficher les quantites vendus par chaque vendeur pour chaque modele"<<endl;
                cout<<"0-Quitter"<<endl;
                cin>>choixAffichage;
                break;
            case 2:
                cout<<"1-Modifier le nom des vendeurs"<<endl;
                cout<<"2-Modifier le nom des modeles"<<endl;
                cout<<"3-Modifier une quantite"<<endl;
                cout<<"4-Modifier un prix"<<endl;
                cout<<"0-Quitter"<<endl;
                cin>>choixModification;
                break;
            case 3:
                cout<<"1-Afficher le nombre total de vehicules vendus par chaque vendeur"<<endl;
                cout<<"2-Afficher le nombre de vehicules vendus de chaque modele"<<endl;
                cout<<"3-Afficher le nombre total de vehicules vendus"<<endl;
                cout<<"4-Afficher le nombre moyen de vehicules vendus par un vendeur"<<endl;
                cout<<"5-Afficher le nom du meilleur vendeur en nombre de vehicules"<<endl;
                cout<<"6-Afficher le nom du modele le plus vendu"<<endl;
                cout<<"7-Afficher le CA genere par chaque vendeur"<<endl;
                cout<<"8-Afficher le nom du vendeur qui a genere le meilleur CA"<<endl;
                cout<<"9-Afficher le chiffre d'affaires de toute la concession"<<endl;
                cout<<"0-Quitter"<<endl;
                cin>>choixStatistiques;
                break;
            case 0:
                continuer=false;
                continuerSousMenu=false;
                break;
            default:
                continuerSousMenu=false;
                break;
            }

            switch (choixAffichage)
            {
            case 1:
                cout<<"Liste des vendeurs"<<endl;
                for (short i=0;i<4;i++)
                {
                    cout<<maConcession.getVendeur(i)<<endl;
                }
                break;
            case 2:
                cout<<"Liste des modeles"<<endl;
                for (short i=0;i<3;i++)
                {
                    cout<<maConcession.getModele(i)<<endl;
                }
                break;
            case 3:
                cout<<"Liste des prix"<<endl;
                for (short modele=0;modele<3;modele++)
                {
                    cout<<maConcession.getModele(modele)<<" : "<<maConcession.getPrix(modele)<<" euros "<<endl;
                }
                break;
            case 4:
                cout<<"Tableau des ventes"<<endl;
                cout<<"\t\t";
                for (short i=0;i<4;i++)
                {
                    cout<<maConcession.getVendeur(i)<<"\t";
                }
                cout<<endl;
                for (short modele=0;modele<3;modele++)
                {
                    cout<<maConcession.getModele(modele)<<"\t\t";
                    for (short vendeur=0;vendeur<4;vendeur++)
                    {
                        cout<<maConcession.getVentes(modele,vendeur)<<"\t\t";
                    }
                    cout<<endl;
                }
                break;
            case 0:
                continuerSousMenu=false;
                break;
            default:
                break;
            }

            switch(choixModification)
            {
            case 1:
                cout<<"Entrer le nom de chaque vendeur"<<endl;
                for (short i=0;i<4;i++)
                {
                    cout<<"Entrer le nom du vendeur numero "<<i+1<<endl;
                    cin>>nom;
                    maConcession.setVendeur(i,nom);
                }
                break;

            case 2:
                 cout<<"Entrer le nom de chaque modele"<<endl;
                 for (short i=0;i<3;i++)
                 {
                     cout<<"Entrer le nom du modele numero "<<i+1<<endl;
                     cin>>nom;
                     maConcession.setModele(i,nom);
                 }
                 break;
            case 3:
                short modele,vendeur;
                cout<<"Entrer le numero du vendeur (entre 1 et 4)"<<endl;
                cin>>vendeur;
                cout<<"Entrer le numero du modele (entre 1 et 3)"<<endl;
                cin>>modele;
                cout<<"Entrer la quantite "<<endl;
                cin>>quantite;
                maConcession.setVentes(modele-1,vendeur-1,quantite);
                break;
            case 4:
                cout<<"Entrer le numero du modele dont le tarif est modifie (entre 1 et 3)"<<endl;
                cin>>modele;
                cout<<"Entrer le nouveau prix"<<endl;
                cin>>prix;
                maConcession.setPrix(modele-1,prix);
                break;
            case 0:
                continuerSousMenu=false;
                break;
            default:
                break;
            }

            switch(choixStatistiques)
            {
            case 1:
                for (short i=0;i<4;i++)
                {
                    cout<<maConcession.getVendeur(i)<<" : "<<maConcession.getNbVehiculesVendeur(i)<<" vehicules vendus"<<endl;
                }
                break;
            case 2:
                for (short i=0;i<3;i++)
                {
                    cout<<maConcession.getModele(i)<<" : "<<maConcession.getNbVehiculesModele(i)<< " vehicules vendus"<<endl;
                }
                break;
            case 3:
                cout<<"Le nombre total de vehicules vendus est de "<<maConcession.getNbVehiculesVendus()<<endl;
                break;
            case 4:
                cout<<"Le nombre moyen de vehicules vendus par un vendeur est de "<<maConcession.getNbMoyenVehiculesVendeur()<<endl;
                break;
            case 5:
                cout<<"Le meilleur vendeur est "<<maConcession.getMeilleurVendeur()<<endl;
                break;
            case 6:
                cout<<"Le modele le plus vendu est le modele "<<maConcession.getMeilleureVente()<<endl;
                break;
            case 7:
                for (short vendeur=0;vendeur<4;vendeur++)
                {
                    cout<<maConcession.getVendeur(vendeur)<<" : "<<maConcession.getCAVendeur(vendeur)<<" euros."<<endl;
                }
                break;
            case 8:
                cout<<"Vendeur qui a genere le meilleur chiffre d'affaire "<<maConcession.getMeilleurCA()<<endl;
                break;
            case 9 :
                cout<<"Chiffre d'affaire total de la concession : "<<maConcession.getCA()<<" euros "<<endl;
                break;
            case 0:
                continuerSousMenu=false;
                break;
            default:
                break;
            }

        cout<<endl;
        }
    }

    return 0;
}
