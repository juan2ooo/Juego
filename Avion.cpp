// avion.cpp
#include "Avion.h"
#include <QTimer>
#include <cmath>

Avion::Avion(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), angulo(0), radio(100) {

    setPixmap(QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/avion.png"));
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    setPos(200, 300);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Avion::mover);
    timer->start(50);
}

void Avion::mover() {
    angulo += 0.1;
    radio = 10;

    double x1 = radio * std::cos(angulo);
    double y1 = radio * std::sin(angulo);

    setPos(x1 + x(), y1+y());
    setRotation(angulo * 180 / M_PI);
}
