/*
# -----------------------------------------------------------------------
# Nom Fichier : JeuMotus.h
# Classe : CJeuMotus
# Sujet : gestion du jeu du pendu
# Auteur : HUCK
# Création : 24/01/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/

#ifndef FONCTIONSMOTUS_H
#define FONCTIONSMOTUS_H
#include <string>

class CJeuMotus
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


#endif // FONCTIONSMOTUS_H
