#ifndef PROYECTILOSCILATORIO_H
#define PROYECTILOSCILATORIO_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QtMath>
#include "proyectilgenerico.h"

class ProyectilOscilatorio : public QObject, public QGraphicsPixmapItem, public ProyectilGenerico
{
    Q_OBJECT

public:
    ProyectilOscilatorio(QObject *parent = nullptr);

public slots:
    void actualizarPosicion() override;

private:
    QTimer *timer;
    qreal velocidad;
    qreal amplitud;
    qreal frecuencia;
    qreal tiempo;
};

#endif // PROYECTILOSCILATORIO_H

