#include "mover.h"
#include "gato.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <QDebug>
#include "ventana.h"
Mover::Mover(Gato * g, ventanabotones *v, ventanamostrador *venta)
{
    ven=venta;
    aux=nullptr;
    id="mover";
    name="mover";
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

void Mover::abrir(QTextStream & text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<5;i++){
        text >> v;
        if(i==0){pasos=v.toDouble();setpasos->setText(v);}
        if(i==2){this->set_x(v.toDouble());}
        if(i==4){this->set_y(v.toDouble());}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

QString Mover::darValores()
{
    QString res="";
    QString texto=setpasos->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" "+texto+" X "+posiX+" Y "+posiY;
    return res;
}

void Mover::crear_nuevo()
{
    Mover * n=new Mover(obj,ventana,ven);
    n->show();
    ventana->add_botones_movimiento(n);
    QLabel * aux=(*((ventana->botones_movimiento).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}

void Mover::correr(){

    pasos=setpasos->toPlainText().toDouble();

    obj->set_captor_de_mover(pasos);
    obj->set_sumador(1);


    if (obj->get_cambiar_posicion_x()!=0 || obj->get_cambiar_posicion_y()!=0){
        obj->mover_gato(obj->get_cambiar_posicion_x()*pasos,obj->get_cambiar_posicion_y()*pasos);
    }
    else{
        obj->mover_gato(pasos,0);
    }
    qDebug() <<"movio";
    if(siguiente!=nullptr){siguiente->correr();}
    ven->pintar_linea();


}
