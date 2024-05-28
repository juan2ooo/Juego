#include "Bando.h"


Bando::Bando(QWidget *parent){
    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *btnFuerzasEje = new QPushButton("Fuerzas del Eje", this);
    connect(btnFuerzasEje, &QPushButton::clicked, this, &Bando::opcionFuerzasEje);
    layout->addWidget(btnFuerzasEje);

    QPushButton *btnAliados = new QPushButton("Aliados", this);
    connect(btnAliados, &QPushButton::clicked, this, &Bando::opcionAliados);
    layout->addWidget(btnAliados);

    setLayout(layout);
}

void Bando::opcionFuerzasEje() {
    emit fuerzasEjeSeleccionado();
    close();
}

void Bando::opcionAliados() {
    emit aliadosSeleccionado();
    close();
}


