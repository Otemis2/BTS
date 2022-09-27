#include "portemonnaie.h"
#include "reservesargent.h"

PorteMonnaie::PorteMonnaie()
{
}

PorteMonnaie::~PorteMonnaie()
{
}

void PorteMonnaie::setNomProprio(char* nameProprio)
{
    nomProprio = nameProprio;
}

char* PorteMonnaie::getNomProprio()
{
    return nomProprio;
}
