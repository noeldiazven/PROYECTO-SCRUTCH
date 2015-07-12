
#include "bloques.h"
#include "imagenes.h"

#include <QDebug>
#include <QSize>

Ayuda::Ayuda(QWidget *par, Gato *gatito)
{
    parent=par;
    img=puntoo;
    this->setPixmap(img);
    obj=gatito;
    contador=0;
    rotar=0;
    posicion_x=205;
    posicion_y=250;
    receptor=0;
    width=4;heigth=4;
    cambiar_posicion_x=0;
    unico_receptor=0;
    activador=0;
    cambiar_posicion_y=0;

    if(contador==0){
        this->setGeometry(obj->get_posicion_x()+28,obj->get_posicion_y()+41,width,heigth);
        this->setParent(parent);
    }
}

void Ayuda:: pintar_punto(){
    contador=1;
}
