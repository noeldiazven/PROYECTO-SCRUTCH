#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>

Angulo::Angulo(Gato*g, ventanabotones *v, ventanamostrador *venta){
    ven=venta;
    dx=0;
    dy=0;
    aux=nullptr;
    id="angulo";
    siguiente=nullptr;
    dentro=nullptr;

    direccion=0;
    mover_x=80;
    mover_y=220;
    width=143;
    height=35;
    obj=g;
    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(block_angulo);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(53,3,30,23);
}

void Angulo::crear_nuevo()
{
    Angulo * n=new Angulo(obj,ventana,ven);
    n->show();
    ventana->add_botones_movimiento(n);
    qDebug() <<"crear";
}
void Angulo::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor()*pi)/180);
    dx=cos((obj->get_receptor()*pi)/180);
}

QString Angulo::darValores()
{
    QString res="";
    res+=id;
    return res;
}

void Angulo::correr(){

    direccion=setpasos->toPlainText().toInt();
    obj->set_Activador3(1);
    obj->rotar_gato(direccion);
    obj->set_receptor(direccion);
    obj->set_captor_de_rotacion(direccion);
    rotacion_en_el_plano();
    qDebug() << "giro";

    obj->set_cambiar_posicion_y(-dy);
    obj->set_cambiar_posicion_x(dx);
    if(siguiente!=nullptr){siguiente->correr();}
    ven->pintar_linea();
}

