/********************************************************************************
** Form generated from reading UI file 'qmainwindowmorse.ui'
**
** Created: Fri 1. Oct 21:18:33 2021
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMAINWINDOWMORSE_H
#define UI_QMAINWINDOWMORSE_H

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

class Ui_QMainWindowMorse
{
public:
    QWidget *centralWidget;
    QLabel *l_MessageClair;
    QLineEdit *lE_MessageClair;
    QPushButton *pBCode;
    QPushButton *pBDecoder;
    QPushButton *pBQuitter;
    QLineEdit *lE_MessageCoder;
    QLabel *l_MessageCoder;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QMainWindowMorse)
    {
        if (QMainWindowMorse->objectName().isEmpty())
            QMainWindowMorse->setObjectName(QString::fromUtf8("QMainWindowMorse"));
        QMainWindowMorse->resize(791, 507);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QMainWindowMorse->setWindowIcon(icon);
        centralWidget = new QWidget(QMainWindowMorse);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        l_MessageClair = new QLabel(centralWidget);
        l_MessageClair->setObjectName(QString::fromUtf8("l_MessageClair"));
        l_MessageClair->setGeometry(QRect(120, 90, 251, 31));
        QFont font;
        font.setPointSize(16);
        l_MessageClair->setFont(font);
        lE_MessageClair = new QLineEdit(centralWidget);
        lE_MessageClair->setObjectName(QString::fromUtf8("lE_MessageClair"));
        lE_MessageClair->setGeometry(QRect(280, 70, 321, 61));
        pBCode = new QPushButton(centralWidget);
        pBCode->setObjectName(QString::fromUtf8("pBCode"));
        pBCode->setGeometry(QRect(50, 330, 191, 91));
        pBCode->setFont(font);
        pBDecoder = new QPushButton(centralWidget);
        pBDecoder->setObjectName(QString::fromUtf8("pBDecoder"));
        pBDecoder->setGeometry(QRect(300, 330, 221, 91));
        pBDecoder->setFont(font);
        pBQuitter = new QPushButton(centralWidget);
        pBQuitter->setObjectName(QString::fromUtf8("pBQuitter"));
        pBQuitter->setGeometry(QRect(570, 330, 191, 91));
        pBQuitter->setFont(font);
        lE_MessageCoder = new QLineEdit(centralWidget);
        lE_MessageCoder->setObjectName(QString::fromUtf8("lE_MessageCoder"));
        lE_MessageCoder->setGeometry(QRect(280, 180, 321, 61));
        l_MessageCoder = new QLabel(centralWidget);
        l_MessageCoder->setObjectName(QString::fromUtf8("l_MessageCoder"));
        l_MessageCoder->setGeometry(QRect(80, 200, 251, 31));
        l_MessageCoder->setFont(font);
        QMainWindowMorse->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QMainWindowMorse);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 791, 20));
        QMainWindowMorse->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QMainWindowMorse);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QMainWindowMorse->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QMainWindowMorse);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QMainWindowMorse->setStatusBar(statusBar);

        retranslateUi(QMainWindowMorse);

        QMetaObject::connectSlotsByName(QMainWindowMorse);
    } // setupUi

    void retranslateUi(QMainWindow *QMainWindowMorse)
    {
        QMainWindowMorse->setWindowTitle(QApplication::translate("QMainWindowMorse", "AppMorse", 0, QApplication::UnicodeUTF8));
        l_MessageClair->setText(QApplication::translate("QMainWindowMorse", "Message clair :", 0, QApplication::UnicodeUTF8));
        lE_MessageClair->setText(QString());
        pBCode->setText(QApplication::translate("QMainWindowMorse", "coder le message", 0, QApplication::UnicodeUTF8));
        pBDecoder->setText(QApplication::translate("QMainWindowMorse", "Decoder le message", 0, QApplication::UnicodeUTF8));
        pBQuitter->setText(QApplication::translate("QMainWindowMorse", "Quitter", 0, QApplication::UnicodeUTF8));
        lE_MessageCoder->setText(QString());
        l_MessageCoder->setText(QApplication::translate("QMainWindowMorse", "Message de/coder :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QMainWindowMorse: public Ui_QMainWindowMorse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMAINWINDOWMORSE_H
