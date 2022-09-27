/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 15. Oct 09:00:30 2021
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
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
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
    QPushButton *pb_Raz;
    QPushButton *pb_Arreter;
    QLabel *label;
    QPushButton *pb_demarer;
    QLabel *label_2;
    QLCDNumber *lcd_Chronometre;
    QPushButton *pb_inc1;
    QPushButton *pb_Quitter;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(371, 296);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pb_Raz = new QPushButton(centralWidget);
        pb_Raz->setObjectName(QString::fromUtf8("pb_Raz"));
        pb_Raz->setGeometry(QRect(50, 140, 75, 23));
        pb_Arreter = new QPushButton(centralWidget);
        pb_Arreter->setObjectName(QString::fromUtf8("pb_Arreter"));
        pb_Arreter->setGeometry(QRect(240, 140, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, -10, 121, 51));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pb_demarer = new QPushButton(centralWidget);
        pb_demarer->setObjectName(QString::fromUtf8("pb_demarer"));
        pb_demarer->setGeometry(QRect(150, 140, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 30, 211, 20));
        lcd_Chronometre = new QLCDNumber(centralWidget);
        lcd_Chronometre->setObjectName(QString::fromUtf8("lcd_Chronometre"));
        lcd_Chronometre->setGeometry(QRect(60, 60, 241, 71));
        pb_inc1 = new QPushButton(centralWidget);
        pb_inc1->setObjectName(QString::fromUtf8("pb_inc1"));
        pb_inc1->setGeometry(QRect(120, 170, 111, 23));
        pb_Quitter = new QPushButton(centralWidget);
        pb_Quitter->setObjectName(QString::fromUtf8("pb_Quitter"));
        pb_Quitter->setGeometry(QRect(140, 200, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 371, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Chronometre", 0, QApplication::UnicodeUTF8));
        pb_Raz->setText(QApplication::translate("MainWindow", "RaZ", 0, QApplication::UnicodeUTF8));
        pb_Arreter->setText(QApplication::translate("MainWindow", "Arr\303\252ter", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Chronom\303\250tre", 0, QApplication::UnicodeUTF8));
        pb_demarer->setText(QApplication::translate("MainWindow", "D\303\251marer", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Utilisation d'un Timer avec la classe QTimer()", 0, QApplication::UnicodeUTF8));
        pb_inc1->setText(QApplication::translate("MainWindow", "Temporisation 10s", 0, QApplication::UnicodeUTF8));
        pb_Quitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
