/*
# -----------------------------------------------------------------------
# Nom Fichier : cskieur.h
# Classe : CSkieur
# Sujet : gestion du programme gestion d'une course de ski
# Auteur : HUCK
# Création : 16/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CSKIEUR_H
#define CSKIEUR_H

class CSkieur
{
private:
    char* nom;
    char* prenom;
    unsigned short numeroDossard;
    char* email;
    unsigned short temps;
public:
    CSkieur(char* nomCompettiteur, char* prenomCompetiteur, char* emailCompetiteur, unsigned short numeroDossardCompetiteur);
    CSkieur();
    ~CSkieur();
    void setNom(char* name);
    void setPrenom(char* vername);
    void setEmail(char* mail);
    void setNumeroDossard(unsigned short dossard);
    void setTemps(unsigned short time);

    char* getEmail();
    char* getNom();
    char* getPrenom();
    unsigned short getTemps();
    unsigned short getNumeroDossard();
};

#endif // CSKIEUR_H
