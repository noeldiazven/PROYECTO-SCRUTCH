#include "for.h"
#include "imagenes.h"
#include <QDebug>

For::For(Gato * g, ventanabotones *v)
{
    aux=nullptr;
    id="for";
    name="for";
    lista=0; //lista es el numero de elementos dentro del for
    obj=g;
    ventana=v;
    mover_x=80;
    mover_y=220;
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

    arriba=new QLabel();
    arriba->setGeometry(0,0,100,30);
    arriba->setPixmap(for_arriba);
    arriba->setParent(this);

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

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(55,2,33,23);
}

QString For::darValores()
{
    QString res="";
    QString texto=setpasos->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    res=res+name+" "+texto+" X "+posiX+" Y "+posiY;
    return res;
}

void For::abrir(QTextStream &text)
{
    this->crear_nuevo();
    (this->get_ventana())->sacar_vectores(this);
    this->show();
    QString v;
    for(entero i=0;i<5;i++){
        text >> v;
        if(i==0){iteraciones=v.toDouble();setpasos->setText(v);}
        if(i==2){this->set_x(v.toDouble());}
        if(i==4){this->set_y(v.toDouble());}
    }
    this->setGeometry((this->get_mover_x()),(this->get_mover_y()),this->get_width(),this->get_height());
    this->actualizar_puntos();
    this->verificarColicion();
}

//CAMBIA LA IMAGEN SEGUN CUANTOS ELEMENTOS ESTEN
void For::cambiar_medio(entero x, int y){
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
    this->actualizar_puntos();
    qDebug()<<varianza_back_x<<varianza_back_y;
}

void For::correr()
{
    iteraciones=setpasos->toPlainText().toDouble();
    for(int i=0;i<iteraciones;i++){
        if(dentro!=nullptr){dentro->correr();}
    }
    if(siguiente!=nullptr){siguiente->correr();}
}

void For::crear_nuevo()
{
    For * n=new For(obj,ventana);
    n->show();
    ventana->add_botones_control(n);
    QLabel * aux=(*((ventana->botones_control).begin()));
    if(aux->isHidden()){n->hide();}
    ventana->erase_todos_botones(this);
    ventana->add_todos_botones(n);
    qDebug() <<"crear";
}

