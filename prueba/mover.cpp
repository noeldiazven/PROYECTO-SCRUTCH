#include "mover.h"
#include "gato.h"
#include <QWidget>
#include  <QLabel>
#include <iostream>
#include <QTextEdit>
#include <QDebug>
//constructor del mover
Mover::Mover(Gato * g)
{
    obj=g;
    pasos=10;
    mover_x=125;
    mover_y=30;
    this->setGeometry(mover_x,mover_y,130,35);
    this->setPixmap(QPixmap(":/image/mover.png"));

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(51,5,33,23);
}

void Mover::mouseDoubleClickEvent(QMouseEvent *event)
{

    //mover gato al hacer dobleclick
    pasos=setpasos->toPlainText().toDouble();

    qDebug() << obj->get_posicion_x()<<"   "<<obj->get_posicion_y();
    //obj->set_receptor(obj->get_receptor());
    if (obj->get_cambiar_posicion_x()!=0 || obj->get_cambiar_posicion_y()!=0){
        if(get_mover_x()>0 && get_mover_x()<300){
            obj->mover_gato(obj->get_cambiar_posicion_x()*pasos,obj->get_cambiar_posicion_y()*pasos);
        }
    }
    else{
        if(get_mover_x()>0 && get_mover_x()<300){
            obj->mover_gato(pasos,0);
        }
    }


}
