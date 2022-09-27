#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Equation.h"

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

void MainWindow::on_pBCalculer_clicked()
{
    short a,b,c, delta;
    float x1,x2;

  a = ui->lEA ->text().toShort();
  b = ui->lEB ->text().toShort();
  c = ui->lEC ->text().toShort();

  CEquation equation;

  equation.setA(a);
  equation.setB(b);
  equation.setC(c);
  equation.calculerDelta();

    if (delta>0)
    {
    ui->lE->setText("La Racine est réel");
    equation.calculerRacineReels();
    x1 = equation.getX1();
    ui->lX1_2->setText(QString ::number(x1));
    x2 = equation.getX2();
    ui->lX2_2->setText(QString ::number(x2));
    ui->lDelta_2->setText(QString ::number(delta));
    }
    else
    {
    if (delta = 0)
    {
     ui->lE->setText("La Racine est double");
     equation.calculerRacineDouble();
     x1 = equation.getX1();
     ui->lX1_2->setText(QString ::number(x1));
     ui->lDelta_2->setText(QString ::number(delta));
    }
    else
    {
    ui->lE->setText("La solution est complexe");
    }
    }
}

void MainWindow::on_pBQuitter_clicked()
{
    exit (0);
}
