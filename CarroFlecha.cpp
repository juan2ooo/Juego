#include "CarroFlecha.h"
#include "qpainter.h"

CarroFlecha::CarroFlecha()
{

    img = new QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/Carro.png");
    setTransformOriginPoint(img->width() / 2, img->height() / 2);
    setPos(50,700);
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
    if (img) {
        painter->drawPixmap(boundingRect().toRect(), *img);
    }
}

QRectF CarroFlecha::boundingRect() const
{
    // Devuelve el rectángulo delimitador basado en el tamaño de la imagen
    if (img) {
        return QRectF(0, 0, img->width(), img->height());
    }
    return QRectF(0, 0, 50, 50); // Valor por defecto
}
