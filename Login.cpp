#include "Login.h"
#include "ui_Login.h"
#include "SignIn.h"

Login::Login(QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_SignIn_clicked()
{
    SignIn *s = new SignIn();
    s->show();
}

