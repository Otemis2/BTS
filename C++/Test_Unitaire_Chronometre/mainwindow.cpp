#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Initialisation de la Valeur du Chronomètre
    valeur=0;
    // Création de l'objet "montimer"
    monTimer=new QTimer(this);
    // Connection du timer "montimer" au SLOT "chronometre()"
    connect(monTimer,SIGNAL(timeout()),this,SLOT(chronometre()));
    // Démarrage de l'IHM
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Méthode associé au timer "montimer" (cf la méthode connect() dans le constructeur)
void MainWindow::chronometre()
{
    // Incrémentation du chronomètre
    valeur=valeur+1;
    // Affichage de "valeur" dans l'objet LCD de l'IHM
    ui->lcd_Chronometre->display(valeur);
}

void MainWindow::on_pb_Raz_clicked()
{
    // RAZ de la valeur du chronomètre
    valeur=0;
    ui->lcd_Chronometre->display(valeur);
}

void MainWindow::on_pb_demarer_clicked()
{
    // Initialise le timer en timer périodique ; obligatoire si
    // l'application utilise le mode SingleShot
    monTimer->setSingleShot(false);
    // Démarrage du timer périodique avec une base de temps d'1 seconde (1000ms)
    monTimer->start(1000);
}

void MainWindow::on_pb_Arreter_clicked()
{
    // Arrêt du timer "montimer" -> Arrêt du chronomètre
    monTimer->stop();
}

void MainWindow::on_pb_inc1_clicked()
{
    // Initialisation du timer "montimer" en mode SingleShot :(1 seule exécution après la temporisation de 10 secondes)
    monTimer->setSingleShot(true);
    // Incrémentation de 10 s (1s +9s au lancement de la méthode chorometre()
    valeur=valeur+10-1;
    // Démarrage du timer avec une temporisation de 10 s.
    monTimer->start(10000);
}

void MainWindow::on_pb_Quitter_clicked()
{
    // Quitter l'application
    exit (0);
}
