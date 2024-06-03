#include "Proyectil.h"
#include "qgraphicsscene.h"
#include <QPainter>
#include <cmath>

Proyectil::Proyectil(QGraphicsScene *scene) : scene(scene), tiempo(0)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(actualizarPosicion()));
    timer.start(100); // Actualizar cada 100 milisegundos
    setPos(50,50);
}

Proyectil::Proyectil(qreal x, qreal y, qreal velocidadInicial, qreal angulo, QGraphicsScene *scene)
    : xInicial(x), yInicial(y), velocidadInicial(velocidadInicial), angulo(angulo), tiempo(0), scene(scene)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(actualizarPosicion()));
    connect(&n,SIGNAL(nuevo()),this,SLOT(nuevoProyectil()));
    timer.start(100); // Actualizar cada 100 milisegundos
    img = new QPixmap();
    img->load("C:/Users/juan/Documents/JuegoProyecto/Carro.png");
}

Proyectil::~Proyectil()
{
    timer.stop();
}

QRectF Proyectil::boundingRect() const
{
    return QRectF(50, 50, 50, 50);
}

void Proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawPixmap(50,50,50,50,*img);
}

void Proyectil::actualizarPosicion()
{
    qreal velocidadX = velocidadInicial * cos(angulo * M_PI / 180);
    qreal velocidadY = velocidadInicial * sin(angulo * M_PI / 180) - 9.81 * tiempo;
    qreal deltaX = velocidadX;
    qreal deltaY = velocidadY;

    setPos(xInicial + deltaX * tiempo, yInicial - deltaY * tiempo);

    tiempo += 0.1;
    qDebug() << pos().y() << " " << scene->height();
    if (pos().y() > scene->height()) {
        scene->addItem(new Proyectil(xInicial, yInicial,velocidadInicial,angulo,scene));;
        delete this;
    }
}
