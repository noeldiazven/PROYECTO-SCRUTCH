#include "subirlapiz.h"

#include "bajarlapiz.h"
#include "angulo.h"
#include "imagenes.h"
#include  <QLabel>
#include <QTextEdit>
#include <math.h>
#include <QDebug>


subirlapiz::subirlapiz(Gato*g, ventanabotones *v){
    dx=0;
    dy=0;
    aux=nullptr;
    id="subirlapiz";
    name="subirLapiz";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    direccion=0;
    mover_x=80;
    mover_y=200;
    width=143;
    height=35;

    ventana=v;
    varianza_up_x=20;
    varianza_up_y=4.7;
    varianza_back_x=20;
    varianza_back_y=30;

    this->setParent(ventana);
    this->setGeometry(get_mover_x(),get_mover_y(),width,height);
    this->setPixmap(subir_lapiz);
}

QString subirlapiz::darValores()
{
    QString res="";
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" X "+posiX+" Y "+posiY;
    return res;
}

void subirlapiz::crear_nuevo()
{
    subirlapiz * n=new subirlapiz(obj,ventana);
    n->show();
    ventana->add_botones_lapiz(n);
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}



void subirlapiz::correr(){

    obj->set_Activador2(0);
    if(siguiente!=nullptr){siguiente->correr();}

}

