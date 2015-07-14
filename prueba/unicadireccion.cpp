#include "unicadireccion.h"
#include "girarderecha.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

UnicaDireccion::UnicaDireccion(Gato*g, ventanabotones *v, ventanamostrador *venta){
    ven=venta;
    dx=0;
    dy=0;
    aux=nullptr;
    id="unicaDireccion";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=320;
    width=160;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_unica_direccion);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(125,4,30,23);
}

void UnicaDireccion::crear_nuevo()
{
    UnicaDireccion * n=new UnicaDireccion(obj,ventana,ven);
    n->show();
    ventana->add_botones_movimiento(n);
    qDebug() <<"crear";
}
void UnicaDireccion::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor_unica_direccion()*pi)/180);
    dx=cos((obj->get_receptor_unica_direccion()*pi)/180);


}

void UnicaDireccion::correr(){

    direccion=setpasos->toPlainText().toInt();
    obj->set_Activador3(3);
    obj->rotar_gato_unica_direccion(direccion);
    obj->set_receptor_unica_direccion(-direccion);

    rotacion_en_el_plano();
    qDebug() << "giro";
    obj->set_captor_de_rotacion(direccion);
    obj->set_cambiar_posicion_y(dy);
    obj->set_cambiar_posicion_x(dx);
    if(siguiente!=nullptr){siguiente->correr();}
    ven->pintar_linea();
}
