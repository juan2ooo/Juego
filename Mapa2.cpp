#include "Mapa2.h"
#include "AvionOscilatorio.h"
#include "Bandera.h"
#include "CarroFlecha.h"
#include "Contador.h"
#include "Proyectil.h"
#include "ProyectilCaida.h"
#include "qboxlayout.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "qmessagebox.h"

Mapa2::Mapa2() {
    ban1=true;
    short alto = 800, ancho = 600;
    scene1 = new QGraphicsScene(this);
    scene1->setSceneRect(0, 0, ancho, alto);

    view = new QGraphicsView(scene1, this);
    view->setFixedSize(ancho, alto); // Tamaño fijo de la vista
    view->setScene(scene1);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    setLayout(layout);

    AvionOscilatorio *a1 = new AvionOscilatorio(this);
    scene1->addItem(a1);

    Proyectil *p1 = new Proyectil(0, 400, 100, 40, scene1);
    p1->setScale(0.5);
    Proyectil *p2 = new Proyectil(0, 500, 100, 40, scene1);
    p2->setScale(0.5);
    scene1->addItem(p1);
    scene1->addItem(p2);

    ProyectilCaida *caida = new ProyectilCaida(200, 0);
    scene1->addItem(caida);

    ProyectilCaida *caida1 = new ProyectilCaida(300, 0);
    scene1->addItem(caida1);

    ProyectilCaida *caida2 = new ProyectilCaida(400, 0);
    scene1->addItem(caida2);

    //ProyectilCaida *caida3 = new ProyectilCaida(500, 0);
    //scene1->addItem(caida3);

    carro = new CarroFlecha();
    carro->setScale(0.2); // Escala del objeto
    carro->setFlag(QGraphicsItem::ItemIsFocusable);
    carro->setFocus();
    scene1->addItem(carro);


    b = new Bandera();
    //b->setPos(400,100);
    b->setScale(0.8);
    scene1->addItem(b);

    vidas = new Contador();
    vidas -> setScale(0.2);
    scene1->addItem(vidas);

    QPixmap fondo("C:/Users/juan/Documents/JuegoProyecto/Imagenes/FondoMapa1.png");
    scene1->setBackgroundBrush(QBrush(fondo));

    // Conexión de la señal de cambio de la escena con la función de evaluación de colisiones
    connect(scene1, &QGraphicsScene::changed, this, &Mapa2::evaluarColisiones1);
}

void Mapa2::evaluarColisiones1()
{

            QList<QGraphicsItem *> colisiones = carro->collidingItems();
            if (!colisiones.isEmpty()) {
                // Manejo de la colisión detectada
                for(QGraphicsItem *item : colisiones){
                    if(Bandera *bandera = dynamic_cast<Bandera *>(item)){
                        if(ban1){
                            b->setPos(-400,500);
                            ban1=false;
                        }else{
                            scene1->removeItem(b);
                            mostrarMensajeVictoria();
                            //emit terminado();

                            this->close();


                            return;
                        }
                    }else{
                        vidas->perderVida();
                        carro->setPos(50, 700);
                    }
                }
                qDebug() << "¡Colisión detectada!";


            }
}


void Mapa2::mostrarMensajeVictoria() {

    QMessageBox mensaje;


    mensaje.setWindowTitle("¡Felicidades!");
    mensaje.setText("¡Has ganado el juego!");
    mensaje.setIcon(QMessageBox::Information);


    mensaje.setStandardButtons(QMessageBox::Ok);
    mensaje.setDefaultButton(QMessageBox::Ok);


    mensaje.exec();
}
