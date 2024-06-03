#ifndef MAPAVIAS_H
#define MAPAVIAS_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "Carro.h"
#include "Contador.h"

class MapaVias : public QWidget
{
    Q_OBJECT

public:
    MapaVias(QWidget *parent = nullptr);
    ~MapaVias();
    Carro *c;


private:
    void dibujarRecta(const QPoint &inicio, const QPoint &fin);
    void dibujarDiagonal(const QPoint &inicio, const QPoint &fin);
    void dibujarCurva(const QPoint &centro, int radio, int anguloInicio, int anguloFinal);
    void dibujarCurvaCompleja(const QPoint &p1, const QPoint &p2, const QPoint &p3, const QPoint &p4);
    void evaluarColisiones();
    QGraphicsView *view;
    QGraphicsScene *scene;
    Contador *vidas;
};

#endif // MAPAVIAS_H
