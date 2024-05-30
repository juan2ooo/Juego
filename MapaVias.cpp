#include <QGraphicsEllipseItem>
#include <QGraphicsPathItem>
#include <QVBoxLayout>
#include "MapaVias.h"
#include "Carro.h"

MapaVias::MapaVias(QWidget *parent) : QWidget(parent)
{
    short dif = 20;
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



    // Segmentos iniciales
    dibujarRecta(QPoint(0, 50), QPoint(300+dif, 50));  // Primera línea horizontal
    dibujarRecta(QPoint(0, 100+dif), QPoint(250, 100+dif));  // Segunda línea horizontal

    dibujarRecta(QPoint(300+dif, 50), QPoint(300+dif, 150));  // Primera línea vertical desde el final de la primera línea horizontal
    dibujarRecta(QPoint(250, 100+dif), QPoint(250, 200+dif));  // Segunda línea vertical desde el final de la segunda línea horizontal

    dibujarRecta(QPoint(300+dif, 150), QPoint(400+dif, 150));  // Tercera línea horizontal desde el final de la primera línea vertical
    dibujarRecta(QPoint(250, 200+dif), QPoint(350, 200+dif));  // Cuarta línea horizontal desde el final de la segunda línea vertical

    dibujarRecta(QPoint(400+dif, 150), QPoint(400+dif, 250));  // Segunda línea vertical desde el final de la tercera línea horizontal
    dibujarRecta(QPoint(350, 200+dif), QPoint(350, 300));  // Segunda línea vertical desde el final de la cuarta línea horizontal

    // Continuación
    dibujarRecta(QPoint(400+dif, 250), QPoint(500, 250));  // Quinta línea horizontal desde el final de la segunda línea vertical
    dibujarRecta(QPoint(350, 300), QPoint(450, 300));  // Sexta línea horizontal desde el final de la segunda línea vertical

    dibujarRecta(QPoint(500, 250), QPoint(500, 350));  // Tercera línea vertical desde el final de la quinta línea horizontal
    dibujarRecta(QPoint(450, 300), QPoint(450, 400+dif));  // Cuarta línea vertical desde el final de la sexta línea horizontal

    dibujarRecta(QPoint(500, 350), QPoint(580, 350));  // Séptima línea horizontal desde el final de la tercera línea vertical
    dibujarRecta(QPoint(450, 400+dif), QPoint(550, 400+dif));  // Octava línea horizontal desde el final de la cuarta línea vertical

    dibujarRecta(QPoint(580, 350), QPoint(580, 540));  // Quinta línea vertical desde el final de la séptima línea horizontal
    dibujarRecta(QPoint(550, 400), QPoint(550, 500));  // Sexta línea vertical desde el final de la octava línea horizontal

    dibujarRecta(QPoint(580, 540), QPoint(500, 540));  // Quinta línea vertical desde el final de la séptima línea horizontal
    dibujarRecta(QPoint(550, 500), QPoint(450, 500));

    dibujarRecta(QPoint(500, 540), QPoint(500, 700));  // Quinta línea vertical desde el final de la séptima línea horizontal
    dibujarRecta(QPoint(450, 500), QPoint(450, 750));

    dibujarRecta(QPoint(500, 700), QPoint(600, 700));  // Quinta línea vertical desde el final de la séptima línea horizontal
    dibujarRecta(QPoint(450, 750), QPoint(600, 750));




    QPixmap background("C:/Users/juan/Documents/JuegoProyecto/Imagenes/FondoMapa1.png");
    scene->setBackgroundBrush(QBrush(background));


    // Crear y añadir el personaje a la escena
    Carro *personaje = new Carro();
    personaje->setScale(0.3);
    scene->addItem(personaje);
    personaje->setFlag(QGraphicsItem::ItemIsFocusable);
    personaje->setFocus();


}

MapaVias::~MapaVias()
{
    // No es necesario eliminar view y scene manualmente ya que Qt se encarga de esto
}

void MapaVias::dibujarRecta(const QPoint &inicio, const QPoint &fin)
{
    QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(inicio, fin));
    line->setPen(QPen(QColor(40, 40, 40), 4));
    scene->addItem(line);
}

void MapaVias::dibujarDiagonal(const QPoint &inicio, const QPoint &fin)
{
    QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(inicio, fin));
    line->setPen(QPen(Qt::blue, 2));
    scene->addItem(line);
}




