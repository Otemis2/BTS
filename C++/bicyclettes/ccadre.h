/*
# -----------------------------------------------------------------------
# Nom Fichier : ccadre.h
# Classe : CCadre
# Sujet : gestion du programme bicyclette
# Auteur : HUCK
# Création : 07/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CCADRE_H
#define CCADRE_H

class CCadre
{
private:
    char* couleur;
    unsigned short taille;
public:
    CCadre();
    ~CCadre();
    void setTaille ( unsigned short tailleCadre );
    void setCouleur ( char* couleurCadre );
    unsigned short getTaille();
    char* getCouleur();
};

#endif // CCADRE_H
