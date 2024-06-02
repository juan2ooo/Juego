#include "Carro.h"
//#include <cmath>

#include "Carro.h"

#include <QTimer>

Carro::Carro(QGraphicsItem *parent) : QGraphicsPixmapItem(parent) {
    //setRotation(90);
    setPixmap(QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/Carro.png")); // Reemplaza "car.png" con la ruta de tu imagen de carro
    setTransformOriginPoint(pixmap().width() / 2, pixmap().height() / 2);
    rotationTimer = new QTimer(this);
    connect(rotationTimer, SIGNAL(timeout()), this, SLOT(rotate()));
    rotationTimer->start(100); // Cambia el valor para ajustar la velocidad de rotación
    moving = false;
    setPos(0,140);

    moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
}

void Carro::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space && !event->isAutoRepeat()) {
        //if (!moving && !verificarColisiones()) {
            //moving = true;
            qDebug() << "presionado";
            rotationTimer->stop();
            moveTimer->start(50);
        //}
    }
}

void Carro::keyReleaseEvent(QKeyEvent *event) {
    //if(moveTimer->isActive())

    if (!event->isAutoRepeat()) {
        //if (moving) {
            //moving = false;
            qDebug() << "desprecionado";
            moveTimer->stop();
            rotationTimer->start(100); // Vuelve a iniciar la rotación

        }
    //}
}

void Carro::rotate() {
    setRotation(rotation() + 15); // Cambia el valor para ajustar la velocidad de rotación
}

void Carro::move() {
    double MOVEMENT_SPEED = 10;
    // Calcula el desplazamiento en x e y basado en el ángulo de rotación actual
    double radians = rotation() * M_PI / 180.0;
    double dx = cos(radians) * MOVEMENT_SPEED;
    double dy = sin(radians) * MOVEMENT_SPEED;

    // Aplica el desplazamiento al carro
    setPos(x() + dx, y() + dy);
}



