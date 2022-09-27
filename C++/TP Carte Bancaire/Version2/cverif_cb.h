/*
# -----------------------------------------------------------------------
# Nom Fichier : cverif_cb.h
# Classe : CVerif_CB
# Sujet : gestion de l'application Carte Bancaire
# Auteur : HUCK
# Création : 02/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef CVERIF_CB_H
#define CVERIF_CB_H

class CVerif_CB
{
private:
    unsigned char numeroCB[16];
    bool numeroCB_OK;
    bool dateCB_OK;
    bool carteValide;

public:
    CVerif_CB();
    ~CVerif_CB();
    bool VerifierNumeroCb(unsigned char* numerocb);
    bool VerifierDateCb(unsigned char moisCB,int anneeCB);
    void setNumeroCB(unsigned char* numerocb);
    bool getNumeroCB_OK();
    bool getCodeCB_OK();
    bool getcarteValide();
};

#endif // CVERIF_CB_H
