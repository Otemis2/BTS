#include "cconcession.h"
#include <string.h>

/*# --------------------------------------
# Nom Procédure Membre : CConcession
# Classe : CConcession
# Sujet : constructeur de la classe
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
CConcession::CConcession()
{
    strcpy(tabModeles[0],"modeleA");
    strcpy(tabModeles[1],"modeleB");
    strcpy(tabModeles[2],"modeleC");

    strcpy(tabVendeurs[0],"vendeur1");
    strcpy(tabVendeurs[1],"vendeur2");
    strcpy(tabVendeurs[2],"vendeur3");
    strcpy(tabVendeurs[3],"vendeur4");

    tabPrix[0]=15000;
    tabPrix[1]=12000;
    tabPrix[2]=17000;

    tabVentes[0][0]=12;
    tabVentes[0][1]=8;
    tabVentes[0][2]=15;
    tabVentes[0][3]=11;
    tabVentes[1][0]=15;
    tabVentes[1][1]=13;
    tabVentes[1][2]=17;
    tabVentes[1][3]=20;
    tabVentes[2][0]=7;
    tabVentes[2][1]=17;
    tabVentes[2][2]=10;
    tabVentes[2][3]=5;
}

/*# --------------------------------------
# Nom Procédure Membre : CConcession
# Classe : CConcession
# Sujet : destructeur de la classe
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
CConcession::~CConcession()
{

}

/*# --------------------------------------
# Nom Procédure Membre : getModele
# Classe : CConcession
# Sujet : récupérer le nom du modèle à partir de son numéro
# Version : 0.1
# Entrée : numero : entier
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
char* CConcession::getModele(short numero)
{
    return tabModeles[numero];
}

/*# --------------------------------------
# Nom Fonction Membre : getVendeur
# Classe : CConcession
# Sujet : récupérer le nom du modèle à partir de son numéro
# Version : 0.1
# Entrée : numero : entier
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
char* CConcession::getVendeur(short numero)
{
    return tabVendeurs[numero];
}

/*# --------------------------------------
# Nom Fonction Membre : getVentes
# Classe : CConcession
# Sujet : récupérer le nombre de véhicules vendus d'un certain modele, par un certain vendeur
# Version : 0.1
# Entrée : modele, vendeur : entier
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
short CConcession::getVentes(short modele, short vendeur)
{
    return tabVentes[modele][vendeur];
}

/*# --------------------------------------
# Nom Fonction Membre : getPrix
# Classe : CConcession
# Sujet : récupérer le prix d'un modèle dont on connait le numéro
# Version : 0.1
# Entrée : modele : entier
# Sortie : aucune
# Retour : flottant
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
float CConcession::getPrix(short modele)
{
    return tabPrix[modele];
}
/*# --------------------------------------
# Nom Procédure Membre : setModele
# Classe : CConcession
# Sujet : modifier le nom d'un modèle connaissant son numéro et son nouveau nom
# Version : 0.1
# Entrée : numero : entier, nom : chaine de caractères
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
void CConcession::setModele(short numero,char* nom)
{
    strcpy(tabModeles[numero],nom);
}

/*# --------------------------------------
# Nom Procédure Membre : setVendeur
# Classe : CConcession
# Sujet : modifier le nom d'un vendeur connaissant son numéro et son nouveau nom
# Version : 0.1
# Entrée : numero : entier, nom : chaine de caractères
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
void CConcession::setVendeur(short numero,char* nom)
{
    strcpy(tabVendeurs[numero],nom);
}

/*# --------------------------------------
# Nom Procédure Membre : setVentes
# Classe : CConcession
# Sujet : modifier le nombre de véhicules vendus par un certain vendeur pour un certain modèle
# Version : 0.1
# Entrée : modele : entier, vendeur : entier, quantite : entier
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
void CConcession::setVentes(short modele, short vendeur,short quantite)
{
    tabVentes[modele][vendeur]=quantite;
}

/*# --------------------------------------
# Nom Procédure Membre : setVentes
# Classe : CConcession
# Sujet : modifier le prix d'un modèle dont on connaît le numéro
# Version : 0.1
# Entrée : modele : entier, vendeur : entier, quantite : entier
# Sortie : aucune
# Retour : aucun
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------*/
void CConcession::setPrix(short modele, float prix)
{
    tabPrix[modele]=prix;
}

