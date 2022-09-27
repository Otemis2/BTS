#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>

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
float nbJoursMois;//initialise la variable nbJoursMois
float somme=0;//initialise la variable somme a 0
float tabTempJour[31];//cree un tableau avec 31 cases (nombre de jour max qu'un mois a )
short b = 1;//initialise la variable b (boucle) à 1 qui permet d'afficher le jour exacte de la température a saisir
short i ;//initialise la variable i (indice) qui correspond a la case du tableau

//variable de température :
short jourLePlusFroid = 0;
short jourLePlusChaud = 0;
short nbTempFroide = 0;
short nbTempChaude = 0;

void MainWindow::on_pBSuivant_clicked()
{
    nbJoursMois = ui->lENbJoursMois ->text().toFloat();//incris dans la variable "nbJoursMois" la veleur présentent dans le lineEdit "lENbJourMois"
    ui->lNumJour->setText(QString::number(b));//affiche la valeur de "b" dans le label "lTempJ
    ui->lENbJoursMois ->setEnabled(false);//grise le lineEdit Pour empecher l'insertion d'autre valeurs
    ui->pBSuivant ->setEnabled(false);//grise le bouton poussoir Suivant
}


void MainWindow::on_pBValider_clicked()
{

            ui->lNumJour->setText(QString::number(b+1));//affiche la valeur de "b+1" dans le label "lTempJ
             tabTempJour[i]= ui->lETemp->text().toFloat();//incris la valeur présentent dans le lineEdit dans la variable du tableau "tabTempJour" dans l'indice [i]
             somme = somme + tabTempJour[i];//calcul de la somme pour effectuer la moyenne
             ui->lETemp->QLineEdit::clear();//enleve les valeurs presente dans le lineEdit

            if (i>=nbJoursMois-1)//si j(jour) est superieur ou égal à nbJourMois alors faire
            {
                ui->lETemp ->QLineEdit::clear();//enleve les valeurs presente dans le lineEdit (pas obliger sachant que "Jour invalide" va écraser les valeurs présentent
                ui->lETemp ->setText("Jour invalide");//Indique que le jour indiqué est invalide
                ui->pBValider ->setEnabled(false);//grise le bouton "Valider" pour embecher l'autre utilisation
            }
            b++,i++;//incrementation
}

void MainWindow::on_pBCalculer_clicked()
{
    float moyenne;
    moyenne = (somme/nbJoursMois);//calcule la moyenne et affiche la moyenne

    ui->lMoyenne->setText(QString::number(moyenne));//affiche la moyenne

        //tempFroide = Temperature du jours le plus froid
        //temChaude = Température du jours le plus chaud

        //jourLePlusFroid = n° du jour le plus Froid
        //jourLePlusChaud = n° du jour le plus Chaud


        float tempChaude = tabTempJour[0];
        float tempFroide = tabTempJour[0];

        for (i=0; i < nbJoursMois; i++)
        {

                    //Chaud
                    if(tabTempJour[i] > moyenne)
                    {
                        if (tempChaude < tabTempJour[i])
                        {
                            tempChaude = tabTempJour[i];
                            jourLePlusChaud = i;
                        }
                        nbTempChaude++;
                    }
                    //Froid
                    if(tabTempJour[i] < moyenne)
                    {
                        if (tempFroide > tabTempJour[i])
                        {
                            tempFroide = tabTempJour[i];
                            jourLePlusFroid = i;
                        }
                        nbTempFroide++;
                    }
        }

    ui ->lTempFroide->setText(QString::number(tempFroide));//affiche le jours le plus froid
    ui ->lTempChaude->setText(QString::number(tempChaude));//affiche le jour le plus chaud
    ui ->lIdJourLePlusChaud->setText(QString::number(jourLePlusFroid+1));//affiche le n° du jour le plus froid
    ui ->lIdJourLePlusFroid->setText(QString::number(jourLePlusChaud+1));//affiche le n° du jour le plus chaud
    ui ->lNbJourFroid->setText(QString::number(nbTempFroide));//affiche le nombre de jour froid
    ui ->lNbJourChaud->setText(QString::number(nbTempChaude));//affiche le nombre de jour chaud
    ui->pBCalculer ->setEnabled(false);//grise le bouton poussoir "Calculer"
}

void MainWindow::on_pBEnregistrer_clicked()
{

    // manque des choses qui permetterai d'écrire dans un fichier csv

    ui ->lInfoEnregister->setText("Les données sont bien sauvegardé");
}
