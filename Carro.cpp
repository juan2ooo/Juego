#include "Carro.h"

Carro::Carro(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    // Configura la imagen del carro
    setPixmap(QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/Carro.png"));


}

void Carro::keyPressEvent(QKeyEvent *event)
{
    // Movimiento del carro basado en las teclas presionadas
    switch (event->key()) {
    case Qt::Key_Left:
        setPos(x() - 10, y());
        break;
    case Qt::Key_Right:
        setPos(x() + 10, y());
        break;
    case Qt::Key_Up:
        setPos(x(), y() - 10);
        break;
    case Qt::Key_Down:
        setPos(x(), y() + 10);
        break;
    }

    // Verificar colisiones después del movimiento
    verificarColisiones();
}

void Carro::verificarColisiones()
{
    // Verifica colisiones con otros elementos
    QList<QGraphicsItem *> colisiones = collidingItems();
    for (QGraphicsItem *item : colisiones) {
        if (QGraphicsLineItem *linea = qgraphicsitem_cast<QGraphicsLineItem *>(item)) {
            // Colisión detectada con una línea, manejarla aquí
            qDebug() << "Colisión detectada con una línea";
            // Revertir movimiento en caso de colisión (ajustar según sea necesario)
            setPos(x() - 10, y() - 10);
        }
    }
}
