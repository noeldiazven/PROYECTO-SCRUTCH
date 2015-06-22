#include "mover.h"
#include "gato.h"
#include  <QLabel>
#include <QTextEdit>
#include <QDebug>

Mover::Mover(Gato * g)
{
    siguiente=nullptr;
    obj=g;
    pasos=10;
    x_inicial=110;y_inicial=30;
    mover_x=110;
    mover_y=30;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setGeometry(mover_x,mover_y,130,35);
    this->setPixmap(QPixmap(":/image/mover.png"));


    setpasos=new QTextEdit(this);
    setpasos->setGeometry(51,5,33,23);
}
void Mover::correr(){

    //mover gato al hacer dobleclick
    pasos=setpasos->toPlainText().toDouble();

    qDebug() << obj->get_posicion_x()<<"   "<<obj->get_posicion_y();

    if (obj->get_cambiar_posicion_x()!=0 || obj->get_cambiar_posicion_y()!=0){
        obj->mover_gato(obj->get_cambiar_posicion_x()*pasos,obj->get_cambiar_posicion_y()*pasos);
    }
    else{
        obj->mover_gato(pasos,0);
    }
}
