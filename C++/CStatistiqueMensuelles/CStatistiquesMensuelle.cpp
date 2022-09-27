#include "CStatistiquesMensuelle.h"

CStatistiquesMensuelle::CStatistiquesMensuelle()
{
    moyenneMensuelle=0;
    temperatureFroide=0;
    temperatureChaude=0;
    nombreJourChaud=0;
    nombreJourFroid=0;
    jourLePlusChaud=0;
    jourLePlusFroid=0;
    nbJoursMois=0;
    for (short i=0;i<31;i++)
    {
        temperature[i]=0;
    }

}

CStatistiquesMensuelle::~CStatistiquesMensuelle()
{
    //pas de code
}

float * CStatistiquesMensuelle::getTemperature()
{
    return temperature;
}

void CStatistiquesMensuelle::setTemperature(unsigned short numeroJour, float temperatureJour)
{
    temperature[numeroJour]=temperatureJour;
}

void CStatistiquesMensuelle::setNBJoursMois(unsigned short nbJours)
{
    nbJoursMois = nbJours;
}

float CStatistiquesMensuelle::getMoyenneMensuelle()
{
    return moyenneMensuelle;
}

void CStatistiquesMensuelle::calculerMoyenne()
{
    float somme=0;
    for(unsigned short i=0;i<nbJoursMois;i++)
    {
        somme =somme + temperature[i];
    }
    moyenneMensuelle = somme/nbJoursMois;
}

unsigned short CStatistiquesMensuelle::getNombreJourChaud()
{
    return nombreJourChaud;
}

unsigned short CStatistiquesMensuelle::getNombreJourFroid()
{
    return nombreJourFroid;
}
float CStatistiquesMensuelle::getTemperatureFroide()
{
    return temperatureFroide;
}

/*
  Var:
  i: entier court; compteur de boucle

  Debut

    POUR i<-0 jusqu'à nbJoursMois-1 avec pas de 1
        SI temperature[i]>= moyenneMensuelle ALORS
            nombreJourChaud <-nombreJourChaud +1
        FINSI
  Fin
  */
void CStatistiquesMensuelle::determinerNombreJourFroid()
{
    for(unsigned short i =0; i< nbJoursMois;i++)
       {
           if (temperature[i]< moyenneMensuelle)
           {
               nombreJourFroid++;
           }

       }
}

void CStatistiquesMensuelle::determinerNombreJourChaud()
{
    for(unsigned short i =0; i< nbJoursMois;i++)
       {
           if (temperature[i]> moyenneMensuelle)
           {
               nombreJourChaud++;
           }

       }
}

void CStatistiquesMensuelle::determinerJourTemperatureFroid()
{
    temperatureFroide = temperature[0];
    jourLePlusFroid = 0;

    for(unsigned short i=0; i<nbJoursMois; i++)
    {
        if(temperature[i] < moyenneMensuelle)
        {
            temperatureFroide = temperature[i];
            jourLePlusFroid = i;
        }
    }
}

void CStatistiquesMensuelle::determinerJourTemperatureChaud()
{
    temperatureChaude = temperature[0];
    jourLePlusChaud = 0;

    for(unsigned short i=0; i < nbJoursMois; i++)
    {
        if(temperature[i] > moyenneMensuelle)
        {
            temperatureChaude = temperature[i];
            jourLePlusChaud = i;
        }
    }
}

unsigned short CStatistiquesMensuelle::getJourLePlusChaud()
{
    return jourLePlusChaud;
}
unsigned short CStatistiquesMensuelle::getJourLePlusFroid()
{
    return jourLePlusFroid;
}

float CStatistiquesMensuelle::getTemperatureChaude()
{
    return temperatureChaude;
}
