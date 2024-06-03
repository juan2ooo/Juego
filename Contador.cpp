#include "Contador.h"

Contador::Contador() {
    vidasRestantes = maxVidas;
    corazon = QPixmap("C:/Users/juan/Documents/JuegoProyecto/Imagenes/corazon.png");
}

void Contador::perderVida() {
    if (vidasRestantes > 0) {
        vidasRestantes--;
        update();
    }
}

void Contador::reiniciarVidas() {
    vidasRestantes = maxVidas;
    update();
}

QRectF Contador::boundingRect() const {
    // Define el área que ocuparán las vidas
    return QRectF(0, 0, maxVidas * (corazon.width() + separacion) - separacion, corazon.height());
}

void Contador::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    for (int i = 0; i < vidasRestantes; ++i) {
        painter->drawPixmap(i * (corazon.width() + separacion), 0, corazon);
    }
}
