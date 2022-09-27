/*
#-----------------------------------------------------------------------
# Nom Fichier: mainwindow.cpp
# Classe : MainWindow
# Sujet : gestion du programme cartebancaire
# Version : 0.1
# Auteur : HUCK
# Cr�ation : 17/09/2021
# Mise � jour :
# ----------------------------------------------------------------------------------------------------------
*/

#include "cverif_cb.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

#include <iostream>

using std::cout;
using std::endl;

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

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_PB_Verifier_clicked
# Classe : MainWindow
# Sujet : permettra d'appeler des fonctions , d'executer des conditions quand l'utilisateur cliquera sur le bouton
# Version : 0.1
# Entrees (in) : QString, R�le : Copie du LineEdit du num�ro de carte pour le mettre dans une variable
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : QMessageBox ; R�le : d'indiquer � l'utilisateur, si la carte saisi est valide ou non
# Auteur : HUCK
# Cr�ation : 17/09/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
void MainWindow::on_PB_Verifier_clicked()
{

    CVerif_CB maVerif;

    QMessageBox msgBox;
    QPixmap pixmap = QPixmap("icon.jpg");
    msgBox.setWindowIcon(QIcon(pixmap));
    msgBox.setStyleSheet("background-color: dodgerblue ");

    bool carteOK; // VRAI si Carte Valide
    bool numcarteOK; // VRAI si num�ro de carte valide
    bool datecarteOK; // VRAI si Date de la carte valide

    int moiscb =ui->LE_Mois->text().toInt();//Mois CB
    int anneecb=ui->LE_Annee->text().toInt();//Annee CB


    unsigned char* numCarte= new unsigned char[16];
    char* numerocB=new char[16];

    strcpy (numerocB , ui->LE_Numero->text().toLatin1());
    for(short i = 0; i <16  ;i++)
    {
        numCarte[i]=numerocB[i]-0x30;
    }
     numcarteOK = maVerif.VerifierNumeroCb(numCarte);// Verification du num�ro CB
     datecarteOK = maVerif.VerifierDateCb(moiscb,anneecb);// Verification de la date
     carteOK = maVerif.getcarteValide();

  // Si carteOK=Vrai
  // Alors "Carte Valide"
  // Sinon "Carte Invalide"
     if (carteOK==true)
     {
         msgBox.setText("Carte Valide");
         msgBox.exec();
     }
     else
     {
         if ((maVerif.getNumeroCB_OK()==false)&&(maVerif.getCodeCB_OK()==false))
         {
             msgBox.setText("Carte Invalide : Num�ro et date de la carte");
         }
         else
         {
             if(maVerif.getNumeroCB_OK()==false)
             {
                 msgBox.setText("Carte Invalide : Num�ro de la carte incorrecte");
             }
             else
             {
                 if(maVerif.getCodeCB_OK()==false)
                 {
                     msgBox.setText("Carte Invalide : Date de validit� de la carte incorrecte");
                 }
             }
         }
         msgBox.exec();
     }

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_PB_Quitter_clicked
# Classe : MainWindow
# Sujet : permettra de quitter l'application
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Cr�ation : 17/09/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
void MainWindow::on_PB_Quitter_clicked()
{
     exit(0);
}
