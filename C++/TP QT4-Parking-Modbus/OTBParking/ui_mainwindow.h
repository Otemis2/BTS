/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 11. Dec 11:32:47 2021
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
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBoxEntree;
    QPushButton *BP_OuvrirEntree;
    QPushButton *BP_FermerEntree;
    QSlider *VS_Entree;
    QGroupBox *groupBoxSortie;
    QPushButton *BP_OuvrirSortie;
    QSlider *VS_Sortie;
    QPushButton *BP_FermerSortie;
    QRadioButton *ArretUrgence;
    QGroupBox *groupBoxPresVehicules;
    QRadioButton *E_Entree;
    QRadioButton *S_Entree;
    QRadioButton *E_Sortie;
    QRadioButton *S_Sortie;
    QLabel *L_Entree;
    QLabel *L_Sortie;
    QGroupBox *groupBoxRegOTB;
    QLabel *L_RegSortie;
    QLineEdit *LE_RegSortie;
    QLabel *L_RegEntree;
    QLineEdit *LE_RegEntree;
    QGroupBox *groupBoxModOTB;
    QCheckBox *EtatConnexionOTB;
    QLabel *L_InfoAdresseIP;
    QLabel *L_InfoPort;
    QLineEdit *LE_AdresseIP;
    QLineEdit *LE_Port;
    QPushButton *BP_Connexion;
    QPushButton *BP_Deconnexion;
    QLabel *L_IP;
    QLabel *L_Port;
    QLabel *L_Etat;
    QPushButton *BP_Lire_Entree;
    QPushButton *BP_Auto;
    QLabel *L_Automatique;
    QLabel *L_Copyright;
    QLCDNumber *LCD_Place;
    QPushButton *BP_Quitter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(897, 444);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBoxEntree = new QGroupBox(centralWidget);
        groupBoxEntree->setObjectName(QString::fromUtf8("groupBoxEntree"));
        groupBoxEntree->setGeometry(QRect(10, 10, 181, 141));
        BP_OuvrirEntree = new QPushButton(groupBoxEntree);
        BP_OuvrirEntree->setObjectName(QString::fromUtf8("BP_OuvrirEntree"));
        BP_OuvrirEntree->setEnabled(true);
        BP_OuvrirEntree->setGeometry(QRect(20, 30, 75, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        BP_OuvrirEntree->setFont(font);
        BP_OuvrirEntree->setStyleSheet(QString::fromUtf8("color: rgb(255, 58, 58);"));
        BP_OuvrirEntree->setAutoDefault(false);
        BP_OuvrirEntree->setDefault(false);
        BP_OuvrirEntree->setFlat(false);
        BP_FermerEntree = new QPushButton(groupBoxEntree);
        BP_FermerEntree->setObjectName(QString::fromUtf8("BP_FermerEntree"));
        BP_FermerEntree->setEnabled(false);
        BP_FermerEntree->setGeometry(QRect(20, 100, 75, 23));
        BP_FermerEntree->setFont(font);
        BP_FermerEntree->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);\n"
""));
        BP_FermerEntree->setFlat(false);
        VS_Entree = new QSlider(groupBoxEntree);
        VS_Entree->setObjectName(QString::fromUtf8("VS_Entree"));
        VS_Entree->setEnabled(false);
        VS_Entree->setGeometry(QRect(120, 30, 31, 91));
        VS_Entree->setMaximum(1);
        VS_Entree->setPageStep(1);
        VS_Entree->setValue(0);
        VS_Entree->setSliderPosition(0);
        VS_Entree->setOrientation(Qt::Vertical);
        groupBoxSortie = new QGroupBox(centralWidget);
        groupBoxSortie->setObjectName(QString::fromUtf8("groupBoxSortie"));
        groupBoxSortie->setGeometry(QRect(210, 10, 181, 141));
        BP_OuvrirSortie = new QPushButton(groupBoxSortie);
        BP_OuvrirSortie->setObjectName(QString::fromUtf8("BP_OuvrirSortie"));
        BP_OuvrirSortie->setEnabled(true);
        BP_OuvrirSortie->setGeometry(QRect(20, 30, 75, 23));
        BP_OuvrirSortie->setFont(font);
        BP_OuvrirSortie->setStyleSheet(QString::fromUtf8("color: rgb(255, 58, 58);\n"
""));
        BP_OuvrirSortie->setFlat(false);
        VS_Sortie = new QSlider(groupBoxSortie);
        VS_Sortie->setObjectName(QString::fromUtf8("VS_Sortie"));
        VS_Sortie->setEnabled(false);
        VS_Sortie->setGeometry(QRect(120, 30, 31, 91));
        VS_Sortie->setMaximum(1);
        VS_Sortie->setPageStep(1);
        VS_Sortie->setValue(0);
        VS_Sortie->setOrientation(Qt::Vertical);
        BP_FermerSortie = new QPushButton(groupBoxSortie);
        BP_FermerSortie->setObjectName(QString::fromUtf8("BP_FermerSortie"));
        BP_FermerSortie->setEnabled(false);
        BP_FermerSortie->setGeometry(QRect(20, 90, 75, 23));
        QPalette palette;
        QBrush brush(QColor(0, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        BP_FermerSortie->setPalette(palette);
        BP_FermerSortie->setFont(font);
        BP_FermerSortie->setStyleSheet(QString::fromUtf8("color: rgb(0, 255, 0);"));
        BP_FermerSortie->setDefault(false);
        BP_FermerSortie->setFlat(false);
        ArretUrgence = new QRadioButton(centralWidget);
        ArretUrgence->setObjectName(QString::fromUtf8("ArretUrgence"));
        ArretUrgence->setEnabled(false);
        ArretUrgence->setGeometry(QRect(430, 10, 191, 41));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        ArretUrgence->setFont(font1);
        ArretUrgence->setCheckable(true);
        groupBoxPresVehicules = new QGroupBox(centralWidget);
        groupBoxPresVehicules->setObjectName(QString::fromUtf8("groupBoxPresVehicules"));
        groupBoxPresVehicules->setGeometry(QRect(420, 50, 211, 101));
        E_Entree = new QRadioButton(groupBoxPresVehicules);
        E_Entree->setObjectName(QString::fromUtf8("E_Entree"));
        E_Entree->setEnabled(false);
        E_Entree->setGeometry(QRect(30, 30, 20, 20));
        E_Entree->setCheckable(true);
        E_Entree->setChecked(false);
        E_Entree->setAutoExclusive(false);
        S_Entree = new QRadioButton(groupBoxPresVehicules);
        S_Entree->setObjectName(QString::fromUtf8("S_Entree"));
        S_Entree->setEnabled(false);
        S_Entree->setGeometry(QRect(170, 30, 20, 20));
        S_Entree->setCheckable(true);
        S_Entree->setAutoExclusive(false);
        E_Sortie = new QRadioButton(groupBoxPresVehicules);
        E_Sortie->setObjectName(QString::fromUtf8("E_Sortie"));
        E_Sortie->setEnabled(false);
        E_Sortie->setGeometry(QRect(30, 70, 20, 20));
        E_Sortie->setCheckable(true);
        E_Sortie->setAutoExclusive(false);
        S_Sortie = new QRadioButton(groupBoxPresVehicules);
        S_Sortie->setObjectName(QString::fromUtf8("S_Sortie"));
        S_Sortie->setEnabled(false);
        S_Sortie->setGeometry(QRect(170, 70, 20, 20));
        S_Sortie->setCheckable(true);
        S_Sortie->setAutoExclusive(false);
        L_Entree = new QLabel(groupBoxPresVehicules);
        L_Entree->setObjectName(QString::fromUtf8("L_Entree"));
        L_Entree->setGeometry(QRect(70, 30, 71, 21));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        L_Entree->setFont(font2);
        L_Sortie = new QLabel(groupBoxPresVehicules);
        L_Sortie->setObjectName(QString::fromUtf8("L_Sortie"));
        L_Sortie->setGeometry(QRect(70, 70, 71, 21));
        L_Sortie->setFont(font2);
        groupBoxRegOTB = new QGroupBox(centralWidget);
        groupBoxRegOTB->setObjectName(QString::fromUtf8("groupBoxRegOTB"));
        groupBoxRegOTB->setGeometry(QRect(660, 50, 221, 121));
        L_RegSortie = new QLabel(groupBoxRegOTB);
        L_RegSortie->setObjectName(QString::fromUtf8("L_RegSortie"));
        L_RegSortie->setGeometry(QRect(20, 30, 81, 16));
        LE_RegSortie = new QLineEdit(groupBoxRegOTB);
        LE_RegSortie->setObjectName(QString::fromUtf8("LE_RegSortie"));
        LE_RegSortie->setGeometry(QRect(110, 30, 91, 21));
        LE_RegSortie->setMaxLength(4);
        LE_RegSortie->setAlignment(Qt::AlignCenter);
        LE_RegSortie->setReadOnly(true);
        L_RegEntree = new QLabel(groupBoxRegOTB);
        L_RegEntree->setObjectName(QString::fromUtf8("L_RegEntree"));
        L_RegEntree->setGeometry(QRect(20, 70, 81, 16));
        LE_RegEntree = new QLineEdit(groupBoxRegOTB);
        LE_RegEntree->setObjectName(QString::fromUtf8("LE_RegEntree"));
        LE_RegEntree->setGeometry(QRect(110, 70, 91, 21));
        LE_RegEntree->setMaxLength(4);
        LE_RegEntree->setAlignment(Qt::AlignCenter);
        groupBoxModOTB = new QGroupBox(centralWidget);
        groupBoxModOTB->setObjectName(QString::fromUtf8("groupBoxModOTB"));
        groupBoxModOTB->setGeometry(QRect(10, 170, 381, 161));
        EtatConnexionOTB = new QCheckBox(groupBoxModOTB);
        EtatConnexionOTB->setObjectName(QString::fromUtf8("EtatConnexionOTB"));
        EtatConnexionOTB->setEnabled(false);
        EtatConnexionOTB->setGeometry(QRect(90, 0, 16, 18));
        EtatConnexionOTB->setCheckable(true);
        L_InfoAdresseIP = new QLabel(groupBoxModOTB);
        L_InfoAdresseIP->setObjectName(QString::fromUtf8("L_InfoAdresseIP"));
        L_InfoAdresseIP->setGeometry(QRect(20, 30, 61, 16));
        L_InfoPort = new QLabel(groupBoxModOTB);
        L_InfoPort->setObjectName(QString::fromUtf8("L_InfoPort"));
        L_InfoPort->setGeometry(QRect(20, 90, 61, 16));
        LE_AdresseIP = new QLineEdit(groupBoxModOTB);
        LE_AdresseIP->setObjectName(QString::fromUtf8("LE_AdresseIP"));
        LE_AdresseIP->setGeometry(QRect(90, 30, 131, 20));
        LE_Port = new QLineEdit(groupBoxModOTB);
        LE_Port->setObjectName(QString::fromUtf8("LE_Port"));
        LE_Port->setGeometry(QRect(90, 90, 131, 20));
        BP_Connexion = new QPushButton(groupBoxModOTB);
        BP_Connexion->setObjectName(QString::fromUtf8("BP_Connexion"));
        BP_Connexion->setGeometry(QRect(260, 30, 75, 23));
        BP_Deconnexion = new QPushButton(groupBoxModOTB);
        BP_Deconnexion->setObjectName(QString::fromUtf8("BP_Deconnexion"));
        BP_Deconnexion->setEnabled(false);
        BP_Deconnexion->setGeometry(QRect(260, 90, 75, 23));
        L_IP = new QLabel(groupBoxModOTB);
        L_IP->setObjectName(QString::fromUtf8("L_IP"));
        L_IP->setGeometry(QRect(90, 60, 131, 16));
        L_Port = new QLabel(groupBoxModOTB);
        L_Port->setObjectName(QString::fromUtf8("L_Port"));
        L_Port->setGeometry(QRect(90, 120, 131, 16));
        L_Etat = new QLabel(centralWidget);
        L_Etat->setObjectName(QString::fromUtf8("L_Etat"));
        L_Etat->setGeometry(QRect(10, 340, 381, 16));
        BP_Lire_Entree = new QPushButton(centralWidget);
        BP_Lire_Entree->setObjectName(QString::fromUtf8("BP_Lire_Entree"));
        BP_Lire_Entree->setGeometry(QRect(480, 200, 91, 23));
        BP_Lire_Entree->setCheckable(false);
        BP_Auto = new QPushButton(centralWidget);
        BP_Auto->setObjectName(QString::fromUtf8("BP_Auto"));
        BP_Auto->setEnabled(true);
        BP_Auto->setGeometry(QRect(480, 250, 91, 23));
        L_Automatique = new QLabel(centralWidget);
        L_Automatique->setObjectName(QString::fromUtf8("L_Automatique"));
        L_Automatique->setEnabled(true);
        L_Automatique->setGeometry(QRect(500, 280, 61, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        L_Automatique->setFont(font3);
        L_Copyright = new QLabel(centralWidget);
        L_Copyright->setObjectName(QString::fromUtf8("L_Copyright"));
        L_Copyright->setGeometry(QRect(220, 400, 181, 20));
        LCD_Place = new QLCDNumber(centralWidget);
        LCD_Place->setObjectName(QString::fromUtf8("LCD_Place"));
        LCD_Place->setGeometry(QRect(670, 230, 191, 91));
        LCD_Place->setFrameShape(QFrame::NoFrame);
        LCD_Place->setSegmentStyle(QLCDNumber::Flat);
        LCD_Place->setProperty("value", QVariant(1000));
        LCD_Place->setProperty("intValue", QVariant(1000));
        BP_Quitter = new QPushButton(centralWidget);
        BP_Quitter->setObjectName(QString::fromUtf8("BP_Quitter"));
        BP_Quitter->setGeometry(QRect(170, 370, 75, 23));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBoxEntree->setTitle(QApplication::translate("MainWindow", "Barri\303\250re Entr\303\251e", 0, QApplication::UnicodeUTF8));
        BP_OuvrirEntree->setText(QApplication::translate("MainWindow", "Ouvrir", 0, QApplication::UnicodeUTF8));
        BP_FermerEntree->setText(QApplication::translate("MainWindow", "Fermer", 0, QApplication::UnicodeUTF8));
        groupBoxSortie->setTitle(QApplication::translate("MainWindow", "Barri\303\250re Sortie", 0, QApplication::UnicodeUTF8));
        BP_OuvrirSortie->setText(QApplication::translate("MainWindow", "Ouvrir", 0, QApplication::UnicodeUTF8));
        BP_FermerSortie->setText(QApplication::translate("MainWindow", "Fermer", 0, QApplication::UnicodeUTF8));
        ArretUrgence->setText(QApplication::translate("MainWindow", "     A .U.", 0, QApplication::UnicodeUTF8));
        groupBoxPresVehicules->setTitle(QApplication::translate("MainWindow", "Pr\303\251sence V\303\251hicules", 0, QApplication::UnicodeUTF8));
        E_Entree->setText(QString());
        S_Entree->setText(QString());
        E_Sortie->setText(QString());
        S_Sortie->setText(QString());
        L_Entree->setText(QApplication::translate("MainWindow", "Entree", 0, QApplication::UnicodeUTF8));
        L_Sortie->setText(QApplication::translate("MainWindow", "Sortie", 0, QApplication::UnicodeUTF8));
        groupBoxRegOTB->setTitle(QApplication::translate("MainWindow", "Registres OTB", 0, QApplication::UnicodeUTF8));
        L_RegSortie->setText(QApplication::translate("MainWindow", "Sortie @ (0100)", 0, QApplication::UnicodeUTF8));
        LE_RegSortie->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        L_RegEntree->setText(QApplication::translate("MainWindow", "Entree @ (0000)", 0, QApplication::UnicodeUTF8));
        LE_RegEntree->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBoxModOTB->setTitle(QApplication::translate("MainWindow", "Module OTB E/S", 0, QApplication::UnicodeUTF8));
        EtatConnexionOTB->setText(QString());
        L_InfoAdresseIP->setText(QApplication::translate("MainWindow", "Adresse IP", 0, QApplication::UnicodeUTF8));
        L_InfoPort->setText(QApplication::translate("MainWindow", "Port", 0, QApplication::UnicodeUTF8));
        BP_Connexion->setText(QApplication::translate("MainWindow", "Connexion", 0, QApplication::UnicodeUTF8));
        BP_Deconnexion->setText(QApplication::translate("MainWindow", "D\303\251connexion", 0, QApplication::UnicodeUTF8));
        L_IP->setText(QString());
        L_Port->setText(QString());
        L_Etat->setText(QString());
        BP_Lire_Entree->setText(QApplication::translate("MainWindow", "Lire Entr\303\251es", 0, QApplication::UnicodeUTF8));
        BP_Auto->setText(QApplication::translate("MainWindow", "Automatique", 0, QApplication::UnicodeUTF8));
        L_Automatique->setText(QString());
        L_Copyright->setText(QApplication::translate("MainWindow", "Copyright HUCK Sylvain- 2021-2022", 0, QApplication::UnicodeUTF8));
        BP_Quitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
