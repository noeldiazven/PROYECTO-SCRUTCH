#include "if.h"
#include "imagenes.h"
#include <QDebug>

IF::IF(Gato * g,ventanabotones * v){
    aux=nullptr;
    id="for";
    lista=0; //lista es el numero de elementos dentro del for
    obj=g;
    ventana=v;
    mover_x=80;
    mover_y=280;
    width=100;
    height=60;
    siguiente=nullptr;
    dentro=nullptr;
    iteraciones=0;

    varianza_up_x=24;
    varianza_up_y=6;
    varianza_back_x=24.5;
    varianza_back_y=54;
    varianza_in_x=42;
    varianza_in_y=29;

    arriba_izq=new QLabel();
    arriba_izq->setGeometry(0,0,100,30);
    arriba_izq->setPixmap(if_arriba_izq);
    arriba_izq->setParent(this);

    arriba_med=new QLabel();
    arriba_med->setGeometry(63,0,100,30);
    arriba_med->setPixmap(if_arriba_med);
    arriba_med->setParent(this);

    arriba_der=new QLabel();
    arriba_der->setGeometry(78,0,100,30);
    arriba_der->setPixmap(if_arriba_der);
    arriba_der->setParent(this);

    medio=new QLabel();
    medio->setGeometry(0,25,100,10);
    medio->setPixmap(for_medio);
    medio->setParent(this);

    abajo=new QLabel();
    abajo->setGeometry(0,35,100,20);
    abajo->setPixmap(for_abajo);
    abajo->setParent(this);

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);


}
void IF::crear_nuevo()
{
    IF * n=new IF(obj,ventana);
    n->show();
    ventana->add_botones_control(n);
    qDebug() <<"crear"<<n->get_pointer_in_x();
}

void IF::cambiar_medio(entero x, int y){
    if(x==0){
        height=60;
        medio->setGeometry(0,25,100,10);
        medio->setPixmap(for_medio);
        abajo->setGeometry(0,35,100,20);
        varianza_back_y=height-6;
    }
    else{
        if(x==1){height-=5;}
        if(y>0){height=(height+(25));}
        else{height=(height-(25));}
        medio->clear();
        medio->setGeometry(0,25,100,(30)*x);
        varianza_back_y=height-6;
        int a=0;
        for(int i=0;i<x;i++){
            QLabel * nuevo=new QLabel(medio);
            nuevo->setGeometry(0,a,100,30);
            nuevo->setPixmap(for_largo);
            nuevo->show();
            a=a+25;
            qDebug()<<a;
        }
        abajo->setGeometry(0,a+30,100,20);
    }
    this->setGeometry(mover_x,mover_y,width,height);
    qDebug()<<varianza_back_x<<varianza_back_y;
}

void IF :: cambiar_medio_a(entero x, int y)
{
    if(x==0){
        width=100;
        arriba_med->setGeometry(63,0,100,30);
        arriba_med->setPixmap(if_arriba_med);
        arriba_der->setGeometry(78,0,100,30);
        varianza_back_x=width-6;
    }
    else{
        if(x==1){width-=5;}
        if(y>0){width=(width+(25));}
        else{width=(width-(25));}
        arriba_med->clear();
        arriba_med->setGeometry(63,0,(100)*x,30);
        varianza_back_x=width-6;
        int a=0;
        for(int i=0;i<x;i++){
            QLabel * nuevo=new QLabel(arriba_med);
            nuevo->setGeometry(a,0,100,30);
            nuevo->setPixmap(if_arriba_med_largo);
            nuevo->show();
            a=a+25;
            qDebug()<<a;
        }
    }
}

void IF::correr(){
    if(dentro_h!=nullptr){
        dentro_h->correr();
        if(dentro_h->get_valor()==true){
            qDebug()<<"salio";
            if(dentro!=nullptr){dentro->correr();}
            }
              }
    if(siguiente!=nullptr){siguiente->correr();}
}
