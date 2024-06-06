#ifndef AVIONGENERICO_H
#define AVIONGENERICO_H
#include <QGraphicsPixmapItem>
#include <QTimer>

class AvionGenerico
{
public:
    AvionGenerico();
public slots:
    virtual void mover()=0;
};

#endif // AVIONGENERICO_H
