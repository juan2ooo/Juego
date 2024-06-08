#ifndef PROYECTILCAIDA_H
#define PROYECTILCAIDA_H

#include "ProyectilGenerico.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class ProyectilCaida : public QObject, public QGraphicsItem, public ProyectilGenerico {
    Q_OBJECT

public:
    ProyectilCaida(double x, double y);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

public slots:
    void actualizarPosicion() override;

private:
    double velocidadY;
    double gravedad;
    double x1, y1;
};

#endif // PROYECTILCAIDA_H
