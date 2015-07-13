#include "mayor_menor.h"
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include "imagenes.h"

Mayor_menor::Mayor_menor(Gato * g,ventanabotones * v)
{
    aux=nullptr;
    id="operador";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;

    mover_x=80;
    mover_y=200;
    ventana=v;
    width=150;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(mayor_menor);


    setpasos=new QTextEdit(this);
    setpasos->setGeometry(10,5,23,23);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(50,5,23,23);


}
void Mayor_menor::crear_nuevo()
{
    Mayor_menor * n=new Mayor_menor(obj,ventana);
    n->show();
    ventana->add_botones_operadores(n);
    qDebug() <<"crear";
}
void Mayor_menor::correr()
{
    comp1=setpasos->toPlainText().toDouble();
    comp2=setpasos1->toPlainText().toDouble();


    if (comp1>comp2){
        valor=true;

    }else{valor=false;}
    qDebug() <<valor;

    if(siguiente!=nullptr){siguiente->correr();}
}


