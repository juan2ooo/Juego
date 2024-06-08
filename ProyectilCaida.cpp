#include "ProyectilCaida.h"

ProyectilCaida::ProyectilCaida(double x, double y)
    : velocidadY(0), gravedad(9.8) {
    // Establece el rectángulo de límites del proyectil
    this->x1=x;
    this->y1=y;
    setPos(x, y);

    // Configura un temporizador para actualizar la posición periódicamente
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ProyectilCaida::actualizarPosicion);
    timer->start(100); // Actualizar cada 100 ms
}

QRectF ProyectilCaida::boundingRect() const {
    // Define el rectángulo de límites del proyectil
    return QRectF(-10, -10, 20, 20);
}

void ProyectilCaida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // Dibuja un círculo representando el proyectil
    painter->setBrush(Qt::blue);
    painter->drawEllipse(-10, -10, 20, 20);
}

void ProyectilCaida::actualizarPosicion() {
    // Actualiza la velocidad y posición del proyectil
    velocidadY += gravedad * 0.3; // Simulación del efecto de la gravedad
    setY(y() + velocidadY * 0.3); // Actualiza la posición vertical del proyectil
    if(y()>800){
        setPos(x1,y1);
        velocidadY = 0;
    }
}
