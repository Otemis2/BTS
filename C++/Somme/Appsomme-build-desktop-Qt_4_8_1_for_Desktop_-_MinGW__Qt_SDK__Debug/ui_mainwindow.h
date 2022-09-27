/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 8. Sep 11:17:02 2020
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
    QPushButton *pbCalculer;
    QLabel *linformation;
    QLabel *lNb1;
    QLabel *lNb2;
    QLabel *legal;
    QLabel *lplus;
    QLineEdit *lENb1;
    QLineEdit *lENb2;
    QLineEdit *lESomme;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pbCalculer = new QPushButton(centralWidget);
        pbCalculer->setObjectName(QString::fromUtf8("pbCalculer"));
        pbCalculer->setGeometry(QRect(150, 170, 75, 23));
        linformation = new QLabel(centralWidget);
        linformation->setObjectName(QString::fromUtf8("linformation"));
        linformation->setGeometry(QRect(140, 10, 121, 31));
        lNb1 = new QLabel(centralWidget);
        lNb1->setObjectName(QString::fromUtf8("lNb1"));
        lNb1->setGeometry(QRect(20, 100, 46, 13));
        lNb2 = new QLabel(centralWidget);
        lNb2->setObjectName(QString::fromUtf8("lNb2"));
        lNb2->setGeometry(QRect(120, 100, 46, 13));
        legal = new QLabel(centralWidget);
        legal->setObjectName(QString::fromUtf8("legal"));
        legal->setGeometry(QRect(210, 100, 46, 13));
        lplus = new QLabel(centralWidget);
        lplus->setObjectName(QString::fromUtf8("lplus"));
        lplus->setGeometry(QRect(110, 100, 46, 13));
        lENb1 = new QLineEdit(centralWidget);
        lENb1->setObjectName(QString::fromUtf8("lENb1"));
        lENb1->setGeometry(QRect(40, 100, 61, 21));
        lENb2 = new QLineEdit(centralWidget);
        lENb2->setObjectName(QString::fromUtf8("lENb2"));
        lENb2->setGeometry(QRect(140, 100, 61, 21));
        lESomme = new QLineEdit(centralWidget);
        lESomme->setObjectName(QString::fromUtf8("lESomme"));
        lESomme->setGeometry(QRect(230, 100, 61, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculer la somme de deux nombres", 0, QApplication::UnicodeUTF8));
        pbCalculer->setText(QApplication::translate("MainWindow", "Calculer", 0, QApplication::UnicodeUTF8));
        linformation->setText(QApplication::translate("MainWindow", "Veuiller saisir 2 nombres", 0, QApplication::UnicodeUTF8));
        lNb1->setText(QApplication::translate("MainWindow", "nb1", 0, QApplication::UnicodeUTF8));
        lNb2->setText(QApplication::translate("MainWindow", "nb2", 0, QApplication::UnicodeUTF8));
        legal->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        lplus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        lENb1->setText(QString());
        lENb2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
