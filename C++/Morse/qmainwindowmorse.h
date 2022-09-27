#ifndef QMAINWINDOWMORSE_H
#define QMAINWINDOWMORSE_H

#include <QMainWindow>
#include "cmorse.h"

namespace Ui {
class QMainWindowMorse;
}

class QMainWindowMorse : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QMainWindowMorse(QWidget *parent = 0);
    ~QMainWindowMorse();
    
private slots:
    void on_pBCode_clicked();

    void on_pBQuitter_clicked();

    void on_pBDecoder_clicked();

private:
    Ui::QMainWindowMorse *ui;
};

#endif // QMAINWINDOWMORSE_H
