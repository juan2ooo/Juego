#ifndef CUERPO_H
#define CUERPO_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>

class Carro : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Carro(QGraphicsItem *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    void verificarColisiones();
};

#endif // CUERPO_H
