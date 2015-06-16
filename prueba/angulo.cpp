#include "angulo.h"
#include "mover.h"
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
    mover_x=125;
    mover_y=100;


    this->setGeometry(get_mover_x(),get_mover_y(),100,50);
    this->setStyleSheet("background-color:#00BFFF;");

    //add text
    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel * l4=new QLabel();
    l4->setText("girar");
    l4->setAlignment(Qt::AlignCenter);
    layout->addWidget(l4);

   setpasos=new QTextEdit(this);
   setpasos->setGeometry(70,15,20,20);
   layout->addWidget(setpasos);
}

entero Angulo::get_mover_x(){
    return mover_x;
}
entero Angulo::get_mover_y(){
    return mover_y;
}
void Angulo::set_mover_x(entero valor){
    mover_x+=valor;
}
void Angulo::set_mover_y(entero valor){
    mover_y+=valor;
}



void Angulo::mover(entero a, entero b)
{
    set_mover_x(a);
    set_mover_y(b);
    this->setGeometry(get_mover_x(),get_mover_y(),100,50);
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

void Angulo::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){
        direccion=setpasos->toPlainText().toInt();

        //mover(event->x(),0);
        mover(event->x(),event->y());

        qDebug() << "funciona\n"<<event->x()<<","<<event->y()<<"\n";

    }

    //if(event->button()==Qt::)

}
void Angulo::paintEvent(QPaintEvent*e){

    QPainter painter(this);
    painter.setPen(QPen(Qt::blue,1,Qt::DashLine));



}


