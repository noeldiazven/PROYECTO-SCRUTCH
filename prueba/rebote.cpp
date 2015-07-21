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
    name="rebote";
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
    res=res+name+" X "+posiX+" Y "+posiY;
    return res;
}

void Rebote::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<4;i++){
        text >> v;
        if(i==1){this->set_x(v.toDouble());}
        if(i==3){this->set_y(v.toDouble());}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

void Rebote::crear_nuevo()
{
    Rebote * n=new Rebote(obj,ventana);
    n->show();
    ventana->add_botones_movimiento(n);
    QLabel * aux=(*((ventana->botones_movimiento).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}

void Rebote::rotacion_en_el_plano(){
    dy=sin((obj->get_receptor_unica_direccion()*pi)/divisor);
    dx=cos((obj->get_receptor_unica_direccion()*pi)/divisor);
}
void Rebote::correr(){
    if(obj->get_posicion_x()>=(ventana->get_width()-60)){
        obj->rotar_gato_unica_direccion(giro2);
        obj->set_activador(1);
    }

    else if(obj->get_posicion_x()<=-15){
       obj->rotar_gato_unica_direccion(giro4);
       obj->set_activador(0);
    }

    else if(obj->get_posicion_y()>=(ventana->get_heigth()-100)){
       obj->rotar_gato_unica_direccion(giro1);
       obj->set_activador(2);
    }
    else if(obj->get_posicion_y()<=20){
        obj->rotar_gato_unica_direccion(giro3);
        obj->set_activador(3);
    }


    if(siguiente!=nullptr){siguiente->correr();}
}


