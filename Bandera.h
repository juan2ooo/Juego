#ifndef BANDERA_H
#define BANDERA_H

#include "qgraphicsitem.h"
class Bandera : public QGraphicsItem
{
public:
    Bandera();
    QPixmap *img;
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // BANDERA_H
