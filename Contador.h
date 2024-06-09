#ifndef CONTADOR_H
#define CONTADOR_H

#include <QGraphicsItem>
#include <QPainter>

class Contador : public QGraphicsItem {
public:
    Contador();
    void perderVida();
    void reiniciarVidas();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    int vidasRestantes;
private:

    QPixmap corazon;
    static const int maxVidas = 3;


    static const int separacion = 10;
};

#endif // CONTADOR_H
