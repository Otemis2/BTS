/*
# -----------------------------------------------------------------------
# Nom Fichier : CMastermind.h
# Classe : CMastermind
# Sujet : gestion du jeu du mastermind
# Auteur : HUCK
# Création : 29/04/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CMASTERMIND_H
#define CMASTERMIND_H

class CMastermind
{
private:
    unsigned short nc;//nombre de couleur
    unsigned short coup;//nombre de coup
    unsigned short combinaison[4];//combinaison secrete
    unsigned short proposition[4];
    unsigned short nbEssai;
    unsigned short nbBienPlacee;
    unsigned short nbBonneCouleur;

public:
    CMastermind();
    ~CMastermind();
    void initialiserJeu(unsigned short nbCoul, unsigned nbCoup);
    void analyser();
    unsigned short getNc();
    void setNc(unsigned short nbCoul);
    unsigned short getCoup();
    void setCoup(unsigned short nbCoup);
    unsigned short getNbEssai();

    unsigned short * getCombinaison();
    unsigned short * getProposition();
    void setProposition(unsigned short tab[4]);
    unsigned short getNbBienPlacee();
    unsigned short getNbBonneCouleur();
};

#endif // CMASTERMIND_H
