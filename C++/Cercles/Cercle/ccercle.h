/*-----------------------------------------------------------------------
#NomFichier:Ccercle.h
#Classe:Ccercle
#Sujet:gestion d'un cercle (déclaration de la classe)
#Auteur:HUCK
#Création:06/10/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

#ifndef CCERCLE_H
#define CCERCLE_H
// a completer
class ccercle
{
private :
    short rayon;
    short x;
    short y;
public:
    ccercle();
    ~ccercle();
    float calculerPerimetre();
    float calculerSurface();
    short getX();
    short getY();
    short getRayon();
    void setRayon (short r);
    void setX (short coordX);
    void setY (short coordY);
};

#endif // CCERCLE_H
