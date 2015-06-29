#include "girarderecha.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

GirarDerecha::GirarDerecha(Gato*g, ventanabotones *v){
    dx=0;
    dy=0;
    aux=nullptr;
    id="girarDerecha";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=110;
    mover_y=270;
    width=143;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_girar_derecha);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(53,3,30,23);
}

void GirarDerecha::crear_nuevo()
{
    GirarDerecha * n=new GirarDerecha(obj,ventana);
    n->show();
    ventana->add_botones_movimiento(n);
    qDebug() <<"crear";
}
void GirarDerecha::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor()*pi)/180);
    dx=cos((obj->get_receptor()*pi)/180);
}

void GirarDerecha::correr(){

    direccion=setpasos->toPlainText().toInt();
    obj->rotar_gato(-direccion);
    obj->set_receptor(direccion);

    rotacion_en_el_plano();
    qDebug() << "giro";

    obj->set_cambiar_posicion_y(dy);
    obj->set_cambiar_posicion_x(dx);
    if(siguiente!=nullptr){siguiente->correr();}
}
