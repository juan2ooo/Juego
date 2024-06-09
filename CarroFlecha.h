#ifndef CARROFLECHA_H
#define CARROFLECHA_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class CarroFlecha : public QGraphicsItem
{
public:
    CarroFlecha();
    QPixmap *img;
    void keyPressEvent(QKeyEvent* event)override;
    QRectF boundingRect() const override ;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // CARROFLECHA_H
