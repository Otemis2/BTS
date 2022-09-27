/*
# -----------------------------------------------------------------------
# Nom Fichier : mainwindow.h
# Classe : MainWindow
# Sujet : gestion du programme du feux tri colore
# Auteur : HUCK
# Création : 27/10/2021
# Mise à jour :
# -----------------------------------------------------------------------
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void dateHeure();
    // Méthode Slot Fonctionnement Clignotant
    void activerClignotant();
    // Méthode Slot Fonctionnement Normal
    void activerNormal();
    // Méthode Slot Fonctionnement Automatique
    void activerAutomatique();
    void enregistrerHoraires();
    void chargerHoraires();
    void on_pb_Normal_clicked();

    void on_pb_Test_Feux_pressed();

    void on_pb_Test_Feux_released();

    void on_pb_Clignotant_clicked();

    void on_pb_Automatique_clicked();

    void on_te_1Debut_timeChanged(const QTime &date);

    void on_te_1Fin_timeChanged(const QTime &date);

    void on_te_2Debut_timeChanged(const QTime &date);

    void on_te_2Fin_timeChanged(const QTime &date);

    void on_te_3Debut_timeChanged(const QTime &date);

    void on_te_3Fin_timeChanged(const QTime &date);

    void on_te_4Debut_timeChanged(const QTime &date);

    void on_te_4Fin_timeChanged(const QTime &date);

private:
    Ui::MainWindow *ui;

    void initialiser();
    // Timer du Chronomètre
    QTimer *timerDateHeure;

    QTimer *timerClignotant;
    // Cycles de Clignotement
    int cycleClignotant;
    // Timer Cycle Normal
    QTimer *timerNormal;
    // Cycles de fonctionnement Normal

    QTimer * timerAutomatique;
    int cycleNormal;
};

#endif // MAINWINDOW_H
