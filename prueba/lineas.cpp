/*#include "lineas.h"
#include "QtCore"
#include <QPainter>
#include "gato.h"
#include "bloques.h"
#include "imagenes.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QSize>
#include "ventanamostrador.h"

lineas::lineas(QWidget * par){
    parent=par;
    img=image_gato;
    this->setPixmap(img);
    rotar=0;
    posicion_x=205;
    posicion_y=150;
    receptor=0;
    width=80;heigth=80;
    cambiar_posicion_x=0;
    unico_receptor=0;
    activador=0;
    cambiar_posicion_y=0;

    //this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);//poniendo en la posicion (x,y) y de tamano (50,50)
    //this->setParent(parent);
}

void lineas::paintEvent(QPaintEvent*){
    QPixmap p;
    QPainter painter(&p);
    QPen linepen(Qt::red);
    linepen.setWidth(2);
    QPoint p1;
    p1.setX(200);
    p1.setY(10);

    QPoint p2;
    p2.setX(1);
    p2.setY(10);

    painter.setPen(linepen);
    painter.drawLine(p1,p2);

    QLine line = QLine(p1,p2);
    painter.drawLine(line);
}


void lineas::rotar_gato(tipo_entero giro){
    rotar+=giro;

    QPixmap rotatedPixmap(img.size());//adapto el valor del img a otro pixmap
    rotatedPixmap.fill(QColor::fromRgb(0, 0, 0, 0));//cambio el color de fondo
    QPainter* p = new QPainter(&rotatedPixmap);//creo un q painter
    QSize size = img.size();//adapto al tamaño
    p->translate(size.height()/2,size.height()/2);//posiciono al centro
    p->rotate(-rotar);
    p->translate(-size.height()/2,-size.height()/2);
    p->drawPixmap(0, 0, img);
    p->end();
    delete p;
    this->setPixmap(rotatedPixmap);
}

//-

//---------------------------------------
void lineas::mover_gato(entero a, entero b){

        set_posicion_x(a);
        set_posicion_y(b);
        this->setGeometry(get_posicion_x(),get_posicion_y(),width,heigth);
}
*/
