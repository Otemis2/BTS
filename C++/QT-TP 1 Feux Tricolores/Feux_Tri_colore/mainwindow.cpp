/*
#-----------------------------------------------------------------------
# Nom Fichier: mainwindow.cpp
# Classe : mainwindow
# Sujet : gestion du programme du feux tri colore
# Version : 0.1
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>

#include <QDate>
#include <QTime>

using namespace std;

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : MainWindow
# Classe : MainWindow
# Sujet : constructeur du programme feux tri colore
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialiser();//Appel la fonction initialiser
    chargerHoraires();//Appel la fonction chargerHoraires
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : initialiser
# Classe : MainWindow
# Sujet : permettra d'initialiser , créer les objets
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::initialiser()
{
    timerDateHeure=new QTimer(this);
    timerClignotant=new QTimer(this);
    timerNormal=new QTimer(this);
    timerAutomatique=new QTimer(this);

    connect(timerClignotant,SIGNAL(timeout()),this,SLOT(activerClignotant()));
    connect(timerNormal,SIGNAL(timeout()),this,SLOT(activerNormal()));
    connect(timerAutomatique,SIGNAL(timeout()),this,SLOT(activerAutomatique()));
    connect(timerDateHeure,SIGNAL(timeout()),this,SLOT(dateHeure()));

    timerDateHeure->start(1000);

    ui->l_F1Rouge->setVisible(false);
    ui->l_F2Rouge->setVisible(false);
    ui->l_F1Orange->setVisible(false);
    ui->l_F2Orange->setVisible(false);
    ui->l_F1Vert->setVisible(false);
    ui->l_F2Vert->setVisible(false);


    cycleClignotant=1;
    cycleNormal=1;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : ~MainWindow
# Classe : MainWindow
# Sujet : desconstructeur du programme feux tri colore
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : dateHeure
# Classe : MainWindow
# Sujet : permettera d'afficher l'heure actuel du systeme dans un label
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::dateHeure()
{
    QTime heure;
    QDate date;
    //int dateHeure = date." ".heure;

    heure = QTime::currentTime();
    date = QDate::currentDate();

    ui->l_DateHeure->setText(date.toString("dd/MM/yyyy")+" "+heure.toString("hh:mm:ss"));
}

void MainWindow::on_pb_Test_Feux_pressed()
{
    timerNormal->stop();//Arret du timerNomal
    timerClignotant->stop();//Arret du timerClignotant
    timerAutomatique->stop();//Arret du timerAutomatique

    ui->l_F1Rouge->setVisible(true);
    ui->l_F2Rouge->setVisible(true);
    ui->l_F1Orange->setVisible(true);
    ui->l_F2Orange->setVisible(true);
    ui->l_F1Vert->setVisible(true);
    ui->l_F2Vert->setVisible(true);
}

void MainWindow::on_pb_Test_Feux_released()
{
    ui->l_F1Rouge->setVisible(false);
    ui->l_F2Rouge->setVisible(false);
    ui->l_F1Orange->setVisible(false);
    ui->l_F2Orange->setVisible(false);
    ui->l_F1Vert->setVisible(false);
    ui->l_F2Vert->setVisible(false);
}

void MainWindow::on_pb_Clignotant_clicked()
{
    cycleClignotant =1;//Activation du cycle clignotant
    activerClignotant();
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : activerClignotant
# Classe : MainWindow
# Sujet : permettera de faire clignotter les feux
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
/*
Debut
    CAS DE cycleClignotant
    VALEUR 1 :
        AfficherF1Orange
        AfficherF2Orange
        cycleClignotant <- 2
        DémarrerTimerClignotant(0,5s)
        FIN
    VALEUR 2 :
        EteindreF1Orange
        EteindreF2Orange
        cycleClignotant <- 1
        DémarrerTimerClignotant(0,5s)
        FIN
    FIN CAS DE
FIN
*/
//faire avec un switch
/*
switch (cycleClignotant)
{
    case 1:
        ui->l_F1Orange->setPixmap(QPixmap("O.png"));
        ui->l_F2Orange->setPixmap(QPixmap("O.png"));
        cycleClignotant = 2;
        timerClignotant->start(500);
        break; //Sortie du switch après le cas 1
    case 2:
        ui->l_F1Orange->setPixmap(QPixmap());
        ui->l_F2Orange->setPixmap(QPixmap());
        cycleClignotant = 1;
        timerClignotant->start(500);
        break; //Sortie du switch après le cas 2
}
  */
