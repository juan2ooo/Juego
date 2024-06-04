#ifndef PROYECTILGENERICO_H
#define PROYECTILGENERICO_H


#include <QGraphicsItem>
#include <QTimer>

class ProyectilGenerico
{
public:
    ProyectilGenerico();


    public slots:
    virtual void actualizarPosicion() = 0;
};

#endif // PROYECTILGENERICO_H
