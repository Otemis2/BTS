/*
#-----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du programme feux tri colore
# Auteur : HUCK
# Cr�ation : 27/10/2021
# Mise � jour :
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
