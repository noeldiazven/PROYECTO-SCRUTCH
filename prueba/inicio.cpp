#include "inicio.h"
#include "imagenes.h"
#include <QLabel>
#include<QDebug>

inicio::inicio(Gato *g, ventanabotones *v)
{
    aux=nullptr;
    id="inicio";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    mover_x=80;
    mover_y=170;
    ventana=v;
    width=130;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=25;
    varianza_back_y=33.7;
    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(block_inicio);
}

QString inicio::darValores()
{
    QString res="";
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+id+" X "+posiX+" Y "+posiY;
    return res;
}

void inicio::correr(){
    if(siguiente!=nullptr){siguiente->correr();}
}

void inicio::crear_nuevo()
{
    inicio * n=new inicio(obj,ventana);
    n->show();
    ventana->add_botones_control(n);
    qDebug() <<"crear";
}
