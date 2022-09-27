/*#----------------------------------------------------------
# Nom Fichier : CTroisNombres.h
# Sujet : Déclaration de la calsse CTroisNombres
# Version : 0.1
# Auteur : Racamond Aimie
# Création : 20/11/2018
# Mise à jour :
#-----------------------------------------------------------*/

#ifndef CTROISNOMBRES_H
#define CTROISNOMBRES_H

class CTroisNombres
{
private: int nb1;
         int nb2;
         int nb3;

public: CTroisNombres();
        CTroisNombres(int val1, int val2, int val3);
        ~CTroisNombres();
        void setNb1(int val1);
        void setNb2(int val2);
        void setNb3(int val3);
        int getNb1();
        int getNb2();
        int getNb3();
        int grand();
        int moyen();
        int petit();
};

#endif // CTROISNOMBRES_H
