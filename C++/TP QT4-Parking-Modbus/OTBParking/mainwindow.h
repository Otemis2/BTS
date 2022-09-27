/*
# -----------------------------------------------------------------------
# Nom Fichier : mainwindow.h
# Classe : MainWindow
# Sujet : gestion de l'application OTBParking
# Auteur : HUCK
# Création : 11/12/2021
# Mise à jour : 11/12/2021
# -----------------------------------------------------------------------
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_BP_FermerEntree_clicked();

    void on_BP_OuvrirEntree_clicked();

    void on_BP_FermerSortie_clicked();

    void on_BP_OuvrirSortie_clicked();

    void on_BP_Connexion_clicked();

    void on_BP_Deconnexion_clicked();

    void on_BP_Lire_Entree_clicked();

    void on_BP_Auto_clicked();

    //void on_ArretUrgence_clicked();

    //void on_ArretUrgence_clicked(bool checked);

    void on_BP_Quitter_clicked();

private:
    Ui::MainWindow *ui;
    unsigned char registreEntree;
    unsigned char registreSortie;

};

#endif // MAINWINDOW_H
