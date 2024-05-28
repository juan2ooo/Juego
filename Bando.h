#ifndef BANDO_H
#define BANDO_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

class Bando : public QDialog {
    Q_OBJECT

public:
    Bando(QWidget *parent = nullptr);

signals:
    void fuerzasEjeSeleccionado();
    void aliadosSeleccionado();

private slots:
    void opcionFuerzasEje();
    void opcionAliados();
};

#endif
