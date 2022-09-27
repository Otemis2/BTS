/*
#-----------------------------------------------------------------------
# Nom Fichier: mainwindow.cpp
# Classe : MainWindow
# Sujet : gestion du programme cartebancaire
# Version : 0.1
# Auteur : HUCK
# Création : 17/09/2021
# Mise à jour :
# ----------------------------------------------------------------------------------------------------------
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>

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
# Nom Fonction Membre : Verification_NumeroCB
# Classe : MainWindow
# Sujet : permettra de vérifier le numero de la carte bancaire
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Boolean ; Rôle : de valider ou pas le numero de la carte
# Auteur : HUCK
# Création : 17/09/2021
# Mise à jour :
# -----------------------------------------------------------------------

   ---CF Algorithme de Luhn---

    Entier somme <- 0
    Entier reste <- 0
    Entier index <- 0
    Entier N1
    index <-1

    TANT QUE ( index<=15 ) FAIRE
        N1 <- NumeroCarte[index]
        Somme <- (Somme+N1)
        index <- index+2
    FINTQ
        index <- 0
    TANT QUE ( index<=15 ) FAIRE
        N1 <- NumeroCarte[index]
        N1 <- N1*2
        SI ( N1>9 ) ALORS
        N1 <- (N1-9)
        FINSI
        Somme <- Somme+N1
        index <- index+2
    FINTQ
    reste <- somme MOD 10
    SI ( reste = 0 ) ALORS
            Retourne (Vrai)
    SINON
            Retourne (Faux)
    FINSI
*/
bool MainWindow::Verification_NumeroCB()
{
    short somme = 0;
    short reste = 0;
    short index = 1;
    short N1 = 0;
    
    while ( index<=15 )
    {
        N1 = Numerocarte[index];
        somme = (somme+N1);
        index = index+2;
    }
    index = 0;
    while ( index<=15 )
    {
        N1 = Numerocarte[index];
        N1 = N1*2;
        if ( N1>9 )
        {
            N1 = (N1-9);
        }
        somme = somme+N1;
        index = index+2;
    }
    reste = somme % 10;

    /*QMessageBox msgBox;
    QString  rest= QString::number(reste);
    msgBox.setText(rest);
    msgBox.exec();*/

    if ( reste == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
	
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : Verification_DateCB
# Classe : MainWindow
# Sujet : permettra de vérifier la date de validiter de la carte bancaire
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Boolean ; Rôle : de valider ou pas la date de validiter de la carte
# Auteur : HUCK
# Création : 17/09/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
bool MainWindow::Verification_DateCB()
   {
    int moiscourrant;
    int anneecourante;
    // Mois courant
    moiscourrant=QDate::currentDate().month();
    // Date courante
    anneecourante=QDate::currentDate().year();
    //Test mois/Année de validité de la carte > Mois/Année courante
    if(ui->LE_Annee->text().toInt()>anneecourante)
    {
        return 1    ;
    }

    if(ui->LE_Annee->text().toInt()<anneecourante)
    {
        return 0;
    }

    if(ui->LE_Annee->text().toInt()==anneecourante)
    {
            if(ui->LE_Mois->text().toInt()>=moiscourrant)
            {
                    return 1;
            }
            else
            {
                    return 0;
            }
    }
   }

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_PB_Verifier_clicked
# Classe : MainWindow
# Sujet : permettra d'appeler des fonctions , d'executer des conditions quand l'utilisateur cliquera sur le bouton
# Version : 0.1
# Entrees (in) : QString, Rôle : Copie du LineEdit du numéro de carte pour le mettre dans une variable
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : QMessageBox ; Rôle : d'indiquer à l'utilisateur, si la carte saisi est valide ou non
# Auteur : HUCK
# Création : 17/09/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::on_PB_Verifier_clicked()
{
    int index;
    // VRAI si Carte Valide
    bool carteOK;
    // VRAI si numéro de carte valide
    bool numcarteOK;
    // VRAI si Date de la carte valide
    bool datecarteOK;
  // Copie du LineEdit du numéro de carte -> char numcarte[255];
    strcpy(Numcarte, ui->LE_Numero->text().toLatin1());
  // Conversion des Ascii de numcar -> entier dans int numerocarte[16]
     for ( index = 0;index<16;index++)
     {
        Numerocarte[index] = Numcarte[index]-0x30;
     }
   //------------ A COMPLETER--------------------------
  // Verification du numéro CB
     numcarteOK = Verification_NumeroCB();

  // Verification de la date
     datecarteOK = Verification_DateCB();

  // Verification du Numero et de la date
     if ((datecarteOK == true)&&(numcarteOK==true))
     {carteOK = true;}
     else{carteOK = false;}

  // Si carteOK=Vrai
  // Alors "Carte Valide"
  // Sinon "Carte Invalide"
     if (carteOK==true)
     {
         QMessageBox msgBox;
         QPixmap pixmap = QPixmap("icon.jpg");
         msgBox.setWindowIcon(QIcon(pixmap));
         msgBox.setStyleSheet("background-color: dodgerblue");
         msgBox.setText("Carte Valide");
         msgBox.exec();
     }
     else
     {
         QMessageBox msgBox;
		 QPixmap pixmap = QPixmap("icon.jpg");
         msgBox.setWindowIcon(QIcon(pixmap));
         msgBox.setStyleSheet("background-color: dodgerblue ");
         msgBox.setText("Carte Invalide");
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
# Création : 17/09/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
void MainWindow::on_PB_Quitter_clicked()
{
     exit(0);
}
