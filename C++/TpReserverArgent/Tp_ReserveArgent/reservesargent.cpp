#include "reservesargent.h"

reservesArgent::reservesArgent()
{
    solde =0;
}

reservesArgent::~reservesArgent()
{
}

float reservesArgent::getSolde()
{
    return solde;
}

void reservesArgent::crediter(float money)
{
    solde = solde+money;
}

void reservesArgent::debiter(float money)
{
    solde = solde-money;
}
