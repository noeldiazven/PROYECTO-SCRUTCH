#include "ventanabotones.h"

ventanabotones::ventanabotones(QWidget * parent,Gato * g)
{
    posx=0;
    posy=0;
    width=750;
    heigth=600;
    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#B5B3B04;");
    this->setParent(parent);

    operaciones=new QWidget(this);
    operaciones->setGeometry(300,0,450,600);
    operaciones->setStyleSheet("background-color:#A09D9D;");

    menu=new menubotones(this);
    mostradorBotones=new mostradorbotones(this,g);
}

