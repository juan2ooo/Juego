#include "Carro.h"
//#include <cmath>

#include "Carro.h"

#include <QTimer>

Carro::Carro(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    setPixmap(QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/Carro.png")); // Reemplaza "car.png" con la ruta de tu imagen de carro
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    setRotation(0);
    rotationTimer = new QTimer(this);
    connect(rotationTimer, SIGNAL(timeout()), this, SLOT(rotate()));
    rotationTimer->start(100); // Cambia el valor para ajustar la velocidad de rotación
    moving = false;
}

void Carro::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        if (!moving) {
            moving = true;

            rotationTimer->stop();



            moveTimer = new QTimer(this);
            connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
            moveTimer->start(50);
        }
    }
}


void Carro::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) {
        if (moving) {
            moving = false;
            rotationTimer->start(100); // Vuelve a iniciar la rotación

            moveTimer->stop();
            delete moveTimer;
        }
    }
}


void Carro::rotate() {
    setRotation(rotation() + 10); // Cambia el valor para ajustar la velocidad de rotación
}



bool Carro::verificarColisiones()
{
    // Verifica colisiones con otros elementos
    QList<QGraphicsItem *> colisiones = collidingItems();
    for (QGraphicsItem *item : colisiones) {
        if (QGraphicsLineItem *linea = qgraphicsitem_cast<QGraphicsLineItem *>(item)) {
            // Colisión detectada con una línea, manejarla aquí
            qDebug() << "Colisión detectada con una línea";
            return true;
        }
    }
    return false;
}


void Carro::move() {
    short MOVEMENT_SPEED = 10;
    // Calcula el desplazamiento en x e y basado en el ángulo de rotación actual
    double radians = rotation() * M_PI / 180.0;
    double dx = cos(radians) * MOVEMENT_SPEED;
    double dy = sin(radians) * MOVEMENT_SPEED;

    // Aplica el desplazamiento al carro
    setPos(x() + dx, y() + dy);
}
