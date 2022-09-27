#include <QtGui/QApplication>
#include "qmainwindowmorse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindowMorse w;
    w.show();
    
    return a.exec();
}
