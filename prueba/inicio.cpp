#include "inicio.h"
#include <QLabel>
#include<QDebug>

inicio::inicio(Gato *g,QWidget * v)
{
    siguiente=nullptr;
    obj=g;
    //pasos=10;
    x_inicial=110;y_inicial=130;
    mover_x=110;
    mover_y=130;
    ventana=v;

    varianza_up_x=24;
    varianza_up_y=7.65;
    varianza_back_x=25;
    varianza_back_y=33.7;
    this->setParent(ventana);
    this->setGeometry(mover_x,mover_y,130,35);
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
