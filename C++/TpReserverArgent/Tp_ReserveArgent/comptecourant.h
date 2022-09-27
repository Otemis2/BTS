#ifndef COMPTECOURANT_H
#define COMPTECOURANT_H

#include "reservesargent.h"

class CompteCourant:public reservesArgent
{
private:
    long numeroCompte;
    char* proprietaire;
public:
    CompteCourant();
    ~CompteCourant();
    void setnumeroCompte(long numCompte);
    void setProprietaire(char* proprio);
    char* getProprietaire();
    long getNumeroCompte();
};

#endif // COMPTECOURANT_H
