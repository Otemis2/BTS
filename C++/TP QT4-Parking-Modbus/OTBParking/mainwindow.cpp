/*
#-----------------------------------------------------------------------
# Nom Fichier: mainwindow.cpp
# Classe : MainWindow
# Sujet : gestion de l'application OTBParking
# Version : 0.1
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# ----------------------------------------------------------------------------------------------------------
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream> //Classe pour gérer les fichiers
#include <string.h>
#include <string>
#include <iostream>

//#include <bitset> //Classe pour affiché/convertir en binaire

using namespace std;

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : MainWindow()
# Classe : MainWindow
# Sujet : Constructeur de la classe
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) :   Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(ui->LCD_Place->intValue()==1000)
    {
        ui->BP_OuvrirSortie->setDisabled(true);
    }

    registreSortie = 0x0C;
    ui->LE_RegSortie->setText(QString::number(registreSortie));

    ifstream f("config.ini");
    char* ligne = new char[56];

    f.is_open();
    f>>ligne;
    ui->LCD_Place->display(ligne);
    f>>ligne;
    ui->LE_AdresseIP->setText(QString::fromAscii(ligne));
    f>>ligne;
    ui->LE_Port->setText(QString::fromAscii(ligne));
    f.close();

    if(ui->LCD_Place->intValue()<1000)
    {
        ui->BP_OuvrirSortie->setDisabled(false);
    }

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : ~MainWindow()
# Classe : MainWindow
# Sujet : Destructeur de la classe
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) :   Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
MainWindow::~MainWindow()
{
    QString ip;
    QString port;
    short valeurLCD;

    valeurLCD = ui->LCD_Place->intValue();
    ip = ui->L_IP->text();
    port = ui->L_Port->text();

    ofstream f ("config.ini");
    f<<valeurLCD<<endl;
    f<<ip.toStdString()<<endl;
    f<<port.toStdString()<<endl;
    f.close();

    delete ui;
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_FermerEntree_clicked()
# Classe : MainWindow
# Sujet : permettera détecter la fermeture de la barriere et de considèré comme entrée de véhicule
d'écrire le statut dans un registre et de l'affiché
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : registreSortie : caractère non signé
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
ALGORITHME :
VAR:
valeurLCD : entier court
FE : caractère non signé

DEBUT
    boutonOuvrirEntree activer
    boutonFermerEntree désactiver
    affichage LCD (valeur-1)
    barriere etat fermer

    valeurLCD <- lcd valeur()
    f <- ouvrir en écriture fichier ("config.ini")
    f <- valeurLCD
    f <- fermeture du fichier

    SI LCD valeur() = 0 FAIRE
        boutonOuvrirEntree désactiver
    FINSI
    SI LCD valeur() <> 1000 FAIRE
        BoutonOuvrirSortie activer
    FINSI
    FE <- 0x04
    registreSortie <- registreSortie^FE;
    LE_RegSortie modificationText (entier(registreSortie))
FIN
*/
void MainWindow::on_BP_FermerEntree_clicked()
{
    ui->BP_OuvrirEntree->setEnabled(true);
    ui->BP_FermerEntree->setDisabled(true);
    ui->VS_Entree->setValue(0);
    ui->LCD_Place->display(ui->LCD_Place->intValue()-1);

    short valeurLCD;
    valeurLCD = ui->LCD_Place->intValue();
    ofstream f ("config.ini");
    f<<valeurLCD<<endl;
    f.close();

    if(ui->LCD_Place->intValue()==0)
    {
        ui->BP_OuvrirEntree->setDisabled(true);
    }
    if ((ui->LCD_Place->intValue()!=1000) && (ui->VS_Sortie->value() != 1))
    {
        ui->BP_OuvrirSortie->setEnabled(true);
    }
    unsigned char FE = 0x04;//FB
    registreSortie = registreSortie^FE;
    ui->LE_RegSortie->setText(QString::number(registreSortie));
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_FermerSortie_clicked()
# Classe : MainWindow
# Sujet : permettera détecter la fermeture de la barriere et de considèré comme sorti de véhicule
d'écrire le statut dans un registre et de l'affiché
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : registreSortie : caractère non signé
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_FermerSortie_clicked()
{
    ui->BP_OuvrirSortie->setEnabled(true);
    ui->BP_FermerSortie->setDisabled(true);
    ui->VS_Sortie->setValue(0);
    ui->LCD_Place->display(ui->LCD_Place->intValue()+1);
    if(ui->LCD_Place->intValue()==1000)
    {
        ui->BP_OuvrirSortie->setDisabled(true);
    }
    short valeurLCD;
    valeurLCD = ui->LCD_Place->intValue();
    ofstream f ("config.ini");
    f<<valeurLCD<<endl;
    f.close();

    unsigned char FS = 0x08;//F7
    registreSortie = registreSortie^FS;
    ui->LE_RegSortie->setText(QString::number(registreSortie));
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_OuvrirEntree_clicked()
# Classe : MainWindow
# Sujet : permettera détecter la ouverture de la barriere et de considèré comme entrée de véhicule
d'écrire le statut dans un registre et de l'affiché
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : registreSortie : caractère non signé
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_OuvrirEntree_clicked()
{
    ui->BP_FermerEntree->setEnabled(true);
    ui->BP_OuvrirEntree->setDisabled(true);
    ui->VS_Entree->setValue(1);

    unsigned char OE = 0xFB;//04
    registreSortie = registreSortie&OE;
    ui->LE_RegSortie->setText(QString::number(registreSortie));
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_OuvrirSortie_clicked()
# Classe : MainWindow
# Sujet : permettera détecter la ouverture de la barriere et de considèré comme entrée de véhicule
d'écrire le statut dans un registre et de l'affiché
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : registreSortie : caractère non signé
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_OuvrirSortie_clicked()
{
    if ((ui->LCD_Place->intValue()==0) && (ui->VS_Entree->value() != 1))
    {
        ui->BP_OuvrirEntree->setEnabled(true);
    }
    ui->BP_FermerSortie->setEnabled(true);
    ui->BP_OuvrirSortie->setDisabled(true);
    ui->VS_Sortie->setValue(1);

    unsigned char OS = 0xF7;//08
    registreSortie = registreSortie&OS;
    ui->LE_RegSortie->setText(QString::number(registreSortie));
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_Connexion_clicked()
# Classe : MainWindow
# Sujet : permettera de ce connecter au serveur OTB en fonction de son ip et du port
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_Connexion_clicked()
{
    ui->BP_Connexion->setDisabled(true);
    ui->BP_Deconnexion->setEnabled(true);
    ui->EtatConnexionOTB->setChecked(true);

    ui->L_IP->setText(ui->LE_AdresseIP->text());
    ui->L_Port->setText(ui->LE_Port->text());
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre :on_BP_Deconnexion_clicked()
# Classe : MainWindow
# Sujet : permettera de ce deconnecter du serveur OTB
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_Deconnexion_clicked()
{
    ui->BP_Deconnexion->setDisabled(true);
    ui->BP_Connexion->setEnabled(true);
    ui->EtatConnexionOTB->setChecked(false);
}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_Lire_Entree_clicked()
# Classe : MainWindow
# Sujet : permettera de récupèrer la valeur du lineEdit d'Entree est de traité
les informations contenue dedans en hexa pour affiché l'état des capteurs
# Version : 0.1
# Entrees (in) : registreEntree : caractère non signé
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
ALGORITHME :
VAR:
    tempCEE : caractère non signé
    tempCES : caractère non signé
    tempCSE : caractère non signé
    tempCSS : caractère non signé
    tempAU : entier court
    etat : boolean

DEBUT
    registreEntree <- entier(valeur)
    tempCEE <- registreEntree&0x01
    tempCES <- registreEntree&0x02;
    tempCSE <- registreEntree&0x04;
    tempCSS <- registreEntree&0x08;

    SI tempCEE = 0x01 FAIRE E_Entree checker SINON E_Entree non checker
    SI tempCES = 0x02 FAIRE E_Sortie checker SINON E_Sortie non checker

    SI tempCSE = 0x04 FAIRE S_Entree checker SINON S_Entree non checker
    SI tempCSS = 0x08 FAIRE S_Sortie checker SINON S_Sortie non checker

    tempAU <- registreEntree&0x10;

    SI tempAU = 0x10 FAIRE etat <- 0 SINON etat <- 1

    SI etat = 1 FAIRE
        BP_FermerEntree <- activer
        BP_FermerSortie <- activer
        ArretUrgence <- non checker

        on_BP_FermerEntree_clicked()
        on_BP_FermerSortie_clicked()
    SI etat = 0 FAIRE
        on_BP_OuvrirEntree_clicked();
        on_BP_OuvrirSortie_clicked();

        BP_FermerEntree <- desactiver
        BP_FermerSortie <- desactiver
        ArretUrgence <- checker
        LCD_Place <- 1000

FIN
*/
void MainWindow::on_BP_Lire_Entree_clicked()
{
    unsigned char tempCEE;
    unsigned char tempCES;
    unsigned char tempCSE;
    unsigned char tempCSS;
    short tempAU;

    registreEntree = ui->LE_RegEntree->text().toInt();//Recuperer la veleut en dec

//    cout<<std::hex<<registreEntree<<dec<<endl;//Afficher en hexa
//    cout<<std::bitset<8>(registreEntree)<<endl;// Afficher en binaire

    //cout<<"registreEntree : "<<int(registreEntree)<<endl;
    tempCEE = registreEntree&0x01;//et logique avec le masque
    //cout<<"tempCEE : "<<int(tempCEE)<<endl;
    tempCES = registreEntree&0x02;
    //cout<<"tempCES : "<<int(tempCES)<<endl;
    tempCSE = registreEntree&0x04;
    //cout<<"tempCSE : "<<int(tempCSE)<<endl;
    tempCSS = registreEntree&0x08;
    //cout<<"tempCSS : "<<int(tempCSS)<<endl;

    if (tempCEE == 0x01){ui->E_Entree->setChecked(true);}else{ui->E_Entree->setChecked(false);}
    if (tempCES == 0x02){ui->E_Sortie->setChecked(true);}else{ui->E_Sortie->setChecked(false);}

    if (tempCSE == 0x04){ui->S_Entree->setChecked(true);}else{ui->S_Entree->setChecked(false);}
    if (tempCSS == 0x08){ui->S_Sortie->setChecked(true);}else{ui->S_Sortie->setChecked(false);}

    tempAU = registreEntree&0x10;
    //cout<<"tempAU : "<<int(tempAU)<<endl;
    bool etat;

    if(tempAU == 0x10){etat=0;}else{etat=1;}
    //cout<<"ETAT : "<<int(etat)<<endl;

    if (etat == 1)
    {
        ui->BP_FermerEntree->setEnabled(true);
        ui->BP_FermerSortie->setEnabled(true);
        ui->ArretUrgence->setChecked(false);

        on_BP_FermerEntree_clicked();
        on_BP_FermerSortie_clicked();
    }
    if (etat == 0)
    {
        on_BP_OuvrirEntree_clicked();
        on_BP_OuvrirSortie_clicked();

        ui->BP_FermerEntree->setEnabled(false);
        ui->BP_FermerSortie->setEnabled(false);
        ui->ArretUrgence->setChecked(true);
        ui->LCD_Place->display(1000);
    }

}

/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_Auto_clicked()
# Classe : MainWindow
# Sujet : permettera d'affiché dans un label que le mode AUTO a été activé
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_Auto_clicked()
{
    ui->L_Automatique->setText("AUTO");
}


/*
#-----------------------------------------------------------------------
# Nom Fonction Membre : on_BP_Quitter_clicked()
# Classe : MainWindow
# Sujet : permettera de quitter l'application par l'action d'un bouton et de sauvegarder
l'ip , le port et le nombre de place disponible
# Version : 0.1
# Entrees (in) : Aucune
# Sorties (out) : Aucune
# Entrees/Sorties (inout) : Aucune
# Retour : Aucune
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
void MainWindow::on_BP_Quitter_clicked()
{
    QString ip;
    QString port;
    short valeurLCD;

    valeurLCD = ui->LCD_Place->intValue();
    ip = ui->L_IP->text();
    port = ui->L_Port->text();

    ofstream f ("config.ini");
    f<<valeurLCD<<endl;
    f<<ip.toStdString()<<endl;
    f<<port.toStdString()<<endl;
    f.close();

    exit(0);
}
