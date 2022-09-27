#ifndef CCONCESSION_H
#define CCONCESSION_H


class CConcession
{
private:
    char tabModeles[3][20];
    char tabVendeurs[4][20];
    int tabVentes[3][4];
    float tabPrix[3];

public:
    CConcession();
    ~CConcession();
    char* getModele(short numero);
    char* getVendeur(short numero);
    short getVentes(short modele,short vendeur);
    float getPrix(short modele);
    void setModele(short numero,char* nom);
    void setVendeur(short numero,char* nom);
    void setVentes(short modele,short vendeur,short quantite);
    void setPrix(short modele,float prix);
    short getNbVehiculesVendeur(short vendeur);
    short getNbVehiculesModele(short modele);
    short getNbVehiculesVendus();
    float getNbMoyenVehiculesVendeur();
    char* getMeilleurVendeur();
    char* getMeilleureVente();
    float getCAVendeur(short vendeur);
    char* getMeilleurCA();
    float getCA();
};


#endif // CCONCESSION_H
