#ifndef AVIONOSCILATORIO_H
#define AVIONOSCILATORIO_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QtMath>
#include "AvionGenerico.h"

class AvionOscilatorio : public QObject, public QGraphicsPixmapItem, public AvionGenerico
{
    Q_OBJECT

public:
    AvionOscilatorio(QObject *parent = nullptr);

public slots:
    void mover() override;

private:
    QTimer *timer;
    qreal velocidad;
    qreal amplitud;
    qreal frecuencia;
    qreal tiempo;
};

#endif // AVIONOSCILATORIO_H

