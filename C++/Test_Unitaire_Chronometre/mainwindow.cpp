#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Initialisation de la Valeur du Chronom�tre
    valeur=0;
    // Cr�ation de l'objet "montimer"
    monTimer=new QTimer(this);
    // Connection du timer "montimer" au SLOT "chronometre()"
    connect(monTimer,SIGNAL(timeout()),this,SLOT(chronometre()));
    // D�marrage de l'IHM
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// M�thode associ� au timer "montimer" (cf la m�thode connect() dans le constructeur)
void MainWindow::chronometre()
{
    // Incr�mentation du chronom�tre
    valeur=valeur+1;
    // Affichage de "valeur" dans l'objet LCD de l'IHM
    ui->lcd_Chronometre->display(valeur);
}

void MainWindow::on_pb_Raz_clicked()
{
    // RAZ de la valeur du chronom�tre
    valeur=0;
    ui->lcd_Chronometre->display(valeur);
}

void MainWindow::on_pb_demarer_clicked()
{
    // Initialise le timer en timer p�riodique ; obligatoire si
    // l'application utilise le mode SingleShot
    monTimer->setSingleShot(false);
    // D�marrage du timer p�riodique avec une base de temps d'1 seconde (1000ms)
    monTimer->start(1000);
}

void MainWindow::on_pb_Arreter_clicked()
{
    // Arr�t du timer "montimer" -> Arr�t du chronom�tre
    monTimer->stop();
}

void MainWindow::on_pb_inc1_clicked()
{
    // Initialisation du timer "montimer" en mode SingleShot :(1 seule ex�cution apr�s la temporisation de 10 secondes)
    monTimer->setSingleShot(true);
    // Incr�mentation de 10 s (1s +9s au lancement de la m�thode chorometre()
    valeur=valeur+10-1;
    // D�marrage du timer avec une temporisation de 10 s.
    monTimer->start(10000);
}

void MainWindow::on_pb_Quitter_clicked()
{
    // Quitter l'application
    exit (0);
}
