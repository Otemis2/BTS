/*
# -----------------------------------------------------------------------
# Nom Fichier : JeuPendu.h
# Classe : CJeuPendu
# Sujet : gestion du jeu du pendu
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

#ifndef FONCTIONSPENDU_H
#define FONCTIONSPENDU_H
#include <string>

class CJeuPendu
{

private:
    char mot7lettres[6][8];
    char secretWord[8];
    char motATrouve[8];
    unsigned short tentative;
public:
    CJeuPendu();
    ~CJeuPendu();
    char* motSecret();
    char* motATrouver();
    char* getMotSecret();
    char* getMotATrouve();
    unsigned short getTentative();
    void setTentative(unsigned short tent);
    bool Proposer(char letter);
};


#endif // FONCTIONSPENDU_H
