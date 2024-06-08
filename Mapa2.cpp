#include "Mapa2.h"
#include "AvionOscilatorio.h"
#include "CarroFlecha.h"
#include "Proyectil.h"
#include "ProyectilCaida.h"
#include "qboxlayout.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"

Mapa2::Mapa2() {
    short alto = 800, ancho = 600;
    scene1 = new QGraphicsScene(this);
    scene1->setSceneRect(0, 0, ancho, alto);

    view = new QGraphicsView(scene1, this);
    view->setFixedSize(ancho, alto); // Tamaño fijo de la vista
    view->setScene(scene1);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    // Inicialización de objetos y adición a la escena
    AvionOscilatorio *a1 = new AvionOscilatorio(this);
    scene1->addItem(a1);

    Proyectil *p1 = new Proyectil(0, 400, 100, 40, scene1);
    Proyectil *p2 = new Proyectil(0, 500, 100, 40, scene1);
    scene1->addItem(p1);
    scene1->addItem(p2);

    //ProyectilCaida *caida = new ProyectilCaida(200, 0);
    //scene1->addItem(caida);

    //ProyectilCaida *caida1 = new ProyectilCaida(300, 0);
    //scene1->addItem(caida1);

    //ProyectilCaida *caida2 = new ProyectilCaida(400, 0);
    //scene1->addItem(caida2);

    //ProyectilCaida *caida3 = new ProyectilCaida(500, 0);
    //scene1->addItem(caida3);

    carro = new CarroFlecha();
    //carro->setScale(0.2); // Escala del objeto
    carro->setFlag(QGraphicsItem::ItemIsFocusable);
    carro->setFocus();
    scene1->addItem(carro);

    //QPixmap fondo("C:/Users/juan/Documents/JuegoProyecto/Imagenes/FondoMapa1.png");
    //scene1->setBackgroundBrush(QBrush(fondo));

    // Conexión de la señal de cambio de la escena con la función de evaluación de colisiones
    connect(scene1, &QGraphicsScene::changed, this, &Mapa2::evaluarColisiones1);
}

void Mapa2::evaluarColisiones1()
{
    // Obtención de todos los elementos en la escena
    QList<QGraphicsItem *> items = scene1->items();
    for (QGraphicsItem *item : items) {
        // Verificación de si el elemento es un CarroFlecha
        if (CarroFlecha *carro1 = dynamic_cast<CarroFlecha *>(item)) {
            // Obtención de los elementos colisionantes
            QList<QGraphicsItem *> colisiones = carro1->collidingItems();
            if (!colisiones.isEmpty()) {
                // Manejo de la colisión detectada
                qDebug() << "¡Colisión detectada!";
                carro1->setPos(50, 700);
                //vidas->perderVida(); // Asegúrate de que esto esté definido correctamente
            }
        }
    }
}
