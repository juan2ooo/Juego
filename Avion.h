// avion.h
#ifndef AVION_H
#define AVION_H

#include <QGraphicsPixmapItem>

class Avion : public QGraphicsPixmapItem, public QObject {
public:
    Avion(QGraphicsItem *parent = nullptr);

private:
    double angulo;
    double radio;

    void mover();
};

#endif // AVION_H
