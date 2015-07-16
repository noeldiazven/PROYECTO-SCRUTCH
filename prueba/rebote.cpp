#include "rebote.h"

#include "posicionargatoen.h"
#include "girarderecha.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

Rebote::Rebote(Gato*g, ventanabotones *v){
    dx=0;
    dy=0;
    aux=nullptr;
    id="Rebote";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;

    mover_x=80;
    mover_y=120;
    width=200;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_rebotar);
}

QString Rebote::darValores()
{
    QString res="";
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+id+" X "+posiX+" Y "+posiY;
    return res;
}

void Rebote::crear_nuevo()
{
    Rebote * n=new Rebote(obj,ventana);
    n->show();
    ventana->add_botones_movimiento(n);
    qDebug() <<"crear";
}

void Rebote::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor_unica_direccion()*pi)/180);
    dx=cos((obj->get_receptor_unica_direccion()*pi)/180);
}
void Rebote::correr(){
    if(obj->get_posicion_x()>=390){
        obj->rotar_gato_unica_direccion(180);
        obj->set_activador(1);
    }

    else if(obj->get_posicion_x()<=-15){
       obj->rotar_gato_unica_direccion(360);
       obj->set_activador(0);
    }

    else if(obj->get_posicion_y()>=500){
       obj->rotar_gato_unica_direccion(-270);
       obj->set_activador(2);
    }
    else if(obj->get_posicion_y()<=20){
        obj->rotar_gato_unica_direccion(270);
        obj->set_activador(3);

    }


    if(siguiente!=nullptr){siguiente->correr();}
}


