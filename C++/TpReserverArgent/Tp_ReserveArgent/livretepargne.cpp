#include "livretepargne.h"
#include "reservesargent.h"

LivretEpargne::LivretEpargne()
{
}

LivretEpargne::~LivretEpargne()
{
}

void LivretEpargne::setTypeEpargne(char* typeErpargne)
{
    typeEpargne = typeErpargne;
}

void LivretEpargne::setInteret(float pourcentage)
{
    interet = pourcentage;
}

char* LivretEpargne::getTypeEpargne()
{
    return typeEpargne;
}

float LivretEpargne::getInteret()
{
    return interet;
}
