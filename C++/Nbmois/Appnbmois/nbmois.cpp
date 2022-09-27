#include "nbmois.h"
#include "ui_nbmois.h"

Nbmois::Nbmois(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Nbmois)
{
    ui->setupUi(this);
}

Nbmois::~Nbmois()
{
    delete ui;
}

void Nbmois::on_pbCalculer_clicked()
{
    short nombre;

    nombre = ui->lENb->text().toShort();

    switch (nombre) {

    case 1:
        ui->lEMois->setText("Janvier");
        break;

    case 2:
        ui->lEMois->setText("Fevrier");
        break;

    case 3:
        ui->lEMois->setText("Mars");
        break;

    case 4:
        ui->lEMois->setText("Avril");
        break;

    case 5:
        ui->lEMois->setText("Mai");
        break;

    case 6:
        ui->lEMois->setText("Juin");
        break;

    case 7:
        ui->lEMois->setText("Juillet");
        break;

    case 8:
        ui->lEMois->setText("Aout");
        break;

    case 9:
        ui->lEMois->setText("Septembre");
        break;

    case 10:
        ui->lEMois->setText("Octobre");
        break;

    case 11:
        ui->lEMois->setText("Novembre");
        break;

    case 12:
        ui->lEMois->setText("Decembre");
        break;

    default:
        ui->lEMois->setText("Incorrect");
        break;
    }
}
