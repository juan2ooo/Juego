#include "ProyectilOscilatorio.h"
#include <QGraphicsScene>

ProyectilOscilatorio::ProyectilOscilatorio(QObject *parent)
    : QObject(parent), QGraphicsPixmapItem(), velocidad(5.0), amplitud(50.0), frecuencia(1.0), tiempo(0)
{
    QPixmap pixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/proyectil.png");
    setPixmap(pixmap);
    setPos(200,200);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ProyectilOscilatorio::actualizarPosicion);
    timer->start(16); // Aproximadamente 60 FPS
}

void ProyectilOscilatorio::actualizarPosicion()
{
    tiempo += 0.086; // Incrementa el tiempo en 16ms por frame
    qreal x1 = velocidad * tiempo;
    qreal y1 = amplitud * qSin(frecuencia * tiempo);
    setPos(x1+200, y1+200);
}
