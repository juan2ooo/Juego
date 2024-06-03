#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QTimer>

class Proyectil : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Proyectil(QGraphicsScene *scene);
    Proyectil(qreal x, qreal y, qreal velocidadInicial, qreal angulo, QGraphicsScene *scene);
    ~Proyectil();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

public slots:
    void actualizarPosicion();

private:
    qreal xInicial;
    qreal yInicial;
    qreal velocidadInicial;
    qreal angulo;
    qreal tiempo;
    QTimer timer;
    QTimer n;
    QGraphicsScene *scene;
    QPixmap *img;
};

#endif // PROYECTIL_H
