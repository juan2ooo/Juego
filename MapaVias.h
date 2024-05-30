#ifndef MAPAVIAS_H
#define MAPAVIAS_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

class MapaVias : public QWidget
{
    Q_OBJECT

public:
    MapaVias(QWidget *parent = nullptr);
    ~MapaVias();


private:
    void dibujarRecta(const QPoint &inicio, const QPoint &fin);
    void dibujarDiagonal(const QPoint &inicio, const QPoint &fin);
    void dibujarCurva(const QPoint &centro, int radio, int anguloInicio, int anguloFinal);
    void dibujarCurvaCompleja(const QPoint &p1, const QPoint &p2, const QPoint &p3, const QPoint &p4);

    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // MAPAVIAS_H
