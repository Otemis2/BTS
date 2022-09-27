/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 8. Nov 10:21:13 2021
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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QTimeEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pb_Normal;
    QPushButton *pb_Clignotant;
    QPushButton *pb_Automatique;
    QPushButton *pb_Test_Feux;
    QTimeEdit *te_2Fin;
    QTimeEdit *te_3Fin;
    QTextEdit *te_feux1;
    QTextEdit *te_feux2;
    QGroupBox *gb_Info_plage;
    QTimeEdit *te_4Debut;
    QTimeEdit *te_4Fin;
    QLabel *l_info_fin;
    QTimeEdit *te_1Fin;
    QTimeEdit *te_1Debut;
    QLabel *l_info_debut;
    QTimeEdit *te_2Debut;
    QTimeEdit *te_3Debut;
    QLabel *l_DateHeure;
    QLabel *l_feu_1;
    QLabel *l_feu_2;
    QLabel *label;
    QLabel *l_F1Rouge;
    QLabel *l_F1Vert;
    QLabel *l_F2Rouge;
    QLabel *l_F1Orange;
    QLabel *l_F2Orange;
    QLabel *l_F2Vert;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(516, 534);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pb_Normal = new QPushButton(centralWidget);
        pb_Normal->setObjectName(QString::fromUtf8("pb_Normal"));
        pb_Normal->setGeometry(QRect(80, 80, 75, 23));
        pb_Clignotant = new QPushButton(centralWidget);
        pb_Clignotant->setObjectName(QString::fromUtf8("pb_Clignotant"));
        pb_Clignotant->setGeometry(QRect(80, 120, 75, 23));
        pb_Automatique = new QPushButton(centralWidget);
        pb_Automatique->setObjectName(QString::fromUtf8("pb_Automatique"));
        pb_Automatique->setGeometry(QRect(80, 150, 75, 23));
        pb_Test_Feux = new QPushButton(centralWidget);
        pb_Test_Feux->setObjectName(QString::fromUtf8("pb_Test_Feux"));
        pb_Test_Feux->setGeometry(QRect(80, 190, 75, 23));
        te_2Fin = new QTimeEdit(centralWidget);
        te_2Fin->setObjectName(QString::fromUtf8("te_2Fin"));
        te_2Fin->setGeometry(QRect(290, 321, 131, 31));
        te_3Fin = new QTimeEdit(centralWidget);
        te_3Fin->setObjectName(QString::fromUtf8("te_3Fin"));
        te_3Fin->setGeometry(QRect(290, 360, 131, 31));
        te_feux1 = new QTextEdit(centralWidget);
        te_feux1->setObjectName(QString::fromUtf8("te_feux1"));
        te_feux1->setGeometry(QRect(180, 70, 91, 171));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        te_feux1->setPalette(palette);
        te_feux2 = new QTextEdit(centralWidget);
        te_feux2->setObjectName(QString::fromUtf8("te_feux2"));
        te_feux2->setGeometry(QRect(310, 70, 91, 161));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        te_feux2->setPalette(palette1);
        gb_Info_plage = new QGroupBox(centralWidget);
        gb_Info_plage->setObjectName(QString::fromUtf8("gb_Info_plage"));
        gb_Info_plage->setGeometry(QRect(30, 250, 441, 201));
        te_4Debut = new QTimeEdit(gb_Info_plage);
        te_4Debut->setObjectName(QString::fromUtf8("te_4Debut"));
        te_4Debut->setGeometry(QRect(100, 150, 121, 31));
        te_4Fin = new QTimeEdit(gb_Info_plage);
        te_4Fin->setObjectName(QString::fromUtf8("te_4Fin"));
        te_4Fin->setGeometry(QRect(260, 150, 131, 31));
        l_info_fin = new QLabel(gb_Info_plage);
        l_info_fin->setObjectName(QString::fromUtf8("l_info_fin"));
        l_info_fin->setGeometry(QRect(270, 10, 46, 13));
        te_1Fin = new QTimeEdit(gb_Info_plage);
        te_1Fin->setObjectName(QString::fromUtf8("te_1Fin"));
        te_1Fin->setGeometry(QRect(260, 30, 131, 31));
        te_1Debut = new QTimeEdit(gb_Info_plage);
        te_1Debut->setObjectName(QString::fromUtf8("te_1Debut"));
        te_1Debut->setGeometry(QRect(100, 30, 121, 31));
        te_1Debut->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        te_1Debut->setTime(QTime(0, 0, 0));
        l_info_debut = new QLabel(gb_Info_plage);
        l_info_debut->setObjectName(QString::fromUtf8("l_info_debut"));
        l_info_debut->setGeometry(QRect(100, 10, 46, 13));
        te_2Debut = new QTimeEdit(gb_Info_plage);
        te_2Debut->setObjectName(QString::fromUtf8("te_2Debut"));
        te_2Debut->setGeometry(QRect(100, 70, 121, 31));
        te_3Debut = new QTimeEdit(gb_Info_plage);
        te_3Debut->setObjectName(QString::fromUtf8("te_3Debut"));
        te_3Debut->setGeometry(QRect(100, 110, 121, 31));
        l_DateHeure = new QLabel(centralWidget);
        l_DateHeure->setObjectName(QString::fromUtf8("l_DateHeure"));
        l_DateHeure->setGeometry(QRect(190, 450, 171, 20));
        l_feu_1 = new QLabel(centralWidget);
        l_feu_1->setObjectName(QString::fromUtf8("l_feu_1"));
        l_feu_1->setGeometry(QRect(210, 50, 46, 13));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        l_feu_1->setFont(font);
        l_feu_2 = new QLabel(centralWidget);
        l_feu_2->setObjectName(QString::fromUtf8("l_feu_2"));
        l_feu_2->setGeometry(QRect(340, 50, 46, 13));
        l_feu_2->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 10, 191, 16));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        l_F1Rouge = new QLabel(centralWidget);
        l_F1Rouge->setObjectName(QString::fromUtf8("l_F1Rouge"));
        l_F1Rouge->setGeometry(QRect(190, 80, 71, 51));
        l_F1Rouge->setPixmap(QPixmap(QString::fromUtf8("R.png")));
        l_F1Rouge->setScaledContents(true);
        l_F1Vert = new QLabel(centralWidget);
        l_F1Vert->setObjectName(QString::fromUtf8("l_F1Vert"));
        l_F1Vert->setGeometry(QRect(190, 180, 71, 51));
        l_F1Vert->setPixmap(QPixmap(QString::fromUtf8("V.png")));
        l_F1Vert->setScaledContents(true);
        l_F2Rouge = new QLabel(centralWidget);
        l_F2Rouge->setObjectName(QString::fromUtf8("l_F2Rouge"));
        l_F2Rouge->setGeometry(QRect(320, 80, 71, 51));
        l_F2Rouge->setPixmap(QPixmap(QString::fromUtf8("R.png")));
        l_F2Rouge->setScaledContents(true);
        l_F1Orange = new QLabel(centralWidget);
        l_F1Orange->setObjectName(QString::fromUtf8("l_F1Orange"));
        l_F1Orange->setGeometry(QRect(190, 130, 71, 51));
        l_F1Orange->setPixmap(QPixmap(QString::fromUtf8("O.png")));
        l_F1Orange->setScaledContents(true);
        l_F2Orange = new QLabel(centralWidget);
        l_F2Orange->setObjectName(QString::fromUtf8("l_F2Orange"));
        l_F2Orange->setGeometry(QRect(320, 130, 71, 51));
        l_F2Orange->setPixmap(QPixmap(QString::fromUtf8("O.png")));
        l_F2Orange->setScaledContents(true);
        l_F2Vert = new QLabel(centralWidget);
        l_F2Vert->setObjectName(QString::fromUtf8("l_F2Vert"));
        l_F2Vert->setGeometry(QRect(320, 180, 71, 51));
        l_F2Vert->setPixmap(QPixmap(QString::fromUtf8("V.png")));
        l_F2Vert->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        gb_Info_plage->raise();
        pb_Normal->raise();
        pb_Clignotant->raise();
        pb_Automatique->raise();
        pb_Test_Feux->raise();
        te_2Fin->raise();
        te_3Fin->raise();
        te_feux1->raise();
        te_feux2->raise();
        l_DateHeure->raise();
        l_feu_1->raise();
        l_feu_2->raise();
        label->raise();
        l_F1Rouge->raise();
        l_F1Vert->raise();
        l_F2Rouge->raise();
        l_F1Orange->raise();
        l_F2Orange->raise();
        l_F2Vert->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 516, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        pb_Normal->setText(QApplication::translate("MainWindow", "Normal", 0, QApplication::UnicodeUTF8));
        pb_Clignotant->setText(QApplication::translate("MainWindow", "Clignotant", 0, QApplication::UnicodeUTF8));
        pb_Automatique->setText(QApplication::translate("MainWindow", "Automatique", 0, QApplication::UnicodeUTF8));
        pb_Test_Feux->setText(QApplication::translate("MainWindow", "TEST Feux", 0, QApplication::UnicodeUTF8));
        gb_Info_plage->setTitle(QApplication::translate("MainWindow", "Plages Horaires - Mode Automatique", 0, QApplication::UnicodeUTF8));
        l_info_fin->setText(QApplication::translate("MainWindow", "Fin", 0, QApplication::UnicodeUTF8));
        l_info_debut->setText(QApplication::translate("MainWindow", "D\303\251but", 0, QApplication::UnicodeUTF8));
        l_DateHeure->setText(QApplication::translate("MainWindow", "               DATE / HEURE", 0, QApplication::UnicodeUTF8));
        l_feu_1->setText(QApplication::translate("MainWindow", "Feu 1", 0, QApplication::UnicodeUTF8));
        l_feu_2->setText(QApplication::translate("MainWindow", "Feu 2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Feux Tricolores", 0, QApplication::UnicodeUTF8));
        l_F1Rouge->setText(QString());
        l_F1Vert->setText(QString());
        l_F2Rouge->setText(QString());
        l_F1Orange->setText(QString());
        l_F2Orange->setText(QString());
        l_F2Vert->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
