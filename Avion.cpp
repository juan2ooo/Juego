// avion.cpp
#include "Avion.h"
#include <QPainter>
#include <QTimer>
#include <cmath>

Avion::Avion(QGraphicsItem *parent) : QGraphicsItem(parent), angulo(0), radio(100) {
    img = new QPixmap();
    img->load("C:/Users/juan/Documents/JuegoProyecto/Imagenes/avion.png");
    setTransformOriginPoint(100 , 100);
    setPos(200, 300);

    timer = new QTimer(this);
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

QRectF Avion::boundingRect() const
{
    return QRectF(50, 50, 50, 50);
}

void Avion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawPixmap(50,50,100,100,*img);
}
