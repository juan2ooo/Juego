#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_Play_clicked();

    void on_create_clicked();

    void on_login_clicked();

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

};
#endif // MAINWINDOW_H
