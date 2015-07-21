#include "if.h"
#include "imagenes.h"
#include <QDebug>

IF::IF(Gato * g,ventanabotones * v){
    aux=nullptr;
    id="for";
    name="if";
    lista=0; //lista es el numero de elementos dentro del for
    obj=g;
    ventana=v;
    mover_x=80;
    mover_y=280;
    width=100;
    height=60;
    height_original=60;
    siguiente=nullptr;
    dentro=nullptr;
    iteraciones=0;

    varianza_up_x=24;
    varianza_up_y=6;
    varianza_back_x=24.5;
    varianza_back_y=54;
    varianza_in_x=42;
    varianza_in_y=29;

    posY_arriba=0;
    posY_medio=25;
    posY_abajo=35;
    posX_medio1=63;
    posX_medio2=78;

    arriba_izq=new QLabel();
    arriba_izq->setGeometry(universal,posY_arriba,width,height/2);
    arriba_izq->setPixmap(if_arriba_izq);
    arriba_izq->setParent(this);

    arriba_med=new QLabel();
    arriba_med->setGeometry(posX_medio1,universal,width,height/2);
    arriba_med->setPixmap(if_arriba_med);
    arriba_med->setParent(this);

    arriba_der=new QLabel();
    arriba_der->setGeometry(posX_medio2,universal,width,height/2);
    arriba_der->setPixmap(if_arriba_der);
    arriba_der->setParent(this);

    medio=new QLabel();
    medio->setGeometry(universal,posY_medio,width,height/6);
    medio->setPixmap(for_medio);
    medio->setParent(this);

    abajo=new QLabel();
    abajo->setGeometry(universal,posY_abajo,width,height/3);
    abajo->setPixmap(for_abajo);
    abajo->setParent(this);

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);


}

QString IF::darValores()
{
    QString res="";
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" X "+posiX+" Y "+posiY;
    return res;
}

void IF::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<4;i++){
        text >> v;
        if(i==1){this->set_x(v.toDouble());}
        if(i==3){this->set_y(v.toDouble());}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

void IF::crear_nuevo()
{
    IF * n=new IF(obj,ventana);
    n->show();
    ventana->add_botones_control(n);
    QLabel * aux=(*((ventana->botones_control).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear"<<n->get_pointer_in_x();
}

void IF::cambiar_medio(entero x, tipo_entero y){
    if(x==0){
        height=60;
        medio->setGeometry(universal,posY_medio,width,height/6);
        medio->setPixmap(for_medio);
        abajo->setGeometry(universal,posY_abajo,width,height/3);
        varianza_back_y=height-6;
    }
    else{
        if(x==1){height-=5;}
        if(y>0){height=(height+(varianza));}
        else{height=(height-(varianza));}
        medio->clear();
        medio->setGeometry(universal,posY_medio,width,(height_original/2)*x);
        varianza_back_y=height-6;
        int a=0;
        for(entero i=0;i<x;i++){
            QLabel * nuevo=new QLabel(medio);
            nuevo->setGeometry(universal,a,width,height_original/2);
            nuevo->setPixmap(for_largo);
            nuevo->show();
            a=a+varianza;
            qDebug()<<a;
        }
        abajo->setGeometry(universal,a+(height_original/2),width,height_original/3);
    }
    this->setGeometry(mover_x,mover_y,width,height);
    this->actualizar_puntos();
    qDebug()<<varianza_back_x<<varianza_back_y;
}

void IF :: cambiar_medio_a(entero x, tipo_entero y)
{
    qDebug()<<x<<"esta es<<<<"<<y<<"<<<<es esta";
    if(x==0){
        width=100;
        arriba_med->setGeometry(posX_medio1+1,posY_arriba,width,height/2);
        arriba_med->setPixmap(if_arriba_med);
        arriba_der->setGeometry(posX_medio2+7,posY_arriba,width,height/2);
        varianza_back_x=width-20;
    }
    else{
        if(x==1){width+=varianza;}
        if(y>0){width=(width+(varianza));}
        else{width=(width-(varianza));}
        arriba_med->clear();
        arriba_med->setGeometry(posX_medio1-1,posY_arriba,(width)*x,height/2);
        varianza_back_x=width-6;
        int a=0;
        for(entero i=0;i<x;i++){
            QLabel * nuevo=new QLabel(arriba_med);
            nuevo->setGeometry(a,posY_arriba,width,height/2);
            nuevo->setPixmap(if_arriba_med_largo);
            nuevo->show();
            a=a+55;
            qDebug()<<a;
        }
        arriba_der->setGeometry(posX_medio2+a,posY_arriba,width,height/2);
    }
     this->setGeometry(mover_x,mover_y,width,height);
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
