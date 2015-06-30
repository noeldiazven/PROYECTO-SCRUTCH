#include "ventanamostrador.h"
#include "imagenes.h"
ventanamostrador::ventanamostrador(QWidget *p)
{
    posx=750;
    posy=0;
    width=450;
    heigth=600;

    comenzar=new QLabel(this);
    comenzar->setGeometry(0,0,450,39);
    comenzar->setPixmap(img_comienzo);

    //creando el gato
    cat=new Gato(this);

    bandera=new botoncomenzar(cat,comenzar);

    this->setGeometry(posx,posy,width,heigth);
    this->setStyleSheet("background-color:#FFFFFF;");
    this->setParent(p);
}

