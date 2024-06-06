// avion.h
#ifndef AVION_H
#define AVION_H

#include "AvionGenerico.h"
#include <QGraphicsPixmapItem>
#include <qtimer.h>


class Avion :  public QObject, public QGraphicsItem, public AvionGenerico {
public:
    Avion(QGraphicsItem *parent = nullptr);
    QTimer *timer;
    QPixmap *img;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double angulo;
    double radio;

public slots:
    void mover() override;
};

#endif // AVION_H
