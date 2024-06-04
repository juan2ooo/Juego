#include "EscenaCarretera.h"
#include <QGraphicsView>

EscenaCarretera::EscenaCarretera(QObject *parent)
    : QGraphicsScene(parent), velocidadCarretera(5)
{
    QPixmap pixmapCarretera(":/images/road.png"); // Asegúrate de tener la imagen en el recurso

    carretera1 = new QGraphicsPixmapItem(pixmapCarretera);
    carretera2 = new QGraphicsPixmapItem(pixmapCarretera);

    addItem(carretera1);
    addItem(carretera2);

    carretera1->setPos(0, 0);
    carretera2->setPos(0, -pixmapCarretera.height());

    temporizador = new QTimer(this);
    connect(temporizador, &QTimer::timeout, this, &EscenaCarretera::actualizarPosicionCarretera);
    temporizador->start(30); // Actualiza cada 30 ms
}

EscenaCarretera::~EscenaCarretera()
{
}

void EscenaCarretera::actualizarPosicionCarretera()
{
    carretera1->setY(carretera1->y() + velocidadCarretera);
    carretera2->setY(carretera2->y() + velocidadCarretera);

    if (carretera1->y() >= carretera1->pixmap().height()) {
        carretera1->setY(carretera2->y() - carretera2->pixmap().height());
    }
    if (carretera2->y() >= carretera2->pixmap().height()) {
        carretera2->setY(carretera1->y() - carretera1->pixmap().height());
    }

    update();
}
