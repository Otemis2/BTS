#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pBSuivant_clicked();

    void on_pBValider_clicked();

    void on_pBCalculer_clicked();

    void on_pBEnregistrer_clicked();

private:
    Ui::MainWindow *ui;
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

#endif // MAINWINDOW_H

