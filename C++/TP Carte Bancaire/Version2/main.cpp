/*
#-----------------------------------------------------------------------
# Nom : main.cpp
# Sujet : programme console de test unitaire du programme cartebancaire
# Auteur : HUCK
# Création : 17/09/2021
# Mise à jour :
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
