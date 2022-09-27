/*-----------------------------------------------------------------------
#NomFichier:Equation.h
#Classe:CEquation
#Sujet: (déclaration de la classe)
#Auteur:HUCK
#Création:13/10/2020
#-----------------------------------------------------------------------*/

#ifndef EQUATION_H
#define EQUATION_H
class CEquation
{
private :
    short a;
    short b;
    short c;
    short delta;
    float x1;
    float x2;
public :
    CEquation ();
    ~CEquation ();
    short getA ();
    short getB ();
    short getC ();
    void setC (short c1);
    void setB (short b1);
    void setA (short a1);
    short calculerDelta();
    float calculerRacineDouble();
    float calculerRacineReels();
    float getX1();
    float getX2();
};

#endif // EQUATION_H
