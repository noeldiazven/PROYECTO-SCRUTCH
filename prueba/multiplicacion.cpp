#include "multiplicacion.h"
#include  <QLabel>
#include <QTextEdit>
#include <QDebug>
#include "imagenes.h"

Multiplicacion::Multiplicacion(Gato *g,ventanabotones * v)
{
    aux=nullptr;
    id="operador";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;

    mover_x=80;
    mover_y=320;
    ventana=v;
    width=150;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=24;
    varianza_back_y=32.3;

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(multiplicacion);


    setpasos=new QTextEdit(this);
    setpasos->setGeometry(10,5,23,23);

    setpasos1=new QTextEdit(this);
    setpasos1->setGeometry(50,5,23,23);


}

QString Multiplicacion::darValores()
{
    QString res="";
    QString texto1=setpasos->toPlainText();
    QString texto2=setpasos1->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+id+" "+texto1+" "+texto2+" X "+posiX+" Y "+posiY;
    return res;
}

void Multiplicacion::crear_nuevo()
{
    Multiplicacion * n=new Multiplicacion(obj,ventana);
    n->show();
    ventana->add_botones_operadores(n);
    qDebug() <<"crear";
}
void Multiplicacion::correr()
{
    valor1=setpasos->toPlainText().toDouble();
    valor2=setpasos1->toPlainText().toDouble();

    valor_num=valor1*valor2;

    qDebug()<<valor_num;

    if(siguiente!=nullptr){siguiente->correr();}
}





