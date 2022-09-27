#ifndef PORTEMONNAIE_H
#define PORTEMONNAIE_H

#include "reservesargent.h"

class PorteMonnaie:public reservesArgent
{
private:
    char* nomProprio;
public:
    PorteMonnaie();
    ~PorteMonnaie();
    void setNomProprio(char* nameProprio);
    char* getNomProprio();
};

#endif // PORTEMONNAIE_H
