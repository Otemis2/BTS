/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 19. Dec 12:04:14 2020
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pBCalculer;
    QLabel *lInformationGlobal;
    QSplitter *splitter;
    QLabel *lNbJourMois;
    QLineEdit *lENbJoursMois;
    QPushButton *pBSuivant;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lInfoTemp;
    QLabel *lNumJour;
    QLineEdit *lETemp;
    QPushButton *pBValider;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lInfoMoyenne;
    QLabel *lMoyenne;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lInfoNJF;
    QLabel *lNbJourFroid;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lInfoJLPF;
    QLabel *lIdJourLePlusFroid;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lTempFroide;
    QLabel *lInfoDegreeFroid;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lInfoNJC;
    QLabel *lNbJourChaud;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lInfoJLPC;
    QLabel *lIdJourLePlusChaud;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lTempChaude;
    QLabel *lInfoDegreeChaud;
    QPushButton *pBEnregistrer;
    QLabel *lInfoEnregister;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(408, 376);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pBCalculer = new QPushButton(centralWidget);
        pBCalculer->setObjectName(QString::fromUtf8("pBCalculer"));
        pBCalculer->setGeometry(QRect(160, 150, 75, 23));
        lInformationGlobal = new QLabel(centralWidget);
        lInformationGlobal->setObjectName(QString::fromUtf8("lInformationGlobal"));
        lInformationGlobal->setGeometry(QRect(30, 10, 351, 20));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(30, 40, 332, 23));
        splitter->setOrientation(Qt::Horizontal);
        lNbJourMois = new QLabel(splitter);
        lNbJourMois->setObjectName(QString::fromUtf8("lNbJourMois"));
        splitter->addWidget(lNbJourMois);
        lENbJoursMois = new QLineEdit(splitter);
        lENbJoursMois->setObjectName(QString::fromUtf8("lENbJoursMois"));
        splitter->addWidget(lENbJoursMois);
        pBSuivant = new QPushButton(splitter);
        pBSuivant->setObjectName(QString::fromUtf8("pBSuivant"));
        splitter->addWidget(pBSuivant);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(140, 70, 125, 72));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lInfoTemp = new QLabel(layoutWidget);
        lInfoTemp->setObjectName(QString::fromUtf8("lInfoTemp"));

        horizontalLayout->addWidget(lInfoTemp);

        lNumJour = new QLabel(layoutWidget);
        lNumJour->setObjectName(QString::fromUtf8("lNumJour"));

        horizontalLayout->addWidget(lNumJour);


        verticalLayout->addLayout(horizontalLayout);

        lETemp = new QLineEdit(layoutWidget);
        lETemp->setObjectName(QString::fromUtf8("lETemp"));

        verticalLayout->addWidget(lETemp);

        pBValider = new QPushButton(layoutWidget);
        pBValider->setObjectName(QString::fromUtf8("pBValider"));

        verticalLayout->addWidget(pBValider);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 180, 101, 16));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        lInfoMoyenne = new QLabel(layoutWidget1);
        lInfoMoyenne->setObjectName(QString::fromUtf8("lInfoMoyenne"));

        horizontalLayout_8->addWidget(lInfoMoyenne);

        lMoyenne = new QLabel(layoutWidget1);
        lMoyenne->setObjectName(QString::fromUtf8("lMoyenne"));

        horizontalLayout_8->addWidget(lMoyenne);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 220, 121, 61));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lInfoNJF = new QLabel(layoutWidget2);
        lInfoNJF->setObjectName(QString::fromUtf8("lInfoNJF"));

        horizontalLayout_2->addWidget(lInfoNJF);

        lNbJourFroid = new QLabel(layoutWidget2);
        lNbJourFroid->setObjectName(QString::fromUtf8("lNbJourFroid"));

        horizontalLayout_2->addWidget(lNbJourFroid);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lInfoJLPF = new QLabel(layoutWidget2);
        lInfoJLPF->setObjectName(QString::fromUtf8("lInfoJLPF"));

        horizontalLayout_4->addWidget(lInfoJLPF);

        lIdJourLePlusFroid = new QLabel(layoutWidget2);
        lIdJourLePlusFroid->setObjectName(QString::fromUtf8("lIdJourLePlusFroid"));

        horizontalLayout_4->addWidget(lIdJourLePlusFroid);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lTempFroide = new QLabel(layoutWidget2);
        lTempFroide->setObjectName(QString::fromUtf8("lTempFroide"));

        horizontalLayout_6->addWidget(lTempFroide);

        lInfoDegreeFroid = new QLabel(layoutWidget2);
        lInfoDegreeFroid->setObjectName(QString::fromUtf8("lInfoDegreeFroid"));

        horizontalLayout_6->addWidget(lInfoDegreeFroid);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_2);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(200, 220, 128, 61));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lInfoNJC = new QLabel(layoutWidget3);
        lInfoNJC->setObjectName(QString::fromUtf8("lInfoNJC"));

        horizontalLayout_3->addWidget(lInfoNJC);

        lNbJourChaud = new QLabel(layoutWidget3);
        lNbJourChaud->setObjectName(QString::fromUtf8("lNbJourChaud"));

        horizontalLayout_3->addWidget(lNbJourChaud);


        verticalLayout_5->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lInfoJLPC = new QLabel(layoutWidget3);
        lInfoJLPC->setObjectName(QString::fromUtf8("lInfoJLPC"));

        horizontalLayout_5->addWidget(lInfoJLPC);

        lIdJourLePlusChaud = new QLabel(layoutWidget3);
        lIdJourLePlusChaud->setObjectName(QString::fromUtf8("lIdJourLePlusChaud"));

        horizontalLayout_5->addWidget(lIdJourLePlusChaud);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lTempChaude = new QLabel(layoutWidget3);
        lTempChaude->setObjectName(QString::fromUtf8("lTempChaude"));

        horizontalLayout_7->addWidget(lTempChaude);

        lInfoDegreeChaud = new QLabel(layoutWidget3);
        lInfoDegreeChaud->setObjectName(QString::fromUtf8("lInfoDegreeChaud"));

        horizontalLayout_7->addWidget(lInfoDegreeChaud);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_5->addLayout(verticalLayout_3);

        pBEnregistrer = new QPushButton(centralWidget);
        pBEnregistrer->setObjectName(QString::fromUtf8("pBEnregistrer"));
        pBEnregistrer->setGeometry(QRect(270, 290, 75, 23));
        lInfoEnregister = new QLabel(centralWidget);
        lInfoEnregister->setObjectName(QString::fromUtf8("lInfoEnregister"));
        lInfoEnregister->setGeometry(QRect(220, 310, 181, 20));
        MainWindow->setCentralWidget(centralWidget);
        splitter->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        pBCalculer->raise();
        lInformationGlobal->raise();
        pBEnregistrer->raise();
        lInfoEnregister->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 408, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "M\303\251t\303\251o", 0, QApplication::UnicodeUTF8));
        pBCalculer->setText(QApplication::translate("MainWindow", "Calculer", 0, QApplication::UnicodeUTF8));
        lInformationGlobal->setText(QApplication::translate("MainWindow", "Bienvenue sur l'application m\303\251t\303\251o, veuillez saisir les valeurs demendez", 0, QApplication::UnicodeUTF8));
        lNbJourMois->setText(QApplication::translate("MainWindow", "Nombre de jours dans le mois :", 0, QApplication::UnicodeUTF8));
        pBSuivant->setText(QApplication::translate("MainWindow", "Suivant", 0, QApplication::UnicodeUTF8));
        lInfoTemp->setText(QApplication::translate("MainWindow", "Temp\303\251rature du jours :", 0, QApplication::UnicodeUTF8));
        lNumJour->setText(QString());
        pBValider->setText(QApplication::translate("MainWindow", "Valider", 0, QApplication::UnicodeUTF8));
        lInfoMoyenne->setText(QApplication::translate("MainWindow", "Moyenne :", 0, QApplication::UnicodeUTF8));
        lMoyenne->setText(QString());
        lInfoNJF->setText(QApplication::translate("MainWindow", "Nb Jours froid : ", 0, QApplication::UnicodeUTF8));
        lNbJourFroid->setText(QString());
        lInfoJLPF->setText(QApplication::translate("MainWindow", "Jour le plus froid, n\302\260 :", 0, QApplication::UnicodeUTF8));
        lIdJourLePlusFroid->setText(QString());
        lTempFroide->setText(QString());
        lInfoDegreeFroid->setText(QApplication::translate("MainWindow", "degree", 0, QApplication::UnicodeUTF8));
        lInfoNJC->setText(QApplication::translate("MainWindow", "Nb Jours chaud :", 0, QApplication::UnicodeUTF8));
        lNbJourChaud->setText(QString());
        lInfoJLPC->setText(QApplication::translate("MainWindow", "Jour le plus chaud, n\302\260 :", 0, QApplication::UnicodeUTF8));
        lIdJourLePlusChaud->setText(QString());
        lTempChaude->setText(QString());
        lInfoDegreeChaud->setText(QApplication::translate("MainWindow", "degree", 0, QApplication::UnicodeUTF8));
        pBEnregistrer->setText(QApplication::translate("MainWindow", "Enregistrer", 0, QApplication::UnicodeUTF8));
        lInfoEnregister->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
