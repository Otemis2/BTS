#ifndef APPSIGNE_H
#define APPSIGNE_H

#include <QMainWindow>

namespace Ui {
class Appsigne;
}

class Appsigne : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Appsigne(QWidget *parent = 0);
    ~Appsigne();
    
private slots:
    void on_pbCalculer_clicked();

private:
    Ui::Appsigne *ui;
};

#endif // APPSIGNE_H
