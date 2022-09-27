#ifndef CPOSTE_H
#define CPOSTE_H

class CPoste
{
private:
    short poidsColis;
    short nbColis;
    short tarifColis;
    float prixColis;
    float prixTotal;
    short tableauPoids[8];
    float tableauPrix[8][4];
public:
    CPoste();
    ~CPoste();
    short getPoidsColis();
    float getPrixColis();
    short getTarifColis();
    short getNbColis();
    float getPrixTotal();
    short setPoidsColis(short poids);
    short setTarifColis(short tarif);
    float setPrixColis(short prix);
    short setNbColis(short nb);
    bool affranchirColis();
};

#endif // CPOSTE_H
