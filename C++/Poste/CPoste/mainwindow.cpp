/*
#-----------------------------------------------------------------------
# Nom : mainwindows.cpp
# Sujet : programme en interface graphique du logiciel de la Poste
# Auteur : HUCK
# Création : 10/02/2021
# Mise à jour :
# -----------------------------------------------------------------------------------------------------------
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
short poids;
short tarif;
short prix;
short nb;
short c = 0;//initialise la variable c (boucle) à 1 qui permet d'afficher le colis exacte de la température a saisir
short i ;//initialise la variable i (indice) qui correspond a la case du tableau

void MainWindow::on_pBEnvoyer_clicked()
{
    nb = ui->lENombreColis->text().toShort();
    affranchissement.setNbColis(nb);
    ui->lENombreColis ->setEnabled(false);//grise le lineEdit Pour empecher l'insertion d'autre valeurs
    ui->pBEnvoyer->setEnabled(false);//grise le bouton poussoir Suivant
    ui->lNumColis->setText(QString::number(c));//affiche la valeur de "c" dans le label
}

void MainWindow::on_pBValider_clicked()
{
    nb = ui->lENombreColis->text().toShort();
    affranchissement.setNbColis(nb);
    ui->lNombre->setText(QString ::number(affranchissement.getNbColis()));

    if (ui-> rBSuivis -> isChecked())
    {
        tarif=0;
    }
    else
    {
        if (ui-> rBVerte -> isChecked())
        {
                    tarif = 1;
        }
        else
        {
            if (ui-> rBRecommander-> isChecked())
            {
                tarif = 2;
            }
            else
            {
                if (ui-> rBPrioritaire -> isChecked())
                {
                    tarif = 3;
                }
            }

        }

    }
    affranchissement.setTarifColis(tarif);

    poids = ui->lEPoids->text().toShort();
    affranchissement.setPoidsColis(poids);

    affranchissement.affranchirColis();//appel la fonction affrenchirColis

    if (i>=nb-1)//si i est superieur ou égal à nbColis alors faire
    {
        ui->lEPoids->QLineEdit::clear();//enleve les valeurs presente dans le lineEdit (pas obliger sachant que "Jour invalide" va écraser les valeurs présentent
        ui->lNumColis->setText("Colis invalide");//Indique que le jour indiqué est invalide
        ui->pBValider ->setEnabled(false);//grise le bouton "Valider" pour embecher l'autre utilisation
    }

    ui->lPoids->setText(QString ::number(affranchissement.getPoidsColis()));
    ui->lType->setText(QString ::number(affranchissement.getTarifColis()));
    ui->lPrix->setText(QString ::number(affranchissement.getPrixColis()));
    ui->lPrixTotal->setText(QString ::number(affranchissement.getPrixTotal()));
    ui->lNumColis->setText(QString::number(c+1));//affiche la valeur de "c+1" dans le label

     c++,i++;//incrementation

}
