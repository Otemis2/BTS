/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 17. Sep 11:23:16 2021
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *PB_Verifier;
    QLabel *lInfoNumCb;
    QLabel *lInfoDate;
    QLabel *lInfoSlach;
    QLabel *lVerification;
    QLineEdit *LE_Numero;
    QLineEdit *LE_Mois;
    QLineEdit *LE_Annee;
    QLabel *lInfo;
    QLabel *lImage;
    QLabel *lCredit;
    QPushButton *PB_Quitter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 308);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(85, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PB_Verifier = new QPushButton(centralWidget);
        PB_Verifier->setObjectName(QString::fromUtf8("PB_Verifier"));
        PB_Verifier->setGeometry(QRect(140, 160, 121, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        PB_Verifier->setPalette(palette1);
        QFont font;
        font.setPointSize(16);
        PB_Verifier->setFont(font);
        lInfoNumCb = new QLabel(centralWidget);
        lInfoNumCb->setObjectName(QString::fromUtf8("lInfoNumCb"));
        lInfoNumCb->setGeometry(QRect(40, 60, 101, 16));
        QFont font1;
        font1.setPointSize(14);
        lInfoNumCb->setFont(font1);
        lInfoDate = new QLabel(centralWidget);
        lInfoDate->setObjectName(QString::fromUtf8("lInfoDate"));
        lInfoDate->setGeometry(QRect(90, 100, 46, 20));
        lInfoDate->setFont(font1);
        lInfoSlach = new QLabel(centralWidget);
        lInfoSlach->setObjectName(QString::fromUtf8("lInfoSlach"));
        lInfoSlach->setGeometry(QRect(180, 100, 21, 16));
        lInfoSlach->setAlignment(Qt::AlignCenter);
        lVerification = new QLabel(centralWidget);
        lVerification->setObjectName(QString::fromUtf8("lVerification"));
        lVerification->setGeometry(QRect(70, 130, 261, 20));
        QFont font2;
        font2.setPointSize(12);
        lVerification->setFont(font2);
        lVerification->setAlignment(Qt::AlignCenter);
        LE_Numero = new QLineEdit(centralWidget);
        LE_Numero->setObjectName(QString::fromUtf8("LE_Numero"));
        LE_Numero->setGeometry(QRect(150, 60, 181, 20));
        LE_Numero->setFont(font1);
        LE_Numero->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        LE_Mois = new QLineEdit(centralWidget);
        LE_Mois->setObjectName(QString::fromUtf8("LE_Mois"));
        LE_Mois->setGeometry(QRect(150, 100, 31, 20));
        LE_Mois->setFont(font1);
        LE_Mois->setAlignment(Qt::AlignCenter);
        LE_Annee = new QLineEdit(centralWidget);
        LE_Annee->setObjectName(QString::fromUtf8("LE_Annee"));
        LE_Annee->setGeometry(QRect(200, 100, 71, 20));
        LE_Annee->setFont(font1);
        LE_Annee->setAlignment(Qt::AlignCenter);
        lInfo = new QLabel(centralWidget);
        lInfo->setObjectName(QString::fromUtf8("lInfo"));
        lInfo->setGeometry(QRect(50, 10, 291, 20));
        QFont font3;
        font3.setPointSize(15);
        lInfo->setFont(font3);
        lInfo->setAlignment(Qt::AlignCenter);
        lImage = new QLabel(centralWidget);
        lImage->setObjectName(QString::fromUtf8("lImage"));
        lImage->setGeometry(QRect(0, 200, 161, 41));
        lImage->setPixmap(QPixmap(QString::fromUtf8("cb.png")));
        lImage->setScaledContents(true);
        lCredit = new QLabel(centralWidget);
        lCredit->setObjectName(QString::fromUtf8("lCredit"));
        lCredit->setGeometry(QRect(240, 230, 161, 20));
        PB_Quitter = new QPushButton(centralWidget);
        PB_Quitter->setObjectName(QString::fromUtf8("PB_Quitter"));
        PB_Quitter->setGeometry(QRect(270, 200, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PARKING-V\303\251rification Carte Bancaire", 0, QApplication::UnicodeUTF8));
        PB_Verifier->setText(QApplication::translate("MainWindow", "V\303\251rifier", 0, QApplication::UnicodeUTF8));
        lInfoNumCb->setText(QApplication::translate("MainWindow", "Num\303\251ro CB", 0, QApplication::UnicodeUTF8));
        lInfoDate->setText(QApplication::translate("MainWindow", "Date", 0, QApplication::UnicodeUTF8));
        lInfoSlach->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        lVerification->setText(QApplication::translate("MainWindow", "Saisir les informations de la carte", 0, QApplication::UnicodeUTF8));
        LE_Numero->setText(QApplication::translate("MainWindow", "5132865025007267", 0, QApplication::UnicodeUTF8));
        LE_Mois->setText(QApplication::translate("MainWindow", "11", 0, QApplication::UnicodeUTF8));
        LE_Annee->setText(QApplication::translate("MainWindow", "2022", 0, QApplication::UnicodeUTF8));
        lInfo->setText(QApplication::translate("MainWindow", "V\303\251rification de Carte Bancaire", 0, QApplication::UnicodeUTF8));
        lImage->setText(QString());
        lCredit->setText(QApplication::translate("MainWindow", "\302\251 Eric DERENDINGER- 2004", 0, QApplication::UnicodeUTF8));
        PB_Quitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
