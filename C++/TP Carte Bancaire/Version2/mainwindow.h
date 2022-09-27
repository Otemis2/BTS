/*
# -----------------------------------------------------------------------
# Nom Fichier : mainwindow.h
# Classe : MainWindow
# Sujet : gestion du programme cartebancaire
# Auteur : HUCK
# Création : 17/09/2021
# Mise à jour :
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

};

#endif // MAINWINDOW_H
