#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Mapa2.h"
#include "MapaVias.h"
#include <QMainWindow>
//#include "Login.h"
#include <map>


using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_Play_clicked();

    void on_create_clicked();

    void on_login_clicked();

    void volver();

    void Mostrarlv2();

    void mostrarP();

private:
    Ui::MainWindow *ui;
    void esconderPrinicial();
    void mostrarPrincipal();
    void mostrarLogin();
    void EsconderLogin();
    map<string,string> datos;
    map<string, string> *leerDatosDesdeArchivo(const string& nombreArchivo);
    void mostrarDatos(const map<string, string> &datos);
    map<string, string>::iterator verificarCredenciales(const string& usuario, const string& contrasena);
    bool existe(const string& usuario);
    MapaVias *lv1;
    Mapa2 *lv2;


};
#endif // MAINWINDOW_H
