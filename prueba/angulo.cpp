#include "angulo.h"
#include "gato.h"
#include <QWidget>
#include <QHBoxLayout>
#include  <QLabel>
#include <iostream>
#include <QTextEdit>
#include <math.h>

Angulo::Angulo(Gato*g){

    obj=g;
    direccion=0;
    mover_x=110;
    mover_y=80;

    this->setGeometry(get_mover_x(),get_mover_y(),130,35);
    //this->setStyleSheet("background-color:#00BFFF;");
    this->setPixmap(QPixmap(":/image/girar_izq.png"));

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(53,3,30,23);
}

void Angulo::mouseDoubleClickEvent(QMouseEvent *event){


    direccion=setpasos->toPlainText().toInt();

    obj->set_receptor(direccion);

    dobles dy=sin((obj->get_receptor()*pi)/180);
    dobles dx=cos((obj->get_receptor()*pi)/180);

    qDebug() << "cos\n"<<dx<<"  seno "<<dy;
        //obj->set_cambiar_posicion_x(+dx);
    obj->set_cambiar_posicion_y(-dy);
    obj->set_cambiar_posicion_x(dx);

}