/*# --------------------------------------
# Nom Fonction Membre : getNbVehiculesVendeur
# Classe : CConcession
# Sujet : Calculer le nombre de vehicules vendus par un vendeur
# Version : 0.1
# Entrée : vendeur : entier
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getNbVehiculesVendeur(in vendeur : entier) : entier
    VAR : i entier
          nbVehicules : entier
    Début
        nbVehicules<-0
        Pour (i<-0 jusqu'à 2 avec un pas de 1) faire
            nbVehicules<-nbVehicules+tabVentes[i][vendeur]
        Fin Pour
        retourner nbVehicules
    Fin
*/

short CConcession::getNbVehiculesVendeur(short vendeur)
{
    short nbVehicules=0;
    for (short i=0;i<3;i++)
    {
        nbVehicules=nbVehicules+tabVentes[i][vendeur];
    }
    return nbVehicules;
}

/*# --------------------------------------
# Nom Fonction Membre : getNBVehiculesModele
# Classe : CConcession
# Sujet : Calculer le nombre de vehicules vendus d'un modele
# Version : 0.1
# Entrée : modele : entier
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getNbVehiculesModele(in modele : entier) : entier
    VAR : i entier
          nbVehicules : entier 
    Début
        nbVehicules<-0
        Pour (i<-0 jusqu'à 3 avec un pas de 1) faire
            nbVehicules<-nbVehicules+tabVentes[modele][i]
        Fin Pour
        retourner nbVehicules
    Fin
*/

short CConcession::getNbVehiculesModele(short modele)
{
    short nbVehicules=0;
    for (short i=0;i<4;i++)
    {
        nbVehicules=nbVehicules+tabVentes[modele][i];
    }
    return nbVehicules;
}

/*# --------------------------------------
# Nom Fonction Membre : getNbVehiculesVendus
# Classe : CConcession
# Sujet : Calculer le nombre total de vehicules vendus
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : entier
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getNbVehiculesVendus() : entier
    VAR : modele,vendeur : entiers
          nbVehicules : entier
    Début
        nbVehicules<-0
        Pour (modele<-0 jusqu'à 2 avec un pas de 1) faire
            Pour (vendeur<-0 jusqu'à 3 avec un pas de 1) faire
                nbVehicules<-nbVehicules+tabVentes[modele][vendeur]
            Fin Pour
        Fin Pour
        retourner nbVehicules
    Fin
*/

short CConcession::getNbVehiculesVendus()
{
    short nbVehicules=0;
    for (short modele=0;modele<3;modele++)
    {
        for (short vendeur=0;vendeur<4;vendeur++)
        {
            nbVehicules=nbVehicules+tabVentes[modele][vendeur];
        }
    }
    return nbVehicules;
}


/*# --------------------------------------
# Nom Fonction Membre : getNbMoyenVehiculesVendeur
# Classe : CConcession
# Sujet : Calculer le nombre moyen de vehicules vendus par un vendeur
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : flottant
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getNbMoyenVehiculesVendeur() : flottant
    VAR : nbVehicules : entier
          moyenne : flottant
    Début
        nbVehicules<-getNbVehiculesVendus()
        moyenne<-nbVehicules/4
        retourner moyenne
    Fin
*/

float CConcession::getNbMoyenVehiculesVendeur()
{
    short nbVehicules=getNbVehiculesVendus();
    float moyenne=float(nbVehicules)/4;
    return moyenne;
}

/*# --------------------------------------
# Nom Fonction Membre : getMeilleurVendeur
# Classe : CConcession
# Sujet : Determiner le nom du meilleur vendeur
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getMeilleurVendeur() : chaine de caracteres
    VAR : vendeur : entier
          meilleurVendeur : entier
    Début
        meilleurVendeur<-0
        Pour (vendeur<-1 jusqu'à 3 avec un pas de 1) faire
            Si (getNbVehiculesVendeur(vendeur)>getNbVehiculesVendeur(meilleurVendeur) alors
                meilleurVendeur<-vendeur
            FinSi
        Fin Pour
        Retourner tabVendeurs[meilleurVendeur]
    Fin
*/

