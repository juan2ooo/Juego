#include "CarroFlecha.h"
#include "qpainter.h"
#include <qpixmap.h>
CarroFlecha::CarroFlecha()
{
    setPos(50,700);
    img = new QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/Carro.png");
}

void CarroFlecha::keyPressEvent(QKeyEvent* event)
{
    // Mover el CarroFlecha según la tecla presionada
    switch (event->key())
    {
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
    default:

        QGraphicsItem::keyPressEvent(event);
        break;
    }
}


void CarroFlecha::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

        // Dibujar la imagen ajustada al rectángulo delimitador
        painter->drawPixmap(50,50,50,50,*img);


}


QRectF CarroFlecha::boundingRect() const
{
    // Devuelve el rectángulo delimitador basado en el tamaño de la imagen
    return QRectF(50, 50, 50, 50);
}
