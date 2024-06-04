#ifndef ESCENACARRETERA_H
#define ESCENACARRETERA_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

class EscenaCarretera : public QGraphicsScene
{
    Q_OBJECT

public:
    EscenaCarretera(QObject *parent = nullptr);
    ~EscenaCarretera();

private slots:
    void actualizarPosicionCarretera();

private:
    QTimer *temporizador;
    QGraphicsPixmapItem *carretera1;
    QGraphicsPixmapItem *carretera2;
    int velocidadCarretera;
};

#endif // ESCENACARRETERA_H
