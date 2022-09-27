/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 5. Nov 15:20:05 2020
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
#include <QtGui/QMenu>
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
    QLabel *lInformation;
    QLabel *lSaisirA;
    QLineEdit *lEA;
    QLabel *lSaisirB;
    QLineEdit *lEB;
    QLabel *lSaisirC;
    QLineEdit *lEC;
    QLabel *lX1;
    QLabel *lX2;
    QLabel *lDelta;
    QLabel *lX1_2;
    QLabel *lX2_2;
    QLabel *lDelta_2;
    QLineEdit *lE;
    QPushButton *pBCalculer;
    QPushButton *pBQuitter;
    QMenuBar *menuBar;
    QMenu *menuEquation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(610, 356);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lInformation = new QLabel(centralWidget);
        lInformation->setObjectName(QString::fromUtf8("lInformation"));
        lInformation->setGeometry(QRect(180, 0, 241, 31));
        lSaisirA = new QLabel(centralWidget);
        lSaisirA->setObjectName(QString::fromUtf8("lSaisirA"));
        lSaisirA->setGeometry(QRect(30, 60, 46, 13));
        lEA = new QLineEdit(centralWidget);
        lEA->setObjectName(QString::fromUtf8("lEA"));
        lEA->setGeometry(QRect(80, 60, 71, 20));
        lSaisirB = new QLabel(centralWidget);
        lSaisirB->setObjectName(QString::fromUtf8("lSaisirB"));
        lSaisirB->setGeometry(QRect(210, 60, 46, 13));
        lEB = new QLineEdit(centralWidget);
        lEB->setObjectName(QString::fromUtf8("lEB"));
        lEB->setGeometry(QRect(260, 60, 81, 20));
        lSaisirC = new QLabel(centralWidget);
        lSaisirC->setObjectName(QString::fromUtf8("lSaisirC"));
        lSaisirC->setGeometry(QRect(380, 60, 46, 13));
        lEC = new QLineEdit(centralWidget);
        lEC->setObjectName(QString::fromUtf8("lEC"));
        lEC->setGeometry(QRect(430, 60, 113, 20));
        lX1 = new QLabel(centralWidget);
        lX1->setObjectName(QString::fromUtf8("lX1"));
        lX1->setGeometry(QRect(30, 120, 46, 13));
        lX2 = new QLabel(centralWidget);
        lX2->setObjectName(QString::fromUtf8("lX2"));
        lX2->setGeometry(QRect(30, 150, 46, 13));
        lDelta = new QLabel(centralWidget);
        lDelta->setObjectName(QString::fromUtf8("lDelta"));
        lDelta->setGeometry(QRect(20, 180, 46, 13));
        lX1_2 = new QLabel(centralWidget);
        lX1_2->setObjectName(QString::fromUtf8("lX1_2"));
        lX1_2->setGeometry(QRect(70, 120, 61, 16));
        lX2_2 = new QLabel(centralWidget);
        lX2_2->setObjectName(QString::fromUtf8("lX2_2"));
        lX2_2->setGeometry(QRect(65, 150, 61, 16));
        lDelta_2 = new QLabel(centralWidget);
        lDelta_2->setObjectName(QString::fromUtf8("lDelta_2"));
        lDelta_2->setGeometry(QRect(70, 180, 46, 13));
        lE = new QLineEdit(centralWidget);
        lE->setObjectName(QString::fromUtf8("lE"));
        lE->setGeometry(QRect(150, 210, 281, 21));
        pBCalculer = new QPushButton(centralWidget);
        pBCalculer->setObjectName(QString::fromUtf8("pBCalculer"));
        pBCalculer->setGeometry(QRect(200, 260, 75, 23));
        pBQuitter = new QPushButton(centralWidget);
        pBQuitter->setObjectName(QString::fromUtf8("pBQuitter"));
        pBQuitter->setGeometry(QRect(290, 260, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 610, 20));
        menuEquation = new QMenu(menuBar);
        menuEquation->setObjectName(QString::fromUtf8("menuEquation"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuEquation->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        lInformation->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Resolveur d'Equation du second degr\303\251e</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        lSaisirA->setText(QApplication::translate("MainWindow", "Saisir A :", 0, QApplication::UnicodeUTF8));
        lSaisirB->setText(QApplication::translate("MainWindow", "Saisir B :", 0, QApplication::UnicodeUTF8));
        lSaisirC->setText(QApplication::translate("MainWindow", "Saisir C :", 0, QApplication::UnicodeUTF8));
        lX1->setText(QApplication::translate("MainWindow", "x1 =", 0, QApplication::UnicodeUTF8));
        lX2->setText(QApplication::translate("MainWindow", "x2 =", 0, QApplication::UnicodeUTF8));
        lDelta->setText(QApplication::translate("MainWindow", "Delta =", 0, QApplication::UnicodeUTF8));
        lX1_2->setText(QString());
        lX2_2->setText(QString());
        lDelta_2->setText(QString());
        pBCalculer->setText(QApplication::translate("MainWindow", "Calculer", 0, QApplication::UnicodeUTF8));
        pBQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        menuEquation->setTitle(QApplication::translate("MainWindow", "Equation ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