void MainWindow::activerClignotant()
{
    /*timerNormal->stop();//Arret du timerNomal
    timerClignotant->stop();//Arret du timerClignotant

    ui->l_F1Rouge->setVisible(false);
    ui->l_F2Rouge->setVisible(false);
    ui->l_F1Orange->setVisible(false);
    ui->l_F2Orange->setVisible(false);
    ui->l_F1Vert->setVisible(false);
    ui->l_F2Vert->setVisible(false);*/

    if(cycleClignotant==1)
    {
        ui->l_F1Orange->setVisible(true);
        ui->l_F2Orange->setVisible(true);
        cycleClignotant = 2;
        timerClignotant->start(500);
    }
    else
    {
        ui->l_F1Orange->setVisible(false);
        ui->l_F2Orange->setVisible(false);
        cycleClignotant = 1;
        timerClignotant->start(500);
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : activerNormal
# Classe : MainWindow
# Sujet : permettera de déclencher le cycle normal des feux
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
/*
Mode Normal : déclenche manuellement les feux avec les temps cycle suivant :
F1R - F2V : 3 s
F1R - F2O : 0,5 s
F1R - F2R : 1 s
F1V – F2R : 4 s
F1O – F2R : 0,5 s
F1R – F2R : 1 s
*/
void MainWindow::activerNormal()
{
    timerNormal->stop();//Arret du timerNomal
    timerClignotant->stop();//Arret du timerClignotant

    ui->l_F1Rouge->setVisible(false);
    ui->l_F2Rouge->setVisible(false);
    ui->l_F1Orange->setVisible(false);
    ui->l_F2Orange->setVisible(false);
    ui->l_F1Vert->setVisible(false);
    ui->l_F2Vert->setVisible(false);

    switch (cycleNormal)
    {
        case 1:
            ui->l_F2Rouge->setVisible(false);
            ui->l_F1Rouge->setVisible(true);
            ui->l_F2Vert->setVisible(true);
            cycleNormal = 2;
            timerNormal->start(3000);
            break; //Sortie du switch après le cas 1
        case 2:
            ui->l_F1Rouge->setVisible(true);
            ui->l_F2Vert->setVisible(false);
            ui->l_F2Orange->setVisible(true);
            cycleNormal = 3;
            timerNormal->start(500);
            break; //Sortie du switch après le cas 2
        case 3:
            ui->l_F1Rouge->setVisible(true);
            ui->l_F2Orange->setVisible(false);
            ui->l_F2Rouge->setVisible(true);
            cycleNormal = 4;
            timerNormal->start(1000);
            break; //Sortie du switch après le cas 3
        case 4:
            ui->l_F1Rouge->setVisible(false);
            ui->l_F1Vert->setVisible(true);
            ui->l_F2Rouge->setVisible(true);
            cycleNormal = 5;
            timerNormal->start(4000);
            break; //Sortie du switch après le cas 4
        case 5:
            ui->l_F1Vert->setVisible(false);
            ui->l_F1Orange->setVisible(true);
            ui->l_F2Rouge->setVisible(true);
            cycleNormal = 6;
            timerNormal->start(500);
            break; //Sortie du switch après le cas 5
        case 6:
            ui->l_F1Orange->setVisible(false);
            ui->l_F1Rouge->setVisible(true);
            ui->l_F2Rouge->setVisible(true);
            cycleNormal = 1;
            timerNormal->start(1000);
            break; //Sortie du switch après le cas 6
    }
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : activerAutomatique
# Classe : MainWindow
# Sujet : permettera de déclencher le cycle automatique des feux en focntion des plages d'horaire défini
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::activerAutomatique()
{
    timerNormal->stop();//Arret du timerNomal
    timerClignotant->stop();//Arret du timerClignotant

    ui->l_F1Rouge->setVisible(false);
    ui->l_F2Rouge->setVisible(false);
    ui->l_F1Orange->setVisible(false);
    ui->l_F2Orange->setVisible(false);
    ui->l_F1Vert->setVisible(false);
    ui->l_F2Vert->setVisible(false);

    QTime debPlage1 = ui->te_1Debut->time();
    QTime debPlage2 = ui->te_2Debut->time();
    QTime debPlage3 = ui->te_3Debut->time();
    QTime debPlage4 = ui->te_4Debut->time();

    QTime finPlage1 = ui->te_1Fin->time();
    QTime finPlage2 = ui->te_2Fin->time();
    QTime finPlage3 = ui->te_3Fin->time();
    QTime finPlage4 = ui->te_4Fin->time();

    QTime timejour = QTime::currentTime();

    if (timejour>debPlage1 && timejour<finPlage1)
    {
        activerNormal();
    }
    else
    {
        if (timejour>debPlage2 && timejour<finPlage2)
        {
            activerNormal();
        }
        else
        {
            if (timejour>debPlage3 && timejour<finPlage3)
            {
                activerNormal();
            }
            else
            {
                if (timejour>debPlage4 && timejour<finPlage4)
                {
                    activerNormal();
                }
                else
                {
                    activerClignotant();
                }
            }
        }
    }
    timerAutomatique->start(1000);
}

void MainWindow::on_pb_Normal_clicked()
{
    timerAutomatique->stop();//Arret du timerAutomatique
    activerNormal();
}

void MainWindow::on_pb_Automatique_clicked()
{
    timerAutomatique->stop();//Arret du timerAutomatique
    activerAutomatique();
}

void MainWindow::on_te_1Debut_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_1Fin_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_2Debut_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_2Fin_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_3Debut_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_3Fin_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_4Debut_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

void MainWindow::on_te_4Fin_timeChanged(const QTime &date)
{
    enregistrerHoraires();
    activerAutomatique();
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : enregistrerHoraires
# Classe : MainWindow
# Sujet : permettera d'enregistrer les horaires modifiées du timeedit dans le fichier csv
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::enregistrerHoraires()
{
    QTime debPlage1b;
    debPlage1b = ui->te_1Debut->time();

    QTime finPlage1b;
    finPlage1b = ui->te_1Fin->time();

    ofstream fichierEcriture ("horaires.csv");

    QString debut1 = debPlage1b.toString(QString("hh:mm"));
    QString fin1 = finPlage1b.toString(QString("hh:mm"));

    fichierEcriture<<debut1.toStdString();
    fichierEcriture<<";";
    fichierEcriture<<fin1.toStdString()<<endl;

    QTime debPlage2b;
    debPlage2b = ui->te_2Debut->time();

    QTime finPlage2b;
    finPlage2b = ui->te_2Fin->time();

    QString debut2 = debPlage2b.toString(QString("hh:mm"));
    QString fin2 = finPlage2b.toString(QString("hh:mm"));

    fichierEcriture<<debut2.toStdString();
    fichierEcriture<<";";
    fichierEcriture<<fin2.toStdString()<<endl;

    QTime debPlage3b;
    debPlage3b = ui->te_3Debut->time();

    QTime finPlage3b;
    finPlage3b = ui->te_3Fin->time();

    QString debut3 = debPlage3b.toString(QString("hh:mm"));
    QString fin3 = finPlage3b.toString(QString("hh:mm"));

    fichierEcriture<<debut3.toStdString();
    fichierEcriture<<";";
    fichierEcriture<<fin3.toStdString()<<endl;

    QTime debPlage4b;
    debPlage4b = ui->te_4Debut->time();

    QTime finPlage4b;
    finPlage4b = ui->te_4Fin->time();

    QString debut4 = debPlage4b.toString(QString("hh:mm"));
    QString fin4 = finPlage4b.toString(QString("hh:mm"));

    fichierEcriture<<debut4.toStdString();
    fichierEcriture<<";";
    fichierEcriture<<fin4.toStdString()<<endl;

    fichierEcriture.close();
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : chargerHoraires
# Classe : MainWindow
# Sujet : permettera d'afficher dans les timeEdits les horaires contenu dans le fichier csv
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour :Aucune
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::chargerHoraires()
{
    QTime debPlage1;
    QTime debPlage2;
    QTime debPlage3;
    QTime debPlage4;

    QTime finPlage1;
    QTime finPlage2;
    QTime finPlage3;
    QTime finPlage4;

    ifstream fichier ("horaires.csv");
    string ligne;
    char* debut = new char[5];
    char* fin = new char[5];

    fichier.is_open();
    //---Debut et Fin 1---
        fichier>>ligne;

        size_t pos=string::npos;
        pos=ligne.find_first_of(";");
        if(pos == 4)
        {
            string car = "0";
            for(short i = 0;i<pos;i++)
            {
                debut[i] = ligne[i];
            }
            car+debut;
        }
        else
        {
            for(short i = 0;i<pos;i++)
            {
                debut[i] = ligne[i];
            }
        }
        debPlage1 = QTime::fromString(debut, "hh:mm");
        ui->te_1Debut->setTime(debPlage1);

        short j =0;
        for(short i = pos+1 ;i<ligne.length();i++)//du ; +1 jusqu'à la longueur de la ligne ( dernier car)
        {
            fin[j] = ligne[i];
            j=j+1;
        }

        finPlage1 = QTime::fromString(fin, "hh:mm");//Conversion en QTime
        ui->te_1Fin->setTime(finPlage1);//Affectation dans le timeEdit

 //---Debut et Fin 2---
        fichier>>ligne;

        size_t pos2=string::npos;
        pos2=ligne.find_first_of(";");

        for(short i = 0;i<pos2;i++)
        {
            debut[i] = ligne[i];
        }

        debPlage2 = QTime::fromString(debut, "hh:mm");
        ui->te_2Debut->setTime(debPlage2);

        j =0;
        for(short i = pos2+1 ;i<ligne.length();i++)//du ; +1 jusqu'à la longueur de la ligne ( dernier car)
        {
            fin[j] = ligne[i];
            j=j+1;
        }

        finPlage2 = QTime::fromString(fin, "hh:mm");//Conversion en QTime
        ui->te_2Fin->setTime(finPlage2);//Affectation dans le timeEdit

//---Debut et Fin 3---
               fichier>>ligne;

               size_t pos3=string::npos;
               pos3=ligne.find_first_of(";");

               for(short i = 0;i<pos3;i++)
               {
                   debut[i] = ligne[i];
               }

               debPlage3 = QTime::fromString(debut, "hh:mm");
               ui->te_3Debut->setTime(debPlage3);

               j =0;
               for(short i = pos3+1 ;i<ligne.length();i++)//du ; +1 jusqu'à la longueur de la ligne ( dernier car)
               {
                   fin[j] = ligne[i];
                   j=j+1;
               }

               finPlage3 = QTime::fromString(fin, "hh:mm");//Conversion en QTime
               ui->te_3Fin->setTime(finPlage3);//Affectation dans le timeEdit

//---Debut et Fin 4---
                              fichier>>ligne;

                              size_t pos4=string::npos;
                              pos4=ligne.find_first_of(";");

                              for(short i = 0;i<pos4;i++)
                              {
                                  debut[i] = ligne[i];
                              }

                              debPlage4 = QTime::fromString(debut, "hh:mm");
                              ui->te_4Debut->setTime(debPlage4);

                              j =0;
                              for(short i = pos4+1 ;i<ligne.length();i++)//du ; +1 jusqu'à la longueur de la ligne ( dernier car)
                              {
                                  fin[j] = ligne[i];
                                  j=j+1;
                              }

                              finPlage4 = QTime::fromString(fin, "hh:mm");//Conversion en QTime
                              ui->te_4Fin->setTime(finPlage4);//Affectation dans le timeEdit

        fichier.close();
}
