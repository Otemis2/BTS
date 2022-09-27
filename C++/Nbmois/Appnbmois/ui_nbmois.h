/********************************************************************************
** Form generated from reading UI file 'nbmois.ui'
**
** Created: Tue 22. Sep 18:58:25 2020
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NBMOIS_H
#define UI_NBMOIS_H

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

class Ui_Nbmois
{
public:
    QWidget *centralWidget;
    QPushButton *pbCalculer;
    QLineEdit *lENb;
    QLineEdit *lEMois;
    QLabel *lInformation;
    QLabel *lNb;
    QLabel *lEgal;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Nbmois)
    {
        if (Nbmois->objectName().isEmpty())
            Nbmois->setObjectName(QString::fromUtf8("Nbmois"));
        Nbmois->resize(400, 300);
        centralWidget = new QWidget(Nbmois);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pbCalculer = new QPushButton(centralWidget);
        pbCalculer->setObjectName(QString::fromUtf8("pbCalculer"));
        pbCalculer->setGeometry(QRect(160, 190, 75, 23));
        lENb = new QLineEdit(centralWidget);
        lENb->setObjectName(QString::fromUtf8("lENb"));
        lENb->setGeometry(QRect(60, 110, 113, 20));
        lEMois = new QLineEdit(centralWidget);
        lEMois->setObjectName(QString::fromUtf8("lEMois"));
        lEMois->setGeometry(QRect(220, 110, 113, 20));
        lInformation = new QLabel(centralWidget);
        lInformation->setObjectName(QString::fromUtf8("lInformation"));
        lInformation->setGeometry(QRect(140, 40, 121, 16));
        lNb = new QLabel(centralWidget);
        lNb->setObjectName(QString::fromUtf8("lNb"));
        lNb->setGeometry(QRect(10, 110, 46, 13));
        lEgal = new QLabel(centralWidget);
        lEgal->setObjectName(QString::fromUtf8("lEgal"));
        lEgal->setGeometry(QRect(190, 110, 46, 13));
        Nbmois->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Nbmois);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        Nbmois->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Nbmois);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Nbmois->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Nbmois);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Nbmois->setStatusBar(statusBar);

        retranslateUi(Nbmois);

        QMetaObject::connectSlotsByName(Nbmois);
    } // setupUi

    void retranslateUi(QMainWindow *Nbmois)
    {
        Nbmois->setWindowTitle(QApplication::translate("Nbmois", "Nbmois", 0, QApplication::UnicodeUTF8));
        pbCalculer->setText(QApplication::translate("Nbmois", "Calculer", 0, QApplication::UnicodeUTF8));
        lInformation->setText(QApplication::translate("Nbmois", "Veuiller saisir un nombre", 0, QApplication::UnicodeUTF8));
        lNb->setText(QApplication::translate("Nbmois", "Nombre : ", 0, QApplication::UnicodeUTF8));
        lEgal->setText(QApplication::translate("Nbmois", "=", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Nbmois: public Ui_Nbmois {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NBMOIS_H
