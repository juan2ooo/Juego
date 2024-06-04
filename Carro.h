#ifndef CUERPO_H
#define CUERPO_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>

class Carro : public QObject, public QGraphicsPixmapItem
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
    void rotarCarro();
    bool moving;
    QTimer *rotationTimer;
    QTimer *moveTimer;


private slots:
    void rotate();
    void move();
};

#endif // CUERPO_H
