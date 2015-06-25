#include "for.h"
#include <QDebug>

For::For(Gato * g,QWidget * v)
{
    aux=nullptr;
    id="for";
    lista=0; //lista es el numero de elementos dentro del for
    obj=g;
    ventana=v;
    x_inicial=110;y_inicial=170;
    mover_x=110;
    mover_y=170;
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
    arriba->setPixmap(QPixmap(":/image/for_arriba.png"));
    arriba->setParent(this);

    medio=new QLabel();
    medio->setGeometry(0,25,100,10);
    medio->setPixmap(QPixmap(":/image/for_medio.png"));
    medio->setParent(this);

    abajo=new QLabel();
    abajo->setGeometry(0,35,100,20);
    abajo->setPixmap(QPixmap(":/image/for_abajo.png"));
    abajo->setParent(this);

    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);

    setpasos=new QTextEdit(this);
    setpasos->setGeometry(55,2,33,23);
}

//CAMBIA LA IMAGEN SEGUN CUANTOS ELEMENTOS ESTEN
void For::cambiar_medio(int x){
    if(x==0){
        height=60;
        medio->setGeometry(0,25,100,10);
        medio->setPixmap(QPixmap(":/image/for_medio.png"));
        abajo->setGeometry(0,35,100,20);
    }
    else{
        height=height+(20*x)+3;
        medio->clear();
        medio->setGeometry(0,25,100,(30)*x);
        if(x==1){varianza_back_y+=20;}
        else{varianza_back_y+=30*x;}
        int a=0;
        for(int i=0;i<x;i++){
            QLabel * nuevo=new QLabel(medio);
            nuevo->setGeometry(0,a,100,30);
            nuevo->setPixmap(QPixmap(":/image/for_largo.png"));
            nuevo->show();
            a=a+25;
            qDebug()<<a;
        }
        abajo->setGeometry(0,a+30,100,20);
    }
    this->setGeometry(mover_x,mover_y,width,height);
}

entero For::get_size_lista()
{
    return lista;
}

void For::set_size_lista(int x)
{
    lista+=x;
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
    qDebug() <<"crear";
}
