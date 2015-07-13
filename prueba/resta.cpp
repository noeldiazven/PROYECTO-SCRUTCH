#include "resta.h"
#include  <QLabel>
#include <QTextEdit>
#include <QDebug>
#include "imagenes.h"

Resta::Resta(Gato *g,ventanabotones *v)
{
    aux=nullptr;
    id="operador";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;

    mover_x=80;
    mover_y=350;
    ventana=v;
    width=150;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(resta);


    setpasos=new QTextEdit(this);
    setpasos->setGeometry(10,5,23,23);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(50,5,23,23);


}
void Resta::crear_nuevo()
{
    Resta * n=new Resta(obj,ventana);
    n->show();
    ventana->add_botones_operadores(n);
    qDebug() <<"crear";
}
void Resta::correr()
{
    valor1=setpasos->toPlainText().toDouble();
    valor2=setpasos1->toPlainText().toDouble();

    valor_num=valor1-valor2;

    qDebug()<<valor_num;

    if(siguiente!=nullptr){siguiente->correr();}
}





