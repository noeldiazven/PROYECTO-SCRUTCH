#include "menor_mayor.h"
#include <QLabel>
#include <QTextEdit>
#include <QDebug>
#include "imagenes.h"

Menor_mayor::Menor_mayor(Gato *g, ventanabotones * v)
{
    aux=nullptr;
    id="operador";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;

    mover_x=80;
    mover_y=230;
    ventana=v;
    width=150;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(menor_mayor);


    setpasos=new QTextEdit(this);
    setpasos->setGeometry(10,5,23,23);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(50,5,23,23);


}

QString Menor_mayor::darValores()
{
    QString res="";
    QString texto1=setpasos->toPlainText();
    QString texto2=setpasos1->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+id+" "+texto1+" "+texto2+" X "+posiX+" Y "+posiY;
    return res;
}

void Menor_mayor::crear_nuevo()
{
    Menor_mayor * n=new Menor_mayor(obj,ventana);
    n->show();
    ventana->add_botones_operadores(n);
    qDebug() <<"crear";
}
void Menor_mayor::correr()
{
    comp1=setpasos->toPlainText().toDouble();
    comp2=setpasos1->toPlainText().toDouble();


    if (comp1<comp2){
        valor=true;
    }else{valor=false;}
    qDebug() <<valor;
    if(siguiente!=nullptr){siguiente->correr();}
}


