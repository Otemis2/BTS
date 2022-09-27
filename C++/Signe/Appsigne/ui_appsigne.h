/********************************************************************************
** Form generated from reading UI file 'appsigne.ui'
**
** Created: Tue 22. Sep 10:25:28 2020
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPSIGNE_H
#define UI_APPSIGNE_H

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

class Ui_Appsigne
{
public:
    QWidget *centralWidget;
    QLabel *linformation;
    QLineEdit *lENb1;
    QLabel *lEgal;
    QLineEdit *lESigne;
    QLabel *lNb1;
    QPushButton *pbCalculer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Appsigne)
    {
        if (Appsigne->objectName().isEmpty())
            Appsigne->setObjectName(QString::fromUtf8("Appsigne"));
        Appsigne->resize(443, 332);
        centralWidget = new QWidget(Appsigne);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        linformation = new QLabel(centralWidget);
        linformation->setObjectName(QString::fromUtf8("linformation"));
        linformation->setGeometry(QRect(150, 20, 121, 31));
        lENb1 = new QLineEdit(centralWidget);
        lENb1->setObjectName(QString::fromUtf8("lENb1"));
        lENb1->setGeometry(QRect(150, 80, 113, 20));
        lEgal = new QLabel(centralWidget);
        lEgal->setObjectName(QString::fromUtf8("lEgal"));
        lEgal->setGeometry(QRect(200, 130, 46, 13));
        lESigne = new QLineEdit(centralWidget);
        lESigne->setObjectName(QString::fromUtf8("lESigne"));
        lESigne->setGeometry(QRect(140, 150, 131, 21));
        lNb1 = new QLabel(centralWidget);
        lNb1->setObjectName(QString::fromUtf8("lNb1"));
        lNb1->setGeometry(QRect(100, 80, 46, 13));
        pbCalculer = new QPushButton(centralWidget);
        pbCalculer->setObjectName(QString::fromUtf8("pbCalculer"));
        pbCalculer->setGeometry(QRect(170, 210, 75, 23));
        Appsigne->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Appsigne);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 443, 20));
        Appsigne->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Appsigne);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Appsigne->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Appsigne);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Appsigne->setStatusBar(statusBar);

        retranslateUi(Appsigne);

        QMetaObject::connectSlotsByName(Appsigne);
    } // setupUi

    void retranslateUi(QMainWindow *Appsigne)
    {
        Appsigne->setWindowTitle(QApplication::translate("Appsigne", "Appsigne", 0, QApplication::UnicodeUTF8));
        linformation->setText(QApplication::translate("Appsigne", "Veuiller saisir le nombre", 0, QApplication::UnicodeUTF8));
        lEgal->setText(QApplication::translate("Appsigne", "=", 0, QApplication::UnicodeUTF8));
        lESigne->setText(QString());
        lNb1->setText(QApplication::translate("Appsigne", "Nombre :", 0, QApplication::UnicodeUTF8));
        pbCalculer->setText(QApplication::translate("Appsigne", "Calculer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Appsigne: public Ui_Appsigne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPSIGNE_H
