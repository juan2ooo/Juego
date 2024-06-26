#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MapaVias.h"
#include <QGraphicsScene>
#include <fstream>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui ->Play->setParent(this);
    ui ->Help->setParent(this);
    ui ->Play->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->Help->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui ->lineEditPass -> setEchoMode(QLineEdit::Password);
    //funcion para cargar la pantalla principla
    mostrarPrincipal();


    lv1 = new MapaVias();
    //lv1->show();

    lv2 = new Mapa2();

    connect(lv1,SIGNAL(sgte()),this, SLOT(Mostrarlv2()));
    connect(lv2,SIGNAL(terminado()),this, SLOT(MostrarP()));

    datos = *(leerDatosDesdeArchivo("datos.txt"));

    //connect(ui->)
    mostrarDatos(datos);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete &datos;
}




void MainWindow::on_Play_clicked()
{
    mostrarLogin();
}


void MainWindow::esconderPrinicial(){
    ui -> Play->setVisible(false);
    ui -> Help -> setVisible(false);
}


void MainWindow::mostrarPrincipal(){
    ui -> Play->setVisible(true);
    ui -> Help -> setVisible(true);
    EsconderLogin();
}

void MainWindow::mostrarLogin(){
    ui -> labelPass -> setVisible(true);
    ui -> labelUser-> setVisible(true);
    ui -> lineEditPass -> setVisible(true);
    ui -> lineEditUser -> setVisible(true);

    ui ->login -> setVisible(true);
    ui ->create-> setVisible(true);


    esconderPrinicial();

}


void MainWindow::EsconderLogin(){
    ui -> labelPass -> setVisible(false);
    ui -> labelUser-> setVisible(false);
    ui -> lineEditPass -> setVisible(false);
    ui -> lineEditUser -> setVisible(false);

    // ahora los pushBotton
    ui ->login->setVisible(false);
    ui -> create ->setVisible(false);
}




void MainWindow::on_create_clicked()
{
    QString nombreUsuario = ui -> lineEditUser->text();
    QString contrasena = ui ->lineEditPass->text();

    // Abrir el archivo en modo de escritura y agregar al final
    std::ofstream archivo("datos.txt",ios::app);
    if (archivo.is_open()) {

        if(existe(nombreUsuario.toStdString())){
            QMessageBox::critical(this, "Error", "Usuario ya existe elija otro.");
            return;
        }


        // Escribir el nombre de usuario y la contraseña en el archivo
        (datos)[(nombreUsuario.toStdString())] = contrasena.toStdString();
        //string s = nombreUsuario.toStdString() + "," + contrasena.toStdString() + "\n";
        archivo << nombreUsuario.toStdString() << "," << contrasena.toStdString() << "\n";

        QMessageBox::information(this, "Confirmación", "Usuario creado correctamente.");
        ui ->lineEditUser->clear();
        ui ->lineEditPass ->clear();
    } else {
        // Si hay un error al abrir el archivo, mostrar mensaje de error
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo para escribir.");
    }

}


void MainWindow::on_login_clicked()
{
    string usr = ui->lineEditUser->text().toStdString();
    string pass = ui->lineEditPass->text().toStdString();
    map<string, string>::iterator it = (datos).find(usr);
    //qDebug() << it->first << " " << it->second;

    if(!(it == datos.end()) ){
        this->close();
        lv1->show();
    }else{
        QMessageBox::critical(this, "Error", "Usuario o contrasena invalidos.");
    }
}


map<string, string> *MainWindow::leerDatosDesdeArchivo(const string& nombreArchivo) {

    map<string, string> *datos = new map<string, string>();
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        //no se puedo abrir
        return datos;
    }

    string linea;
    while (getline(archivo, linea)) {
        short comaPos = linea.find(',');
        if (comaPos != string::npos) {
            string usuario = linea.substr(0, comaPos);
            string contrasena = linea.substr(comaPos + 1);
            (*datos)[usuario] = contrasena;
        }
    }

    archivo.close();
    return datos;

}


#include <QDebug>

void MainWindow::mostrarDatos(const std::map<string, string> &datos) {
    qDebug() << "Datos cargados desde el archivo:";
    for (const auto& par : datos) {
        qDebug() << "Usuario:" << QString::fromStdString(par.first) << ", Contraseña:" << QString::fromStdString(par.second);
    }
}



map<string, string>::iterator MainWindow::verificarCredenciales(const string& usuario, const string& contrasena) {

    map<string, string>::iterator it = datos.find(usuario);

    if (it == datos.end()) {
        return datos.end();
    }
    return it;
}


bool MainWindow::existe(const string& usuario) {

    map<string, string>::iterator it = datos.find(usuario);
    if (it == datos.end()) {
        return false;
    }
    return true;
}


void MainWindow::volver(){
    this->show();
}


void MainWindow::Mostrarlv2(){
    lv2->show();
    disconnect(lv1,SIGNAL(sgte()),this, SLOT(Mostrarlv2()));
}


void MainWindow::mostrarP(){
    this->show();
}
