#ifndef LIVRETEPARGNE_H
#define LIVRETEPARGNE_H

#include "reservesargent.h"

class LivretEpargne:public reservesArgent
{
private:
    char* typeEpargne;
    float interet;
public:
    LivretEpargne();
    ~LivretEpargne();
    void setTypeEpargne(char* typeErpargne);
    void setInteret(float pourcentage);
    char* getTypeEpargne();
    float getInteret();
};

#endif // LIVRETEPARGNE_H
