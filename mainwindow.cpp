#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui ->Play->setParent(this);
    ui ->Help->setParent(this);
    ui ->Play->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->Help->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //connect(ui->)
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_Play_clicked()
{
    login = new Login();
    this->hide();
    login->show();
}

