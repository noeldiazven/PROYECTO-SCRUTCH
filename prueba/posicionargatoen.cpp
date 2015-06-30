#include "posicionargatoen.h"
#include "girarderecha.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

PosicionarGatoEn::PosicionarGatoEn(Gato*g, ventanabotones *v){
    aux=nullptr;
    id="girarDerecha";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=205;
    direccion1=250;
    mover_x=80;
    mover_y=370;
    width=143;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_posicion);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(58,4,31,23);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(110,4,31,23);
}

void PosicionarGatoEn::crear_nuevo()
{
    PosicionarGatoEn * n=new PosicionarGatoEn(obj,ventana);
    n->show();
    ventana->add_botones_movimiento(n);
    qDebug() <<"crear";
}
void PosicionarGatoEn::correr(){
    direccion=setpasos->toPlainText().toInt();
    direccion1=setpasos1->toPlainText().toInt();
    qDebug() << direccion;
    qDebug() << direccion1;
    obj->set_posicion_xx(direccion);
    obj->set_posicion_yy(direccion1);
    if(obj->get_posicion_x()<=200&&obj->get_posicion_y()<=265&&obj->get_posicion_x()>=-10&&obj->get_posicion_y()>=20){
        obj->mover_gato(obj->get_posicion_x(),obj->get_posicion_y());
    }


    if(siguiente!=nullptr){siguiente->correr();}
}

