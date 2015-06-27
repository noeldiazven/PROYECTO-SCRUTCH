#include "mostradorbotones.h"

mostradorbotones::mostradorbotones(QWidget * parent,Gato * g)
{
    posx=0;
    posy=150;
    width=300;
    heigth=450;

    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#E1E0E0;");
    this->setParent(parent);

    //creando botones
/*
    //agregandolo al boton mover
    botonmover=new Mover(g,this);

    //agregandolo al boton angulo
    botonangulo=new Angulo(g,this);

    //agregando el boton correr
    botoninicio=new inicio(g,this);

    //agregando el boton for
    botonfor=new For(g,this);*/
}

