#ifndef MAPA2_H
#define MAPA2_H

#include "CarroFlecha.h"
#include "qgraphicsscene.h"
#include "qwidget.h"
class Mapa2: public QWidget
{
    Q_OBJECT
public:
    Mapa2();
    QGraphicsView *view;
    QGraphicsScene *scene1;
    void evaluarColisiones1();
    CarroFlecha *carro;
    QGraphicsScene *scene;
};

#endif // MAPA2_H
