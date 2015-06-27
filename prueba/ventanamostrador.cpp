#include "ventanamostrador.h"

ventanamostrador::ventanamostrador(QWidget *p)
{
    posx=750;
    posy=0;
    width=450;
    heigth=600;

    comenzar=new QLabel(this);
    comenzar->setGeometry(0,0,450,39);
    comenzar->setPixmap(QPixmap(":/image/comenzar.png"));

    //creando el gato
    cat=new Gato(this);

    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#FFFFFF;");
    this->setParent(p);
}

