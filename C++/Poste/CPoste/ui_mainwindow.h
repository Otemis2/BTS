/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 11. Feb 09:45:31 2021
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
#include <QtGui/QRadioButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pBEnvoyer;
    QPushButton *pBValider;
    QLabel *lInformation;
    QLabel *lAffranchissement;
    QLabel *lInfoNombre;
    QLabel *lInfoPoids;
    QLabel *lInfoPrix;
    QLabel *lInfoPrixTotal;
    QLabel *lNombre;
    QLabel *lPoids;
    QLabel *lInfoType;
    QLabel *lType;
    QLabel *lPrix;
    QLabel *lPrixTotal;
    QLabel *lTypeColis;
    QSplitter *splitter_6;
    QRadioButton *rBSuivis;
    QRadioButton *rBVerte;
    QRadioButton *rBRecommander;
    QRadioButton *rBPrioritaire;
    QLabel *lPoids_2;
    QLabel *lPoidsColis;
    QLineEdit *lEPoids;
    QLabel *lRecapitulatif;
    QLabel *lNumColis;
    QLineEdit *lENombreColis;
    QLabel *lNbColis;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(461, 365);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pBEnvoyer = new QPushButton(centralWidget);
        pBEnvoyer->setObjectName(QString::fromUtf8("pBEnvoyer"));
        pBEnvoyer->setGeometry(QRect(110, 80, 75, 23));
        pBValider = new QPushButton(centralWidget);
        pBValider->setObjectName(QString::fromUtf8("pBValider"));
        pBValider->setGeometry(QRect(170, 280, 75, 23));
        lInformation = new QLabel(centralWidget);
        lInformation->setObjectName(QString::fromUtf8("lInformation"));
        lInformation->setGeometry(QRect(220, 0, 51, 16));
        lAffranchissement = new QLabel(centralWidget);
        lAffranchissement->setObjectName(QString::fromUtf8("lAffranchissement"));
        lAffranchissement->setGeometry(QRect(280, 20, 101, 16));
        lInfoNombre = new QLabel(centralWidget);
        lInfoNombre->setObjectName(QString::fromUtf8("lInfoNombre"));
        lInfoNombre->setGeometry(QRect(280, 40, 101, 16));
        lInfoPoids = new QLabel(centralWidget);
        lInfoPoids->setObjectName(QString::fromUtf8("lInfoPoids"));
        lInfoPoids->setGeometry(QRect(30, 210, 101, 16));
        lInfoPrix = new QLabel(centralWidget);
        lInfoPrix->setObjectName(QString::fromUtf8("lInfoPrix"));
        lInfoPrix->setGeometry(QRect(30, 250, 81, 16));
        lInfoPrixTotal = new QLabel(centralWidget);
        lInfoPrixTotal->setObjectName(QString::fromUtf8("lInfoPrixTotal"));
        lInfoPrixTotal->setGeometry(QRect(280, 60, 121, 16));
        lNombre = new QLabel(centralWidget);
        lNombre->setObjectName(QString::fromUtf8("lNombre"));
        lNombre->setGeometry(QRect(370, 40, 46, 13));
        lPoids = new QLabel(centralWidget);
        lPoids->setObjectName(QString::fromUtf8("lPoids"));
        lPoids->setGeometry(QRect(110, 210, 71, 16));
        lInfoType = new QLabel(centralWidget);
        lInfoType->setObjectName(QString::fromUtf8("lInfoType"));
        lInfoType->setGeometry(QRect(30, 230, 81, 16));
        lType = new QLabel(centralWidget);
        lType->setObjectName(QString::fromUtf8("lType"));
        lType->setGeometry(QRect(110, 230, 46, 13));
        lPrix = new QLabel(centralWidget);
        lPrix->setObjectName(QString::fromUtf8("lPrix"));
        lPrix->setGeometry(QRect(110, 250, 46, 13));
        lPrixTotal = new QLabel(centralWidget);
        lPrixTotal->setObjectName(QString::fromUtf8("lPrixTotal"));
        lPrixTotal->setGeometry(QRect(400, 60, 46, 13));
        lTypeColis = new QLabel(centralWidget);
        lTypeColis->setObjectName(QString::fromUtf8("lTypeColis"));
        lTypeColis->setGeometry(QRect(280, 110, 145, 33));
        splitter_6 = new QSplitter(centralWidget);
        splitter_6->setObjectName(QString::fromUtf8("splitter_6"));
        splitter_6->setGeometry(QRect(280, 140, 125, 72));
        splitter_6->setOrientation(Qt::Vertical);
        rBSuivis = new QRadioButton(splitter_6);
        rBSuivis->setObjectName(QString::fromUtf8("rBSuivis"));
        splitter_6->addWidget(rBSuivis);
        rBVerte = new QRadioButton(splitter_6);
        rBVerte->setObjectName(QString::fromUtf8("rBVerte"));
        splitter_6->addWidget(rBVerte);
        rBRecommander = new QRadioButton(splitter_6);
        rBRecommander->setObjectName(QString::fromUtf8("rBRecommander"));
        splitter_6->addWidget(rBRecommander);
        rBPrioritaire = new QRadioButton(splitter_6);
        rBPrioritaire->setObjectName(QString::fromUtf8("rBPrioritaire"));
        splitter_6->addWidget(rBPrioritaire);
        lPoids_2 = new QLabel(centralWidget);
        lPoids_2->setObjectName(QString::fromUtf8("lPoids_2"));
        lPoids_2->setGeometry(QRect(190, 210, 46, 13));
        lPoidsColis = new QLabel(centralWidget);
        lPoidsColis->setObjectName(QString::fromUtf8("lPoidsColis"));
        lPoidsColis->setGeometry(QRect(20, 120, 238, 15));
        lEPoids = new QLineEdit(centralWidget);
        lEPoids->setObjectName(QString::fromUtf8("lEPoids"));
        lEPoids->setGeometry(QRect(100, 140, 91, 21));
        lRecapitulatif = new QLabel(centralWidget);
        lRecapitulatif->setObjectName(QString::fromUtf8("lRecapitulatif"));
        lRecapitulatif->setGeometry(QRect(30, 180, 218, 16));
        lNumColis = new QLabel(centralWidget);
        lNumColis->setObjectName(QString::fromUtf8("lNumColis"));
        lNumColis->setGeometry(QRect(150, 180, 121, 20));
        lENombreColis = new QLineEdit(centralWidget);
        lENombreColis->setObjectName(QString::fromUtf8("lENombreColis"));
        lENombreColis->setGeometry(QRect(120, 40, 61, 22));
        lNbColis = new QLabel(centralWidget);
        lNbColis->setObjectName(QString::fromUtf8("lNbColis"));
        lNbColis->setGeometry(QRect(70, 20, 156, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 461, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Poste", 0, QApplication::UnicodeUTF8));
        pBEnvoyer->setText(QApplication::translate("MainWindow", "Envoyer", 0, QApplication::UnicodeUTF8));
        pBValider->setText(QApplication::translate("MainWindow", "Valider", 0, QApplication::UnicodeUTF8));
        lInformation->setText(QApplication::translate("MainWindow", "La Poste", 0, QApplication::UnicodeUTF8));
        lAffranchissement->setText(QApplication::translate("MainWindow", "Affranchissement : ", 0, QApplication::UnicodeUTF8));
        lInfoNombre->setText(QApplication::translate("MainWindow", "Nombre de Colis :", 0, QApplication::UnicodeUTF8));
        lInfoPoids->setText(QApplication::translate("MainWindow", "Poids du Colis :", 0, QApplication::UnicodeUTF8));
        lInfoPrix->setText(QApplication::translate("MainWindow", "Prix du Colis :", 0, QApplication::UnicodeUTF8));
        lInfoPrixTotal->setText(QApplication::translate("MainWindow", "Prix total du/des Colis :", 0, QApplication::UnicodeUTF8));
        lNombre->setText(QString());
        lPoids->setText(QString());
        lInfoType->setText(QApplication::translate("MainWindow", "Type de Colis :", 0, QApplication::UnicodeUTF8));
        lType->setText(QString());
        lPrix->setText(QString());
        lPrixTotal->setText(QString());
        lTypeColis->setText(QApplication::translate("MainWindow", "Veuillez saisir le type de colis : ", 0, QApplication::UnicodeUTF8));
        rBSuivis->setText(QApplication::translate("MainWindow", "Lettre Suivis", 0, QApplication::UnicodeUTF8));
        rBVerte->setText(QApplication::translate("MainWindow", "Lettre Verte", 0, QApplication::UnicodeUTF8));
        rBRecommander->setText(QApplication::translate("MainWindow", "Lettre Recommand\303\251e", 0, QApplication::UnicodeUTF8));
        rBPrioritaire->setText(QApplication::translate("MainWindow", "Lettre Prioritaire", 0, QApplication::UnicodeUTF8));
        lPoids_2->setText(QApplication::translate("MainWindow", "gramme", 0, QApplication::UnicodeUTF8));
        lPoidsColis->setText(QApplication::translate("MainWindow", "Veuillez saisir le poids de votre colis (en gramme) :", 0, QApplication::UnicodeUTF8));
        lRecapitulatif->setText(QApplication::translate("MainWindow", "Recapitulatif du colis n' :", 0, QApplication::UnicodeUTF8));
        lNumColis->setText(QString());
        lNbColis->setText(QApplication::translate("MainWindow", "Veuillez saisir le nombre de colis :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
