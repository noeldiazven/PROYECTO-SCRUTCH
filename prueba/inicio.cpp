#include "inicio.h"
#include "imagenes.h"
#include <QLabel>
#include<QDebug>

inicio::inicio(Gato *g, ventanabotones *v)
{
    aux=nullptr;
    id="inicio";
    name="inicio";
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
    res=res+name+" X "+posiX+" Y "+posiY;
    return res;
}

void inicio::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<4;i++){
        text >> v;
        if(i==1){this->set_x(v.toDouble());qDebug()<<"/"<<v.toDouble();}
        if(i==3){this->set_y(v.toDouble());qDebug()<<"/"<<v.toDouble();}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

void inicio::correr(){
    if(siguiente!=nullptr){siguiente->correr();}
}

void inicio::crear_nuevo()
{
    inicio * n=new inicio(obj,ventana);
    n->show();
    ventana->add_botones_control(n);
    QLabel * aux=(*((ventana->botones_control).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}
