#include "angulo.h"
#include "mover.h"
#include "gato.h"
#include <QWidget>
#include <QHBoxLayout>
#include  <QLabel>
#include <iostream>
#include <QTextEdit>
#include <QLineEdit>
#include <QDebug>
Angulo::Angulo(Gato*g){

    obj=g;
    pasos=10;
    mover_x=125;
    mover_y=100;

    this->setGeometry(get_mover_x(),get_mover_y(),100,50);
    this->setStyleSheet("background-color:#00BFFF;");

    //add text
    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel * l4=new QLabel();
    l4->setText("Angulo");
    l4->setAlignment(Qt::AlignCenter);
    layout->addWidget(l4);


   QWidget *win = new QWidget();
   QVBoxLayout* layou = new QVBoxLayout(this);
   layou->setAlignment(Qt::AlignHCenter);
   QFrame * line = new QFrame(win);
   line->setObjectName(QString::fromUtf8("line"));
   line->setFrameShape(QFrame::HLine);
   line->setLineWidth(2); line->setFrameShadow(QFrame::Plain);
   layou->insertWidget(74, line);
   QLineEdit* ln1 = new QLineEdit();
   ln1->setText("1"); ln1->setFixedWidth(ln1->width() / 4);

   setpasos=new QTextEdit(this);
   setpasos->setGeometry(70,15,20,20);
   layou->addWidget(setpasos);

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

void Angulo::mouseDoubleClickEvent(QMouseEvent *event)
{
    //mover gato al hacer dobleclick
    obj->mover(pasos);
}

void Angulo::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton){
        //mover(event->x(),0);
        mover(event->x(),event->y());

        qDebug() << "funciona\n"<<event->x()<<","<<event->y()<<"\n";

    }
}
