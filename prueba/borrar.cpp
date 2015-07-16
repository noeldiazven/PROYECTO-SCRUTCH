#include "borrar.h"

#include "bajarlapiz.h"
#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>
#include "linea.h"


Borrar::Borrar(Gato*g, ventanabotones *v, ventanamostrador *venta){
    ven=venta;
    dx=0;
    dy=0;
    aux=nullptr;
    id="bajarlapiz";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=160;
    width=45;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(borrar);
}

QString Borrar::darValores()
{
    QString res="";
    res+=id;
    return res;
}

void Borrar::paintEvent()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);


    painter.setPen(Qt::darkGray);
    painter.drawLine(100,200,300,400);
}

void Borrar::crear_nuevo()
{
    Borrar * n=new Borrar(obj,ventana,ven);
    n->show();
    ventana->add_botones_lapiz(n);
    qDebug() <<"crear";
}
void Borrar::correr(){  
    if(siguiente!=nullptr){siguiente->correr();}
    ven->eliminar_puntos();

}
