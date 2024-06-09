#include "Bandera.h"
#include "qpainter.h"

Bandera::Bandera() {
    img = new QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/bandera.png");

}


QRectF Bandera::boundingRect() const {
    return QRectF(600,50,50,50);
}

void Bandera::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    painter->drawPixmap(boundingRect().toRect(),*img);
}
