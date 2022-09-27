/*# -----------------------------------------------------------------------
# Nom Fichier: CEquationSecondDegre.h
# Sujet : Declaration de la classe CEQuationSecondDegre.
# Version : 0.1
# Auteur : Chameroy Estelle
# Création : 26/11/2018
# Mise à jour :
# --------------------------------------------------------------------------*/
#ifndef CEQUATIONSECONDEGRE_H
#define CEQUATIONSECONDEGRE_H

class CEquationSeconDegre
{
private:
    short delta;
    float x1;
    float x2;
    short a;
    short b;
    short c;
    void essai();
public:
    CEquationSeconDegre();
    ~CEquationSeconDegre();
    CEquationSeconDegre(short a1,short b1,short c1);
    short calculerDiscriminant();
    bool racineDouble();
    bool racineReel();
    short getA();
    short getB();
    short getC();
    void setA(short a1);
    void setB(short b1);
    void setC(short c1);
    float getX1();
    float getX2();
};

#endif // CEQUATIONSECONDEGRE_H
