/*
#-----------------------------------------------------------------------
# Nom : main.cpp
# Sujet :
# Auteur : HUCK
# Cr�ation : 11/12/2021
# Mise � jour : 11/12/2021
# -----------------------------------------------------------------------------------------------------------
*/
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
