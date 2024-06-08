#include "Mapa2.h"
#include "mainwindow.h"
#include "SignIn.h"
#include "MapaVias.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //SignIn s;
    //s.show();
    //MapaVias ma;
    //ma.show();
    //MainWindow w;
    //w.show();
    Mapa2 m;
    m.show();
    return a.exec();
}
