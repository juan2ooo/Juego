#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QVBoxLayout>
#include "MapaVias.h"
#include "Mapa2.h"
#include "Proyectil.h"
#include "Avion.h"
#include "Contador.h"
#include "AvionOscilatorio.h"
#include "Vias.h"

MapaVias::MapaVias()
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

    //short dif = 40;
    //double x = ancho / 2;
    //primera via

    QPixmap fondo("C:/Users/juan/Documents/JuegoProyecto/Imagenes/FondoMapa1.png");
    scene->setBackgroundBrush(QBrush(fondo));

    double dif = 70;
    double a = 5;
    //Vias v1;
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

    c = new Carro(scene);
    c->setScale(0.2);

    c->setFlag(QGraphicsItem::ItemIsFocusable);
    c->setFocus();
    scene->addItem(c);
    connect(scene, &QGraphicsScene::changed, this, &MapaVias::evaluarColisiones);

    Proyectil *p = new Proyectil(0,300,100,40,scene);
    p->setScale(0.3);
    scene ->addItem(p);
    Avion *v = new Avion();
    v->setScale(0.3);
    scene->addItem(v);
    vidas = new Contador();
    vidas->setScale(0.2);
    scene->addItem(vidas);

    connect(c, SIGNAL(ganar()), this, SLOT(gano()));

    //AvionOscilatorio *o = new AvionOscilatorio();
    //o->setScale(0.2);
    //scene->addItem(o);

}


MapaVias::~MapaVias()
{
    delete c;
}

void MapaVias::evaluarColisiones()
{

            QList<QGraphicsItem *> colisiones = c->collidingItems();
            if (!colisiones.isEmpty()) {
                //qDebug() << "¡Colisión detectada!";
                c->setPos(0,140);
                if(vidas->vidasRestantes < 0){
                    this->close();
                }

                vidas->perderVida();
            }
}


void MapaVias::gano(){
    this->close();
    disconnect(c, SIGNAL(ganar()), this, SLOT(gano()));
    emit sgte();
}





