#ifndef NBMOIS_H
#define NBMOIS_H

#include <QMainWindow>

namespace Ui {
class Nbmois;
}

class Nbmois : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Nbmois(QWidget *parent = 0);
    ~Nbmois();
    
private slots:
    void on_pbCalculer_clicked();

private:
    Ui::Nbmois *ui;
};

#endif // NBMOIS_H
