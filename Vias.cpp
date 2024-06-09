#include "vias.h"

Vias::Vias(qreal x, qreal y, qreal width, qreal height) {
    setRect(x, y, width, height);
}

void Vias::setPosition(qreal x, qreal y) {
    setRect(x, y, rect().width(), rect().height());
}

void Vias::setDimensions(qreal width, qreal height) {
    setRect(rect().x(), rect().y(), width, height);
}

void Vias::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::gray);  // Puedes cambiar el color de la vía aquí
    painter->drawRect(rect());
}

