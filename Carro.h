#ifndef CUERPO_H
#define CUERPO_H

#include "CarroGenerico.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>

class Carro : public QObject, public QGraphicsPixmapItem, public CarroGenerico
{
    Q_OBJECT
public:
    Carro(QGraphicsScene *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event)override;
    QGraphicsScene *scene;

private:
    bool verificarColisiones();
    bool rotating;
    //void mover();
    bool moving;
    QTimer *rotationTimer;
    QTimer *moveTimer;


private slots:
    void rotate();
    void move() override;

signals:
    void ganar();

};

#endif // CUERPO_H
