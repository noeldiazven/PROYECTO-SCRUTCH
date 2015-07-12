#include "bajarlapiz.h"
#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>


BajarLapiz::BajarLapiz(Gato*g, ventanabotones *v){
    dx=0;
    dy=0;
    aux=nullptr;
    id="bajarlapiz";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=120;
    width=143;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(bajar_lapiz);
}

void BajarLapiz::paintEvent()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);


    painter.setPen(Qt::darkGray);
    painter.drawLine(100,200,300,400);
}


void BajarLapiz::pintar_imagen(){
    entero xx=obj->get_posicion_x()-10;
    entero yy=obj->get_posicion_y()-10;
}


void BajarLapiz::crear_nuevo()
{
    BajarLapiz * n=new BajarLapiz(obj,ventana);
    n->show();
    ventana->add_botones_lapiz(n);
    qDebug() <<"crear";
}

void BajarLapiz::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor()*pi)/180);
    dx=cos((obj->get_receptor()*pi)/180);
}

void BajarLapiz::correr(){

    obj->set_Activador2(1);
    if(siguiente!=nullptr){siguiente->correr();}

}