char* CConcession::getMeilleurVendeur()
{
    short meilleurVendeur=0;
    for(short vendeur=1;vendeur<4;vendeur++)
    {
        if (getNbVehiculesVendeur(vendeur)>getNbVehiculesVendeur(meilleurVendeur))
        {
            meilleurVendeur=vendeur;
        }
    }
    return tabVendeurs[meilleurVendeur];
}

/*# --------------------------------------
# Nom Fonction Membre : getMeilleurVente
# Classe : CConcession
# Sujet : Determiner le nom modele le plus vendu
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getMeilleureVente() : chaine de caracteres
    VAR : modele : entier
          meilleurModele : entier
    Début
        meilleurModele<-0
        Pour (modele<-1 jusqu'à 2 avec un pas de 1) faire
            Si (getNbVehiculesModele(modele)>getNbVehiculesModele(meilleurModele) alors
                meilleurModele<-modele
            FinSi
        Fin Pour
        Retourner tabModeles[meilleurModele]
    Fin
*/

char* CConcession::getMeilleureVente()
{
    short meilleurModele=0;
    for(short modele=1;modele<3;modele++)
    {
        if (getNbVehiculesModele(modele)>getNbVehiculesModele(meilleurModele))
        {
            meilleurModele=modele;
        }
    }
    return tabModeles[meilleurModele];
}


/*# --------------------------------------
# Nom Fonction Membre : getCAVendeur
# Classe : CConcession
# Sujet : Calculer le CA d'affaire généré par un vendeur
# Version : 0.1
# Entrée : vendeur : entier
# Sortie : aucune
# Retour : flottant
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getCAVendeur(in vendeur:entier) : flottant
    VAR : modele : entier
          chiffreAffaire : flottant
    Début
        chiffreAffaire<-0
        Pour (modele<-0 jusqu'à 2 avec un pas de 1) faire
            chiffreAffaire=chiffreAffaire+tabVentes[modele][vendeur]*tabPrix[modele]
        Fin Pour
        Retourner chiffreAffaire
    Fin
*/

float CConcession::getCAVendeur(short vendeur)
{
    float chiffreAffaire=0;
    for(short modele=0;modele<3;modele++)
    {
        chiffreAffaire=chiffreAffaire+tabVentes[modele][vendeur]*tabPrix[modele];
    }
    return chiffreAffaire;
}

/*# --------------------------------------
# Nom Fonction Membre : getMeilleurCA
# Classe : CConcession
# Sujet : Determiner le nom du vendeur qui a généré le meilleur CA
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : chaine de caractères
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getMeilleureCA() : chaine de caracteres
    VAR : vendeur : entier
          meilleurVendeur : entier
    Début
        meilleurVendeur<-0
        Pour (vendeur<-1 jusqu'à 3 avec un pas de 1) faire
            Si (getCAVendeur(vendeur)>getCAVendeur(meilleurVendeur) alors
                meilleurVendeur<-vendeur
            FinSi
        Retourner tabVendeurs[meilleurVendeur]
    Fin
*/

char* CConcession::getMeilleurCA()
{
    short meilleurVendeur=0;
    for(short vendeur=1;vendeur<4;vendeur++)
    {
        if (getCAVendeur(vendeur)>getCAVendeur(meilleurVendeur))
        {
            meilleurVendeur=vendeur;
        }
    }
    return tabVendeurs[meilleurVendeur];
}

/*# --------------------------------------
# Nom Fonction Membre : getCA
# Classe : CConcession
# Sujet : Calculer le CA d'affaire de la concession
# Version : 0.1
# Entrée : aucune
# Sortie : aucune
# Retour : flottant
# Auteur : Mme Rapebach
# Création : 26/01/21
# Mise à jour :
# ----------------------------------------
Fonction getCA() : flottant
    VAR : vendeur : entier
          chiffreAffaire : flottant
    Début
        chiffreAffaire<-0
        Pour (vendeur<-0 jusqu'à 3 avec un pas de 1) faire
            chiffreAffaire=chiffreAffaire+getCAVendeur(vendeur)
        Fin Pour
        Retourner chiffreAffaire
    Fin
*/

float CConcession::getCA()
{
    float chiffreAffaire=0;
    for(short vendeur=0;vendeur<4;vendeur++)
    {
        chiffreAffaire=chiffreAffaire+getCAVendeur(vendeur);
    }
    return chiffreAffaire;
}

