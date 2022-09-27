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
    void on_pBCalculer_clicked();

    void on_pBQuitter_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
