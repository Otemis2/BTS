#include <QtGui/QApplication>
#include "appsigne.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Appsigne w;
    w.show();
    
    return a.exec();
}
