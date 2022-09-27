#include "qmainwindowmorse.h"
#include "ui_qmainwindowmorse.h"
#include "cmorse.h"


QMainWindowMorse::QMainWindowMorse(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QMainWindowMorse)
{
    ui->setupUi(this);


}

QMainWindowMorse::~QMainWindowMorse()
{
    delete ui;
}

void QMainWindowMorse::on_pBCode_clicked()
{
    CMorse monMorse;
    char* message=new char[256];
    strcpy (message , ui->lE_MessageClair->text().toStdString().c_str());
    monMorse.setMessageClair(message);
    monMorse.codeMorse();
    message = monMorse.getMessageCode();
    ui->lE_MessageCoder->setText(message);
}

void QMainWindowMorse::on_pBQuitter_clicked()
{
    exit (0);
}

void QMainWindowMorse::on_pBDecoder_clicked()
{
    CMorse monMorse;
    char* message=new char[256];
    strcpy (message , ui->lE_MessageCoder->text().toStdString().c_str());
    monMorse.setMessageCode(message);
    monMorse.decoderMorse();
    message = monMorse.getMessageClaire();
    ui->lE_MessageClair->setText(message);
}
