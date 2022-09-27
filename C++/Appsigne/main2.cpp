#include <iostream>
#include "CStatistiquesMensuelle.h"

using namespace std;

int main()
{
    CStatistiquesMensuelle releveNovembre;

    float *tabTemperature;
    float nbJoursMois;
    float temperatureJour;

    cout<<"nombre de jours dans le mois : ";
    cin>>nbJoursMois;

    releveNovembre.setNBJoursMois(nbJoursMois);

    for (unsigned short i = 0; i<nbJoursMois; i++)
    {
        cout<<"temperature du jour "<<i+1<<" : ";
        cin>>temperatureJour;
        releveNovembre.setTemperature(i,temperatureJour);
    }

    releveNovembre.calculerMoyenne();
    cout<<"moyenne :"<<releveNovembre.getMoyenneMensuelle()<<endl;

    releveNovembre.determinerJourTemperatureChaud();
    cout<<"Jour le plus chaud : "<<releveNovembre.getJourLePlusChaud()<<endl;
    cout<<"Temperature la plus chaude : "<<releveNovembre.getTemperatureChaude()<<endl;


    releveNovembre.determinerJourTemperatureFroid();
    cout<<"Jour froid : "<<releveNovembre.getJourLePlusFroid()<<endl;
    cout <<"Temperature la plus froide : "<<releveNovembre.getTemperatureFroide()<<endl;

    releveNovembre.determinerNombreJourChaud();
    cout<<"Nombre de jour chaud : "<<releveNovembre.getNombreJourChaud()<<endl;
    releveNovembre.determinerNombreJourFroid();
    cout <<"Nombre de jour froid : "<<releveNovembre.getNombreJourFroid()<<endl;
    return 0;
}
