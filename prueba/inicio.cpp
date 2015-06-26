#include "inicio.h"
#include <QLabel>
#include<QDebug>

inicio::inicio(Gato *g,QWidget * v)
{
    aux=nullptr;
    id="inicio";
    siguiente=nullptr;
    dentro=nullptr;
    obj=g;
    mover_x=110;
    mover_y=130;
    ventana=v;
    width=130;
    height=35;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=25;
    varianza_back_y=33.7;
    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,width,height);
    this->setPixmap(QPixmap(":/image/inicio.png"));
}
void inicio::correr(){
    if(siguiente!=nullptr){siguiente->correr();}
}

void inicio::crear_nuevo()
{
    inicio * n=new inicio(obj,ventana);
    n->show();
    qDebug() <<"crear";
}
