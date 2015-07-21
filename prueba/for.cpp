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

    arriba=new QLabel();
    arriba->setGeometry(universal,posY_arriba,width,height/2);
    arriba->setPixmap(for_arriba);
    arriba->setParent(this);

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

    posX_t=55;
    posY_t=3;
    width_t=30;
    height_t=23;

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(posX_t,posY_t,width_t,height_t);
}

QString For::darValores()
{
    QString res="";
    QString texto=setpasos->toPlainText();
    QString posiX = QString::number(mover_x);
    QString posiY = QString::number(mover_y);
    if(texto==""){res=res+name+" "+"0"+" X "+posiX+" Y "+posiY;}
    else{res=res+name+" "+texto+" X "+posiX+" Y "+posiY;}
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
void For::cambiar_medio(entero x, tipo_entero y){
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
        medio->setGeometry(universal,posY_medio,width,(30)*x);
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
        abajo->setGeometry(universal,a+30,width,height_original/3);
    }
    this->setGeometry(mover_x,mover_y,width,height);
    this->actualizar_puntos();
    qDebug()<<varianza_back_x<<varianza_back_y;
}

void For::correr()
{
    iteraciones=setpasos->toPlainText().toDouble();
    for(entero i=0;i<iteraciones;i++){
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

