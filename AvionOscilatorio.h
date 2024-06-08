#ifndef AVIONOSCILATORIO_H
#define AVIONOSCILATORIO_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QtMath>
#include "AvionGenerico.h"

class AvionOscilatorio : public QObject, public QGraphicsItem, public AvionGenerico
{
    Q_OBJECT

public:
    AvionOscilatorio(QObject *parent = nullptr);
    QRectF boundingRect()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;



private:
    QTimer *timer;
    double velocidad;
    double amplitud;
    double frecuencia;
    double tiempo;
    QPixmap *img;


public slots:
    void mover() override;
};

#endif // AVIONOSCILATORIO_H

