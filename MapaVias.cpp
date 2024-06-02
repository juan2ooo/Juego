#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QVBoxLayout>
#include "MapaVias.h"


#include "Vias.h"

MapaVias::MapaVias(QWidget *parent) : QWidget(parent)
{
    short alto = 800, ancho = 600;
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, ancho, alto);

    // Se crea la vista y se asigna la escena
    view = new QGraphicsView(scene, this);
    view->setFixedSize(ancho, alto); // Tamaño fijo de la vista

    // Se añade la vista al layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    // Agregamos múltiples instancias de Vias a la escena
    //short dif = 40;
    //double x = ancho / 2;
    //primera via
    double dif = 50;
    double a = 5;
    scene->addItem(new Vias(0, 150, 200+dif,a));
    scene->addItem(new Vias(0, 150+dif, 200,a));

    scene->addItem(new Vias(200+dif, 150, a,200+dif));
    scene->addItem(new Vias(200, 150+dif, a ,200+dif));

    scene->addItem(new Vias(200+dif, 150+200+dif, 200+dif,a));
    scene->addItem(new Vias(200, 150+dif+(200+dif), 200+dif ,a));

    scene->addItem(new Vias((200+dif)*2, 150+200+dif, a ,200+dif));
    scene->addItem(new Vias(200*2+dif, 150+dif+(200+dif), a ,200+dif));

    scene->addItem(new Vias((200+dif)*2, 150+200+dif+(200+dif), 200+dif ,a));
    scene->addItem(new Vias(200*2+dif, 150+dif+(200+dif)*2, 200+dif ,a));

    c = new Carro();
    c->setScale(0.2);

    c->setFlag(QGraphicsItem::ItemIsFocusable);
    c->setFocus();
    scene->addItem(c);
    connect(scene, &QGraphicsScene::changed, this, &MapaVias::evaluarColisiones);



}


MapaVias::~MapaVias()
{
    // No es necesario eliminar view y scene manualmente ya que Qt se encarga de esto
}

void MapaVias::evaluarColisiones()
{
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        if (Carro *carro = dynamic_cast<Carro *>(item)) {
            QList<QGraphicsItem *> colisiones = carro->collidingItems();
            if (!colisiones.isEmpty()) {
                // Si hay colisiones, se puede manejar aquí
                qDebug() << "¡Colisión detectada!";
                c->setPos(0,140);
                // Manejar la colisión según sea necesario
            }
        }
    }
}





