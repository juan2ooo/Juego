#include "AvionOscilatorio.h"
#include "qpainter.h"
#include <QGraphicsScene>

AvionOscilatorio::AvionOscilatorio(QObject *parent)
    : QObject(parent), velocidad(25), amplitud(50.0), frecuencia(2), tiempo(0)
{
    img = new QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/Avion.png");

    setPos(0,200);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mover()));
    timer->start(16); // Aproximadamente 60 FPS
}

void AvionOscilatorio::mover()
{

    tiempo += 0.016; // Incrementa el tiempo en 16ms por frame
    double x1 = velocidad * tiempo;
    double y1 = amplitud * qSin(frecuencia * tiempo);
    setPos(x1, y1 + 200); // Ajusta la posición relativa
    //qDebug()<<x1<<" "<<y1;
    //update(); // Asegura que el gráfico se actualice
}

QRectF AvionOscilatorio::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void AvionOscilatorio::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawPixmap(0,0,50,50,*img);
}
