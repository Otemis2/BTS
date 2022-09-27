/*
# -----------------------------------------------------------------------
# Nom Fichier : CSalle.h
# Classe : CSalle
# Sujet : gestion de l'occupation d'une salle
# Auteur : HUCK
# Création : 25/02/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CSALLE_H
#define CSALLE_H

class CSalle
{
private:
    bool occupations;
    double proba;
    char tabJours[5][20];
    char tabCreneau [11][20];
    bool tabOccupation[11][5];
public:
    CSalle();
    ~CSalle();

    char* getJours(short jour);
    char* getCreneaux(short creneau);
    bool getOccupations(short creneau, short jour);
    double getProba (float nbOccuper, float nbCreneauMax);

    bool setOccupation(short creneau, short jour, bool occupation);
};

#endif // CSALLE_H
