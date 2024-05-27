#include "signin.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

SignIn::SignIn(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *userLabel = new QLabel("Usuario:", this);
    userEdit = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("Contraseña:", this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    QPushButton *signInButton = new QPushButton("Crear Sesión", this);

    layout->addWidget(userLabel);
    layout->addWidget(userEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(signInButton);

    connect(signInButton, &QPushButton::clicked, this, &SignIn::signInClicked);

    setLayout(layout);
    setWindowTitle("Crear Sesión");
}

void SignIn::signInClicked() {
    QString user = userEdit->text();
    QString password = passwordEdit->text();
    if (!user.isEmpty() && !password.isEmpty()) {
        QMessageBox::information(this, "Confirmación", "Sesión creada correctamente.");
    } else {
        QMessageBox::warning(this, "Error", "Por favor, ingrese usuario y contraseña.");
    }

}
