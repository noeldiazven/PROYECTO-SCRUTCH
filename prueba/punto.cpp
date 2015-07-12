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
    if(g->get_color()==0){
        this->setPixmap(color0);
        this->setGeometry(x,y+80,2,2);
        this->setParent(second);
    }
    else if(g->get_color()==1){
        this->setPixmap(puntoo);
        this->setGeometry(x,y+80,2,2);
        this->setParent(second);
    }
    else if(g->get_color()==2){
        this->setPixmap(color2);
        this->setGeometry(x,y+80,2,2);
        this->setParent(second);
    }
    else if(g->get_color()==3){
        this->setPixmap(color1);
        this->setGeometry(x,y+80,2,2);
        this->setParent(second);
    }
    else{
        this->setPixmap(color3);
        this->setGeometry(x,y+80,2,2);
        this->setParent(second);
    }

}

void Punto::create_nuevo()
{
    Punto * n=new Punto(hola,second,100,100);
    n->show();
    qDebug() <<"crear";
}
