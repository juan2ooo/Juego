#ifndef VIAS_H
#define VIAS_H

#include <QGraphicsRectItem>
#include <QPainter>

class Vias : public QGraphicsRectItem {
public:
    Vias(qreal x, qreal y, qreal width, qreal height);

    // Método para actualizar la posición de la vía
    void setPosition(qreal x, qreal y);

    // Método para actualizar las dimensiones de la vía
    void setDimensions(qreal width, qreal height);

    // Método para dibujar la vía
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // VIAS_H
