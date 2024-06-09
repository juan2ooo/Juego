#ifndef MAPA2_H
#define MAPA2_H

#include "Bandera.h"
#include "CarroFlecha.h"
#include "Contador.h"
#include "qgraphicsscene.h"
#include "qwidget.h"
class Mapa2: public QWidget
{
    Q_OBJECT
public:
    bool ban1;
    void mostrarMensajeVictoria();
    Bandera *b;
    Mapa2();
    QGraphicsView *view;
    QGraphicsScene *scene1;
    void evaluarColisiones1();
    CarroFlecha *carro;
    Contador *vidas;
    //QGraphicsScene *scene;

signals:
    void terminado();
};

#endif // MAPA2_H
