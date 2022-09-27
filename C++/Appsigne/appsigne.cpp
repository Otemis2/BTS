/*
#---------------------------------------
#Programme : Signe
#Sujet : On veut une IHM qui détermine le signe d'un nombre
#Auteur : HUCK Sylvain
#Date de création :22/09/2020
# Version : 0
#---------------------------------------

VAR: Nb1

Début
afficher "Veuiller saisir le nombre"
Saisir Nb1
Si Nb1 > 0 alors afficher "le nombre est positif"
Si Nb1 < 0 alors afficher "le nombre est negatif"
Si Nb1 = 0 alors afficher "le nombre est nul"

Fin

#Tests

*/
#include "appsigne.h"
#include "ui_appsigne.h"

Appsigne::Appsigne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Appsigne)
{
    ui->setupUi(this);
}

Appsigne::~Appsigne()
{
    delete ui;
}

/*void Appsigne::on_pbCalculer_clicked()
{
    short nb1;
  nb1 = ui->lENb1 ->text().toShort();

    if (nb1>0)
    {
    ui->lESigne->setText("le nombre est positif");
    }
    else
    {
    if (nb1<0)
    {
     ui->lESigne->setText("le nombre est negatif");
    }
    else
    {
    ui->lESigne->setText("le nombre est nul");
    }
    }
}
*/
/*
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


 */
//CStatistiquesMensuelle releveNovembre;

void Appsigne::on_pbSuivant_clicked()
{
    float nbJour,nb;

    nbJour = ui->lENbJourMois ->text().toFloat();
    //releveNovembre.setNBJoursMois(nbJour);
    ui->laff->setText(QString::number(nbJour));





}
