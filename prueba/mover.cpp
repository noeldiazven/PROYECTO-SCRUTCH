#include "mover.h"
#include "gato.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <QDebug>

Mover::Mover(Gato * g, ventanabotones *v)
{
    aux=nullptr;
    id="mover";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    pasos=10;
    mover_x=80;
    mover_y=170;
    ventana=v;
    width=150;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(block_mover);


    setpasos=new QTextEdit(this);
    setpasos->setGeometry(51,5,33,23);
}

void Mover::crear_nuevo()
{
    Mover * n=new Mover(obj,ventana);
    n->show();
    ventana->add_botones_movimiento(n);
    qDebug() <<"crear";
}

void Mover::correr(){

    //mover gato al hacer dobleclick
    pasos=setpasos->toPlainText().toDouble();


    if (obj->get_cambiar_posicion_x()!=0 || obj->get_cambiar_posicion_y()!=0){
        obj->mover_gato(obj->get_cambiar_posicion_x()*pasos,obj->get_cambiar_posicion_y()*pasos);
    }
    else{
        obj->mover_gato(pasos,0);
    }
    qDebug() <<"movio";
    if(siguiente!=nullptr){siguiente->correr();}
}
