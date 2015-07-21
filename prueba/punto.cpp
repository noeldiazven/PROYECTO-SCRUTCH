#include "punto.h"
#include "bloques.h"
#include "imagenes.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include <QSize>


Punto::Punto(Gato*g,QWidget * par, entero x, entero y){
    hola=g;
    second=par;
    imagen=puntoo;
    entero size=2;
    if(g->get_color()==1){
        this->setPixmap(puntoo);
    }
    else if(g->get_color()==2){
        this->setPixmap(color0);
    }
    else if(g->get_color()==3){
        this->setPixmap(color1);
    }
    else if(g->get_color()==4){
        this->setPixmap(color2);
    }
    else if(g->get_color()==5){
        this->setPixmap(color3);
    }
    else{
        this->setPixmap(color0);
    }
    this->setGeometry(x,y+80,size,size);
    this->setParent(second);

}

void Punto::create_nuevo()
{
    entero size=100;
    Punto * n=new Punto(hola,second,size,size);
    n->show();
    qDebug() <<"crear";
}
