#ifndef SIGNIN_H
#define SIGNIN_H

#include <QWidget>
#include <QLineEdit> // Añade esta línea para incluir QLineEdit

class SignIn : public QWidget {
    Q_OBJECT

public:
    SignIn(QWidget *parent = nullptr);

private slots:
    void signInClicked();

private:
    QLineEdit *userEdit;
    QLineEdit *passwordEdit;
};

#endif // SIGNIN_H
