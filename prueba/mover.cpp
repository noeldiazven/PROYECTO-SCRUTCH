#include "mover.h"
#include "gato.h"
#include <QWidget>
#include <QHBoxLayout>
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
    this->setGeometry(get_mover_x(),get_mover_y(),100,50);
    this->setStyleSheet("background-color:#FA4606;");

    //add text
    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel * l1=new QLabel();
    l1->setText("Mover");
    l1->setAlignment(Qt::AlignCenter);
    layout->addWidget(l1);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(70,15,10,10);
    layout->addWidget(setpasos);
}

entero Mover::get_mover_x(){
    return mover_x;
}
entero Mover::get_mover_y(){
    return mover_y;
}
void Mover::set_mover_x(entero valor){
    mover_x+=valor;
}
void Mover::set_mover_y(entero valor){
    mover_y+=valor;
}



void Mover::mover(entero a, entero b)
{
    set_mover_x(a);
    set_mover_y(b);
    this->setGeometry(get_mover_x(),get_mover_y(),100,50);
}

void Mover::mouseDoubleClickEvent(QMouseEvent *event)
{
    //mover gato al hacer dobleclick
    obj->mover(pasos);
}

void Mover::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){
        //mover(event->x(),0);
        mover(event->x(),event->y());

        qDebug() << "funciona\n"<<event->x()<<","<<event->y()<<"\n";

    }
}
