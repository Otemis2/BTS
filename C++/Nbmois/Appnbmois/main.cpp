#include <QtGui/QApplication>
#include "nbmois.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Nbmois w;
    w.show();
    
    return a.exec();
}
