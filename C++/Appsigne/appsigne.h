#ifndef APPSIGNE_H
#define APPSIGNE_H

#include <QMainWindow>

namespace Ui {
class Appsigne;
}

class Appsigne : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Appsigne(QWidget *parent = 0);
    ~Appsigne();
    
private slots:
    void on_pbCalculer_clicked();

    void on_pbSuivant_clicked();

private:
    Ui::Appsigne *ui;
};
class CStatistiquesMensuelle
{
private:
    float moyenneMensuelle;
    float temperatureFroide;
    float temperatureChaude;
    unsigned short nombreJourChaud;
    unsigned short nombreJourFroid;
    unsigned short jourLePlusChaud;
    unsigned short jourLePlusFroid;
    unsigned short nbJoursMois;
    float temperature[31];

public:
    CStatistiquesMensuelle();
    ~CStatistiquesMensuelle();
    void calculerMoyenne();
    void determinerNombreJourChaud();
    void determinerNombreJourFroid();
    void determinerJourTemperatureFroid();
    void determinerJourTemperatureChaud();
    void setTemperature(unsigned short numeroJour,float temperatureJour);
    void setNBJoursMois(unsigned short nbJours);
    float getMoyenneMensuelle();
    float getTemperatureFroide();
    float getTemperatureChaude();
    unsigned short getJourLePlusChaud();
    unsigned short getJourLePlusFroid();
    unsigned short getNombreJourChaud();
    unsigned short getNombreJourFroid();
    unsigned short getNbJoursmois();
    float* getTemperature();
};

#endif // APPSIGNE_H
