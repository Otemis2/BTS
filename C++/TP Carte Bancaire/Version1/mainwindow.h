/*
# -----------------------------------------------------------------------
# Nom Fichier : mainwindow.h
# Classe : MainWindow
# Sujet : gestion du programme cartebancaire
# Auteur : HUCK
# Cr�ation : 17/09/2021
# Mise � jour :
# -----------------------------------------------------------------------
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

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
    void on_PB_Quitter_clicked();

    void on_PB_Verifier_clicked();

private:
    Ui::MainWindow *ui;
    // Tableau des valeurs d�cimales du num�ro de carte (16 entiers)
    int Numerocarte[16];
    // Tableau des valeurs ASCII du num�ro de carte (16 Chiffres)
    char Numcarte[50];

    bool Verification_NumeroCB();
    bool Verification_DateCB();

};

#endif // MAINWINDOW_H
