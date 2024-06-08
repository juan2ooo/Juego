#ifndef CARROFLECHA_H
#define CARROFLECHA_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class CarroFlecha : public QGraphicsRectItem
{
public:
    CarroFlecha();
    QPixmap *img;
    void keyPressEvent(QKeyEvent* event);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // CARROFLECHA_H
