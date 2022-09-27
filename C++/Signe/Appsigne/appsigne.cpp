/*
#---------------------------------------
#Programme : Signe
#Sujet : On veut une IHM qui d�termine le signe d'un nombre
#Auteur : HUCK Sylvain
#Date de cr�ation :22/09/2020
# Version : 0
#---------------------------------------

VAR: Nb1

D�but
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

void Appsigne::on_pbCalculer_clicked()
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
