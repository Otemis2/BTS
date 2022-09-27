/*-----------------------------------------------------------------------
#NomFichier:mainWindow.cpp
#Classe:MainWindow
#Sujet:fenetre principal de l'application
#Version:0.1
#Auteur:chameroy
#Création:06/10/2020
#Mise à jour:
#----------------------------------------------------------------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ccercle.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*-----------------------------------------------------------------------
#Nom Fonction Membre: on_pBQuittter_clicked
#Classe:MainWindow
#Sujet:slot appellé lors du clique sur le bouton quitter
            permet de quiiter l'application
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucun
#Auteur:HUCK
#Création:06/10/2020
#Miseàjour:
#-----------------------------------------------------------------------*/
void MainWindow::on_pBQuitter_clicked()
{
    exit (0);
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre: on_pBCalculerSuperficie_clicked
#Classe:MainWindow
#Sujet:slot du cas d'utilisation calculer superficie
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucun
#Auteur:HUCK
#Création:06/10/2020
#Miseàjour:
#-----------------------------------------------------------------------*/

void MainWindow::on_pBCalculerSuperficie_clicked()
{
    ccercle monCercle;
    short rayon;
    float superficie;
    rayon = ui->lERayon->text().toShort();
    monCercle.setRayon(rayon);
    superficie = monCercle.calculerSurface();
    ui->lESurface->setText(QString ::number (superficie));
}

/*-----------------------------------------------------------------------
#Nom Fonction Membre: on_pBcalculerperimetre_clicked
#Classe:MainWindow
#Sujet:slot du cas d'utilisation calculer perimetre
#Version:0.1
#Entrees (in): Aucune
#Sorties (out): Aucune
#Entrees/Sorties (inout): Aucune
#Retour:Type; Aucun
#Auteur:HUCK
#Création:06/10/2020
#Mise à jour:
#-----------------------------------------------------------------------*/




void MainWindow::on_pBcalculerperimetre_clicked()
{
    ccercle monCercle;
    short rayon;
    float perimetre;
    rayon = ui->lERayon->text().toShort();
    monCercle.setRayon(rayon);
    perimetre = monCercle.calculerPerimetre();
    ui->lEPerimetre->setText(QString ::number (perimetre));
}
