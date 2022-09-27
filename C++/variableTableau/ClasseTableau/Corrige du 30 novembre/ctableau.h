#ifndef CTABLEAU_H
#define CTABLEAU_H


class CTableau
{
private:
    short nbCases;
    short* table;

public:
    CTableau();
    CTableau(short nbC,short table[]);
    CTableau(short nbC,short n);
    ~CTableau();
    short *getTable();
    short getNbCases();
    short calculerSomme();
    float calculerMoyenne();
    short determinerMaximum();
    short determinerMinimum();
    bool appartenir(short element);
    short determinerOccurence(short element);
    //short determinerNbSup10();
    //short determinerNbApparitions(short element);
    void trierABulles();
    void trierParSelection();
    void trierParInsertion();
};

#endif // CTABLEAU_H
