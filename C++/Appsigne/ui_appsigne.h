/********************************************************************************
** Form generated from reading UI file 'appsigne.ui'
**
** Created: Wed 16. Dec 12:46:44 2020
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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Appsigne
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lnbJourMois;
    QLineEdit *lENbJourMois;
    QPushButton *pbSuivant;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *lTemp;
    QLineEdit *lETemp;
    QPushButton *pBValider;
    QLineEdit *laff;
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
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 112, 70));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lnbJourMois = new QLabel(layoutWidget);
        lnbJourMois->setObjectName(QString::fromUtf8("lnbJourMois"));

        verticalLayout->addWidget(lnbJourMois);

        lENbJourMois = new QLineEdit(layoutWidget);
        lENbJourMois->setObjectName(QString::fromUtf8("lENbJourMois"));

        verticalLayout->addWidget(lENbJourMois);

        pbSuivant = new QPushButton(layoutWidget);
        pbSuivant->setObjectName(QString::fromUtf8("pbSuivant"));

        verticalLayout->addWidget(pbSuivant);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 60, 112, 70));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lTemp = new QLabel(layoutWidget1);
        lTemp->setObjectName(QString::fromUtf8("lTemp"));

        verticalLayout_2->addWidget(lTemp);

        lETemp = new QLineEdit(layoutWidget1);
        lETemp->setObjectName(QString::fromUtf8("lETemp"));

        verticalLayout_2->addWidget(lETemp);

        pBValider = new QPushButton(layoutWidget1);
        pBValider->setObjectName(QString::fromUtf8("pBValider"));

        verticalLayout_2->addWidget(pBValider);

        laff = new QLineEdit(centralWidget);
        laff->setObjectName(QString::fromUtf8("laff"));
        laff->setGeometry(QRect(50, 150, 113, 20));
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
        lnbJourMois->setText(QApplication::translate("Appsigne", "Jours dans le mois", 0, QApplication::UnicodeUTF8));
        pbSuivant->setText(QApplication::translate("Appsigne", "Suivant", 0, QApplication::UnicodeUTF8));
        lTemp->setText(QApplication::translate("Appsigne", "Temp :", 0, QApplication::UnicodeUTF8));
        lETemp->setText(QString());
        pBValider->setText(QApplication::translate("Appsigne", "Valider", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Appsigne: public Ui_Appsigne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPSIGNE_H
