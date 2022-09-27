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
// methode du bouton calculer
void MainWindow::on_pbCalculer_clicked()
{
  short nb1,nb2,somme; // déclaration des 3 variables locales
  //QString qstSomme;
  nb1 = ui->lENb1 ->text().toShort();
  //lit et convertit la valeur saisie dans l'ihm
  nb2 = ui->lENb2->text().toShort();
  somme = nb1 + nb2;
  //qstSomme ::number(somme);
  ui->lESomme->setText(QString ::number(somme));
}
