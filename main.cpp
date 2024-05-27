#include "mainwindow.h"
#include "SignIn.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //SignIn s;
    //s.show();

    MainWindow w;
    w.show();
    //qDebug() << "Estilo CSS aplicado a la ventana principal:" << w.styleSheet();
    return a.exec();
}
