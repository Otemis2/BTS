/*-----------------------------------------------------------------------
#NomFichier:CTerrain.h
#Classe:Ccercle
#Sujet:gestion d'un terrain (d�claration de la classe)
#Auteur:HUCK
#Cr�ation:12/10/2020
#-----------------------------------------------------------------------*/

#ifndef CTERRAIN_H
#define CTERRAIN_H
class CTerrain
{
private :
    long longueur;
    long largeur;
public:
    CTerrain();
    ~CTerrain();
    long calculerSuperficieEnM2();
    float calculerSuperficieEnHectare();
    long getLongueur();
    long getLargeur();
    void setLongueur (long L);
    void setLargeur (long l);
};

#endif
