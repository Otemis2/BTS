#include "comptecourant.h"
#include "reservesargent.h"

CompteCourant::CompteCourant()
{
}

CompteCourant::~CompteCourant()
{
}

void CompteCourant::setnumeroCompte(long numCompte)
{
    numeroCompte = numCompte;
}

void CompteCourant::setProprietaire(char* proprio)
{
    proprietaire = proprio;
}

char* CompteCourant::getProprietaire()
{
    return proprietaire;
}

long CompteCourant::getNumeroCompte()
{
    return numeroCompte;
}
