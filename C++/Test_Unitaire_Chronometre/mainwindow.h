#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
// D�claration du SLOT Chronom�tre associ� au Timer
void chronometre();
// D�claration des SLOT des Bouttons
void on_pb_Quitter_clicked();
void on_pb_Raz_clicked();
void on_pb_demarer_clicked();
void on_pb_Arreter_clicked();
void on_pb_inc1_clicked();

private:
    Ui::MainWindow *ui;
    // Valeur du Chronom�tre
    int valeur;
    // Timer du Chronom�tre
    QTimer *monTimer;

};

#endif // MAINWINDOW_H
