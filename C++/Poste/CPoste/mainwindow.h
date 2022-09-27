#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cposte.h"

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
    void on_pBEnvoyer_clicked();

    void on_pBValider_clicked();

private:
    Ui::MainWindow *ui;
    CPoste affranchissement;
};

#endif // MAINWINDOW_H
